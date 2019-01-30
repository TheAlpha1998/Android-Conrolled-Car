#define in1 12
#define in2 11
#define in3 8
#define in4 7
#define ena1 6
#define ena2
char data;
int in1 = 12;
int in2 = 11;
int in3 = 8;
int in4 = 7;
int ena1= 6;
int ena2= 5;
void setup() {
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(1, OUTPUT); 
  pinMode(0, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena1, OUTPUT);
  pinMode(ena2, OUTPUT);
}

void loop() {
  if (Serial.available()>0)
  {
    data = Serial.read();
    Serial.println(data);
    if (data == '0')
    { // STOP THE CAR
      digitalWrite (in1, LOW);
      digitalWrite (in2, LOW);
      digitalWrite (in3, LOW);
      digitalWrite (in4, LOW);
    }
    
    else if (data == '1')
    { // FORWARD DIRECTION
      analogWrite(6, 120);
      analogWrite(5, 120);  
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (in3, LOW );
      digitalWrite (in4, HIGH);
    }
    
    else if (data == '2')
    { // LEFT DIRECTION
      analogWrite(6, 60);
      analogWrite(5, 120);        
      analogWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (in3, LOW);
      digitalWrite (in4, HIGH);
   
      
    }
    else if (data == '3')
    { // RIGHT DIRECTION
      analogWrite(6, 120);
      analogWrite(5, 60);  
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (in3, LOW);
      digitalWrite (in4, HIGH);
    }
    else if (data == '4')
    { // BACKWARD DIRECTION
      analogWrite(6, 120);
      analogWrite(5, 120);  
      digitalWrite (in1, LOW);
      digitalWrite (in2, HIGH);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);

    }
  }
}
