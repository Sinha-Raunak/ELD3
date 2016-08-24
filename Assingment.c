#define PORT (*(volatile unsigned char *)0x25)
#define DDRB (*(volatile unsigned char *)0x24)
#define PIN_SET(x) (1 << (x))
#define GIVING_VALUE(dest_name , pin) (dest_name) |= PIN_SET(pin)
#define RESET(dest_name, pin) (dest_name) ^= PIN_SET(pin)


#ifdef F_CPU
#define F_CPU 16000000UL
#endif

void my_function_delay(unsigned long multiplier) {
  unsigned long i = 0;
  for (i = 0; i < multiplier; i++) {
      __asm__("nop");
  }
}


int main(){
  DDRB = GIVING_VALUE(DDRB,5);
  while(1){
    GIVING_VALUE(PORT,5);
    my_function_delay(2250000);
    RESET(PORT,5);
    my_function_delay(2250000);
  }
  return 0;
}

//450000 -- 1second 
//nop -- 6.25ns
