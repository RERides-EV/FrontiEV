/*  FrontiEV auxillary controls
    Copyright (C) 2025 David Durazzo
    for RERides EV

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "arduino_leaf_ac.h"

// Global variables
bool acEnabled = false;

// Global PIN definitions
int AC_OUTPUT_PIN = 1;       // Must be Serial1 TX pin for proper LIN communication
int AC_INPUT_PIN = 2;        // Input pin to detect when AC should be ON/OFF
int DUMMY_PIN = 3;           // Used for debugging/triggering

void setup() {
  // Initialize the AC module
  setupAC();
}

void loop() {
  // Read the toggle switch and update AC state
  acEnabled = digitalRead(AC_INPUT_PIN);
  updateAC(acEnabled);
  
  // Small delay to prevent too frequent updates
  delay(100);
}
