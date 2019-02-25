String label = "Menu chon do an";
String doAn[5] = {"0. Pho bo", "1. Mien tron", "2. Com ga", "3. Lau thai", "4. Xoi xeo"};

int pin2, pin3;
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  pin2 = digitalRead(2);
  pin3 = digitalRead(3);

  Serial.println(label);
  if (pin2 == LOW) {
    if (i == 5) {
      i = 0;
    }
    Serial.println(doAn[i]);
    i++;
    Serial.println();
  }

  if (pin3 == LOW) {
    //Dùng i-1 do khi nhấn chuyển đồ ăn, i đã bị tăng lên 1 sau khi in ra
    Serial.println("Ban da lua chon mon: " + doAn[i - 1]);
    Serial.println();
    i = 0;
    delay(500);
  }

  delay(200);
}
