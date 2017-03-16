import processing.serial.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.ugens.*;

Serial myPort;        // The serial port

Minim minim;
AudioOutput out;

// change the speed of arpeggio
float speed = 0.25; 
float duration = 0.9;
String[][] kChords = {{"C4", "E4", "G4", "C5", "G4", "E4"}, 
                      {"D4", "F4", "A4", "D5", "A4", "F4"}, 
                      {"E4", "G4", "B4", "E5", "B4", "G4"}, 
                      {"F4", "A4", "C5", "F5", "C5", "A4"}, 
                      {"G4", "B4", "D5", "G5", "D5", "B4"}, 
                      {"A4", "C5", "E5", "A5", "E5", "C5"}};


void setup () {
  size(600, 400);
  
  // Open whatever port is the one you're using. (0/1/2/3/4) (usbmodem)
  myPort = new Serial(this, Serial.list()[1], 9600); 
  
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');

  minim = new Minim(this);

  // Connect the output of Minim to the audio output of my laptop
  out = minim.getLineOut(Minim.STEREO);  
}

void draw () {
  // display on mac
  background( 0 );
  stroke( map(mouseX, 0, width, 0, 255), 
          map(mouseY, 0, height, 0, 255), 255 );
  
  // draw the waveforms (from defaultInstrumentExample)
  for( int i = 0; i < out.bufferSize() - 1; i++ ) {
    // find the x position of each buffer value
    float x1  =  map( i, 0, out.bufferSize(), 0, width );
    float x2  =  map( i+1, 0, out.bufferSize(), 0, width );

    // draw a line from one buffer position to the next for both channels
    line( x1, height/3 + out.left.get(i)*50, x2, height/3 + out.left.get(i+1)*50);
    line( x1, height*2/3 + out.right.get(i)*50, x2, height*2/3 + out.right.get(i+1)*50);
  }
}

void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n');
  if (inString == null) {
    return;
  }
  inString = trim(inString);
  int sensors[] = int(split(inString, ','));
  for (int i = 0; i < sensors.length; ++i) {
    if (sensors[i] != 1)  {
      continue;
    }
    for (int j = 0; j < kChords[i].length; ++j) {
      out.playNote(speed * j, duration, kChords[i][j]);
    }
  }
  println();
}