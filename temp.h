
char temp_re[6];
sbit M1=P1^2;
sbit M2=P1^3;
float temp1;

void temp_read()
{
  int temp,i; 
  float temprature;
  char counter,slope;
	
  i2c_device_write(0x90,0xA1,0x23);
  i2c_device_write(0x90,0xA2,0xA);
  i2c_device_write(0x90,0xAC,0x2);
  i2c_device_write(0x90,0xEE,0x0); 

  temp=i2c_device_read(0x90,0xAA);
  counter=i2c_device_read(0x90,0xA9);
  slope=i2c_device_read(0x90,0xA8);


  temprature=temp-0.25+(slope-counter)/slope;
  temp1=temprature;

  sprintf(temp_re,"%f",temprature);
  lcd_cmd(0xC0);
  lcd_string("T:");
  i=temprature;
  temprature=temprature-i;
  lcd_data(i/10+48);
  lcd_data(i%10+48);
  lcd_data('.');
  i=temprature*100;
  lcd_data(i/10+48);
  lcd_data(i%10+48);
	
}

void motor()
{  
	 temp_read();
   if(temp1<=30.0 && temp1<=35.0)
   {		 
	   M1=0;
     delay_ms(100);
     M2=1;
	 }
	 else if(temp1<=25.0 && temp1<=29.99)
   {		 
	   M1=0;
     delay_ms(300);
     M2=1;
	 }
} 
