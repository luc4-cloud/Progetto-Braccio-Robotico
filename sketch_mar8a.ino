#include <ESP32Servo.h>

// Definizione dei pin
#define SERVO_PIN 18    // Pin PWM per il servo
#define JOY_X_PIN 34    // Pin analogico per l'asse X del joystick

Servo servo;
int pos = 90; // Posizione iniziale del servo (al centro)

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(pos);
    pinMode(JOY_X_PIN, INPUT);
}

void loop() {
    int joyValue = analogRead(JOY_X_PIN);
    
    // Controlla se il joystick viene spostato e aggiorna la posizione
    if (joyValue > 3000) { // Sposta a destra
        pos = constrain(pos + 1, 0, 180);
    } else if (joyValue < 1000) { // Sposta a sinistra
        pos = constrain(pos - 1, 0, 180);
    }
    
    // Il servo mantiene la posizione attuale senza tornare indietro
    servo.write(pos);
    
    delay(20); // Ritardo per evitare movimenti troppo bruschi
}