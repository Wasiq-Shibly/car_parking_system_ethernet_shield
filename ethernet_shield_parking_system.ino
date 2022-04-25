const byte interruptPin = 3;
int count;
unsigned long count1=0;
int delaytime=0;


unsigned long last_time;
String prev_data;

unsigned long  open_time,close_time;

String led_status;
#include <rdm6300.h>
#define RDM6300_RX_PIN 2 // read the SoftwareSerial doc above! may need to change this pin to 10...
#define READ_LED_PIN 13

Rdm6300 rdm6300;

#include <SPI.h>
#include <Ethernet.h>

// replace the MAC address below by the MAC address printed on a sticker on the Arduino Shield 2
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient client;

int    HTTP_PORT   = 80;
String HTTP_METHOD = "GET";
//char   HOST_NAME[] = "10.100.93.85";
//String PATH_NAME   = "/door_locker/card_parking_api.php";

char   HOST_NAME[] = "erp.superhostelbd.com";
String PATH_NAME   = "/super_home/json/api/check_parking";
String queryString = "";
#define buzzer1 8
#define buzzer2 9
#define up 7
#define down 6


void setup() {
  pinMode(buzzer1,OUTPUT);
  pinMode(buzzer2,OUTPUT);
  pinMode(up,OUTPUT);
  pinMode(down,OUTPUT);
  digitalWrite(buzzer1,1);
    digitalWrite(buzzer2,1);
      digitalWrite(up,1);
    digitalWrite(down,1);
  
  Serial.begin(9600);

  pinMode(interruptPin, INPUT_PULLUP);


  pinMode(READ_LED_PIN, OUTPUT);
  digitalWrite(READ_LED_PIN, LOW);

  rdm6300.begin(RDM6300_RX_PIN);

  Serial.println("\nPlace RFID tag near the rdm6300...");


 
}

void loop() {

  
  if (rdm6300.update())
  {
   String data="00";

data+=String(rdm6300.get_tag_id(),DEC);
  if((data!=prev_data) || (millis()>(last_time+500)))
  {
  prev_data=data;
  Serial.println(data);
  queryString = "?authorization=raspberry&card_number=";
  queryString += data;
  
  Serial.println(queryString);
  count=0;
  database();
  last_time=millis();
  }

  
  }


Serial.println("loop");
  

}
