#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int led = 7;
int buzzer = 8;

void setup() {
  Wire.begin();
  mpu.initialize();

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  float magnitude = sqrt(ax*ax + ay*ay + az*az);

  Serial.println(magnitude);

  if (magnitude > 20000) { // Threshold (calibrate)
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(3000);
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}
