int a = -1;
int b = -1;
int value = 2000;

int pin2;
int pin3;
int pin4;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  pin2 = digitalRead(2);
  pin3 = digitalRead(3);
  pin4 = digitalRead(4);

  if (pin2 == LOW) {
    a += 1;
    if (a == 10) {
      a = -1;
    }
    printValue();
  }

  if (pin3 == LOW) {
    b += 1;
    if (b == 10) {
      b = -1;
    }
    printValue();
  }

  if (pin4 == LOW) {
    checkLeapYear();
  }

  delay(200);
}

void printValue() {
  Serial.print("a = ");
  Serial.print(a);
  Serial.print(" b = ");
  Serial.println(b);
}

void checkLeapYear() {
  value += a * 10 + b;
  if (diviFourNotOneHundred() || diviFourHundred()) {
    Serial.println("Nam nhuan");
  } else {
    Serial.println("Khong phai nam nhuan");
  }

  a = -1;
  b = -1;
  delay(500);
  printValue();
}

boolean diviFourNotOneHundred() {
  if (value % 4 == 0 && value % 100 != 0) {
    return true;
  }

  return false;
}

boolean diviFourHundred() {
  if (value % 400 == 0) {
    return true;
  }
  
  return false;
}
