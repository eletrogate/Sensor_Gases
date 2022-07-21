#include <LiquidCrystal.h>

//Ligacoes de Hardware
#define Buzzer 10
#define MQ2_Analog 0
#define MQ2_Digital 2
#define SensorLevel 500
#define LCD_RS 9
#define LCD_E 8
#define LCD_D4 3
#define LCD_D5 4
#define LCD_D6 5
#define LCD_D7 6

int digital_read = 0;
int analog_read = 0;

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);//RS E D4 D5 D6 D7

void setup()
{
  // Configura os IOs
  pinMode(MQ2_Digital, INPUT);
  pinMode(Buzzer, OUTPUT);
  // Inicializa a serial
  Serial.begin(9600);
  //Inicializa o LCD
 lcd.begin(16, 2); 
}

void loop()
{
  // Le os dados do sensor MQ2
  digital_read = digitalRead(MQ2_Digital);
  analog_read = analogRead(MQ2_Analog);
  

  //apresenta as leituras na porta serial
  Serial.println("Saida Digital:");
  Serial.println(digital_read);
  Serial.println(" Saida Analogica:");
  Serial.println(analog_read);

  if (analog_read > SensorLevel)
  {
    // Apresenta os dados no LCD
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ar contaminado!");
    // Aciona o Buzzer
    digitalWrite(Buzzer, HIGH);

  }
  else
  {
     // Apresenta os dados no LCD
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ar normal");
    // Desliga o buzzer e o led vermelho
    digitalWrite(Buzzer, LOW);
  }
  
  delay(2000);
}