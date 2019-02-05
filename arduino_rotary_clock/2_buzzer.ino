// piezoelectric passive buzzer

#define PWM_PIN 10

static uint8_t tune = 50;
static bool SoundTrigger = OFF;

void confirmation_sound( void ) {
  static unsigned long pms;
  if ( SoundTrigger ) {
    pms = millis();
    analogWrite( PWM_PIN,tune );
    SoundTrigger = OFF;
  }
  if ( millis() - pms > 20 ) analogWrite( PWM_PIN,255 );
}

unsigned int frequency = 4000;
float duty = 0.1;

void piezo_alarm( void ) {
  TCCR1A = 0b00100001;
  TCCR1B = 0b00010010;
  OCR1A = ( uint16_t )( 1000000 / frequency );
  OCR1B = ( uint16_t )( 1000000 / frequency * duty );
}
