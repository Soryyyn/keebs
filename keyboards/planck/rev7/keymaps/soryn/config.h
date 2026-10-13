/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

//
// Change the mousekey settings.
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MAX_SPEED 4

//
// Turn off the backlight once the PC goes into sleep.
#define RGB_MATRIX_SLEEP

//
// Enable typing heatmap effect.
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#define FORCE_NKRO
