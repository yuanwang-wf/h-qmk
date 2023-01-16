{
  description = "yuanw/h-qmk";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-parts.url = "github:hercules-ci/flake-parts";
    haskell-flake.url = "github:srid/haskell-flake";
    flake-root.url = "github:srid/flake-root";
    mission-control.url = "github:Platonic-Systems/mission-control";
    pre-commit-hooks-nix.url = "github:cachix/pre-commit-hooks.nix";
  };

  outputs = inputs@{ self, nixpkgs, flake-parts, ... }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      systems = nixpkgs.lib.systems.flakeExposed;
      imports = [
        inputs.haskell-flake.flakeModule
        inputs.pre-commit-hooks-nix.flakeModule
        inputs.flake-root.flakeModule
        inputs.mission-control.flakeModule
      ];
      perSystem = { self', lib, config, pkgs, ... }:

        {
          # The "main" project. You can have multiple projects, but this template
          # has only one.
          haskellProjects.main = {
            packages = {
              haskell-template.root = ./.;
            };
            # overrides = self: super: {}
            hlsCheck.enable = false;
            hlintCheck.enable = true;
          };
          pre-commit.settings.hooks = {
            nixpkgs-fmt.enable = true;
            cabal-fmt.enable = true;
            fourmolu.enable = true;
          };

          # Dev shell scripts.
          mission-control.scripts = {
            docs = {
              description = "Start Hoogle server for project dependencies";
              exec = ''
                echo http://127.0.0.1:8888
                hoogle serve -p 8888 --local
              '';
              category = "Dev Tools";
            };
            repl = {
              description = "Start the cabal repl";
              exec = ''
                cabal repl "$@"
              '';
              category = "Dev Tools";
            };
            run = {
              description = "Run the project with ghcid auto-recompile";
              exec = ''
                ghcid -c "cabal repl exe:haskell-template" --warnings -T :main
              '';
              category = "Primary";
            };
          };

          # Default package.
          packages.default = self'.packages.main-haskell-template;

          # Default shell.
          devShells.default =
            let
              inherit (config.pre-commit) installationScript;
            in

            config.mission-control.installToDevShell (
              self'.devShells.main.overrideAttrs (oa: {
                nativeBuildInputs = (oa.nativeBuildInputs or [ ]) ++ [ pkgs.pre-commit ];
                shellHook = (oa.shellHook or "") + installationScript;
              }));
        };
    };
}
