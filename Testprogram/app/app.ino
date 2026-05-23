#include <HijelHID_BLEKeyboard.h>

const byte ROW_PINS[] = {6,7,15,16,17,18};
const byte COL_PINS[] = {2,42,41,40,39,38,37,36,35,0,45,48,47,21};

const int ROW_COUNT = sizeof(ROW_PINS);
const int COL_COUNT = sizeof(COL_PINS);

unsigned char keymap[ROW_COUNT][COL_COUNT] = {
    {KEY_ESCAPE, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_DELETE},
    {KEY_GRAVE, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_MINUS, KEY_EQUAL, KEY_BACKSPACE},
    {KEY_TAB, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_BACKSLASH},
    {KEY_CAPS_LOCK, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_APOSTROPHE, KEY_ENTER, 0},
    {KEY_LEFT_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, KEY_UP, 0, 0},
    {KEY_LEFT_CTRL, KEY_FN, KEY_LEFT_GUI, KEY_LEFT_ALT, KEY_SPACE, KEY_RIGHT_ALT, KEY_RIGHT_CTRL, KEY_LEFT, KEY_DOWN, KEY_RIGHT, 0, 0, 0, 0}
};

bool keyStates[ROW_COUNT][COL_COUNT];

HijelHID_BLEKeyboard keyboard("Matrix Keyboard", "MyESP32S3", 100);

void setup() {
  Serial.begin(115200);
  for (int r = 0; r < ROW_COUNT; r++) {
    pinMode(ROW_PINS[r], INPUT);
  }
  for (int c = 0; c < COL_COUNT; c++) {
    pinMode(COL_PINS[c], INPUT_PULLUP);
  }
  Serial.println("Starting BLE work!");
  keyboard.begin();
}

void loop() {
  if (keyboard.isConnected()) {
    scanMatrix();
  }
  delay(10);
}

void scanMatrix() {
  for (int r = 0; r < ROW_COUNT; r++) {
    pinMode(ROW_PINS[r], OUTPUT);
    digitalWrite(ROW_PINS[r], LOW);

    for (int c = 0; c < COL_COUNT; c++) {
      bool currentState = (digitalRead(COL_PINS[c]) == LOW);
      if (currentState != keyStates[r][c]) {
        keyStates[r][c] = currentState;

        char key = keymap[r][c];
        if (key != 0) {
          if (currentState) {
            Serial.print("Pressed: ");
            Serial.println(key);
            keyboard.press(key);
          } else {
            Serial.print("Released: ");
            Serial.println(key);
            keyboard.release(key);
          }
        }
      }
    }
    pinMode(ROW_PINS[r], INPUT);
  }
}
