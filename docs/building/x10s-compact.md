# X10/X10S Compact UI on EdgeTX 2.12.5

Based on official tag v2.12.5 (0ebe2e98b2085e2251ad6773b26c8a7ab8dd3e99).

Enable with `-DX10S_COMPACT_UI=ON -DPCB=X10 -DPCBREV=STD`.
The option defaults to OFF and rejects other boards, including Express.

The quick menu uses the original 2.12.5 icons, captions and geometry.
Compact UI instead reduces shared settings controls from 32 to 24 pixels
and uses the language-aware XS font for standard/bold UI styles (17-pixel
Latin line height). Table vertical padding is reduced from 7 to 4 pixels.
Standard and bold UI text both use the regular XS font. Header icon assets
and header geometry are retained. Lua getFont() identifiers and metrics are
unchanged. Other screens using the same standard UI controls also inherit
the smaller control font and heights; this is not a per-screen setting.

The workflow builds ARM firmware using the upstream 2.12 container and the
standalone Windows SDL simulator with MinGW GCC. Windows compilation uses
`-mno-ms-bitfields` for firmware-compatible packed data. All existing
structure-size assertions remain enabled. The package includes detected
MinGW runtime DLLs and runs `simu.exe --help` without build tools on PATH.

Inputs/Mixes, Logical Switches, Special/Global Functions and Global Variables
also use compact list frames with adjusted content positions.
Output rows also use 24-pixel frames, with centered values and bars. Named
channels use a single line (channel number followed by name, ellipsized if
needed); the full name remains in the output editor. Form rows use 2-pixel
vertical padding and text inputs/buttons use tighter internal padding.

A successful build/startup check is not a visual GUI test. Before a hardware
test, inspect Radio Setup, Model Setup, Inputs, Mixes and Outputs in EN/PL,
including text editing and dropdowns. Verify rotary selection, Enter, Back,
page keys and favorites using test model data, and confirm that the quick
menu retains its original appearance.

Model/Radio Setup navigation buttons use a 24-pixel minimum instead of
62-pixel tiles. Wrapped labels increase only their own button and row height
as needed; rows have 2-pixel gaps. Quick-menu tiles remain unchanged.
