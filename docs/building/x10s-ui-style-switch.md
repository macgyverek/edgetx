# X10S runtime UI style experiment

Based on EdgeTX 2.12.5 and compact branch e94c25c.
Build with X10S_COMPACT_UI=ON for X10 STD.

Radio settings: UI style (restart) -> Normal / Compact.
Save the choice and restart normally. Default for existing radio.yml without
the new key is Normal. The active style is fixed until restart.
The setting uses one formerly spare bit; the RadioData size is unchanged.
Both styles share fonts, icons, screens and model data.

Validation: compare both styles after separate restarts, including named
mixers, output rows, flight modes, function markers, setup buttons, numeric
keyboard, dropdowns, toggles and backlight sliders.
