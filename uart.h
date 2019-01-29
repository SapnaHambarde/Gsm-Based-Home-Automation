void uart_init()
{
	TMOD = 0x20;//timer 1 mode 2
	TH1 = 253;// TH1 = -3; //set 9600bps baudrate
	SCON = 0x50;//universal mode,REN = 1
	TR1 = 1;//start timer 1
}
void uart_tx(unsigned char ch)
{
	SBUF = ch;
	while(TI ==0);
	TI = 0;//vimp
}
unsigned char uart_rx()
{
	while(RI ==0);
	RI = 0;//vimp
	return SBUF;  
}
void uart_string(char *s)
{
	while(*s)
	{
		uart_tx(*s++);
  }
}
