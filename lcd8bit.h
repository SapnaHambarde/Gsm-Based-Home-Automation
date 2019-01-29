sfr LCD = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
void lcd_cmd(unsigned char cmd)
{
	LCD = cmd;
	RS = 0;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0;
}
void lcd_data(unsigned char d)
{
	LCD = d;
	RS = 1;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0;
}
 void lcd_string(char *s)
 {
 int c=0;
  	 while(*s)
	 {		if(c==16)
	 			lcd_cmd(0xc0);
			lcd_data(*s++);	
			c++;	
	}
 }
void lcd_init()
{
	lcd_cmd(0x02);
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
}
/*void lcd_int(int n)
{
	int i=0;
	char buf[6];
	if(n==0)
		lcd_data(0+48);
	for(;n;n=n/10)
		buf[i++] = n%10+48;
	buf[i]='\0';
	for(i=0;buf[i];i++);
	for(i=i-1;i>=0;i--)
		lcd_data(buf[i]);
} */
/*void lcd_float(float f)
{
	int j,n=f;
	if(n<0)
		lcd_data(0+48);
	else
		lcd_int(n);
	f=f-n;
	lcd_data('.');
	for(j=0;j<2;j++)
	{
		f=f*10;
		n=f;
		lcd_int(n);
		f=f-n;
	}
} */

