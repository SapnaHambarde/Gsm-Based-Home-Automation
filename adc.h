sbit clk=P2^7;
sbit dout=P2^6;
sbit din=P2^5;
sbit cs=P2^4;
char s[15];
unsigned int read_adc(bit d1,bit d0)
{
	unsigned int temp=0;
	char i;
	cs=0;
	
	clk=0;din=1;clk=1;//start bit
  clk=0;din=1;clk=1;//single ended mode selected
	clk=0;din=1;clk=1;//d2 is don't care in MPC3204
	
	//selecting channel
	clk=0;din=d1;clk=1;//d1
	clk=0;din=d0;clk=1;//d0 &start sampling
	
	clk=0;din=1;clk=1;//Tsample
	clk=0;din=1;clk=1;//Null bit
	
	for(i=11;i>=0;i--)
	{
		clk=0;
		if(dout==1)
		temp=temp|(1<<i);
		clk=1;
	}
	cs=1;
	return temp;
}

void adc_data(void)
{
  float temp,c=0;
  //char s[15];
	
//Voltage on uart with channel 0
  temp=read_adc(0,0);
  temp=temp*5.0/4095;
  sprintf(s,"%f",temp);
  //uart_string("\r\nVoltage:");
  //uart_string(s);
 // uart_string(" V\r\n");
	
//Current on uart with channel 1
  temp=read_adc(0,1);
  temp=temp/4095;
  sprintf(s,"%f",temp);
  //uart_string("\r\nCurrent:");
 // uart_string(s);
  //uart_string(" A\r\n");
	
//light intensity on uart with channel 2
  temp=read_adc(1,0);
  temp=((4095-temp)/4095)*100;
  sprintf(s,"%f",temp);
 // uart_string("\r\nLight Intensity:");
 // uart_string(s);
  lcd_cmd(0xc0+8);
  lcd_string("L:");
  lcd_string(s);
  //uart_string("\r\n");
	
}