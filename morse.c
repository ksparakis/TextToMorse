#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define COUNT 100
#define TIME 100000 //Time T in milliseconds for time values
FILE *fvalue;
const int dot_on_time = TIME;
const int dash_on_time = 3*TIME;
const int off_in_letter = TIME;
const int between_letters =3*TIME;
const int between_words = 7*TIME;



int writeOnce(char *fname, char *data)
{
	FILE *f;
	if(f=fopen(fname,"w")){
		fprintf(f,"%s",data);
		fclose(f);
	}else{
		fprintf(stderr,"Failed to open %s\n", fname);
	}
}
void inletter()
{
	gpioW(0);
	usleep(off_in_letter);
}
void gpioW(int value)
{
	fprintf(fvalue,"%d",value);
	fflush(fvalue);
}

void dot()
{
 	 gpioW(1);
 	 usleep(dot_on_time);
}

void dash()
{
	gpioW(0);
	usleep(dash_on_time);
}



int main(int argc, char *argv[]){
       //	FILE *fvalue;
	int i, value;
	char msg[256];
	if(argc!=2){
		fprintf(stderr,"Usage of %s \" String to output as morse code \"\n", argv[0]);
		exit(-1);
	}

	strcpy(msg,argv[1]);
writeOnce("/sys/class/gpio/export","17");
writeOnce("/sys/class/gpio/gpio17/direction","out");
fvalue=fopen("/sys/class/gpio/gpio17/value","w");

// Sleep time values
value = 0;


//initiialer makes sure that the first time running through there is no sleep
int initialer =0;


//loops through each character and plays appropriate response
//using while loop because length of msg is not known and this will loop until null is detected
 i=0;
while(msg[i]){
    
    
    if(msg[i]==' ')
	{
        //does nothing if space this is taken care of in switch statement
	}
	else if(initialer =0)
	{
        //does nothing if first time running loop
	}
	else{
        // sleeps bettween letters
		usleep(between_letters);
	}
	initialer =1;
	printf("Blinking Letter: %c\n",msg[i]);

	switch(msg[i])
	{	
		case' ':
		gpioW(0);
		usleep(between_words);	
		break;

		case 'a': case 'A':
		dot();
		inletter();
		dash();
		
		break;
		
		case 'b': case'B':
		dash();
		inletter();
		dot();
		inletter();
		dot();
		inletter();
		dot();
		break;
		
		case 'c':case'C':
		dash();
		inletter();
		dot();
		inletter();
		dash();
		inletter();
		dot();
		break;
		
		case 'd':case'D':
		dash();
		inletter();
		dot();
		inletter();
		dot();
		break;
		
		case 'e':case'E':
		dot();
		break;
		
		case 'f':case'F':
		dot();
		inletter();
		dot();
		inletter();
		dash();
		inletter();
		dot();
		break;
	
		case 'g':case'G':
		dash();
		inletter();
		dash();
		inletter();
		dot();
		break;
	
		case 'h':case'H':
		dot();inletter();dot();inletter();dot();inletter();dot();
		break;
		
		case 'i':case'I':
		dot();inletter();dot(); 
		break;
		
		case 'j':case'J':
		dot();inletter();dash();inletter();dash();inletter();dash();
		break;
		
		case'k':case'K':
		dash();inletter();dot();inletter();dash();
		break;
		
		case'l':case'L':
		dot();inletter();dash();inletter();dot();inletter();dot();
		break;
		
		case'm':case'M':
		dash();inletter();dash();
		break;
		
		case'n':case'N':
		dash();inletter();dot();
		break;

		case'o':case'O':
		dash();inletter();dash();inletter();dash();
		break;

		case'p':case'P':
		dot();inletter();dash();inletter();dash();inletter();dot();
		break;

		case'q':case'Q':
		dash();inletter();dash();inletter();dot();inletter();dash();
		break;

		case'r':case'R':
		dot();inletter();dash();inletter();dot();
		break;
		
		case's':case'S':
		dot();inletter();dot();inletter();dot();
		break;

		case't':case'T':
		dash();
		break;

		case'u':case'U':
		dot();inletter();dot();inletter();dash();
		break;

		case'v':case'V':
		dot();inletter();dot();inletter();dot();inletter();dash();
		break;

		case'w':case'W':
		dot();inletter();dash();inletter();dash();
		break;

		case'x':case'X':
		dash();inletter();dot();inletter();dot();inletter();dash();
		break;

		case'y':case'Y':
		dash();inletter();dot();inletter();dash();inletter();dash();
		break;

		case'z':case'Z':
		dash();inletter();dash();inletter();dot();inletter();dot();
		break;
		
		default:
		 printf("Error: Char %c is not defined.\n", msg[i]);
		break;
	}
	i++;	
}
dash();
fclose(fvalue);
writeOnce("/sys/class/gpio/unexport","17");
}
