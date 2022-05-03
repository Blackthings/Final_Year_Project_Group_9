void right(int spd, int dir) // Smart Elex
{
  if(dir == 1) //ccw
  {
    digitalWrite(26, LOW); //35
    //digitalWrite(24, LOW);
    //digitalWrite(26, HIGH);
  }
  else if(dir == 0 ) //cw
  {
    digitalWrite(26, HIGH);
    //digitalWrite(24, HIGH);
    //digitalWrite(26, LOW);
  }
  analogWrite(4, spd);
  
}


void left(int spd, int dir) // RIGHT // Hercules
{
  if(dir == 1) //ccw
  {
    digitalWrite(34, LOW);
    digitalWrite(32, HIGH);
  }
  else if(dir == 0)  //cw
  {
    digitalWrite(34, HIGH);
    digitalWrite(32, LOW);
  }
  analogWrite(5, spd);
  
}

void front(int spd, int dir) // LEFT
{ 
  if(dir == 1)  //ccw
  {
    digitalWrite(42, LOW);
    digitalWrite(40, HIGH);
  }
  else if(dir == 0) //cw
  {
    digitalWrite(42, HIGH);
    digitalWrite(40, LOW);
  }
  analogWrite(6, spd);
  
}

void stop_bot()
{
  front(0, 0);
  left(0, 0);
  right(0, 0);
  weed_motor(0,0);
//  Serial.print(f);
//  Serial.print(" ");
//  Serial.print(l);
//  Serial.print(" ");
//  Serial.print(r);
//  Serial.print(" ");
//  Serial.println();
}

void weed_motor(int spd, int dir) // Smart Elex
{
  
  if(dir == 1) //ccw
  {
    digitalWrite(26, LOW); //35
    //digitalWrite(24, LOW);
    //digitalWrite(26, HIGH);
  }
  else if(dir == 0 ) //cw
  {
    digitalWrite(26, HIGH);
    //digitalWrite(24, HIGH);
    //digitalWrite(26, LOW);
  }
  analogWrite(4, spd);
  

}
