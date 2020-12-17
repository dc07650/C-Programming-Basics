#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592
#define X_MAX 51
#define Y_MAX 26

char coord[X_MAX][Y_MAX];
char ans;

double increment = 30;
double angle = 0;
double x, y;

int main() {
	
reStart:

	for (int i = 0; i < X_MAX; i++) {			//Initialization
		for (int j = 0; j < Y_MAX; j++) {
			coord[i][j] = '.';
		}
	}
	
	printf("Circle Plot Program with Interactive Increment\n\n");
	printf("Enter angle increment value: ");

	scanf("%lf", &increment);
	printf("Angle increment: %.0lf degree\n", increment);

	int repeat = trunc((360.0 / increment));

	for (int i = 0; i < repeat; i++) {			//Calculate coordinates
		angle += increment;
		x = (sin(angle *(PI / 180)) + 1.0) * (double)(X_MAX) / 2.0;
		y = (cos(angle *(PI / 180)) + 1.0) * (double)(Y_MAX) / 2.0;
		coord[(int)(x)][(int)(y)] = '*';
	}


	for (int j = Y_MAX - 1; j >= 0; j--) {
		printf("%2d\t", j);
		for (int i = 0; i < X_MAX ; i++) {
			printf("%c", coord[i][j]);
		}
		printf("\n");
	}


	while (1) {
		getchar();
		printf("\nRestart program? (Y/N): ");
		scanf("%c", &ans);

		switch (ans) {
		case 'Y': case 'y':
			system("Cls");
			goto reStart;
			break;
		case 'N': case 'n':
			goto termProg;
			break;
		default:
			printf("Error::Unidentified command, please re-enter");
		}

	}

termProg:
	return 0;


}
