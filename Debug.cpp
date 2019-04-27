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

#include <Debug.h>
#include <Arduino.h>
// This function has a dual purpose:
// - It prevents Serial.print() being called prior to the main sketch's setup().
// - It calls Serial.begin() if asked to do so.
bool debugSafeToSerial(bool callSerialBeginNow) {
  static bool initialised(false);
  if(initialised) return (true);

  if(!callSerialBeginNow) return false;

  Serial.begin(115200);
  int now(millis());
  while(!Serial && (millis() - now < 2000));

  initialised = true;
  Serial.print("DEBUGGING IS ON\n");
}
