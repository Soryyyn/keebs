# keebs

## Building firmware

Use `build.sh` which syncs the keymap, compiles, and copies the binary to `firmware/`:

```bash
# Standard QMK (e.g. planck)
./build.sh planck/rev7 soryn

# Vial QMK (e.g. splaytoraid)
./build.sh splaytoraid soryn --vial
```

QMK compiles from its own copy of the keymap, not this repo directly - the script handles the sync automatically.

### Setting up vial-qmk

Required for keyboards using Vial (e.g. splaytoraid):

```bash
git clone https://github.com/vial-kb/vial-qmk.git ~/vial-qmk
cd ~/vial-qmk && make git-submodule
```
