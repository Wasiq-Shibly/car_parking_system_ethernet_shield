                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   void database()
{

Serial.println("database is called");
  // initialize the Ethernet shield using DHCP:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to obtaining an IP address using DHCP");
    while(true);
  }

  // connect to web server on port 80:
  if(client.connect(HOST_NAME, HTTP_PORT)) {
    // if connected:
    Serial.println("Connected to server");
    // make a HTTP request:
    // send HTTP header




    
    client.println(HTTP_METHOD + " " + PATH_NAME + queryString + " HTTP/1.1");
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println(); // end HTTP header
    led_status="";

    while(client.connected()) {
      if(client.available()){
        // read an incoming byte from the server and print it to serial monitor:
        char c = client.read();
        led_status+=String(c);
        Serial.print(c);
      }
    }

Serial.println("data");

Serial.println(led_status);
Serial.println(led_status.length());
Serial.println(led_status);
Serial.println(led_status[480]);
Serial.println(led_status[481]);


Serial.println("data end");


if(led_status[480]=='u' && led_status[481]=='e')
{
//  digitalWrite(buzzer1,0);
//  digitalWrite(buzzer2,0);
  digitalWrite(up,0);
  delay(14000);
  digitalWrite(up,1);
  open_time=millis();
  digitalWrite(buzzer1,1);
  digitalWrite(buzzer2,1);
Serial.println("data _data _data");

while( (((open_time+1000+delaytime)>millis())  && (count<10))  ||  (digitalRead(3)==0)   )
{
  if(digitalRead(3)==0)
  {
    count++;
   
    
   
  }
 
  Serial.println(count);
 Serial.println("Gate is  closing");
 
}



delay(10000);
last_time=millis();
while(millis()<(last_time+5000))
{
  digitalWrite(buzzer1,0);
  digitalWrite(buzzer2,0);
  delay(50);
   digitalWrite(buzzer1,1);
  digitalWrite(buzzer2,1);
   delay(50);
}
count=0;


Serial.println("Down start");
last_time=millis();
count1=0;
while(((last_time+14000+(count1*16)))>millis())
{
  if(digitalRead(3)==0)
  {
    count1++;
    Serial.println(count1);
   digitalWrite(down,1);
  }
  else{
digitalWrite(down,0);
  }

}

Serial.println("all work is done ");
digitalWrite(up,1);
digitalWrite(down,1);
Serial.println(millis());
Serial.println((last_time+14000+count1));
delay(2000);
Serial.println(count);
}



    // the server's disconnected, stop the client:
    client.stop();
    Serial.println();
    Serial.println("disconnected");
  } else {// if not connected:
    Serial.println("connection failed");
  }



  
}
