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
