/*
 * Created by Matheus Teles.
 */

const byte numRows = 4;
const byte numCols = 4;

byte rowPins[numRows] = {2, 3, 4, 5};
byte colPins[numCols] = {6, 7, 8, 9};

char keys[numRows][numCols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

void setup() {
  Serial.begin(9600);
  
  // Set up keypad row pins
  for(int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
  }
  
  // Set up keypad column pins
  for(int i = 0; i < numCols; i++) {
    pinMode(colPins[i], INPUT);
  }
}

void loop() {
  char key = getKey();
  
  if(key != -1) {
    // DO
  }
}

char getKey() {
  for(int i = 0; i < numRows; i++) {
    for(int j = 0; j < numRows; j++) {
      digitalWrite(rowPins[j], LOW);
    }
		
    digitalWrite(rowPins[i], HIGH);
	
    for(int j = 0; j < numCols; j++) {
      if(digitalRead(colPins[j]) == HIGH) {
        Serial.println(keys[i][j]);
        while(digitalRead(colPins[j]) == HIGH);
        return keys[i][j];
      }
    }
  }
  
  return -1;
}
