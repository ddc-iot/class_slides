#ifndef _BUTTON_H_
#define _BUTTON_H_

class Button {
  int _buttonPin;

  public:
    Button(int buttonPin) {
      _buttonPin = buttonPin;
      pinMode(_buttonPin, INPUT);
    }

    bool isPressed() {
      return digitalRead(_buttonPin);
    }
<<<<<<< HEAD

=======
>>>>>>> 33c69d4ffe5ef36ba5dd8e5b562c1a8781a8d5e2
};

#endif // _BUTTON_H_
