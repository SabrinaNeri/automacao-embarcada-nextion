#include <Nextion.h>
#include <Servo.h>

Servo servo;
#define pin1  10
#define pin2  9
#define pinoA A1

const int servoPin = 6;
const int pinoRele = 7;
int statusLamp = 0;
int statusServo = 0;
int pmwValue;
int statusmotor = 0;

NexPage page5 = NexPage(5, 0, "page5");
NexDSButton bt0 = NexDSButton(5, 1, "bt0");
NexDSButton bt1 = NexDSButton(5, 5, "bt1");
NexDSButton bt2 = NexDSButton(5, 6, "bt2");
NexSlider slider = NexSlider(5, 2, "slider");
NexNumber n0 = NexNumber(5, 13, "n0");

NexTouch *nex_listen_list[]{
   &bt0,
   &bt1,
   &bt2,
   &slider,
  NULL
  };

uint32_t estado_DSbotao0;
uint32_t estado_DSbotao1;
uint32_t estado_DSbotao2;
uint32_t number;

void sliderPopCallback(void *ptr) {
 analogWrite(pinoA, 0);
 uint32_t number;
  
slider.getValue(&number);

if(number == 0){
pmwValue = number;
   }
if(number>0){
pmwValue = number+128;
 Serial.println("\n");
  Serial.println("funcionaaaaaa");
 Serial.println(pmwValue);
  Serial.println(number);
    }
if(statusmotor == 1){
ponteH(1, 0,pmwValue);
  }
}

void setup() {
nexInit();
Serial.begin(9600);
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pinoA, OUTPUT);
pinMode(pinoRele, OUTPUT);
digitalWrite(pinoRele, HIGH);
servo.attach(6,500,2400);
digitalWrite(pin2, LOW);
digitalWrite(pin1, HIGH);
slider.attachPop(sliderPopCallback);  
}

int pos = 0;

void loop() {
nexLoop(nex_listen_list);
delay(200);
if((pmwValue) && (statusmotor == 1) ){
ponteH(1, 0,pmwValue);
  }
bt0.getValue(&estado_DSbotao0);
if ((estado_DSbotao0 == 1) && (statusmotor == 0)){
  ponteH(1, 0,pmwValue);
  statusmotor=1;
  }
  
 if ((estado_DSbotao0== 0) && (statusmotor == 1)){
 
      ponteH(1, 0, 0);
      statusmotor=0;
    }

bt1.getValue(&estado_DSbotao1);
  if ((estado_DSbotao1 > 0) && (statusLamp == 0)){
 digitalWrite(pinoRele, LOW);
    statusLamp = 1;  
 }
    bt1.getValue(&estado_DSbotao1);
    if ((estado_DSbotao1 == 0) && (statusLamp == 1)){
     digitalWrite(pinoRele, HIGH);
     statusLamp = 0;
     delay(200);    
     }

 bt2.getValue(&estado_DSbotao2);
  if (estado_DSbotao2 > 0) {
      digitalWrite(servoPin, LOW);
      for(pos=0; pos <= 120; pos +=1){
      servo.write(pos);
      delay(10);
      }
     
      for(pos=120; pos >= 0; pos -=1){
      servo.write(pos);
      delay(10);
      }
  }

  bt2.getValue(&estado_DSbotao2);
  if (estado_DSbotao2 == 0) {
       digitalWrite(servoPin,HIGH);
       }
}

void ponteH(int x, int y, int z) {
  digitalWrite(pin1, x);
  digitalWrite(pin2, y);
  analogWrite(pinoA, z);  
}
