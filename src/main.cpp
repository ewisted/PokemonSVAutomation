#include <Arduino.h>
#include <NintendoSwitchControlLibrary.h>

const int _buttonDelay = 200;
const int _dialogDelay = 1250;

void setup() {
  // Connect controller
  pushButton(Button::B, 500, 5);

  // Open boxes
  pushButton(Button::X, _buttonDelay);
}

void loop() {
  // Select Koriadon
  printf("Selecting Koriadon...");
  pushButton(Button::A, _buttonDelay);
  
  // Change to ride form
  printf("Changing Koriadon to ride form...");
  pushHat(Hat::UP, 25, 2);
  pushButton(Button::A, _buttonDelay);

  // Wait for dialog and proceed
  printf("Waiting for dialog boxes...");
  delay(_dialogDelay);
  pushButton(Button::A, _buttonDelay + _dialogDelay, 3);

  // Move to boxes
  printf("Moving to boxes...");
  pushHat(Hat::RIGHT, _buttonDelay);
  pushHat(Hat::UP, _buttonDelay, 4);
  pushButton(Button::A, _buttonDelay);

  // Change to item select
  printf("Changing to item select...");
  pushButton(Button::X, _buttonDelay, 2);

  // Change to Koriadon box
  printf("Changing to Koriadon box...");
  pushButton(Button::L);

  // Select and remove Koriadon item
  printf("Removing Koriadon's held item...");
  pushButton(Button::A, _buttonDelay);
  pushHat(Hat::DOWN, _buttonDelay, 3);
  pushButton(Button::A, _buttonDelay);

  // Exit boxes
  printf("Exiting boxes...");

  // Reset position
  printf("Resetting position...");
  pushHat(Hat::LEFT, _buttonDelay);
}