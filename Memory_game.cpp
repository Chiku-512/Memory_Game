#include<Arduino.h>
int LED[]={3,4,5,6};
int button[]={7,8,9,10};
#define buzzer 12
int level=1;
String memory="";
String ans="";
int wait_button_press()
    {
        while(true)
    {
        if(digitalRead(button[0])==HIGH) 
        {
            digitalWrite(LED[0],HIGH);
            digitalWrite(buzzer,HIGH);
            delay(50);
            digitalWrite(buzzer,LOW);
            delay(50);
            digitalWrite(LED[0],LOW);
            return button[0]; 
        }
        if(digitalRead(button[1])==HIGH) 
        {
            digitalWrite(LED[1],HIGH);
            digitalWrite(buzzer,HIGH);
            delay(50);
            digitalWrite(buzzer,LOW);
            delay(50);
            digitalWrite(LED[1],LOW);
            return button[1];
        }
        if(digitalRead(button[2])==HIGH) 
        {
            digitalWrite(LED[2],HIGH);
            digitalWrite(buzzer,HIGH);
            delay(50);
            digitalWrite(buzzer,LOW);
            delay(50);
            digitalWrite(LED[2],LOW);
            return button[2];
        }
        if(digitalRead(button[3])==HIGH) 
        {
            digitalWrite(LED[3],HIGH);
            digitalWrite(buzzer,HIGH);
            delay(50);
            digitalWrite(buzzer,LOW);
            delay(50);
            digitalWrite(LED[3],LOW);
            return button[3];
        }
        delay(10);
    }
    return 0;
    }
void setup()
{
    Serial.begin(115200);
    for(int i=0;i<4;i++)
    {
        pinMode(button[i],INPUT);
        pinMode(LED[i],OUTPUT);
        digitalWrite(LED[i],LOW);
    }
    pinMode(buzzer,OUTPUT);
    randomSeed(analogRead(A0));
}
void loop()
{
    Serial.println("Ready for Memory Game??");
    Serial.print("Level: ");
    Serial.println(level);
    delay(5000);
    for(int i=0;i<4;i++)
    {
        digitalWrite(LED[i],LOW);
    }
    int c=level*(level+1)/2;
    if(memory.length()!=0)
    {
        for(unsigned int i=0;i<memory.length();i++)
        {
            digitalWrite((int)memory[i]-48,HIGH);
            delay(300);
            digitalWrite((int)memory[i]-48,LOW);
            delay(500);
        }
    }
    while(c-(level-1)*level/2>0)
    {
        int random_led=random(LED[0],LED[3]+1);
        digitalWrite(random_led,HIGH);
        delay(500);
        digitalWrite(random_led,LOW);
        delay(300);
        memory+=(String)random_led;
        c--;
    }
    c=level*(level+1)/2;
    Serial.println("Now please enter your response by pressing the corresponding buttons");
    while(c>0)
    {
        int pressedbutton=wait_button_press();
        ans+=(String)(pressedbutton-4);
        while(digitalRead(pressedbutton)==HIGH)
            delay(20);
        c--;
        delay(20);
    }
    if(memory==ans)
    {
        Serial.print("Congrats!! on passing Level ");
        Serial.println(level);
        level++;
        ans="";
}
else {
    Serial.println("Game over");
     Serial.print("Score: ");
     Serial.println(level);
     while(true)
        delay(1000);
}
}