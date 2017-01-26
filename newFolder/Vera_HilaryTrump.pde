// This program is rewritten by Vera on Oct 3, 2016
// Press 'h' if you want Hilary to laugh. Press 't' if you want Trump to laugh.

Head hilary[] = new Head[25];
Head trump[] = new Head[25];
boolean aboutScreen = true;
PImage imgh1, imgh2, imgt1, imgt2;

float angle = 0.0;

void setup(){
  size(600, 600);
  imgh1 = loadImage("hilary1.png");
  imgh2 = loadImage("hilary2.png");
  imgt1 = loadImage("trump1.png");
  imgt2 = loadImage("trump2.png");
  for (int i = 0; i < hilary.length; i++) hilary[i] = new Head();
  for (int j = 0; j < hilary.length; j++) trump[j] = new Head();
}

void draw(){  
  if (aboutScreen) titleCard();
  else myArt();
}

void mousePressed() {
  aboutScreen = !aboutScreen;
}

void titleCard() {
  background(100);
  
  textSize(50);
  fill(255);
  textAlign(CENTER);
  text("Welcome to myArt.", width/2, height/2);
  
  textSize(50);
  fill(255);
  textAlign(CENTER);
  text("Hilary or Trump?", width/2, height*5/6);
    
  textSize(15);
  fill(255);
  textAlign(CENTER);
  text("Press 'h' for Hilary and 't' for Trump", width/2, height*5/6 + 40);
  text("Try pressing UP, DOWN, LEFT, RIGHT, 'r', 'g', 'b', 'y'", width/2, height*5/6 + 70);
}


  
  
void myArt() {  
  background(0);
  
  for (int i = 0, j = 0; i < hilary.length && j < trump.length; i++, j++) {
    trump[j].display('t'); 
    trump[j].Tint();        // press 'r', 'g', 'b', or 'y'
    trump[j].jiggle(10.0); 
    trump[j].drift(10.0);    // press LEFT, RIGHT, UP or DOWN
    
    hilary[i].display('h'); 
    hilary[i].Tint();       // press 'r', 'g', 'b', or 'y'
    hilary[i].jiggle(1.0); 
    hilary[i].drift(2.0);   // press LEFT, RIGHT, UP or DOWN    
  }
}