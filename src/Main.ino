#define YAW_FORWARD_PIN 13
#define YAW_BACKWARD_PIN 14
#define PITCH_FORWARD_PIN 12
#define PITCH_BACKWARD_PIN 11

#define YAW_PLUS_PIN 10
#define YAW_MINUS_PIN 9
#define PITCH_PLUS_PIN 8
#define PITCH_MINUS_PIN 7

long yawTime;
long pitchTime;
// Time based tracking for yaw and pitch movements to eliminate the need for servo or encoder. Precision is ....

void setup() {
    pinMode(YAW_FORWARD_PIN, OUTPUT);
    pinMode(YAW_BACKWARD_PIN, OUTPUT);
    pinMode(PITCH_FORWARD_PIN, OUTPUT);
    pinMode(PITCH_BACKWARD_PIN, OUTPUT);

    pinMode(YAW_PLUS_PIN, INPUT);
    pinMode(YAW_MINUS_PIN, INPUT);
    pinMode(PITCH_PLUS_PIN, INPUT);
    pinMode(PITCH_MINUS_PIN, INPUT);
}

void loop() {
    if (digitalRead(YAW_PLUS_PIN) == HIGH) {
        moveYawForward();
    }
    else if (digitalRead(YAW_MINUS_PIN) == HIGH) {
        moveYawBackward();
    }

    if (digitalRead(PITCH_PLUS_PIN) == HIGH) {
        movePitchForward();
    }
    else if (digitalRead(PITCH_MINUS_PIN) == HIGH) {
        movePitchBackward();
    }

    else {
        digitalWrite(YAW_FORWARD_PIN, LOW);
        digitalWrite(YAW_BACKWARD_PIN, LOW);
        digitalWrite(PITCH_FORWARD_PIN, LOW);
        digitalWrite(PITCH_BACKWARD_PIN, LOW);
    }
}

void moveYawForward() {
    unsigned long start = millis();
    digitalWrite(YAW_FORWARD_PIN, HIGH);
    digitalWrite(YAW_BACKWARD_PIN, LOW);
    yawTime = yawTime + (millis() - start);
}

void moveYawBackward() {
    unsigned long start = millis();
    digitalWrite(YAW_FORWARD_PIN, LOW);
    digitalWrite(YAW_BACKWARD_PIN, HIGH);
    yawTime = yawTime - (millis() - start);
}

void movePitchForward() {
    unsigned long start = millis();
    digitalWrite(PITCH_FORWARD_PIN, HIGH);
    digitalWrite(PITCH_BACKWARD_PIN, LOW);
    pitchTime = pitchTime + (millis() - start);
}

void movePitchBackward() {
    unsigned long start = millis();
    digitalWrite(PITCH_FORWARD_PIN, LOW);
    digitalWrite(PITCH_BACKWARD_PIN, HIGH);
    pitchTime = pitchTime - (millis() - start);
}