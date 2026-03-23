#!/usr/bin/env bash
set -euo pipefail

KB=${1:-}
KM=${2:-}
VIAL=false

for arg in "${@:3}"; do
    if [[ "$arg" == "--vial" ]]; then
        VIAL=true
    fi
done

if [[ -z "$KB" || -z "$KM" ]]; then
    echo "Usage: $0 <keyboard> <keymap> [--vial]"
    echo "  e.g. $0 planck/rev7 soryn"
    echo "       $0 splaytoraid soryn --vial"
    exit 1
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [[ "$VIAL" == true ]]; then
    QMK_DIR="${VIAL_QMK_DIR:-$SCRIPT_DIR/vial-qmk}"
    if [[ ! -d "$QMK_DIR" ]]; then
        echo "Error: vial-qmk not found at $QMK_DIR"
        echo "Clone it with: git clone https://github.com/vial-kb/vial-qmk.git vial-qmk && cd vial-qmk && make git-submodule"
        exit 1
    fi
else
    QMK_DIR="${QMK_DIR:-$SCRIPT_DIR/qmk_firmware}"
fi

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
if [[ "$VIAL" == true ]]; then
    make -C "$QMK_DIR" "${KB}:${KM}"
else
    qmk compile -kb "$KB" -km "$KM"
fi

# Copy any resulting binary (.bin, .hex, .uf2) to firmware/
KB_FLAT="${KB//\//_}"
for ext in bin hex uf2; do
    FILE="$QMK_DIR/${KB_FLAT}_${KM}.${ext}"
    if [[ -f "$FILE" ]]; then
        echo "Copying ${KB_FLAT}_${KM}.${ext} to firmware/"
        cp "$FILE" firmware/
    fi
done
