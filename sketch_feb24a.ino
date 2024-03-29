#include <SPI.h>
#include <Ethernet.h>

byte mac [] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED 
};

// Enter the IP address for Arduino

IPAddress ip(192.168);

int photocellPin = 0;  // Analog input pin on Arduino we connected the SIG pin from sensor
int photocellReading;  // Here we will place our reading
char server[] = "192.168.0.11"; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600)

  Ethernet.begin(mac, ip)

}

void loop() {
  // put your main code here, to run repeatedly:
  photocellReading = analogRead(photocellPin);

   if (client.connect(server, 80)) {
    client.print("GET /write_data.php?"); // This
    client.print("value="); // This
    client.print(photocellReading); // And this is what we did in the testing section above. We are making a GET request just like we would from our browser but now with live data from the sensor
    client.println(" HTTP/1.1"); // Part of the GET request
    client.println("Host: 192.168.0.11"); // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie.Host: "www.yourwebpage.com")
    client.println("Connection: close"); // Part of the GET request telling the server that we are over transmitting the message
    client.println(); // Empty line
    client.println(); // Empty line
    client.stop();    // Closing connection to server

  }

  else {
    // If Arduino can't connect to the server (your computer or web page)
    Serial.println("--> connection failed\n");
  }
 
  // Give the server some time to recieve the data and store it. I used 10 seconds here. Be advised when delaying. If u use a short delay, the server might not capture data because of Arduino transmitting new data too soon.
  delay(10000);

}
