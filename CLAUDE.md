# keebs

## Building firmware

Use `build.sh` which syncs the keymap to qmk_firmware, compiles, and copies the binary to `firmware/`:

```bash
./build.sh planck/rev7 soryn
```

QMK compiles from its own copy of the keymap, not this repo directly - the script handles the sync automatically.
