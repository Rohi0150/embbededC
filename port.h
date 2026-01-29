#define a_dir *(volatile char * )0x21 
#define a_port *(volatile char * )0x22 
#define a_pin *(volatile char * )0x20 
#define b_pin *(volatile char * )0x23 
#define b_dir *(volatile char * )0x24 
#define b_port *(volatile char * )0x25 
void init_a(char s){
  a_dir = s;  
}
void init_b(char s){
  b_dir = s;  
}
void out_a(char s){
  a_port = s;
}
void out_b(char s){
  b_port = s;
}
char in_a(void ){
  return(a_pin);
}
char in_b(void ){
  return(b_pin);
}
void delay1(float x){
  for (volatile long int i =0 ;i <x*100000;i++);
}
void b_last(int x){
  if(x==0){

  }
  else {

  }
}