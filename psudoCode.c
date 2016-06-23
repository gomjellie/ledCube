#include <wiringPi.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t thread1;
pthread_t thread2;

void* slAnimation(void *arg){
//	system("sl");
//	system("grep -r sl /");
}

void controlLayer(int _in);
void controlNode(int _in);
void* cubeControl(void *arg);

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
	},
	{
		1,1,1,1,
		0,1,1,0,
		0,1,1,0,
		1,0,0,1,
	},
	{
		1,0,0,1,
		0,1,1,0,
		0,1,1,0,
		1,0,0,1,
	},
	{
		1,1,1,1,
		1,0,0,1,
		1,0,0,1,
		1,1,1,1,
	}
}
;
/*int array[4][16]={
	{
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1,1,1, 
	},
	{
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
	},
	{
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
	},
	{
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
	}
};
*/


int main(void){
	pthread_create(&thread1, NULL, slAnimation, NULL);
	pthread_create(&thread2, NULL, cubeControl, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	
	//cubeControl();
/*	int i,j;
	int a;

	wiringPiSetup();
	for(i=0;i<4;i++) pinMode(layer[i], OUTPUT);

	for(i=0;i<9;i++) pinMode(node[i], OUTPUT);
//	pinMode(21,OUTPUT);

//pinMode(1, INPUT);
	while(1){
		for(j=180;j>10;j-=5){
			for(i=0;i<4;i++){
				delay(j);
				controlNode(i);
				controlLayer(i);

			}
		}
		//delay(1000);
		for(j=10;j<180;j+=5){
			for(i=0;i<4;i++){
				delay(j);
				controlNode(i);
				controlLayer(i);

			}
		}
	}*/
	return 0;
}

void* cubeControl(void *arg){
	int i,j;
	int a;

	wiringPiSetup();
	for(i=0;i<4;i++) pinMode(layer[i], OUTPUT);

	for(i=0;i<9;i++) pinMode(node[i], OUTPUT);
	//	pinMode(21,OUTPUT);

	//pinMode(1, INPUT);
	while(1){
		for(j=180;j>10;j-=5){
			for(i=0;i<4;i++){
				delay(j);
				controlNode(i);
				controlLayer(i);

			}
		}
		//delay(1000);
		for(j=10;j<180;j+=5){
			for(i=0;i<4;i++){
				delay(j);
				controlNode(i);
				controlLayer(i);

			}
		}
	}
}

void controlNode(int _in){
	int i;
	for(i=0;i<9;i++){
		if(array[_in][i]==1)	digitalWrite(node[i], HIGH);
		else digitalWrite(node[i], LOW);
	}
}

void controlLayer(int _in){
	int i=0;
	for(i=0;i<4;i++) {
		if(_in==i)	
			digitalWrite(layer[i], LOW);
		else 
			digitalWrite(layer[i], HIGH);
	}
}
