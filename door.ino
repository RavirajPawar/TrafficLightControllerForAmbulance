#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define red1 D0
#define green1 D1
#define red2 D2
#define green2 D3
#define red3 D4
#define green3 D5
#define red4 D6
#define green4 D7
#define ELed D8

#define FIREBASE_HOST "FIREBASE HOST "
#define FIREBASE_AUTH "SECRET KEY FROM FIREBASE"
#define WIFI_SSID "NAME OF WIFI NETWORK"
#define WIFI_PASSWORD "PASSWORD OF WIFE NETWORK"

char l[5];


void setup() {
  // put your setup code here, to run once:
pinMode(D0,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D5,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D7,OUTPUT);
pinMode(D8,OUTPUT);

Serial.begin(115200);
    Serial.print("connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) 
    {
    Serial.print(".");
    delay(500);
    }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void firebasereconnect(){
  Serial.println("Trying to reconnect");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  }

void SignalA()
{
  Serial.println("Signal A...");
    digitalWrite(green1,HIGH);  
    digitalWrite(red2,HIGH);  
    digitalWrite(red3,HIGH);  
    digitalWrite(red4,HIGH);  
}
void SignalB()
{
  Serial.println("Signal B...");
    digitalWrite(green2,HIGH);  
    digitalWrite(red1,HIGH);  
    digitalWrite(red3,HIGH);  
    digitalWrite(red4,HIGH);  
}

void SignalC()
{
  Serial.println("Signal C...");
    digitalWrite(green3,HIGH);  
    digitalWrite(red2,HIGH);  
    digitalWrite(red1,HIGH);  
    digitalWrite(red4,HIGH);  
}

void SignalD()
{
  Serial.println("Signal D...");
    digitalWrite(green4,HIGH);  
    digitalWrite(red2,HIGH);  
    digitalWrite(red3,HIGH);  
    digitalWrite(red1,HIGH);  
}


void Off()
{
    digitalWrite(red1,LOW);  
    digitalWrite(red2,LOW);  
    digitalWrite(red3,LOW);  
    digitalWrite(red4,LOW);  
    digitalWrite(green1,LOW);  
    digitalWrite(green2,LOW);  
    digitalWrite(green3,LOW);  
    digitalWrite(green4,LOW);    
}

void high()
{
   digitalWrite(D0,HIGH);
   digitalWrite(D1,HIGH);
   digitalWrite(D2,HIGH);  
   digitalWrite(D5,HIGH);
   digitalWrite(D6,HIGH);  
   digitalWrite(D3,HIGH);  
   digitalWrite(D4,HIGH);  
   digitalWrite(D7,HIGH);  
}

void Check()
{
  for (int i =0 ;i<10 ; i++)
  {  
    Firebase.getString("locate/Distance_GCEK").toCharArray(l,sizeof(l));
    delay(100);
    int led = atoi(l);

    Serial.print("LED value :");
    Serial.println(led);
  
    if (led < 400 && led >10)
    { Serial.print("LED OONNNN......:");
         digitalWrite(ELed,HIGH);    }
     if (led < 10)
    {     Off(); digitalWrite(ELed,LOW);SignalA(); delay(1000);   }
  }
}

void loop() {
  SignalA();   
    Check();    
    Off();
    
    SignalB();
    Check();
    Off();
    
    
    SignalC();
    Check();
    Off();
    
    SignalD();
    Check();
    Off();
  
  }
