/*
wait for random amt of time
display something and start the clock
until anything is pressed, wait
when something is clicked, subtract the time and print
if they are too slow, then print too slow.
*/

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

void getchAlternative(){
	while(1){
		if(GetAsyncKeyState(VK_SPACE)){
			return;
		}
	}
}

int main(){
	int i,count,c,tot;
	clock_t start,end;
	srand(time(NULL));
	char color[20][20]={"blue","green","yellow","violet","purple","red","red","red"};
	while(1){
		system("cls");
		printf("Press <space> as soon as you see the word red");
		Sleep(1000);
		printf("\nPress <space> to start the test...\n");
		getchAlternative();
		count=tot=0;
		for(i=0;i<20;i++){
			c=rand()%8;
			Sleep(rand()%2000+500);
			if(c>4){
				count++;
				puts(color[c]);
				start=clock();
				while(1){
					if(GetAsyncKeyState(VK_SPACE)){
						if(clock()-start<=10){
							//printf("Glitched!!");
							continue;
						}
						break;
					}
				}
				end=clock();
				tot+=end-start;
			}
			else{
				puts(color[c]);
			}
		}
		if(count==0){
			printf("Test Glitched for some unknown reason. Please restart the program.");
			return 0;
		}
		printf("The average reaction time is: %dms\n",tot/count);
		Sleep(4000);
		puts("Press <space> to continue...");
		getchAlternative();
		//clrscr();
	}
}