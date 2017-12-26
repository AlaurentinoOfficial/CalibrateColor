#define COLOR_GREEN 22
#define COLOR_RED 23

#define BLACK_COLOR 0
#define WHITE_COLOR 1
#define GREEN_COLOR 2

int pins[5] = {A0, A1, A2, A2, A3};

// lim(verde) = (v+b)/2
// lim(branco) = b-50

void setup()
{
  Serial.begin(9600);
  pinMode(COLOR_GREEN, OUTPUT);
  pinMode(COLOR_RED, OUTPUT);
}

void loop()
{
  limits();
  delay(30000);
  Serial.println("");
}

void limits()
{
  Serial.println("Put in green plan");
  delay(5000);
  
  int g[2][5] = {{0,0,0,0,0}, {0,0,0,0,0}};
  int r[2][5] = {{0,0,0,0,0}, {0,0,0,0,0}};

  for(int i = 0; i < 2; i++)
  {
    delay(5000);
    digitalWrite(COLOR_GREEN, HIGH);
    digitalWrite(COLOR_RED, LOW);
    delay(20);
  
    for(int j = 0; j < 5; j++)
    {
      g[i][j] = analogRead(pins[i]);
    }


    Serial.println("Put in white plan");
    delay(5000);
    
    digitalWrite(COLOR_GREEN, HIGH);
    digitalWrite(COLOR_RED, LOW);
    delay(20);
  
    for(int j = 0; j < 5; j++)
    {
      r[i][j] = analogRead(pins[i]);
    }
  }

  int g_lim[5] = {0,0,0,0,0};
  int w_lim[5] = {0,0,0,0,0};

  for(int j = 0; j < 5; j++)
  {
    g_lim[j] = abs((g[0][j] + g[1][j])/2);
    w_lim[j] = abs(r[1][j] - 75);
  }

  Serial.println("Values");

  Serial.println("Green env:");
  Serial.print("Green: "); draw(g[0]);
  Serial.print("Red: "); draw(r[0]);
  
  Serial.println("White env:");
  Serial.print("Green: "); draw(g[1]);
  Serial.print("Red: "); draw(r[1]);

  Serial.println("\nLimits");
  Serial.print("Green: "); draw(g_lim);
  Serial.print("Red: "); draw(w_lim);
}

void draw(int list[])
{
  int count = sizeof(list)/sizeof(int);
  
  Serial.print("{");
  for(int i = 0; i < count; i++)
  {
    Serial.print(analogRead(list[i]));

    if(i != count)
    {
      Serial.print(", ");
    }
  }
  Serial.println("}");
}
