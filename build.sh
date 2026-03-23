#!/usr/bin/env bash
set -euo pipefail

KB=${1:-}
KM=${2:-}

if [[ -z "$KB" || -z "$KM" ]]; then
    echo "Usage: $0 <keyboard> <keymap>"
    echo "  e.g. $0 planck/rev7 soryn"
    exit 1
fi

QMK_DIR="${QMK_DIR:-$HOME/qmk_firmware}"
SRC="keyboards/$KB/keymaps/$KM"
DST="$QMK_DIR/keyboards/$KB/keymaps/$KM"

if [[ ! -d "$SRC" ]]; then
    echo "Error: $SRC not found in this repo"
    exit 1
fi

echo "Syncing $SRC -> $DST"
mkdir -p "$DST"
cp -r "$SRC/." "$DST/"

echo "Compiling..."
qmk compile -kb "$KB" -km "$KM"

BIN="${KB//\//_}_${KM}.bin"
if [[ -f "$QMK_DIR/$BIN" ]]; then
    echo "Copying $BIN to firmware/"
    cp "$QMK_DIR/$BIN" firmware/
fi
