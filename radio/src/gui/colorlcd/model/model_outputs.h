/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include <vector>

#include "pagegroup.h"

class OutputLineButton;

class ModelOutputsPage : public PageGroupItem
{
 public:
  ModelOutputsPage(PageDef& pageDef);

  void build(Window* window) override;

  static constexpr coord_t ADD_TRIMS_X = PAD_SMALL;
  static constexpr coord_t ADD_TRIMS_Y = PAD_SMALL;
  static LAYOUT_SIZE(ADD_TRIMS_W, (LCD_W / 2) - PAD_LARGE, LCD_W - PAD_LARGE - PAD_SMALL)
  static coord_t ADD_TRIMS_H() { return EdgeTxStyles::UI_ELEMENT_HEIGHT(); }
  static LAYOUT_VAL_SCALED(EXLIM_XO, 58)
  static constexpr coord_t EXLIMCB_X = LCD_W - EXLIM_XO;
  static coord_t EXLIMCB_Y() { return (NARROW_LAYOUT ? (ADD_TRIMS_Y + ADD_TRIMS_H() + PAD_TINY) : (PAD_SMALL)); }
  static LAYOUT_VAL_SCALED(EXLIMCB_W, 52)
  static coord_t EXLIMCB_H() { return EdgeTxStyles::UI_ELEMENT_HEIGHT(); }
  static LAYOUT_SIZE(EXLIM_X, ADD_TRIMS_X + ADD_TRIMS_W + PAD_SMALL, PAD_MEDIUM)
  static coord_t EXLIM_Y() { return compactUiEnabled() ? (EXLIMCB_Y() + (EXLIMCB_H() - EdgeTxStyles::STD_FONT_HEIGHT()) / 2) : ((NARROW_LAYOUT ? (ADD_TRIMS_Y + ADD_TRIMS_H() + PAD_LARGE) : (PAD_LARGE + PAD_TINY))); }
  static constexpr coord_t EXLIM_W = EXLIMCB_X - EXLIM_X - PAD_SMALL;
  static constexpr coord_t TRIMB_X = PAD_SMALL;
  static coord_t TRIMB_Y() { return EXLIMCB_Y() + EXLIMCB_H() + PAD_MEDIUM / 2; }
  static constexpr coord_t TRIMB_W = LCD_W - PAD_SMALL * 2;

 protected:
  std::vector<OutputLineButton*> outputButtons;

  void editOutput(uint8_t channel, OutputLineButton* btn);
};
