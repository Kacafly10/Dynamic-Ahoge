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
// before testing, time is represented as desired angle relative to first position (straight up)
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

void moveYawForward(unsigned long time = 0) {
    if (time == 0) {
        static unsigned long start = millis();
        digitalWrite(YAW_FORWARD_PIN, HIGH);
        digitalWrite(YAW_BACKWARD_PIN, LOW);
        return;
    }
    else if (time == 4294967295) {
        yawTime = yawTime + (millis() - start);
    }
    else {
    static unsigned long start = millis();
    digitalWrite(YAW_FORWARD_PIN, HIGH);
    digitalWrite(YAW_BACKWARD_PIN, LOW);
    delay(time);
    yawTime = yawTime + (millis() - start);
    digitalWrite(YAW_FORWARD_PIN, LOW); }
}

void moveYawBackward(unsigned long time = 0) {
    if (time == 0) {
        static unsigned long start = millis();
        digitalWrite(YAW_FORWARD_PIN, LOW);
        digitalWrite(YAW_BACKWARD_PIN, HIGH);
        return;
    }
    else if (time == 4294967295) {
        yawTime = yawTime - (millis() - start);
    }
    else {
    static unsigned long start = millis();
    digitalWrite(YAW_FORWARD_PIN, LOW);
    digitalWrite(YAW_BACKWARD_PIN, HIGH);
    yawTime = yawTime - (millis() - start);
    delay(time);
    digitalWrite(YAW_BACKWARD_PIN, LOW);
    }
}
}

void movePitchForward(unsigned long time = 0) {
    if (time == 0) {
        static unsigned long start = millis();
        digitalWrite(PITCH_FORWARD_PIN, HIGH);
        digitalWrite(PITCH_BACKWARD_PIN, LOW);
        return;
    }
    else if (time == 4294967295) {
        pitchTime = pitchTime + (millis() - start);
    }
    else {
        static unsigned long start = millis();
        digitalWrite(PITCH_FORWARD_PIN, HIGH);
        digitalWrite(PITCH_BACKWARD_PIN, LOW);
        pitchTime = pitchTime + (millis() - start);
        delay(time);
        digitalWrite(PITCH_FORWARD_PIN, LOW);
    }
}

void movePitchBackward(unsigned long time = 0) {
    if (time == 0) {
        static unsigned long start = millis();
        digitalWrite(PITCH_FORWARD_PIN, LOW);
        digitalWrite(PITCH_BACKWARD_PIN, HIGH);
        return;
    }
    else if (time == 4294967295) {
        pitchTime = pitchTime - (millis() - start);
    }
    else {
    static unsigned long start = millis();
    digitalWrite(PITCH_FORWARD_PIN, LOW);
    digitalWrite(PITCH_BACKWARD_PIN, HIGH);
    pitchTime = pitchTime - (millis() - start);
    delay(time);
    digitalWrite(PITCH_BACKWARD_PIN, LOW); }
}

// Poses fully implemented only after testing

void pose1() {
    // 0 degrees yaw, 0 degrees pitch (at least in theory)
    if (yawTime < 0) {
        moveYawForward(yawTime * -1);
    }
    else if (yawTime > 0) {
        moveYawBackward(yawTime);
    }
    else {
        // at 0
    }

    if (pitchTime < 0) {
        movePitchForward(pitchTime * -1);
    }
    else if (pitchTime > 0) {
        movePitchBackward(pitchTime);
    }
    else {
        // at 0
    }
}

void pose2() {
    // Quick rise (90 to be tested)
    movePitchForward(90 - pitchTime);
    movePitchBackward(90);
}

void pose3() {
    // Implement the specific pose 3
}

void pose4() {
    // Implement the specific pose 4
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
            moveYawForward();
            while (digitalRead(YAW_PLUS_PIN) == HIGH)
            {
            }
            moveYawForward(4294967295);
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
            moveYawBackward();
            while (digitalRead(YAW_MINUS_PIN) == HIGH)
            {
            }
            moveYawBackward(4294967295);
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
            movePitchForward(4294967295);
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

