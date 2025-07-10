#include <stdio.h>
int main() {
float a, b, som;
char op;

	printf("Entrer Le premier nombre : \n");
	scanf("%f", &a);
	printf("Entrer Le deuxieme nombre : \n");
        scanf("%f", &b);
	printf("Entrer votre operateur : (+) (-) (*) (/) \n");
	scanf(" %c", &op);
	
	switch (op) {
	
		case ('+') :
		        som = a + b;
			printf("%.2f\n", som);
 			break;			
		case ('-') :
			som = a - b;
			printf("%.2f\n", som);
			break;
		case ('*') :
                        som = a * b;
                        printf("%.2f\n", som);                 
                	break;
		case ('/') :
                        som = a / b;
                        if (b != 0) {
			printf("%.2f\n", som);}
       			else{
			printf("La division par 0 est impossible \n");
			}			
                	break;

		default : printf("L'operateur est incorrecte \n");
			break;
	}
	return 0;
}
