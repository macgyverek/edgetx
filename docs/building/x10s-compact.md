# X10/X10S Compact UI on EdgeTX 2.12.5

Based on official tag v2.12.5 (0ebe2e98b2085e2251ad6773b26c8a7ab8dd3e99).

Enable with `-DX10S_COMPACT_UI=ON -DPCB=X10 -DPCBREV=STD`.
The option defaults to OFF and rejects other boards, including Express.

This increment reduces quick-menu tiles from 72x70 to 64x52 pixels,
icons from 30x30 to 20x20, and Latin label line height from 17 to 12 pixels.
It retains the 2.12 five-column, two-row quick menu. Long captions are
ellipsized within the tile. Setup pages and home-screen widgets are unchanged.

The workflow builds ARM firmware using the upstream 2.12 container and the
standalone Windows SDL simulator with MinGW GCC. Windows compilation uses
`-mno-ms-bitfields` for firmware-compatible packed data. All existing
structure-size assertions remain enabled. The package includes detected
MinGW runtime DLLs and runs `simu.exe --help` without build tools on PATH.

A successful build/startup check is not a visual GUI test. Before a hardware
test, inspect all menu tiles and EN/PL labels in the simulator, then verify
rotary selection, Enter, Back, page keys and favorites using test model data.
