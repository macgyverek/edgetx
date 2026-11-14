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

#include "page.h"

class TimerWindow : public SubPage
{
 public:
  TimerWindow(uint8_t timer);

  static LAYOUT_VAL_SCALED(COUNTDOWN_W, 144)
  static coord_t COUNTDOWN_LBL_YO() { return (NARROW_LAYOUT ? ((EdgeTxStyles::UI_ELEMENT_HEIGHT() + PAD_TINY) / 2) : (0)); }
  static LAYOUT_SIZE(COUNTDOWN_VAL_XO, COUNTDOWN_W + PAD_SMALL, 0)
  static coord_t COUNTDOWN_VAL_YO() { return (NARROW_LAYOUT ? (EdgeTxStyles::UI_ELEMENT_HEIGHT() + PAD_TINY) : (0)); }

 protected:
  Window* timerDirLine = nullptr;
};
