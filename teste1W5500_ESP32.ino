#include <SPI.h>
#include <Ethernet2.h>
#define RESET_P  26

byte mac[] = {0x1,0x2,0x3,0x4,0x5,0x6};

void Reseta_W5500() {
    Serial.println("Resetando o W5500");
    pinMode(RESET_P, OUTPUT);
    digitalWrite(RESET_P, HIGH);
    delay(250);
    digitalWrite(RESET_P, LOW);
    delay(50);
    digitalWrite(RESET_P, HIGH);
    delay(350);
    Serial.println("Fim reset");
}

void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
  }
  
  Reseta_W5500();
  
  //Seta o pino de CS no esp32
  Ethernet.init(5);

  delay(100);

  while(Ethernet.begin(mac) == 0) {
     Serial.println("Falha ao obter ip");
     delay(200);
  }
  
  delay(1000);

  Serial.println("Conectando...");

  Serial.print("IP placa: ");
  Serial.println(Ethernet.localIP());
  
  Serial.print("Mascara de subrede: ");
  Serial.println(Ethernet.subnetMask());
  
  Serial.print("Gateway: ");
  Serial.println(Ethernet.gatewayIP());
  
  Serial.print("DNS: ");
  Serial.println(Ethernet.dnsServerIP());

}

void loop()
{

}
