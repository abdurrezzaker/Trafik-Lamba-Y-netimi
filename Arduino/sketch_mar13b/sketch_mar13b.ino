int L_N_Red = 8;
int L_N_Yellow = 9;
int L_N_Green = 10;
int L_S_Red = 11;
int L_S_Yellow = 12;
int L_S_Green = 13;
int button_N = 2;
int button_S = 3;
int state_button_N = 0;
int state_button_S = 0;
int cState = 0;

void setup() {
  pinMode(L_N_Red, OUTPUT);
  pinMode(L_N_Yellow, OUTPUT);  
  pinMode(L_N_Green, OUTPUT);
  pinMode(L_S_Red, OUTPUT);
  pinMode(L_S_Yellow, OUTPUT);  
  pinMode(L_S_Green, OUTPUT);
  pinMode(button_N, INPUT);
  pinMode(button_S, INPUT);
  attachInterrupt(digitalPinToInterrupt(button_N), button_kesme_N, HIGH);
  attachInterrupt(digitalPinToInterrupt(button_S), button_kesme_S, HIGH);

}
void button_kesme_N(){
  state_button_N ++;
}
void button_kesme_S(){
  state_button_S ++;

}
void constant_state(){
  if(cState == 0){
    digitalWrite(L_N_Red, HIGH);
    digitalWrite(L_S_Green, HIGH);
  }else{
    digitalWrite(L_N_Green, HIGH);
    digitalWrite(L_S_Red, HIGH);
  }

}
void loop() {

    constant_state();

    if((state_button_N > state_button_S) && (state_button_N > 19)){
      north_road_green();
      state_button_N = 0;
      state_button_S = 0;
    }else if((state_button_S > state_button_N) && (state_button_S > 19)){
      south_road_green();
      state_button_N = 0;
      state_button_S = 0;*
    }


}
void north_road_green(){
  digitalWrite(L_S_Yellow, HIGH);
  digitalWrite(L_N_Yellow, HIGH);
  delay(2000);
  digitalWrite(L_S_Green, LOW);
  digitalWrite(L_S_Yellow, LOW);
  digitalWrite(L_S_Red, HIGH);
  delay(1000);
  digitalWrite(L_N_Yellow, LOW);
  digitalWrite(L_N_Red, LOW);
  digitalWrite(L_N_Green, HIGH);
  delay(5000);
  cState = 1;


}
void south_road_green(){
  digitalWrite(L_N_Yellow, HIGH);
  digitalWrite(L_S_Yellow, HIGH);
  delay(2000);
  digitalWrite(L_N_Green, LOW);
  digitalWrite(L_N_Yellow, LOW);
  digitalWrite(L_N_Red, HIGH);
  delay(1000);
  digitalWrite(L_S_Yellow, LOW);
  digitalWrite(L_S_Red, LOW);
  digitalWrite(L_S_Green, HIGH);
  delay(5000);
  cState = 0;
  
}












