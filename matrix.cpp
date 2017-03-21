int motorPin1 = 2; // pin 2 on L293D IC
int motorPin2 = 3; // pin 7 on L293D IC

int motorPin3 = 6; // pin 2 on L293D IC
int motorPin4 = 7; // pin 7 on L293D IC


const int buttonPin[] = {A0, A1, A2, A3 };     // the number of the pushbutton pins
 // variables will change:
int buttonState = 0;   

#include <SD.h>
const int chipSelect = 10;

int analogPin = A5;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // resistance of R1 (100K) -see text!
float R2 = 10000.0; // resistance of R2 (10K) - see text!
int value = 0;  

void setup() {
  // initialize serial communication at 9600 bits per second:
  
 Serial.begin(9600);
 Serial.print("Initializing SD card...");
 // make sure that the default chip select pin is set to
 // output, even if you don't use it:
 pinMode(10, OUTPUT);
 // see if the card is present and can be initialized:
 if (!SD.begin(chipSelect)) {
 Serial.println("Card failed, or not present");
 // don't do anything more:
 return;
 }
 Serial.println("card initialized.");


    
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
   
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  
  

   for(int x=0; x<4; x++)
   {
    pinMode(buttonPin[x], INPUT_PULLUP); 
  }  

}

void loop() 
    {
      {
         // read the value at analog input
   value = analogRead(analogPin);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;//statement to quash undesired reading !
}
String dataString = "";
 // read three sensors and append to the string:

 dataString += String(vin);
 if (analogPin < 2) {
 dataString += ",";

 }
   
  
 File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
 dataFile.print("Grid voltage =");
 
 dataFile.println(dataString);
 delay(1000);
 dataFile.close();
 delay(100);
 }
 else {
 Serial.println("error opening datalog.txt");
 }
      
  // read the state of the keypad value:
  for(int x=0; x<4; x++)
  {
    //signifying the state of which the button is in by reading the appropriate pin #
    buttonState = digitalRead(buttonPin[x]);

    // check if the pushbutton on the keypad is pressed.
    // if it is, the buttonState is LOW:
    if (buttonState == LOW && buttonPin[x] == A0) {  
      
                                 //1 grd

     Serial.print("grid voltge=");
     Serial.println(dataString);                             
    Serial.println("MATRIX 2X2");
    digitalWrite(2, HIGH); //1 block
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
 
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
                                //turn 1
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);

     Serial.print("grid voltge=");
     Serial.println(dataString);
    digitalWrite(2, HIGH); //2 block
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
   
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
                             
                              //turn 2
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);

     Serial.print("grid voltge=");
     Serial.println(dataString);
    digitalWrite(2, HIGH); //3 block
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
                                 //turn 3
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
     Serial.print("grid voltge=");
     Serial.println(dataString);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
    
    }
                                                      //code for 3x3 matrix
     if (buttonState == LOW && buttonPin[x] == A1) {  
                            
       
     Serial.print("grid voltge=");
     Serial.println(dataString);                   //1 block
    Serial.println("MATRIX 3X3"); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     
                              //2 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

    
    digitalWrite(2, HIGH);// turn/3
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(1050);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
     Serial.print("grid voltge=");
     Serial.println(dataString);
     
                            //4 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
    
                              //5 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
  
    
    digitalWrite(2, HIGH);// turn
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(1050);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
     Serial.print("grid voltge=");
     Serial.println(dataString);
                     
                           //6 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
        
                           //7 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(1050);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    

                                 //8 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
     Serial.print("grid voltge=");
     Serial.println(dataString);
     
    digitalWrite(2, HIGH);// turn
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(1050);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
     Serial.print("grid voltge=");
     Serial.println(dataString);
    
                           //9 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    }
    
                                                     //code for 4x4 matrix
   if (buttonState == LOW && buttonPin[x] == A2) {  


     Serial.print("grid voltge=");
     Serial.println(dataString); 
    Serial.println("a2");  //1 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);                             //2 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                  //3 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/3
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);       // 4 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);               //5 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                //6 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/6
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);           // 7 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);        //8 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);         //9 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/9
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);               // 10 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);              //11 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/11
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                 //12 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/13
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
      
     Serial.print("grid voltge=");
     Serial.println(dataString);         //14 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
    digitalWrite(2, HIGH);// turn/14
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);

    
     Serial.print("grid voltge=");
     Serial.println(dataString);             //14 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
   }
                                                   //code for 5x5 matrix
   if (buttonState == LOW && buttonPin[x] == A3) {  


     Serial.print("grid voltge=");
     Serial.println(dataString);                 //1 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);         //2 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

       Serial.print("grid voltge=");
     Serial.println(dataString);               //3 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                 //4 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/4
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);           //5 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);                  //6 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);             //7 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);         //8 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/8
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 


     Serial.print("grid voltge=");
     Serial.println(dataString);                //9 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);                 //10 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                //11 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                 //12 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/12
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                //13 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);                //14 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                //15 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/15
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);           //16 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);
    
     Serial.print("grid voltge=");
     Serial.println(dataString);               //17 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                //18 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/18
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);               //19 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                  //20 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/20
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                   //21 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                        //22 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/22
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 

     Serial.print("grid voltge=");
     Serial.println(dataString);                       //23 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 
    
    digitalWrite(2, HIGH);// turn/23
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(900);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000);

     Serial.print("grid voltge=");
     Serial.println(dataString);               //24 block
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(2000); 




          }
        }
      }
      }
    
    