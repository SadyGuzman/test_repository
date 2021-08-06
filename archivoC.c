#include <time.h>
#include <stdio.h>
#define filas 5
#define columnas 5
#define alumnos 63
#define cant_notas 11 //una columna mas para guardar el promedio
void crear_datos(int (*)[columnas]);
void imprimir_datos(int (*)[columnas]);
void promedio_pares(int (*)[columnas]);
void promedio_impares(int (*)[columnas]);
void posiciones_pares_impares(int (*)[columnas]);
void crear_notas(float (*)[cant_notas]);
void imprimir_notas(float (*)[cant_notas]);
void calcular_promedio(float (*)[cant_notas]);
void estadisticas(float (*)[cant_notas]);
void ordenar_datos(int (*)[columnas]);

void main(){
	int datos[filas][columnas];
	float notas[alumnos][cant_notas];
//Pregunta 1
/*
	crear_datos(datos);
	imprimir_datos(datos);
	promedio_pares(datos);
	promedio_impares(datos);
	posiciones_pares_impares(datos);
*/
	
//Pregunta 2
/*
	crear_notas(notas);
	calcula_promedio(notas);
	imprimir_notas(notas);
	estadisticas(notas);
*/
	
//Pregunta 3

	ordenar_fil(datos);
	imprimir_datos(datos);
	
	system("pause");
}
void ordenar_fil(int numeros[filas][columnas]){
	int maximo = filas*columnas, contador=1,contador2, f,c,sgte_f,sgte_c,aux;
	while(contador < maximo){
		contador2 = 1;c=0;f=0;sgte_f = f;sgte_c = c+1;
		while(contador2 < maximo){
			if(numeros[f][c]>numeros[sgte_f][sgte_c]){
				aux = numeros[f][c];
				numeros[f][c]=numeros[sgte_f][sgte_c];
				numeros[sgte_f][sgte_c]=aux;
			}
			c++;
			sgte_c++;
			if (sgte_c == columnas){
				sgte_c = 0;
				sgte_f = sgte_f + 1;
			}
			if(c == columnas){
				c = 0;
				f = f+1;
			}
			contador2++;
	    } 
	    contador++;
	}
}
void ordenar_col(int numeros[filas][columnas]){
	int maximo = filas*columnas, contador=1,contador2, f,c,sgte_f,sgte_c,aux;
	while(contador < maximo){
		contador2 = 1;c=0;f=0;sgte_f = f+1;sgte_c = c;
		while(contador2 < maximo){
			if(numeros[f][c]>numeros[sgte_f][sgte_c]){
				aux = numeros[f][c];
				numeros[f][c]=numeros[sgte_f][sgte_c];
				numeros[sgte_f][sgte_c]=aux;
			}
			f++;
			sgte_f++;
			if (sgte_f == filas){
				sgte_f = 0;
				sgte_c = sgte_c + 1;
			}
			if(f == filas){
				f = 0;
				c = c+1;
			}
			contador2++;
	    } 
	    contador++;
	}
}
void estadisticas(float notas[alumnos][cant_notas]){
	int i,j,suma_curso=0,pos_mayor=-1,pos_menor=-1,aprobados=0,reprobados=0;
	float valor,nota_mayor=-1.0,nota_menor = 8.0;
	i=0;
	while(i<alumnos){
		suma_curso = suma_curso + notas[i][10];
		if(notas[i][10]>3.9){
			aprobados++;
		}else{
			reprobados++;
		}
		if(notas[i][10]>nota_mayor){
			nota_mayor = notas[i][10];
			pos_mayor = i;
		}
		if(notas[i][10]<nota_menor){
			nota_menor = notas[i][10];
			pos_menor = i;
		}
		i++;
	}
	valor = (float)suma_curso/(float)alumnos;
	printf("\nPromedio del curso %3.1f\n",valor);
	printf("\nEl mejor alumno es %i y su nota es %3.1f\n",pos_mayor+1,notas[pos_mayor][10]);
	printf("\nEl peor alumno es %i y su nota es %3.1f\n",pos_menor+1,notas[pos_menor][10]);
	valor = ((float)aprobados/(float)alumnos)*100;
	printf("\nEl porcentaje de aprobados es %3.1f \n",valor);
	valor = ((float)reprobados/(float)alumnos)*100;
	printf("\nEl porcentaje de aprobados es %3.1f \n",valor);
}
void calcula_promedio(float notas[alumnos][cant_notas]){
	int i,j,suma;
	i=0;
	while(i<alumnos){
		j=0;printf("Alumno %2i ",i+1);
		while(j<cant_notas-1){
			suma = suma + notas[i][j];
			j++;
		}
		notas[i][j]=(float)suma/(float)10;
		suma =0;
		i++;
		printf("\n");
	}
}
void imprimir_notas(float notas[alumnos][cant_notas]){
	int i,j;
	i=0;
	while(i<alumnos){
		j=0;printf("Alumno %2i ",i+1);
		while(j<cant_notas){
			printf(" %3.1f",notas[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
void crear_notas(float notas[alumnos][cant_notas]){
	int i,j;
	srand(time(NULL));
	i=0;
	while(i<alumnos){
		j=0;
		while(j<cant_notas-1){
			notas[i][j]=(float)(rand()%71)/(float)10;
			j++;
		}
		i++;
	}
}
void posiciones_pares_impares(int datos[filas][columnas]){
	int i,j,cont_posicion=1,suma_par=0,cont_par=0,suma_impar=0,cont_impar=0;
	float valor;
	i=0;
	while(i<filas){
		j=0;
		while(j<columnas){
			if(cont_posicion%2 ==0){
				suma_par = suma_par+datos[i][j];
				cont_par++;
			}else{
				suma_impar = suma_impar+datos[i][j];
				cont_impar++;
			}
			j++;
			cont_posicion++;
		}
		i++;
	}
	
	if(cont_par!=0){
		valor = (float)(suma_par+suma_impar)/(float)(cont_par+cont_impar);
		printf("\npromedio de TOTAL es %3.1f \n",valor);
		valor = (float)suma_par/(float)cont_par;
		printf("\npromedio de las posiciones pares es %3.1f \n",valor);
	}else{
		printf("\nNO HAY VALORES EN LAS POSICIONES PARES \n");
	}
	if(cont_impar !=0){
		valor = (float)suma_impar/(float)cont_impar;
		printf("\npromedio de los posiciones impares es %3.1f \n",valor);
	}else{
		printf("\nNO HAY VALORES EN LAS POSICIONES IMPARES \n");
	}
	
}
void promedio_impares(int datos[filas][columnas]){
	int i,j,suma_impar=0,cont_impar=0;
	float valor;
	i=0;
	while(i<filas){
		j=0;
		while(j<columnas){
			if(datos[i][j]%2!=0){
				suma_impar = suma_impar+datos[i][j];
				cont_impar++;
			}
			j++;
		}
		i++;
	}
	if(cont_impar !=0){
		valor = (float)suma_impar/(float)cont_impar;
		printf("\npromedio de los valores impares es %3.1f \n",valor);
	}else{
		printf("\nNO HAY VALORES IMPARES \n");
	}
	
}
void promedio_pares(int datos[filas][columnas]){
	int i,j,suma_par=0,cont_par=0;
	float valor;
	i=0;
	while(i<filas){
		j=0;
		while(j<columnas){
			if(datos[i][j]%2==0){
				suma_par = suma_par+datos[i][j];
				cont_par++;
			}
			j++;
		}
		i++;
	}
	if(cont_par !=0){
		valor = (float)suma_par/(float)cont_par;
		printf("\npromedio de los valores pares es %3.1f \n",valor);
	}else{
		printf("\nNO HAY VALORES PARES \n");
	}
	
}
void crear_datos(int datos[filas][columnas]){
	int i,j;
	srand(time(NULL));
	i=0;
	while(i<filas){
		j=0;
		while(j<columnas){
			datos[i][j]=rand()%100;
			j++;
		}
		i++;
	}
}
void imprimir_datos(int datos[filas][columnas]){
	int i,j;
	i=0;
	printf("\n\n");
	while(i<filas){
		j=0;
		while(j<columnas){
			printf(" %3i ",datos[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
