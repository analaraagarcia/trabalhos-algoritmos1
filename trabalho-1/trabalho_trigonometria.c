#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main(){
	
	int grauOuRad=0;
	double angRad, angulo;
	
	printf("\nCalculadora de funcoes trigonometricas!\n");
	printf("\n----------------------------------------\n\n");
	
	while (grauOuRad!=1 && grauOuRad!=2){
		printf("O angulo eh em 1-graus ou 2-radianos ? ");
		scanf("%d", &grauOuRad);
	}
	
	if (grauOuRad==2){
		printf("Digite o angulo desejado (digite 'PI' se quiser usar o valor de pi): ");
		scanf("%lf", &angulo);
		angRad = angulo;
	}else if (grauOuRad==1){
		printf("Digite o angulo desejado: ");
		scanf("%lf", &angulo);
		angRad = angulo*PI/180.0;
	}
	
	
	printf("\n\tsen(%.2lf) = %.3lf\n", angulo, sin(angRad));
	printf("\tcos(%.2lf) = %.3lf\n", angulo, cos(angRad));
	printf("\ttg(%.2lf) = %.3lf\n", angulo, tan(angRad));
	printf("\tcossec(%.2lf) = %.3lf\n", angulo, 1/sin(angRad));
	printf("\tsec(%.2lf) = %.3lf\n", angulo, 1/cos(angRad));
	printf("\tcotg(%.2lf) = %.3lf\n", angulo, 1/tan(angRad));
	
	return 0;
}