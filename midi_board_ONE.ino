/**
 *  @file		midi_board_ONE.ino
 *  Project		axefx.de MIDI Borad
 *	@brief		MIDI-Board Main Program
 *	@version	1.0.0
 *  @author		Bastian Buehrig
 *	@date		05/11/13
 *  license		GPL axefx.de - 2013
 */


/****************************************************
 **
 **  Uses Arduino-MIDI-Library (v3.2)
 **  http://playground.arduino.cc/Main/MIDILibrary
 **  http://sourceforge.net/projects/arduinomidilib/
 **
 *****************************************************/


// ==== 3rd Party Libraries
#include <MIDI.h>              // Arduino-MIDI-Library


// ==== Button-Class
#include "Button.h"

// ==== Setup-File: Edit for you own MIDI-Board
#include "setup.h"



// ==== Button-Array for iteration
Button *buttons[MAX_BUTTONS];




// ====
void setup() {
  // MIDI-Initialising
  MIDI.begin(MIDI_CHANNEL);
  
  // Button-Definitions:
  //                      Button-Pin   LED-Pin  Funkt.  CC/PC   High  Low,  init. Ctrl. State
  buttons[0] = new Button(    8,       28,      "PC",    0,      0,     0,        LOW );
  buttons[1] = new Button(    9,       29,      "PC",    1,      0,     0,        LOW );
  buttons[2] = new Button(   10,       30,      "PC",    2,      0,     0,        LOW );
  buttons[3] = new Button(   11,       31,      "PC",    3,      0,     0,        LOW );
  buttons[4] = new Button(   12,       32,      "CC",   20,    127,     0,        LOW );
  buttons[5] = new Button(   13,       33,      "CC",   21,    127,     0,        LOW );
  buttons[6] = new Button(   14,       34,      "CC",   22,    127,     0,       HIGH );
  buttons[7] = new Button(   15,       35,      "CC",   23,    127,     0,       HIGH );

  

}



void loop() {
  
  // Read Button-State und check for activation!
  for (byte btnNo=0; btnNo < MAX_BUTTONS; btnNo++) {
    buttons[btnNo]->checkState();
  }
  
  // Read all Expression-Pedals
  // TODO
}



