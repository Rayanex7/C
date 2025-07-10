#include <stdio.h>
#include <math.h>

int main()
{
int a, b, c, delta;
	printf("Entrer la valeur de a :");
	scanf("%d", &a);
	printf("Entrer la valeur de b :");
        scanf("%d", &b);
	printf("Entrer la valeur de c :");
        scanf("%d", &c);
	delta = pow(-b, 2) - (4 * a * c);
	float x1, x2, x3;
		if(delta > 0)
		{
			printf("Δ = %d\n", delta);
			x1 = (-b-sqrt(delta)) / (2 * a);
			x2 = (-b+sqrt(delta)) / (2 * a);
			printf("L'equation a deux solution x1 = %.2f et x2 = %.2f \n", x1, x2);
		}
		else if(delta < 0)
		{
			printf("Δ = %d\n", delta);
			printf("L'equation n'admet aucune solution");

		}
		else 
		{
			printf("Δ = %d\n", delta);
			x3 = -b / (2 * a);
                        printf("L'equation a une unique solution x1 = %.2f \n", x3);
		}


return 0;
}
