/*
 * Copyright (c) 2019-2020, Dmitry (DiSlord) dislordlive@gmail.com
 * All rights reserved.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * The software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include <stdint.h>
#include "nanovna.h"

/*
 * Most font glyph have width 5 pixels
 * Check 0 byte of char bitmap data for get width
 */

#if 0
// Font definitions for header
#define FONT_START_CHAR   0x17
#define FONT_WIDTH           5
#define FONT_WIDTH_MASK   0x07
#define FONT_GET_HEIGHT      7
#define FONT_STR_HEIGHT      8
#define FONT_GET_DATA(ch)   (  &x5x7_bits[(ch-FONT_START_CHAR)*FONT_GET_HEIGHT])
#define FONT_GET_WIDTH(ch)  (8-(x5x7_bits[(ch-FONT_START_CHAR)*FONT_GET_HEIGHT] & FONT_WIDTH_MASK))
#endif

#define CW_01  (8 - 1)
#define CW_02  (8 - 2)
#define CW_03  (8 - 3)
#define CW_04  (8 - 4)
#define CW_05  (8 - 5)
#define CW_06  (8 - 6)
#define CW_07  (8 - 7)
#define CW_08  (8 - 8)

#if FONT_START_CHAR!=0x17
#error "Need set correct offset in x5x7_bits font"
#endif

