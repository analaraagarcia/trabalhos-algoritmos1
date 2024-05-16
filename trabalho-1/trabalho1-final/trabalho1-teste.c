#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main(){
	
	int i=1;
	int opFuncao=0;		//escolha da funcao que quer calcular
	int opAng=0; 		//escolha do angulo em graus ou radianos
	int opPI=0;			//escolha do angulo com pi ou sem pi
	double angGrau;		//angulo em grau
	double angRad;		//angulo em rad
	double numerador;	//numerador do angulo em rad
	double denominador; //denominador do angulo em rad
	double arco;		//valor do seno, cosseno ou tangente para calcular os arcos
	double seno=0, cosseno=0, tangente=0;
	
	
	
	printf("\nCalculadora de funcoes trigonometricas!\n");
	printf("\n----------------------------------------\n\n");
	
while(i==1){
	

	//MENU DE ESCOLHA DE FUNCAO

	printf("\nO que voce deseja calcular?\n\n");
	printf("\t1-seno\n\t2-cosseno\n\t3-tangente\n\t4-secante\n\t5-cossecante\n\t6-cotangente\n\t7-arco seno\n\t8-arco cosseno\n\t9-arco tangente\n");
	printf("\nDigite sua opcao: ");
	scanf("%d", &opFuncao);
	
	while (opFuncao<1 || opFuncao>9){
		printf("\nOpcao invalida, digite novamente: ");
		scanf("%d", &opFuncao);
	}
	
	switch (opFuncao){
		
		//se escolher calcular seno, cosseno....
		case 1: case 2: case 3: case 4: case 5: case 6:
			while (opAng!=1 && opAng!=2){
				printf("\nO angulo eh em 1-graus ou 2-radianos ? ");
				scanf("%d", &opAng);
			}
			
			//se o angulo for em RADIANOS
			if (opAng==2){
		
				while (opPI!=1 && opPI!=2){
					printf("\nO angulo possui pi? 1-Sim, 2-Nao: ");
					scanf("%d", &opPI);	
				}
				
				//se o angulo tiver pi, vai multiplicar o valor de entrada por pi
				if (opPI==1){
					printf("\nDigite o numerador (sem pi): ");
					scanf("%lf", &numerador);
					printf("\nDigite o denominador: ");
					scanf("%lf", &denominador);

					while (denominador==0){
						printf("Divisao por zero! Digite um denominador diferente de zero: ");
						scanf("%lf", &denominador);
						if (denominador!=0){
							break;
						}
					}
					
					angRad = numerador*PI/denominador;
			
				} else if (opPI==2){
					printf("\nDigite o angulo em radianos: ");
					scanf("%lf", &angRad);

				}	
		
			//se o angulo for em GRAUS
			}else if (opAng==1){
		
				printf("\nDigite o angulo em graus: ");
				scanf("%lf", &angGrau);
				angRad = angGrau*PI/180.0;
				angGrau = angRad*180.0/PI;
			}
			
			opAng=0;
			
			seno=sin(angRad);
          	cosseno=cos(angRad);
          	tangente=tan(angRad);
			
			switch (opFuncao) {
				
	    		//SENO
	    		case 1:
					printf("\nO valor do seno eh %.3lf\n", seno);
					break;
					
				//COSSENO
				case 2:
					printf("\nO valor do cosseno eh %.3lf\n", cosseno);
					break;
					
				//TANGENTE
				case 3:
					if(tangente > 58) {
	    				printf("\nO valor da tangente nao eh determinado\n");
	    			
					}else {
						printf("\nO valor da tangente eh %.3lf", tangente);
					}
					
					break;
				
				//SECANTE	
				case 4:
					if(fabs(cosseno) < 1e-6) {
	     			printf("\nO valor da secante nao eh determinado\n");
	     			
					}else {
	    				printf("\nO valor da secante eh %.3lf", 1/cosseno);
					}
					break;
					
				//COSSECANTE	
				case 5:
					if(fabs(seno) < 1e-6) {
	     				printf("\nO valor da cossecante nao eh determinado\n");
	     				
					}else if (seno!=0){
	    				printf("\nO valor da cossecante eh %.3lf", 1/seno);
					}
					break;
				
				//COTANGENTE
				case 6:
					if(tangente < 1/tan(89*PI/180.0)) {
	     				printf("\nO valor da cotangente nao eh determinado\n");
	     				
					}else {
	    				printf("\nO valor da cotangente eh %.3lf",cosseno/seno);
					}
					break;
			} 
			
			break;
		
		//se escolher calcular um arco	
		case 7: case 8: case 9:
			if (opFuncao==7){
				printf("\nDigite o valor do seno do arco: ");
				
			}else if (opFuncao==8){
				printf("\nDigite o valor do cosseno do arco: ");
				
			}else if (opFuncao==9){
				printf("\nDigite o valor da tangente do arco: ");
				
			}
			scanf("%lf", &arco);
			
			//COLOCAR OS ARCOS!!!
			switch (opFuncao){
				//ARCO SENO
				case 7:
					printf("\nO arco seno eh igual a %.3lf radianos ou %.3lf graus", asin(arco), asin(arco)*180.0/PI);
					break;
					
				case 8:
					printf("\nO arco cosseno eh igual a %.3lf radianos ou %.3lf graus", acos(arco), acos(arco)*180.0/PI);
					break;
				
				case 9:
					printf("\nO arco tangente eh igual a %.3lf radianos ou %.3lf graus", atan(arco), atan(arco)*180.0/PI);
					break;
				
			}
			
			break;
			
	}
	
	opPI=0;

	printf("\n\nAperte 1 para continuar ou qualquer tecla para sair: ");
	scanf("%d", &i);
	
	
	if (i!=1){
		printf("\n\tObrigada! Ate mais...\n");
	}
	
}
	return 0;
}