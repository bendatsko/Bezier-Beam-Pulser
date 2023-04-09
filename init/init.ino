/* 
* Generates dynamic pulse frequencies on an Arduino using a Bezier curve to modulate delay between pulses. 
* Animation goes from a delay of 0ms to 20ms and back to 0ms, repeating indefinitely. 
* Outputs a tone on pin 8 (connected to osciliscope probe) with a frequency that changes based on the value of the delay.
*/

const int pin = 8;
int t = 0;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  int ms = max(0, bezier(t));
  tone(pin, 250 * ms);
  t = (t + 1) % 101;
  delay(100);
}

int bezier(int t) {
  float u = t / 100.0;
  float y = (1 - u) * (1 - u) * 0 + 2 * (1 - u) * u * 20 + u * u * 0;
  return (int) y;
}

