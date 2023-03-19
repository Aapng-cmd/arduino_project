/* Кунина Лиза, команда 3, "Таймер" */
#include <Wire.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F, 20, 4); // Устанавливаем дисплей

#define PIP 8
#define pot A0

int timm(int q = 5)
{
  unsigned long tim = 0;
  unsigned long timer = millis();
  int o = 0;
  q *= 1000;

  while (millis() - timer < q)
  {
    String s1 = "Time left: ";
    String s2 = "Time chosen: ";
    o = q / 1000 - (millis() - timer) / 1000;
    s1 += o;
    s1 += "  ";
    s2 += q / 1000;
    s2 += "  ";
    lcd.print(s1);
    lcd.setCursor(0, 1);
    lcd.print(s2);
    lcd.setCursor(0, 0);
  }
  
  lcd.clear();
  lcd.print("Done!");
  lcd.setCursor(0, 0);

  for (int i = 0; i < 7; i++)
  {
    tim = millis();   
    while (millis() - tim < 1000)
    {
      if (i % 2)
      {
        tone(PIP, 2000);
      }
      else
      {
        noTone(PIP);
      }
    }
  }
  return 0;
}

void setup()
{
  pinMode(pot, 0);
  lcd.init();
  lcd.backlight(); // Включаем подсветку дисплея
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop()
{
  unsigned long tim = millis();
  int val = 5;
  int o = 0;

  while (millis() - tim < 4 * 1000)
  {
    String s1 = "Chosen time: ";
    String s2 = "WARNING!  ";
    val = map(analogRead(pot), 0, 1023, 3, 20);
    s1 += val;
    s1 += "  ";
    o = 4 - (millis() - tim) / 1000 - 1;
    s2 += o;

    lcd.print(s1);
    lcd.setCursor(0, 1);
    lcd.print(s2);
    lcd.setCursor(0, 0);
  }

  lcd.clear();
  timm(val); 

}
