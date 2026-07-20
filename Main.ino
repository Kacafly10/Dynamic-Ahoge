#define YAW_FORWARD_PIN 3
#define YAW_BACKWARD_PIN 4
#define PITCH_FORWARD_PIN 18
#define PITCH_BACKWARD_PIN 17

#define YAW_PLUS_PIN 7
#define YAW_MINUS_PIN 10
#define PITCH_PLUS_PIN 14
#define PITCH_MINUS_PIN 11

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
//Yaw Plus-------------------------------
if (digitalRead(YAW_PLUS_PIN) == HIGH) {
        unsigned long press = millis();
        while (digitalRead(YAW_PLUS_PIN) == HIGH) {

        }

        press = millis() - press;
        if (press < 500){
            pose1();
        }
        else {
            while (digitalRead(YAW_PLUS_PIN) == HIGH)
            {
            moveYawForward();
            }
        }
    }

//Yaw Minus-------------------------------
if (digitalRead(YAW_MINUS_PIN) == HIGH) {
        unsigned long press = millis();
        while (digitalRead(YAW_MINUS_PIN) == HIGH) {

        }

        press = millis() - press;
        if (press < 500){
            pose2();
        }
        else {
            while (digitalRead(YAW_MINUS_PIN) == HIGH)
            {
            }
        }
    }

//Pitch Plus-------------------------------
if (digitalRead(PITCH_PLUS_PIN) == HIGH) {
        unsigned long press = millis();
        while (digitalRead(PITCH_PLUS_PIN) == HIGH) {

        }

        press = millis() - press;
        if (press < 500){
            pose3();
        }
        else {
            movePitchForward();
            while (digitalRead(PITCH_PLUS_PIN) == HIGH)
            {
            }
            digitalWrite(PITCH_FORWARD_PIN, LOW);
        }
    }

//Pitch Minus-------------------------------
if (digitalRead(PITCH_MINUS_PIN) == HIGH) {
        unsigned long press = millis();
        while (digitalRead(PITCH_MINUS_PIN) == HIGH) {

        }

        press = millis() - press;
        if (press < 500){
            pose4();
        }
        else {
            movePitchBackward();
            while (digitalRead(PITCH_MINUS_PIN) == HIGH) {
            }
            digitalWrite(PITCH_BACKWARD_PIN, LOW);
        }
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

// Poses implemented after testing

void pose1() {
    // Implement the specific pose 1
}

void pose2() {
    // Implement the specific pose 2
}

void pose3() {
    // Implement the specific pose 3
}

void pose4() {
    // Implement the specific pose 4
}