# X10/X10S Compact UI — first increment

Experimental, opt-in quick-menu layout for the original FrSky X10/X10S.
Enable with `-DX10S_COMPACT_UI=ON -DPCB=X10 -DPCBREV=STD`.
The option defaults to OFF and rejects other boards, including Express.

Changes at 480 x 272:

| Item | Standard | Compact |
| --- | --- | --- |
| Submenu grid | 6 x 2 | 6 x 3 |
| Tile size | 75 x 71 | 75 x 52 |
| Icon size | 30 x 30 | 20 x 20 |
| Latin label line height | 17 px (XS) | 12 px (XXS) |

Long labels are bounded to the tile and ellipsized. The original selection,
disabled-state styling, rotary navigation and page actions are retained.
Icons are resampled into a 400-byte buffer per button when created.
This increment does not change model data, RF handling, Lua font metrics,
home-screen widgets or the layout of individual setup pages.

## Validation status

Prepared against cc2aa403dd6326aed2ce642fef0651c933c0f41f.
The patch and workflow are drafts until a real CI run succeeds.
No firmware or simulator binary has yet been built from this patch.
The Windows `--help` check only checks executable startup, not GUI rendering.

## Required acceptance checks

1. Build firmware and Windows simulator using `X10S Compact UI` Actions.
2. Open the simulator with a separate test storage directory.
3. Verify all six categories and the 18 visible submenu positions.
4. Check EN and PL labels, long Lua tool names and favorites.
5. Check rotary selection, Enter, Back and page navigation; scroll to items
   beyond the first 18 and verify disabled entries and focus visibility.
6. Rebuild with the option OFF and compare the original quick menu.
7. Confirm that enabling the option on Express fails configuration.

Review the simulator visually before considering a hardware test.
