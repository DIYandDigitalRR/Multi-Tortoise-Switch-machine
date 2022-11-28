const int switchpin1=2;//set up digital pin 2 for controlling switch 1
const int switchpin2=3;//set up digital pin 3 for controlling switch 1
const int switchpin3=4;//set up digital pin 4 for controlling switch 2
const int switchpin4=5;//set up digital pin 5 for controlling switch 2
const int switchpin5=6;//set up digital pin 6 for controlling switch 3
const int switchpin6=7;//set up digital pin 7 for controlling switch 3
const int switchpin7=8;//set up digital pin 8 for controlling switch 4
const int switchpin8=9;//set up digital pin 9 for controlling switch 4
const int switchpin9=10;//set up digital pin 10 for controlling switch 5
const int switchpin10=11;//set up digital pin 11 for controlling switch 5
const int button1=A0;//set up analog pin A0 for reading button 1
const int button2=A1;//set up analog pin A0 for reading button 2
const int button3=A2;//set up analog pin A0 for reading button 3
const int button4=A3;//set up analog pin A0 for reading button 4
const int button5=A4;//set up analog pin A0 for reading button 5

int State1=0;//Sets our value for the state of switch 1
int State2=0;//Sets our value for the state of switch 2
int State3=0;//Sets our value for the state of switch 3
int State4=0;//Sets our value for the state of switch 4
int State5=0;//Sets our value for the state of switch 5

void setup() {
  Serial.begin(9600);//sets up our readings in the serial monitor and the baud rate of 9600
  pinMode(switchpin1,OUTPUT);
  pinMode(switchpin2,OUTPUT);
  pinMode(switchpin3,OUTPUT);
  pinMode(switchpin4,OUTPUT);
  pinMode(switchpin5,OUTPUT);
  pinMode(switchpin6,OUTPUT);
  pinMode(switchpin7,OUTPUT);
  pinMode(switchpin8,OUTPUT);
  pinMode(switchpin9,OUTPUT);
  pinMode(switchpin10,OUTPUT);
}
enum SWITCHSTATES
{
  ST_OFF,
  ST_STRAIGHT1,
  ST_TURN1,
  ST_STRAIGHT2,
  ST_TURN2,
  ST_STRAIGHT3,
  ST_TURN3,
  ST_STRAIGHT4,
  ST_TURN4,
  ST_STRAIGHT5,
  ST_TURN5,
};//Sets up states that arduino can hop between

SWITCHSTATES switchState=ST_OFF;

