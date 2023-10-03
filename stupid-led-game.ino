int NUMBER_OF_LEDS = 9;
int DELAY = 75;

int btnPin = 3;
int winPin = 9;
int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};

int index = 0;
int step = 1;

int btnState = 0;

bool playing = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(btnPin, INPUT);
  
  for(int i = 0; i < NUMBER_OF_LEDS; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  btnState = digitalRead(btnPin);

  
  if(index == NUMBER_OF_LEDS - 1){
    step = -1;  
  }
  if(index == 0){
    step = 1;  
  }
  
  digitalWrite(ledPins[index], HIGH);
  delay(DELAY);
  digitalWrite(ledPins[index], LOW);

  if(btnState == HIGH){

    if(ledPins[index] == winPin){
      winAnimation();
    }
    else{
      loseAnimation();  
    }
    clear();
    playing = true;
   
  }

  index = index + step;
}

void winAnimation(){
  int frames = 2;
  for(int i = 0; i < frames; i++){
    digitalWrite(9, HIGH);
    delay(200);
    digitalWrite(9, LOW);
    delay(100);
  }
}
void loseAnimation(){
  int frames = 2;
  for(int i = 0; i < frames; i++){
    digitalWrite(11, HIGH);
    digitalWrite(7, HIGH);
    delay(200);
    digitalWrite(11, LOW);
    digitalWrite(7, LOW);
    delay(100);
  }
  
}

void clear(){
  for(int i = 0; i < NUMBER_OF_LEDS; i++){
    digitalWrite(ledPins[i], LOW);
  }
}
