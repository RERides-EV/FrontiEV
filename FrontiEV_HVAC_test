/*  Leaf AC Compressor Controls from Arduino - Header File
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

This code is in the Public Domain
*/

#include "arduino_leaf_ac.h"
#include "arduino_vw_heat.h"

// Pin Assignments
// AC Control Pins
static const int AC_OUTPUT_PIN = 1;    // MUST BE SAME PIN AS SERIAL ONE
static const int AC_INPUT_PIN = 2;     // AC control input
static const int AC_DEBUG_PIN = 3;     // Debug signal pin

// Heater Control Pins
static const int POTENTIOMETER_PIN = A0;  // Analog pin for heater control
static const int RELAY_CHANNEL1_PIN = 5;  // Heater relay 1
static const int RELAY_CHANNEL2_PIN = 6;  // Heater relay 2
static const int RELAY_CHANNEL3_PIN = 7;  // Heater relay 3

// Global state variables
static bool acEnabled = false;  // Removed 'const' to allow state changes

void setup() {
  // Initialize the AC system
  initializeAC(AC_OUTPUT_PIN, AC_INPUT_PIN, AC_DEBUG_PIN);
  
  // Initialize the heater system
  initializeVWHeater(RELAY_CHANNEL1_PIN, RELAY_CHANNEL2_PIN, RELAY_CHANNEL3_PIN);
}

void loop() {
  // Read AC control input
  acEnabled = digitalRead(AC_INPUT_PIN);

  // Update AC system
  updateAC(acEnabled, AC_OUTPUT_PIN, AC_DEBUG_PIN);
  
  // Update heater system
  updateVWHeater(POTENTIOMETER_PIN, 
                 RELAY_CHANNEL1_PIN, 
                 RELAY_CHANNEL2_PIN, 
                 RELAY_CHANNEL3_PIN);
}