void loop(){
  Serial.println("State 1");
  Serial.println(State1);//display in serial monitor what the State of State 1 is with the text "State 1" in front.
  Serial.println("State 2");
  Serial.println(State2);//display in serial monitor what the State of State 2 is with the text "State 2" in front.
  Serial.println("State 3");
  Serial.println(State3);//display in serial monitor what the State of State 3 is with the text "State 3" in front.
  Serial.println("State 4");
  Serial.println(State4);//display in serial monitor what the State of State 4 is with the text "State 4" in front.
  Serial.println("State 5");
  Serial.println(State5);//display in serial monitor what the State of State 5 is with the text "State 5" in front.
  
int ButtonRead1=analogRead(button1);//Stores value for button1
int ButtonRead2=analogRead(button2);//Stores value for button2
int ButtonRead3=analogRead(button3);//Stores value for button3
int ButtonRead4=analogRead(button4);//Stores value for button4
int ButtonRead5=analogRead(button5);//Stores value for button1

  Serial.println("Button 1");
  Serial.println(ButtonRead1);//display in serial monitor what the State of Button 1 is with the text "Button 1" in front.
  Serial.println("Button 2");
  Serial.println(ButtonRead2);//display in serial monitor what the State of Button 2 is with the text "Button 2" in front.
  Serial.println("Button 3");
  Serial.println(ButtonRead3);//display in serial monitor what the State of Button 3 is with the text "Button 3" in front.
  Serial.println("Button 4");
  Serial.println(ButtonRead4);//display in serial monitor what the State of Button 4 is with the text "Button 4" in front.
  Serial.println("Button5");
  Serial.println(ButtonRead5);//display in serial monitor what the State of Button 5 is with the text "Button 5" in front.
  delay(200);// 0.2 second pause between readings
  switch(switchState)
  {
    case ST_OFF:
    switchoff(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5,State1,State2,State3,State4,State5);
    break;
    case ST_STRAIGHT1:
    switchstraight1(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_TURN1:
    switchturn1(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_STRAIGHT2:
    switchstraight2(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_TURN2:
    switchturn2(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_STRAIGHT3:
    switchstraight3(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_TURN3:
    switchturn3(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_STRAIGHT4:
    switchstraight4(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_TURN4:
    switchturn4(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_STRAIGHT5:
    switchstraight5(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    case ST_TURN5:
    switchturn5(ButtonRead1,ButtonRead2,ButtonRead3,ButtonRead4,ButtonRead5);
    break;
    
  }
}

void switchoff(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5, int State1, int State2, int State3, int State4, int State5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW);  

  if ((ButtonRead1>500) && (State1==1)){
    switchState=ST_STRAIGHT1;//sends to straight 1 with button press
  }
  if ((ButtonRead1>500) && (State1==0)){
    switchState=ST_TURN1;//sends to turn 1 with button press
  }
  if ((ButtonRead2>500) && (State2==1)){
    switchState=ST_STRAIGHT2;//sends to straight 1 with button press
  }
  if ((ButtonRead2>500) && (State2==0)){
    switchState=ST_TURN2;//sends to turn 1 with button press
  }
  if ((ButtonRead3>500) && (State3==1)){
    switchState=ST_STRAIGHT3;//sends to straight 1 with button press
  }
  if ((ButtonRead3>500) && (State3==0)){
    switchState=ST_TURN3;//sends to turn 1 with button press
  }
    if ((ButtonRead4>500) && (State4==1)){
    switchState=ST_STRAIGHT4;//sends to straight 1 with button press
  }
  if ((ButtonRead4>500) && (State4==0)){
    switchState=ST_TURN4;//sends to turn 1 with button press
  }
  if ((ButtonRead5>500) && (State5==1)){
    switchState=ST_STRAIGHT5;//sends to straight 1 with button press
  }
  if ((ButtonRead5>500) && (State5==0)){
    switchState=ST_TURN5;//sends to turn 1 with button press
  }  
}

void switchstraight1(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,HIGH);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW);  
  delay(2000);//keep power to the turnout for 2 seconds
  State1=0;//sets value to 0
  switchState=ST_OFF;
}

void switchturn1(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,HIGH);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW);  
  delay(2000);//keep power to the turnout for 2 seconds
State1=1;//sets value to 1
  switchState=ST_OFF;
}  

void switchstraight2(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,HIGH);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW);  
  delay(2000);//keep power to the turnout for 2 seconds
  State2=0;//sets value to 0
  switchState=ST_OFF;
}

void switchturn2(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,HIGH);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW);  
  delay(2000);//keep power to the turnout for 2 seconds
State2=1;//sets value to 1
  switchState=ST_OFF;
} 
void switchstraight3(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,HIGH);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW); 
  delay(2000);//keep power to the turnout for 2 seconds
  State3=0;//sets value to 0
  switchState=ST_OFF;
}

void switchturn3(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,HIGH);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW); 
  delay(2000);//keep power to the turnout for 2 seconds
State3=1;//sets value to 1
  switchState=ST_OFF;
}

void switchstraight4(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,HIGH);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW);   
  delay(2000);//keep power to the turnout for 2 seconds
  State4=0;//sets value to 0
  switchState=ST_OFF;
}

void switchturn4(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,HIGH);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,LOW); 
  delay(2000);//keep power to the turnout for 2 seconds
State4=1;//sets value to 1
  switchState=ST_OFF;
} 
void switchstraight5(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,HIGH);
  digitalWrite(switchpin10,LOW); 
  delay(2000);//keep power to the turnout for 2 seconds
  State5=0;//sets value to 0
  switchState=ST_OFF;
}

void switchturn5(int ButtonRead1, int ButtonRead2, int ButtonRead3, int ButtonRead4, int ButtonRead5){
  digitalWrite(switchpin1,LOW);
  digitalWrite(switchpin2,LOW);
  digitalWrite(switchpin3,LOW);
  digitalWrite(switchpin4,LOW);
  digitalWrite(switchpin5,LOW);
  digitalWrite(switchpin6,LOW);
  digitalWrite(switchpin7,LOW);
  digitalWrite(switchpin8,LOW);
  digitalWrite(switchpin9,LOW);
  digitalWrite(switchpin10,HIGH); 
  delay(2000);//keep power to the turnout for 2 seconds
State5=1;//sets value to 1
  switchState=ST_OFF;
} 
