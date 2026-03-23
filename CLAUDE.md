# keebs

## Building firmware

Before compiling, sync the keymap files from this repo to qmk_firmware - QMK compiles from its own copy, not this repo directly:

```bash
cp keyboards/planck/rev7/keymaps/soryn/keymap.c ~/qmk_firmware/keyboards/planck/rev7/keymaps/soryn/keymap.c
cp keyboards/planck/rev7/keymaps/soryn/functions.c ~/qmk_firmware/keyboards/planck/rev7/keymaps/soryn/functions.c
```

Then compile:

```bash
qmk compile -kb planck/rev7 -km soryn
```

## Copying firmware to the repo

After a successful build, copy the `.bin` from the qmk_firmware root to `firmware/`:

```bash
cp ~/qmk_firmware/planck_rev7_soryn.bin firmware/
```
