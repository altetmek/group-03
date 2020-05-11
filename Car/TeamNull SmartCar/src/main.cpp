#include "main.hpp"

unsigned long loadTime = 0;

void setup() {

    // Open Serial Connection
    Serial.begin(9600);
    Wire.begin();
    pinMode(LED_BUILTIN, OUTPUT);

    blink(1);

    initialiseSensors();

    // Connect to WiFi - commented out do to location specific WiFi credentials
    // - Yes, I am aware that I am giving out my Wifi details :p
    char* WiFiSSID = "TheMancave";
    char* WiFiPassword = "tagedirtybumpaberra";
    connectToWiFi(WiFiSSID, WiFiPassword);
    blink(1);

    Serial.println("Returned from connectToWiFi");

    //Test collision avoidance
    // setDesiredVehicleSpeed(30);
    loadTime = millis();
}

void loop() {
    collisionAvoidance();

    // delay(1000);

    // Serial.println("loop");

    getInstructionsFromServer();
}