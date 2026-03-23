# keebs

## Building firmware

QMK compiles from its own copy of the keymap, not this repo directly. Before compiling, sync the keymap files:

```bash
KB=planck/rev7 KM=soryn
cp -r keyboards/$KB/keymaps/$KM/. ~/qmk_firmware/keyboards/$KB/keymaps/$KM/
qmk compile -kb $KB -km $KM
```

## Copying firmware to the repo

After a successful build, copy the `.bin` from the qmk_firmware root to `firmware/`:

```bash
cp ~/qmk_firmware/planck_rev7_soryn.bin firmware/
```
