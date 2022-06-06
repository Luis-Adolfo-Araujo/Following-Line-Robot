//Definição dos pinos de controle do motor
#define M1A 8 // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta ATV_A ponte H; roda mais rapida 
#define M1B 9 //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta ATV_B ponte H;
#define M2A 10 //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
#define M2B 11 //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;
//Definição dos pinos dos sensores
#define pin_S1 A0
#define pin_S2 A1
#define BLACK 600
#define WHITE 200
int Sensor1 = 0;
int Sensor2 = 0;
//variável responsável por controlar a velocidade dos motores
int velocidade = 255; //roda mais rapida
int velocidade1 = 255; 


void frente(void){
  analogWrite(M1A, velocidade); // Ambos motores ligam na mesma velocidade
  analogWrite(M2A, velocidade1);
  digitalWrite(M1B, LOW);
  digitalWrite(M2B, LOW);
}
void direita(void){
  analogWrite(M1A, velocidade); // Ambos motores ligam na mesma velocidade
  analogWrite(M2A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2B, LOW);
}

void esquerda(void){
  analogWrite(M1A, LOW); // Ambos motores ligam na mesma velocidade
  analogWrite(M2A, velocidade1);
  digitalWrite(M1B, LOW);
  digitalWrite(M2B, LOW);
}

void pare(void){
  analogWrite(M1A, LOW); // Ambos motores ligam na mesma velocidade
  analogWrite(M2A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2B, LOW);
}

void setup(){
  
  //Setamos os pinos de controle dos motores como saída
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  
  //Setamos a direção inicial do motor como 0, isso fará com que ambos os motores girem para frente
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);

  //Setamos os pinos dos sensores como entrada
  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);

  Serial.begin(9600);
}
void loop(){
   //Neste processo armazenamos o valor lido pelo sensor na variável que armazena tais dados.
  Sensor1 = analogRead(pin_S1);
  Sensor2 = analogRead(pin_S2);
  Serial.print("Sensor_1 => ");
  Serial.println(Sensor1);
  Serial.print("Sensor_2 => ");
  Serial.println(Sensor2);
  
  if((Sensor1 > BLACK) && (Sensor2 < WHITE)){ 
    frente();
  }
  if((Sensor1 > BLACK) && (Sensor2 > BLACK)){ 
    direita();
    }
  if((Sensor1 < BLACK) && (Sensor2 < BLACK)){
    esquerda();
  }
}
