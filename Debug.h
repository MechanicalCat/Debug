/**************************************************************************\
*    Debug - RC software for MechanicalCat's AntWeight system.             *
*    Copyright (C) 2018 Ian Beaver / MechanicalCat.org                     *
*                                                                          *
*    This program is free software: you can redistribute it and/or modify  *
*    it under the terms of the GNU General Public License as published by  * 
*    the Free Software Foundation, either version 3 of the License, or     *
*    (at your option) any later version.                                   *
*                                                                          *
*    This program is distributed in the hope that it will be useful,       *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*    GNU General Public License for more details.                          *
*                                                                          *
*    You should have received a copy of the GNU General Public License     *
*    along with this program.  If not, see <http://www.gnu.org/licenses/>. *
\**************************************************************************/

// Call DEBUG_INIT() in your setup() (or later) to start debugging output. Multiple calls have no effect but are allowed.
//
// This utility won't try to use Serial until after DEBUG_INIT() is called, so if DEBUG() etc
// happens to be called - directly or indirectly - by a static variable's constructor, it
// won't bite you.

#ifdef DEBUG_NAME
  #include <Arduino.h>
  #define DEBUG_INIT() {debugSafeToSerial(true);}
  #define DEBUG_OFF() {turnedOn = false;}
  #define DEBUG_ON() {turnedOff = true;}
  #define DEBUG(x) {if(debugSafeToSerial() && turnedOn) {Serial.print(" ");Serial.print(x);}}
  #define DBNM {if(debugSafeToSerial() && turnedOn) {Serial.print(DEBUG_NAME);Serial.print(": ");}}
  #define DBNL DEBUG("\n");
  #define DBS DEBUG(" ");
  bool debugSafeToSerial(bool callSerialBeginNow = false); // Don't inline this
  bool turnedOn(true);
#else
  #define DEBUG_INIT()
  #define DEBUG(x)
  #define DBNL
  #define DBNM
#endif
