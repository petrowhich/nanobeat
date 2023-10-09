/*
   Macros
*/
#define arrayLength(a) (sizeof(a) / sizeof(a[0]))

/*
   Constants
*/
#define SPK_PIN 12
#define POWER_LED_PIN 13
#define BPM 100

/*
   Pattern, timing and playback
*/
const int drumPattern[] = {
  1, 0, 1, 0, 1, 1, 0, 0
};
const size_t drumPatternLength = arrayLength(drumPattern);
const int estimatedTimeMs = 35;
const float noteDelayMs = 60000.0 / float(BPM * 2) - estimatedTimeMs;
#define drumHit tone(SPK_PIN, 125, estimatedTimeMs)
#define skipHit delay(estimatedTimeMs)

/*
   Arduino functions
*/
void setup()
{
  pinMode(SPK_PIN, OUTPUT);
  pinMode(POWER_LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(POWER_LED_PIN, HIGH);
  for (size_t i = 0; i < drumPatternLength; i++)
  {
    if (drumPattern[i])
      drumHit;
    else
      skipHit;

    delay(noteDelayMs);
  }
}
