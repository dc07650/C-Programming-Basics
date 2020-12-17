/*
[Title]		: Simulator for FiFo and Stack data structure
[Programmer]: Choi Won Bin (wt. 3 members)
[Date]		: May 15th, 2018
[Version]	: 2.3.1
*/
//Edit the preprocessor option as : [challenge3 우클릭] - [속성] - [C/C++] - [전처리기] - [전처리기 정의] - : _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define CLEAR_n
#define WATCHDOG_n
#define INITIAL_n

typedef enum { false, true } bool;

struct DATA
{
	int item;
	bool header;
};

typedef struct DATA node;

void help();

int decode(char*);

bool initial = 1, sInitial = 1;
int wp = 0, rp = 0, count = 0, sp = 0, sCount = 0;
int data = 0;

int main() {
	system("color F0");
	node link[MAX] = { 0, }, sLink[MAX] = { 0, };
	char command[5];

	system("title Simulator for FiFo and Stack data structure - A.L. [Ver 2.3.1]");
	printf("Enter command and data (for help, enter '?', for termination, enter 'exit') \n");
	while (1) {

#ifdef INITIAL_
		printf("[ FiFo:%d | ", initial);
		printf("Stack:%d ]", sInitial);
#endif // INITIAL

		while (1) {
			printf(">> ");
			scanf("%s", command);

			if (!strcmp(command, "?")) {
				help();
				continue;
			}
			break;
		}

		switch (decode(command)) {
		case 1:
			if (count >= MAX) {					//Overflow check (Max out)
				printf("Overflow_Error\n");
				break;								//No more input
			}

			if (wp >= MAX)
				wp = 0;

			if (initial == 1) {					//If the value is considered first input, then it's a header
				link[wp].header = true;
				initial = 0;						//The others are not inital
			}

			scanf("%d", &data);
			link[wp].item = data;
			wp++;	count++;

			
			break;

		case 2:
			if (count <= 0) {					//When all data is sorted out, then there is no more which makes the next input initial
				printf("Underflow_Error\n");
				initial = 1;
				break;
			}
			if (rp >= MAX)							//Underflow error patch
				rp = 0;

			data = link[rp].item;
			
			link[rp].item = 0;
			int nextP;								//
			nextP = rp + 1;							//
			if (nextP > MAX - 1)					//This part recieves the current read position and sends over the header mark to the next node.
				nextP = 0;							//Just in case the read point is in overflow, it resets the nextP to zero
			link[nextP].header = link[rp].header;	//
			link[rp].header = false;				//

			if (count - 1 <= 0) {					//To check initiality. As you take out the data from the structure, 
				initial = 1;						//there must be a state where all the data is emptied. Thats when count is 1 before the decrement
			}

			printf("%d\n", data);
				
			rp++; count--;
			
			
			
			break;

		case 3:
			if (sCount >= MAX) {
				printf("Overflow_StackError\n");
				break;
			}
			if (sInitial == 1) {
				sLink[sp].header = true;
				sInitial = 0;
			}
			scanf("%d", &data);
			sLink[sp].item = data;
			sp++; 
			sCount++;

			break;
		case 4:
			if (sCount <= 0) {
				printf("Underflow_StackError\n");
				sInitial = 1;
				break;
			}
			sp--;

			data = sLink[sp].item;
			sLink[sp].item = 0;
			if (sCount - 1 <= 0) {					//To check initiality
				sInitial = 1;
			}
			sCount--;

			printf("%d\n", data);
			break;
		case 5:
			printf("FiFo data: \n\t");
			
			int startp = 0;
			for (int i = 0; i < MAX; i++) {
				if (link[i].header == true) {
					startp = i;
				}
			}
			for (int i = 0; i < MAX; i++) {
				if (startp >= MAX) {
					startp = 0;
				}
				
				printf("%d", link[startp].item);
				
#ifdef WATCHDOG_
				printf("%d | %d", link[startp].item, link[startp].header);
#endif // WATCHDOG_

				if (i != MAX - 1)
					printf(" -> ");
				startp++;
			}
			printf("\n");

			printf("Stack data: \n\t");
			
			startp = MAX - 1;
			for (int i = 0; i < MAX; i++) {
				if (sLink[i].header == true) {
					startp = MAX - ( i + 1 );
				}
			}
			for (int i = MAX - 1; i >= 0; i--) {
				if (startp < 0) {
					startp = MAX - 1;
				}
				
				printf("%d", sLink[startp].item);
#ifdef WATCHDOG_
				printf("%d | %d", sLink[startp].item, sLink[startp].header);
#endif //WATCHDOG_
				if (startp != 0)
					printf(" -> ");
				startp--;
			}
			printf("\n");

			break;
		case 0:
			return;
		default:
			printf("Invalid command\n");
		}

#ifdef CLEAR_
		system("Pause");
		system("cls");
#endif // DEBUG

	}
	system("Pause");
	return 0;
}

void help() {
	printf("FI: FiFo Input - FI (num)\n");
	printf("FO: FiFo Output data\n");
	printf("SI: Stack Input - SI (num)\n");
	printf("SO: Stack Output data\n");
	printf("SHOW: FiFo/Stack data display\n");
}

int decode(char *_input) {
	if (!strcmp(_input, "FI") || !strcmp(_input, "fi")) {
		return 1;
	}
	if (!strcmp(_input, "FO") || !strcmp(_input, "fo")) {
		return 2;
	}
	if (!strcmp(_input, "SI") || !strcmp(_input, "si")) {
		return 3;
	}
	if (!strcmp(_input, "SO") || !strcmp(_input, "so")) {
		return 4;
	}
	if (!strcmp(_input, "SHOW") || !strcmp(_input, "show")) {
		return 5;
	}
	if (!strcmp(_input, "exit")) {
		return 0;
	}
	return -1;
}