//ENTRADAS
int butRed = A5;
int butYel = A4;
int butGre = A3;
//Led
int ledRed = 13;
int ledYel = 12;
int ledGre = 11;
//Buzzer
int buzzerPin = 3;
//Tons botões
#define tomRed 294
#define tomYel 330
#define tomGre 350
//VARIÁVEIS
int rodada = 0;
int led = 0;
int temp_led_ligado = 600;
int temp_led_desligado = 100;
int mat[10];
int posi_mat = 0;
void setup(){
 //Configuração dos pinos de entrada
 pinMode(butRed, INPUT);
 pinMode(butYel, INPUT);
 pinMode(butGre, INPUT);
 //Configuração dos pinos de saída
 pinMode(ledRed, OUTPUT);
 pinMode(ledYel, OUTPUT);
 pinMode(ledGre, OUTPUT);
 pinMode(buzzerPin, OUTPUT);
 //Inicialização da comunicação serial
 Serial.begin(9600);
 //Função randômica
 randomSeed(analogRead(A0));
 inicio();
}
void loop(){
 led = random(0, 3);
 mat[posi_mat] = led;
 for (int j = 0; j <= posi_mat; j++) {
 switch (mat[j]) {
  case 0:
 digitalWrite(ledGre, HIGH);
 analogWrite(buzzerPin, tomGre);
 delay(200);
 digitalWrite(buzzerPin, LOW);
 delay(temp_led_ligado);
 digitalWrite(ledGre, LOW);
 delay (temp_led_desligado);
 break;
 case 1:
 digitalWrite(ledYel, HIGH);
 analogWrite(buzzerPin, tomYel);
 delay(200);
 digitalWrite(buzzerPin, LOW);
 delay(temp_led_ligado);
 digitalWrite(ledYel, LOW);
 delay (temp_led_desligado);
 break;
 case 2:
 digitalWrite(ledRed, HIGH);
 analogWrite(buzzerPin, tomRed);
 delay(200);
 digitalWrite(buzzerPin, LOW);
 delay(temp_led_ligado);
 digitalWrite(ledRed, LOW);
 delay (temp_led_desligado);
 break;
 default:
 break;
 }
 }
 int temp = 0;
 while (temp <= posi_mat){
 if (digitalRead(butGre) == HIGH) {
 digitalWrite(ledGre, HIGH);
 analogWrite(buzzerPin, tomGre);
 delay(100);
 digitalWrite(buzzerPin, LOW);
 while (digitalRead(butGre) == HIGH);
 digitalWrite(ledGre, LOW);
 delay(200);
 if ( mat[temp] == 0) {
 temp = temp + 1;
 } else
 {
 posi_mat = 11;
 break;
 }
 }
 if (digitalRead(butYel) == HIGH) {
 digitalWrite(ledYel, HIGH);
 analogWrite(buzzerPin, tomYel);
 delay(100);
 digitalWrite(buzzerPin, LOW);
 while (digitalRead(butYel) == HIGH);
 digitalWrite(ledYel, LOW);
 delay(200);
 if ( mat[temp] == 1) {
 temp = temp + 1;
 } else
 {
 posi_mat = 11;
 break;
 }
 }
 if (digitalRead(butRed) == HIGH) {
 digitalWrite(ledRed, HIGH);
 analogWrite(buzzerPin, tomRed);
 delay(100);
 digitalWrite(buzzerPin, LOW);
 while (digitalRead(butRed) == HIGH);
 digitalWrite(ledRed, LOW);
 delay(200);
 if ( mat[temp] == 2) {
 temp = temp + 1;
 } else
 {
 posi_mat = 11;
 break;
 }
 }
 }
 posi_mat = posi_mat + 1;
 if (posi_mat == 10) {
 ganhou();
 posi_mat = 0;
 }
 if (posi_mat >= 11) {
 perdeu();
 posi_mat = 0;
 delay(3000);
 }
}
void inicio() {
 for (int y = 0; y < 2; y++) {
 tone(buzzerPin, 330, 200);
 digitalWrite(ledRed, HIGH);
 delay(100);
 tone(buzzerPin, 330, 200);
 digitalWrite(ledYel, HIGH);
 delay(100);
 tone(buzzerPin, 330, 200);
 digitalWrite(ledGre, HIGH);
 delay(100);
 tone(buzzerPin, 262, 300);
 delay(100);
 digitalWrite(ledRed, LOW);
 digitalWrite(ledYel, LOW);
 digitalWrite(ledGre, LOW);
 delay(500);
 }
}
void perdeu() {
 for (int x = 0; x < 3; x++) {
 for (int z = 0; z < 3; z++) {
 tone(buzzerPin, 262, 200);
 digitalWrite(ledRed, HIGH);
 digitalWrite(ledYel, HIGH);
 digitalWrite(ledGre, HIGH);
 delay(250);
 digitalWrite(ledRed, LOW);
 digitalWrite(ledYel, LOW);
 digitalWrite(ledGre, LOW);
 }
 tone(buzzerPin, 528, 300);
 delay(100);
 }
}
void ganhou() {
 for (int w = 0; w < 2; w++) {
 tone(buzzerPin, 440, 200);
 digitalWrite(ledRed, HIGH);
 digitalWrite(ledYel, HIGH);
 digitalWrite(ledGre, HIGH);
 delay(250);
 digitalWrite(ledRed, LOW);
 digitalWrite(ledYel, LOW);
 digitalWrite(ledGre, LOW);
 tone(buzzerPin, 495, 200);
 digitalWrite(ledRed, HIGH);
 digitalWrite(ledYel, HIGH);
 digitalWrite(ledGre, HIGH);
 delay(250);
 digitalWrite(ledRed, LOW);
 digitalWrite(ledYel, LOW);
 digitalWrite(ledGre, LOW);
 tone(buzzerPin, 528, 200);
 digitalWrite(ledRed, HIGH);
 digitalWrite(ledYel, HIGH);
 digitalWrite(ledGre, HIGH);
 delay(250);
 digitalWrite(ledRed, LOW);
 digitalWrite(ledYel, LOW);
 digitalWrite(ledGre, LOW);
 tone(buzzerPin, 528, 200);
 digitalWrite(ledRed, HIGH);
 digitalWrite(ledYel, HIGH);
 digitalWrite(ledGre, HIGH);
 delay(250);
 digitalWrite(ledRed, LOW);
 digitalWrite(ledYel, LOW);
 digitalWrite(ledGre, LOW);
 delay(500);
 }
}
