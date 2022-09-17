//shai ely & uri koren//
const int trigPin1 = 2; // left sensor trigger
const int echoPin1 = 3; // left sensor echo
const int trigPin2 = 4;  // right sensor trigger
const int echoPin2 = 5;  // right sensor echo

// vars
long duration;                               
int distance1, distance2; 
float r;
unsigned long temp=0;  
int sensorPin = A1;
int sensorValue = 0;
boolean isLow=true;

void find_distance (void);

void find_distance (void) // function that return distance in CM from both sensors
{ 
  ///////////////////////////////////////// left sensor
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration = pulseIn(echoPin1, HIGH, 5000);// wait 5000us, max can be 60cm
 
  r = 3.4 * duration / 2;                       
  distance1 = r / 100.00;
  ///////////////////////////////////////// right sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH, 5000);
  r = 3.4 * duration / 2;     
  distance2 = r / 100.00;
  delay(100);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  delay (1000);  
}

void loop()
{

  
  sensorValue = analogRead(sensorPin); //check the current light
  if (sensorValue > 400 && !isLow) {
      Serial.println("highLight");
        //delay(50);
        isLow=true;

  }

   if (sensorValue < 400 && isLow) {
      Serial.println("lowLight");
        //delay(50);
        isLow=false;

  }
  
    find_distance(); 

      if( (distance2>5 && distance2 < 20) && (distance1>5 && distance1 < 20) ){
      temp=millis();
      while(millis()<temp+2000){ //if more than 3 second - print exit
        if( !(distance2>5 && distance2 < 20) || !(distance1>5 && distance1 < 20) ){
          break;
          }
        }
        if(millis()>=temp+2000){
          Serial.println("exit");
          }    
    }
    
    if( (distance2>30 && distance2 < 50) && (distance1>30 && distance1 < 50) ){
      Serial.println("space");
            delay (2000);   
    }
  
     if(distance2<10 && distance2 > 1 && distance1>55) {
     Serial.println("left");    
     delay (10);             
  }

   if(distance2>10 && distance2 < 25 && distance1>55) {
     Serial.println("down"); 
     delay (10);                 
  }

      if(distance1<10 && distance1 > 1 && distance2>55) {
     Serial.println("right");  
     delay (10);                
  }

   if(distance1>10 && distance1 < 25 && distance2>55) {
     Serial.println("up");    
     delay (10);              
  }

}
