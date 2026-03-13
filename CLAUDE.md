# keebs

## Building firmware

Use `qmk compile` targeting the keyboard and keymap:

```bash
qmk compile -kb planck/rev7 -km soryn
```

## Copying firmware to the repo

After a successful build, copy the `.bin` from the qmk_firmware root to `firmware/`:

```bash
cp ~/qmk_firmware/planck_rev7_soryn.bin firmware/
```
