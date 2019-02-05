//    Arduino rotary clock ( Wake up alarm does not work but confirmation sound is available )
//
//    2018 Dec 28 Fri'
//    MT 17:32:43 21˚C
//
//    https://youtu.be/HsTXarwsVWQ

void setup() {
  setup_lcd();
  setup_rtc();
  setup_EEPROM();
  setup_encoder();
  piezo_alarm();
}

void loop( ) {
  check_switch_condition();
  long_push_timer();
  release_timer();
  event_dispatcher();
  confirmation_sound();
  display_clock();
}

#define ON  true
#define OFF false
