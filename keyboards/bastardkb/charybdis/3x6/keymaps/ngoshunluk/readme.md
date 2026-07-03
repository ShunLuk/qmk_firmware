# ngoshunluk's Charybdis 3x6 keymap

Ported from the [illness072/elephant42 keymap](../../../../elephant42/keymaps/ngoshunluk/). See that keymap's comments for the shared design (home-row mods, one-shot layers, OS-based Ctrl/Cmd swap, combos).

Differences from the elephant42 original, forced by the 41-key/5-thumb Charybdis layout (vs. 42-key/8-thumb):
- Row2 outer pinky columns (`L20`/`R25`) are new slots not present on elephant42 — left unassigned (`KC_NO`).
- Right thumb only has 2 slots instead of 3: Backspace and `OSL(_NUM)` are merged into one key, `LT(_NUM, KC_BSPC)` (tap = Backspace, hold = Num layer).
- `RGB_MATRIX_ENABLE = no` — VIA + combos + pointing device already fill the Elite-C's 28K flash; RGB matrix didn't fit alongside them.
- Trackball (pmw3360) works out of the box with default settings; no dedicated DPI/sniper/drag-scroll keys added yet.