// Font character bitmap data.
const uint8_t x5x7_bits[] =
{
#if 0
// Char 0x00 width = 5
  0b11110000|CW_05, // |****    |
  0b11110000,       // |****    |
  0b11110000,       // |****    |
  0b11110000,       // |****    |
  0b11110000,       // |****    |
  0b11110000,       // |****    |
  0b00000000,       // |        |

// Char 0x01 width = 5
  0b00000000|CW_05, // |        |
  0b00100000,       // |  *     |
  0b01110000,       // | ***    |
  0b11111000,       // |*****   |
  0b01110000,       // | ***    |
  0b00100000,       // |  *     |
  0b00000000,       // |        |

// Char 0x02 width = 5
  0b01010000|CW_05, // | * *    |
  0b10101000,       // |* * *   |
  0b01010000,       // | * *    |
  0b10101000,       // |* * *   |
  0b01010000,       // | * *    |
  0b10101000,       // |* * *   |
  0b01010000,       // | * *    |

// Char 0x03 width = 5
  0b10100000|CW_05, // |* *     |
  0b11100000,       // |***     |
  0b10100000,       // |* *     |
  0b10100000,       // |* *     |
  0b01110000,       // | ***    |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 0x04 width = 5
  0b00100000|CW_05, // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b11100000,       // |***     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 0x05 width = 5
  0b11000000|CW_05, // |**      |
  0b10000000,       // |*       |
  0b11000000,       // |**      |
  0b01100000,       // | **     |
  0b01010000,       // | * *    |
  0b01100000,       // | **     |
  0b01010000,       // | * *    |

// Char 0x06 width = 5
  0b10000000|CW_05, // |*       |
  0b10000000,       // |*       |
  0b11000000,       // |**      |
  0b00110000,       // |  **    |
  0b00100000,       // |  *     |
  0b00110000,       // |  **    |
  0b00100000,       // |  *     |

// Char 0x07 width = 5
  0b00100000|CW_05, // |  *     |
  0b01010000,       // | * *    |
  0b00100000,       // |  *     |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char 0x08 width = 5
  0b00000000|CW_05, // |        |
  0b00100000,       // |  *     |
  0b01110000,       // | ***    |
  0b00100000,       // |  *     |
  0b00000000,       // |        |
  0b01110000,       // | ***    |
  0b00000000,       // |        |

// Char 0x09 width = 5
  0b10010000|CW_05, // |*  *    |
  0b11010000,       // |** *    |
  0b10110000,       // |* **    |
  0b10010000,       // |*  *    |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00110000,       // |  **    |

// Char 0x0A width = 5
  0b10100000|CW_05, // |* *     |
  0b10100000,       // |* *     |
  0b10100000,       // |* *     |
  0b01000000,       // | *      |
  0b01110000,       // | ***    |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 0x0B width = 5
  0b00100000|CW_05, // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b11100000,       // |***     |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char 0x0C width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b11100000,       // |***     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 0x0D width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00111000,       // |  ***   |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 0x0E width = 5
  0b00100000|CW_05, // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00111000,       // |  ***   |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char 0x0F width = 5
  0b00100000|CW_05, // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b11111000,       // |*****   |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 0x10 width = 5
  0b00000000|CW_05, // |        |
  0b11111000,       // |*****   |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char 0x11 width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b11111000,       // |*****   |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char 0x12 width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b11111000,       // |*****   |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char 0x13 width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b11111000,       // |*****   |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char 0x14 width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b11111000,       // |*****   |
  0b00000000,       // |        |

// Char 0x15 width = 5
  0b00100000|CW_05, // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00111000,       // |  ***   |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 0x16 width = 6
  0b00000000|CW_06, // |        |
  0b11000000,       // |**      |
  0b11110000,       // |****    |
  0b00011100,       // |   ***  |
  0b11110000,       // |****    |
  0b11000000,       // |**      |
  0b00000000,       // |        |
#endif

// Char "\029" width = 6
  0b00000000|CW_06, // |        |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b01010000,       // | * *    |
  0b01010000,       // | * *    |
  0b10001000,       // |*   *   |
  0b11111000,       // |*****   |

// Char "\030" width = 4
  0b10000000|CW_04, // |*       |
  0b11000000,       // |**      |
  0b11100000,       // |***     |
  0b11110000,       // |****    |
  0b11100000,       // |***     |
  0b11000000,       // |**      |
  0b10000000,       // |*       |

// Char "\031" width = 7
  0b00000000|CW_07, // |        |
  0b01101100,       // | ** **  |
  0b10110010,       // |* **  * |
  0b10010010,       // |*  *  * |
  0b10011010,       // |*  ** * |
  0b01101100,       // | ** **  |
  0b00000000,       // |        |

// Char "\032" width = 6
  0b00000000|CW_06, // |        |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b11111000,       // |*****   |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |
  0b00000000,       // |        |

// Char "\033" width = 6
  0b00000000|CW_06, // |        |
  0b00100000,       // |  *     |
  0b00010000,       // |   *    |
  0b11111000,       // |*****   |
  0b00010000,       // |   *    |
  0b00100000,       // |  *     |
  0b00000000,       // |        |

// Char "\034" width = 6
  0b00000000|CW_06, // |        |
  0b11111000,       // |*****   |
  0b01010000,       // | * *    |
  0b01010000,       // | * *    |
  0b01010000,       // | * *    |
  0b01010000,       // | * *    |
  0b10011000,       // |*  **   |

// Char "\035" width = 6
  0b00000000|CW_06, // |        |
  0b00000000,       // |        |
  0b10001000,       // |*   *   |
  0b10001000,       // |*   *   |
  0b11011000,       // |** **   |
  0b10101000,       // |* * *   |
  0b10000000,       // |*       |

// Char "\036" width = 6
  0b00000000|CW_06, // |        |
  0b01110000,       // | ***    |
  0b10001000,       // |*   *   |
  0b10001000,       // |*   *   |
  0b10001000,       // |*   *   |
  0b01010000,       // | * *    |
  0b11011000,       // |** **   |

// Char "\037" width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char ' ' width = 4
  0b00000000|CW_04, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char '!' width = 3
  0b01000000|CW_03, // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b00000000,       // |        |
  0b01000000,       // | *      |

// Char '"' width = 8
  0b01010000|CW_08, // | * *    |
  0b01010000,       // | * *    |
  0b01010000,       // | * *    |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char '#' width = 6
  0b01010000|CW_06, // | * *    |
  0b01010000,       // | * *    |
  0b11111000,       // |*****   |
  0b01010000,       // | * *    |
  0b11111000,       // |*****   |
  0b01010000,       // | * *    |
  0b01010000,       // | * *    |

// Char '$' width = 6
  0b00100000|CW_06, // |  *     |
  0b01111000,       // | ****   |
  0b10100000,       // |* *     |
  0b01110000,       // | ***    |
  0b00101000,       // |  * *   |
  0b11110000,       // |****    |
  0b00100000,       // |  *     |

// Char '%' width = 6
  0b11000000|CW_06, // |**      |
  0b11001000,       // |**  *   |
  0b00010000,       // |   *    |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b10011000,       // |*  **   |
  0b00011000,       // |   **   |

// Char '&' width = 6
  0b00000000|CW_06, // |        |
  0b00100000,       // |  *     |
  0b01010000,       // | * *    |
  0b01100000,       // | **     |
  0b10101000,       // |* * *   |
  0b10010000,       // |*  *    |
  0b01101000,       // | ** *   |

// Char ''' width = 4
  0b01100000|CW_04, // | **     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char '(' width = 4
  0b00100000|CW_04, // |  *     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |

// Char ')' width = 4
  0b10000000|CW_04, // |*       |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |

// Char '*' width = 6
  0b00000000|CW_06, // |        |
  0b00100000,       // |  *     |
  0b10101000,       // |* * *   |
  0b01110000,       // | ***    |
  0b10101000,       // |* * *   |
  0b00100000,       // |  *     |
  0b00000000,       // |        |

// Char '+' width = 6
  0b00000000|CW_06, // |        |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b11111000,       // |*****   |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00000000,       // |        |

// Char ',' width = 3
  0b00000000|CW_03, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b11000000,       // |**      |
  0b01000000,       // | *      |
  0b10000000,       // |*       |

// Char '-' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b11110000,       // |****    |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char '.' width = 3
  0b00000000|CW_03, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b11000000,       // |**      |
  0b11000000,       // |**      |

// Char '/' width = 4
  0b00100000|CW_04, // |  *     |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b10000000,       // |*       |

// Char '0' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char '1' width = 5
  0b00100000|CW_05, // |  *     |
  0b01100000,       // | **     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b01110000,       // | ***    |

// Char '2' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b00010000,       // |   *    |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b11110000,       // |****    |

// Char '3' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b00010000,       // |   *    |
  0b01100000,       // | **     |
  0b00010000,       // |   *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char '4' width = 5
  0b10010000|CW_05, // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11110000,       // |****    |
  0b00010000,       // |   *    |
  0b00010000,       // |   *    |

// Char '5' width = 5
  0b11110000|CW_05, // |****    |
  0b10000000,       // |*       |
  0b11100000,       // |***     |
  0b00010000,       // |   *    |
  0b00010000,       // |   *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char '6' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10000000,       // |*       |
  0b11100000,       // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char '7' width = 5
  0b11110000|CW_05, // |****    |
  0b00010000,       // |   *    |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |

// Char '8' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char '9' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01110000,       // | ***    |
  0b00010000,       // |   *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char ':' width = 4
  0b00000000|CW_04, // |        |
  0b11000000,       // |**      |
  0b11000000,       // |**      |
  0b00000000,       // |        |
  0b11000000,       // |**      |
  0b11000000,       // |**      |
  0b00000000,       // |        |

// Char ';' width = 4
  0b00000000|CW_04, // |        |
  0b01100000,       // | **     |
  0b01100000,       // | **     |
  0b00000000,       // |        |
  0b01100000,       // | **     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |

// Char '<' width = 5
  0b00000000|CW_05, // |        |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |
  0b00000000,       // |        |

// Char '=' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b11110000,       // |****    |
  0b00000000,       // |        |
  0b11110000,       // |****    |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char '>' width = 5
  0b00000000|CW_05, // |        |
  0b10000000,       // |*       |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b00000000,       // |        |

// Char '?' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b00010000,       // |   *    |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b00000000,       // |        |
  0b01000000,       // | *      |

// Char '@' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10110000,       // |* **    |
  0b10110000,       // |* **    |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b01110000,       // | ***    |

// Char 'A' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11110000,       // |****    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |

// Char 'B' width = 5
  0b11100000|CW_05, // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11100000,       // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11100000,       // |***     |

// Char 'C' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char 'D' width = 5
  0b11100000|CW_05, // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11100000,       // |***     |

// Char 'E' width = 5
  0b11110000|CW_05, // |****    |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b11100000,       // |***     |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b11110000,       // |****    |

// Char 'F' width = 5
  0b11110000|CW_05, // |****    |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b11100000,       // |***     |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |

// Char 'G' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10000000,       // |*       |
  0b10110000,       // |* **    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01110000,       // | ***    |

// Char 'H' width = 5
  0b10010000|CW_05, // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11110000,       // |****    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |

// Char 'I' width = 4
  0b11100000|CW_04, // |***     |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b11100000,       // |***     |

// Char 'J' width = 5
  0b01110000|CW_05, // | ***    |
  0b00010000,       // |   *    |
  0b00010000,       // |   *    |
  0b00010000,       // |   *    |
  0b00010000,       // |   *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char 'K' width = 5
  0b10010000|CW_05, // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11100000,       // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |

// Char 'L' width = 5
  0b10000000|CW_05, // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b11110000,       // |****    |

// Char 'M' width = 6
  0b10001000|CW_06, // |*   *   |
  0b11011000,       // |** **   |
  0b10101000,       // |* * *   |
  0b10101000,       // |* * *   |
  0b10101000,       // |* * *   |
  0b10001000,       // |*   *   |
  0b10001000,       // |*   *   |

// Char 'N' width = 5
  0b10010000|CW_05, // |*  *    |
  0b10010000,       // |*  *    |
  0b11010000,       // |** *    |
  0b10110000,       // |* **    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |

// Char 'O' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char 'P' width = 5
  0b11100000|CW_05, // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11100000,       // |***     |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |

// Char 'Q' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10100000,       // |* *     |
  0b01010000,       // | * *    |

// Char 'R' width = 5
  0b11100000|CW_05, // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11100000,       // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |

// Char 'S' width = 5
  0b01100000|CW_05, // | **     |
  0b10010000,       // |*  *    |
  0b10000000,       // |*       |
  0b01100000,       // | **     |
  0b00010000,       // |   *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char 'T' width = 6
  0b11111000|CW_06, // |*****   |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 'U' width = 5
  0b10010000|CW_05, // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01110000,       // | ***    |

// Char 'V' width = 5
  0b10010000|CW_05, // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |
  0b01100000,       // | **     |

// Char 'W' width = 6
  0b10001000|CW_06, // |*   *   |
  0b10001000,       // |*   *   |
  0b10001000,       // |*   *   |
  0b10101000,       // |* * *   |
  0b10101000,       // |* * *   |
  0b10101000,       // |* * *   |
  0b01010000,       // | * *    |

// Char 'X' width = 6
  0b10001000|CW_06, // |*   *   |
  0b10001000,       // |*   *   |
  0b01010000,       // | * *    |
  0b00100000,       // |  *     |
  0b01010000,       // | * *    |
  0b10001000,       // |*   *   |
  0b10001000,       // |*   *   |

// Char 'Y' width = 6
  0b10001000|CW_06, // |*   *   |
  0b10001000,       // |*   *   |
  0b10001000,       // |*   *   |
  0b01010000,       // | * *    |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char 'Z' width = 5
  0b11110000|CW_05, // |****    |
  0b00010000,       // |   *    |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b11110000,       // |****    |

// Char '[' width = 4
  0b11100000|CW_04, // |***     |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b11100000,       // |***     |

// Char '\' width = 4
  0b10000000|CW_04, // |*       |
  0b10000000,       // |*       |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char ']' width = 4
  0b11100000|CW_04, // |***     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b11100000,       // |***     |

// Char '^' width = 4
  0b01000000|CW_04, // | *      |
  0b10100000,       // |* *     |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char '_' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b11111000,       // |*****   |

// Char '`' width = 4
  0b11000000|CW_04, // |**      |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |

// Char 'a' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b01110000,       // | ***    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10110000,       // |* **    |
  0b01010000,       // | * *    |

// Char 'b' width = 5
  0b10000000|CW_05, // |*       |
  0b10000000,       // |*       |
  0b10100000,       // |* *     |
  0b11010000,       // |** *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11100000,       // |***     |

// Char 'c' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b01110000,       // | ***    |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b01110000,       // | ***    |

// Char 'd' width = 5
  0b00010000|CW_05, // |   *    |
  0b00010000,       // |   *    |
  0b01010000,       // | * *    |
  0b10110000,       // |* **    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01110000,       // | ***    |

// Char 'e' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b01100000,       // | **     |
  0b10010000,       // |*  *    |
  0b11110000,       // |****    |
  0b10000000,       // |*       |
  0b01110000,       // | ***    |

// Char 'f' width = 5
  0b00100000|CW_05, // |  *     |
  0b01010000,       // | * *    |
  0b01000000,       // | *      |
  0b11100000,       // |***     |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |

// Char 'g' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b01110000,       // | ***    |
  0b10010000,       // |*  *    |
  0b01110000,       // | ***    |
  0b00010000,       // |   *    |
  0b01100000,       // | **     |

// Char 'h' width = 5
  0b10000000|CW_05, // |*       |
  0b10000000,       // |*       |
  0b10100000,       // |* *     |
  0b11010000,       // |** *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |

// Char 'i' width = 4
  0b01000000|CW_04, // | *      |
  0b00000000,       // |        |
  0b11000000,       // |**      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b11100000,       // |***     |

// Char 'j' width = 4
  0b00100000|CW_04, // |  *     |
  0b00000000,       // |        |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b10100000,       // |* *     |
  0b01000000,       // | *      |

// Char 'k' width = 5
  0b10000000|CW_05, // |*       |
  0b10000000,       // |*       |
  0b10010000,       // |*  *    |
  0b10100000,       // |* *     |
  0b11000000,       // |**      |
  0b10100000,       // |* *     |
  0b10010000,       // |*  *    |

// Char 'l' width = 4
  0b11000000|CW_04, // |**      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b11100000,       // |***     |

// Char 'm' width = 6
  0b00000000|CW_06, // |        |
  0b00000000,       // |        |
  0b11110000,       // |****    |
  0b10101000,       // |* * *   |
  0b10101000,       // |* * *   |
  0b10101000,       // |* * *   |
  0b10101000,       // |* * *   |

// Char 'n' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b10100000,       // |* *     |
  0b11010000,       // |** *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |

// Char 'o' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b01100000,       // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |

// Char 'p' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b11100000,       // |***     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b11100000,       // |***     |
  0b10000000,       // |*       |

// Char 'q' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b01110000,       // | ***    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01110000,       // | ***    |
  0b00010000,       // |   *    |

// Char 'r' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b10100000,       // |* *     |
  0b11010000,       // |** *    |
  0b10000000,       // |*       |
  0b10000000,       // |*       |
  0b10000000,       // |*       |

// Char 's' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b01110000,       // | ***    |
  0b10000000,       // |*       |
  0b01100000,       // | **     |
  0b00010000,       // |   *    |
  0b11100000,       // |***     |

// Char 't' width = 5
  0b01000000|CW_05, // | *      |
  0b01000000,       // | *      |
  0b11100000,       // |***     |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b00110000,       // |  **    |

// Char 'u' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10110000,       // |* **    |
  0b01010000,       // | * *    |

// Char 'v' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |
  0b01100000,       // | **     |

// Char 'w' width = 6
  0b00000000|CW_06, // |        |
  0b00000000,       // |        |
  0b10001000,       // |*   *   |
  0b10001000,       // |*   *   |
  0b10101000,       // |* * *   |
  0b10101000,       // |* * *   |
  0b01010000,       // | * *    |

// Char 'x' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01100000,       // | **     |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |

// Char 'y' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b10010000,       // |*  *    |
  0b10010000,       // |*  *    |
  0b01110000,       // | ***    |
  0b00010000,       // |   *    |
  0b11100000,       // |***     |

// Char 'z' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b11110000,       // |****    |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b11110000,       // |****    |

// Char '{' width = 4
  0b00100000|CW_04, // |  *     |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b10000000,       // |*       |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |

// Char '|' width = 4
  0b00100000|CW_04, // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |
  0b00100000,       // |  *     |

// Char '}' width = 4
  0b10000000|CW_04, // |*       |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b00100000,       // |  *     |
  0b01000000,       // | *      |
  0b01000000,       // | *      |
  0b10000000,       // |*       |

// Char '~' width = 5
  0b00000000|CW_05, // |        |
  0b00000000,       // |        |
  0b01010000,       // | * *    |
  0b10100000,       // |* *     |
  0b00000000,       // |        |
  0b00000000,       // |        |
  0b00000000,       // |        |
};
