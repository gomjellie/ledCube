#include <wiringPi.h>

void controlLayer(int _in);
void controlNode(int _in);

int layer[4]={//minus 
	7,0,2,3
};// temporary numbers
int node[16]={
	21,22,23,24,25,26,27,28,29
};

int array[4][16]={
	{
		1,1,1,1,
		1,0,0,1,
		1,0,0,1,
		1,1,1,1, 
	},{
		0,0,0,1,
		0,1,1,0,
		0,1,1,0,
		1,0,0,1,
	},{
		1,0,0,1,
		0,1,1,0,
		0,1,1,0,
		1,0,0,1,
	},{
		1,1,1,1,
		1,0,0,1,
		1,0,0,1,
		1,1,1,1,
	},
}
;

int main(void){
	int i,j;
	int a;

	wiringPiSetup();
	for(i=0;i<4;i++) pinMode(layer[i], OUTPUT);

	for(i=0;i<9;i++) pinMode(node[i], OUTPUT);
	pinMode(21,OUTPUT);

	//pinMode(1, INPUT);
	//while(1){
	for(i=0;i<4;i++){
		controlLayer(i);
		//			digitalWrite(21, HIGH);
		controlNode(i);

		//digitalWrite(layer[i],HIGH);
		delay(25);

		//digitalWrite(0,HIGH);
		//delay(500);
		//digitalWrite(0,LOW);
		//delay(500);
	}
	//}

	return 0;
}

void controlNode(int _in){
	int i;
	for(i=0;i<9;i++){
		digitalWrite(node[i], LOW);
	}
}

void controlLayer(int _in){
	int i=0;
	for(i=0;i<4;i++) {
		digitalWrite(layer[i], LOW);
	}
}
