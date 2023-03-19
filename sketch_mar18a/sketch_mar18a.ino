/* Кунина Лиза, Варежников Кирилл, камонда 3, "Умная кормушка" */
#include <Wire.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F, 20, 4); // Устанавливаем дисплей

int val = 0; // Для считывания показаний потенциометра
#define potpin A0 // Подключение потенциометра
#define buttonPin1 A2// Подключение кнопки
#define buttonPin2 6
int flag = 0; // для кнопки
unsigned int counter = 0;

int SEC = 0;

unsigned long timer = 0;
int tam;

unsigned int disp_func(unsigned int counter, bool boot = false)
{
  int button1 = !digitalRead(buttonPin1);
  int val1 = 0;
  if (!boot)
  {
    if (counter == 1)
    {
      
    }
    
    else if (counter == 2)
    {
      
    }
  }
  else
  {   
    while (!button1)
    {
      String s = "Choose a time >> ";
      val1 = map(analogRead(potpin), 0, 1023, 0, 60);
      s += val1;
      s += "  ";
      // lcd.print(s.concat(val1));
      lcd.print(s);
      // lcd.setCursor(17, 0);
      // lcd.print(val1);
      // lcd.clear();
      // lcd.setCursor(0, 0);
    }
      
    return val1;
  }
}

void setup()
{
  // pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin1, 0);
  pinMode(buttonPin2, INPUT_PULLUP);
  lcd.init();
  lcd.backlight(); // Включаем подсветку дисплея
  lcd.print("Ready to start!");

  timer = millis();
}

int boot_l = 0;
unsigned long time_left = 0;

void loop()
{
  int button1 = !digitalRead(buttonPin1);
  int button2 = !digitalRead(buttonPin2);
  int start_up = 0;

  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 60);

  unsigned long tim = millis();
  while (millis() - tim > 1000)
  {
    if (button1 == 1)
    {
      counter++;
    }
  }
  
  // counter = 1;

  if (counter > 0 && !boot_l)
  {
    time_left = disp_func(0, true);
    boot_l = 1;
    start_up = 1;
  }
  else
  {
    disp_func(counter);
  }

  while (time_left > 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("Time left: " + time_left);
    // lcd.clear();
  }

  if (start_up)
  {

  }

  /*
  if (button1 == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Time:");
    lcd.setCursor(8, 1);
    lcd.print(val);
  }
  */

}


/* val = analogRead(potpin);
     if (button1 && flag && millis() - btnTimer < 1000)
  val = map(val, 0, 1023, 0, 60);
  if (button1 && flag && millis() - btnTimer > 2000)
  {
   btnTimer = millis();

  lcd.print("Time:");
  lcd.setCursor(8, 1);
  lcd.print(val);
  delay(300);
*/


/* // читаем инвертированное значение для удобства
  bool btnState = !digitalRead(3);
  if (btnState && !flag && millis() - btnTimer > 100) {
   flag = true;
   btnTimer = millis();
   Serial.println("press");
  }
  if (btnState && flag && millis() - btnTimer > 500) {
   btnTimer = millis();
   Serial.println("press hold");
  }
  if (!btnState && flag && millis() - btnTimer > 500) {
   flag = false;
   btnTimer = millis();
   //Serial.println("release");
  }
*/

/*int SEC = 0;
  int MIN = 0;
  unsigned long timer;

  void setup() {
  Serial.begin(9600);
  timer = millis();
  }

  void loop() {
  // если прошло 1000 мс - прибавляем одну секунду к переменной SEC
  if (millis() - timer > 1000) {
    timer = millis();
    SEC = SEC + 1;
    if (SEC > 59) { SEC = 0; MIN = MIN + 1; }
    // выводим текущий счетчик времени на монитор порта
    Serial.println(String(MIN) + " : " + String(SEC));
  }

  }

*/