/* 
Copyright (C) 2018 Microsoft Corporation

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <string.h>
#include "frotz.h"
#include "games.h"
#include "frotz_interface.h"

// Zork I: http://ifdb.tads.org/viewgame?id=0dbnusxunq7fw5ro

char** zork1_intro_actions(int *n) {
  *n = 0;
  return NULL;
}

char* zork1_clean_observation(char* obs) {
  char* pch;
  pch = strchr(obs, '\n');
  if (pch != NULL) {
    return pch+1;
  }
  return obs;
}

// Zork1 specific indicator if the player has won
int zork1_victory() {
  char *victory_text = "Inside the Barrow";
  if (strstr(world, victory_text)) {
    return 1;
  }
  return 0;
}

// Zork1 specific indicator if the player has died
int zork1_game_over() {
  char *death_text = "****  You have died  ****";
  if (strstr(world, death_text)) {
    return 1;
  }
  return 0;
}

int zork1_max_score() {
  return 350;
}

// Get the self object number in Zork-1
int zork1_get_self_object_num() {
  return 4;
}

int zork1_get_num_world_objs() {
  return 250;
}

// Ignores the theif (object 114)
int zork1_ignore_moved_obj(zword obj_num, zword dest_num) {
  if (obj_num == 114)
    return 1;
  return 0;
}

// Ignores theif and self (obj 4 attr 12)
int zork1_ignore_attr_diff(zword obj_num, zword attr_idx) {
  if (obj_num == 114)
    return 1;
  if (obj_num == 4 && attr_idx == 12)
    return 1;
  return 0;
}

int zork1_ignore_attr_clr(zword obj_num, zword attr_idx) {
  if (obj_num == 4 || obj_num == 114 || obj_num == 217)
    if (attr_idx == 1 || attr_idx == 2)
      return 1;
  if (obj_num == 4 && attr_idx == 12)
    return 1;
  return 0;
}

// Zork1-specific move count
int zork1_get_moves() {
  return (((short) zmp[8821]) << 8) | zmp[8822];
}

// Zork1-specific score
int zork1_get_score() {
  return (((short) zmp[8819]) << 8) | zmp[8820];
}
