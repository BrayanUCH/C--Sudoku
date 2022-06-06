#include <iostream>
#include <time.h>
//#include <windows.h>
//#include<stdio.h>
using namespace std;

class Sudoku{
private:
	int XcoordenadaFila=0,Ycoordenadacolumna=0,numero=0;
	int Matriz [9][9]={
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0}};
	
	//Esta variable almacena la cantidad de numeros que fueron añadidos aleatorimente
	int contadorFC=0;
	//Estos vectores almacenan las codenadas de los numeros aletorios para compararlos
	//despues y asi no poder cambia estos numeros.
	int filaV[100];
	int columnaV[100];
	
public:
	//Este método tiene la función de tomar las coordenadas y el numero que 
	//el usuario brinda para poder colocar el dato en el cuadro del sudoku 
	//además verifica que los datos sean mayores a 1, menores a 9 y sean 
	//números enteros.
	int JUGAR(){
		while(true){
			bool Addnumero = true;
			imprimir();
			cout<<"Digite las coordenas para ingresar el numero..."<<endl;
			cout<<"Digite el numero de fila-->";
			while(true){
				cin >> XcoordenadaFila;
				//regresa la bandera de estado de stream
				if((cin.fail() && cin.rdstate())||(XcoordenadaFila>9)){
					if(XcoordenadaFila==100){
						Sair();
					}else if (XcoordenadaFila==200){
						COMPROBAR();
					}else{
						cout << "DATO NO VALIDO..." << endl<<"VUELVA A INTENTARLO."<<endl;
						cin.clear();
						cin.ignore();
					}
				}else{
					break;
				}
			}
			cout<<"Digite el numero de columna-->";
			while(true){
				cin >> Ycoordenadacolumna;
				if((cin.fail() && cin.rdstate())||(Ycoordenadacolumna>9)){
					if(Ycoordenadacolumna==100){
						Sair();
					}else if (Ycoordenadacolumna==200){
						COMPROBAR();
					}else{
						cout << "DATO NO VALIDO..." << endl<<"VUELVA A INTENTARLO."<<endl;
						cin.clear();
						cin.ignore();
					}
				}else{
					break;
				}
			}
			cout<<"Digite el numero que quiere agregar a la posicion indicada-->";
			while(true){
				cin >> numero;
				if((cin.fail() && cin.rdstate())||(numero>9)){
					if(numero==100){
						Sair();
					}else if (numero==200){
						COMPROBAR();
					}else{
						cout << "DATO NO VALIDO..." << endl<<"VUELVA A INTENTARLO."<<endl;
						cin.clear();
						cin.ignore();
					}
				}else{
					break;
				}
			}
			//En este bucle se comparan las posiciones de los numeros aletorios
			//para asi no poder digitar un nuevo numero en esa posicion.
			for (int i=0;i<contadorFC;i++){
				if((columnaV[i]==Ycoordenadacolumna-1)&&(filaV[i]==XcoordenadaFila-1)){
					Addnumero=false;
				}
			}
			if(Addnumero==true){
				Matriz[XcoordenadaFila-1][Ycoordenadacolumna-1]=numero;
				system("pause");
				system("cls");
			}else{
				system("pause");
				system("cls");
			}
		}
	}
	//Este método tiene la función de comparar toda la matriz todas las
	//filas, todas la columnas, en las subcuadrículas de 3x3 y si hay algun 
	// cero en la matriz(lo que indicario que esta mal) para verificar
	//si a ganado el juego o no.
	void COMPROBAR (){
		bool verdad=false;
		int vector[9]={0,0,0,0,0,0,0,0,0};
		
		//La comparacion de las (Filas).
		for (int f=0;f<9;f++) {
			int contador=0;
			for (int c=0;c<9;c++) {
				vector[contador]=Matriz[f][c];
				contador+=1;
			}
			for (int num=1;num<10;num++) {
				int contador1=0;
				for (int i=0;i<9;i++) {
					if (vector[i]==num){
						contador1++;
					}
				}
				if (contador1>=2){
					verdad=true;
				}
			}
		}
		
		//La comparacion de las (Columnas).
		int contador=0;
		int contador1=0;
		for (int c=0;c<9;c++) {
			contador=0;
			for (int f=0;f<9;f++) {
				vector[contador]=Matriz[c][f];
				contador+=1;
			}
			for (int num=1;num<10;num++) {
				contador1=0;
				for (int i=0;i<9;i++) {
					if (vector[i]==num){
						contador1++;
					}
				}
				if (contador1>=2){
					verdad=true;
					
				}
			}
		}
		
		//La comparacion de las (Subcuadriculas).  
		int vectors[9]={0,0,0,0,0,0,0,0,0};
		contador=0;
		int contadors=0;
		int contadorWhile=0;
		int marcador=0;
		int columna=0;
		int fila=0;
		int columnaEND=2;
		int filaEND=2;
		while(contadorWhile<3){
			contador=0;
			for (int f=fila;f<=filaEND;f++) {
				for (int c=columna;c<=columnaEND;c++) {
					vectors[contador]=Matriz[f][c];
					contador++;
				}
			}
			for (int num=1;num<=9;num++) {
				contadors=0;
				for (int i=0;i<9;i++) {
					if (vectors[i]==num){
						contadors++;
					}
				}
				if (contadors>1){
					verdad=true;
				}
			}
			
			columna+=3;
			columnaEND+=3;
			contadorWhile++;
			if ((contadorWhile==3)&&(marcador==0)){
				columna=0;
				fila=3;
				contadorWhile=0;
				filaEND=5;
				columnaEND=2;
				marcador+=1;
			}
			if ((contadorWhile==3)&&(marcador==1)){
				columna=0;
				fila=6;
				contadorWhile=0;
				filaEND=8;
				columnaEND=2;
				marcador=2;
			}
		}
		
		//La comparacion de las (Ceros).
		for (int f=0;f<9;f++) {
			for (int c=0;c<9;c++) {
				if (Matriz[f][c]==0){
					verdad=true;
				}
			}
		}
		
		if(verdad==true){
			cout<< "\n \t ******************";
			cout<< "\n \t *Juego No Válido.*";
			cout<< "\n \t ******************"<<endl;
		}else{
			cout<< "\n \t *****************";
			cout<< "\n \t *¡Juego Exitoso!*";
			cout<< "\n \t *****************"<<endl;
		}
		system("pause");
		system("cls");
		JUGAR();
	}
	
	void imprimir(){
		//Este método tiene como función imprimir el cuadro(9x9) de sudoku.
		cout << "\n \t ***************";
		cout << "\n \t * Salir(100)  *";
		cout << "\n \t *Comparar(200)*";
		cout << "\n \t ***************"<<endl;
		cout<<"**********************************"<<endl;
		cout<<"Columna--";
		
		for (int i=1;i<10;i++) {
			if((i==1)||(i==4)||(i==7)){
				cout<<"||";
			}
			cout<<i<<"-";
			if(i==9){
				cout<<"||";
			}
		}
		cout<<endl<<endl;
		for (int f=0;f<9;f++) {
			cout<<"Fila "<<f+1<<"---";
			for (int c=0;c<9;c++) {
				if((c==0)||(c==3)||(c==6)){
					cout<<"||";
				}
				cout<<""<<Matriz[f][c]<<" ";
				if(c==8){
					cout<<"||";
				}
			}
			cout<<endl;
			if ((f==2)||(f==5)){
				cout<<endl;
			}
		}
		cout<<"**********************************"<<endl;
	}
	//Este método tiene la función de llenar el cuadro con algunos números 
	//aleatorios en algunas posiciones aleatorias para iniciar con algunos 
	//números en el cuadro del sudoku, ademas guarda las coordenadas de los 
	//numeros agregados para compararlos despues y asi que no los puedan cambiar. 
	void llenarMatriz(){
		int numeroAdd=0;
		int columna=0;
		int columna1=0;
		int contador=0;
		int contador1=0;
		srand(time(NULL));
		
		for (int f=0;f<9;f++) {
			contador1=0;
			
			while(contador1<2){
				int fila=0;
				numeroAdd=1+rand()%9;
				columna=rand()%10;
				columna1=columna;
				contador=0;
				
				//fila y columna(comparar la existencia en las fila y columna)
				for (int f2=0;f2<9;f2++) {
					if(Matriz[f2][columna]==numeroAdd){
						contador+=1;
					}
				}
				for (int c=0;c<9;c++){
					if(Matriz[f][c]==numeroAdd){
						contador+=1;
					}
				}
				
				//3*3(localizar en cual de los subcuadrículas este la posicion 
				//que fue impuesta por el random)
				if ((f==0)||(f==1)||(f==2)){
					if((columna==0)||(columna==1)||(columna==2)){
						fila=0;
						columna=0;
					}
					if((columna==3)||(columna==4)||(columna==5)){
						fila=0;
						columna=3;
					}
					if((columna==6)||(columna==7)||(columna==8)){
						fila=0;
						columna=6;
					}
				}
				if ((f==3)||(f==4)||(f==5)){
					if((columna==0)||(columna==1)||(columna==2)){
						fila=3;
						columna=0;
					}
					if((columna==3)||(columna==4)||(columna==5)){
						fila=3;
						columna=3;
					}
					if((columna==6)||(columna==7)||(columna==8)){
						fila=3;
						columna=6;
					}
				}
				if ((f==6)||(f==7)||(f==8)){
					if((columna==0)||(columna==1)||(columna==2)){
						fila=6;
						columna=0;
					}
					if((columna==3)||(columna==4)||(columna==5)){
						fila=6;
						columna=3;
					}
					if((columna==6)||(columna==7)||(columna==8)){
						fila=6;
						columna=6;
					}
				}
				int finalFila = fila + 3;//Este entero es para saber el final de la fila.
				//del cuadro de 3*3
				int finalColumna = columna + 3;//Este entero es para saber el final de la columna.
				//del cuadro de 3*3
				
				//Los siguentes for comparan el cuadro de 3*3 para verificar que el 
				//numero digitado por el usuario no tenga existencia en le cuadro de 3*3.
				int comparar[9]={0,0,0,0,0,0,0,0,0};
				int a=0;
				for (int f1=fila;f1<finalFila;f1++) {
					for (int c=columna;c<finalColumna;c++) {
						comparar[a]=Matriz[f1][c];
						a+=1;
					}
				}
				for (int i=0;i<9;i++) {
					if (comparar[i]==numeroAdd){
						contador+=1;
					}
				}
				
				if((contador==0)&&(numeroAdd!=0)){
					Matriz[f][columna1]=numeroAdd;
					columnaV[contadorFC]=columna1;
					filaV[contadorFC]=f;
					contadorFC++;
				}
				//_____________________________________________
				contador1+=1;
			}
		}
	}
	
	//Este método tiene la función de salir o cerrar el programa cuando
	//el usuario lo desee.
	void Sair(){
		cout<<"\n \t *******************************************";
		cout<<"\n \t *               GAME OVER                 *";
		cout<<"\n \t *******************************************"<<endl;
		system("pause");
		exit (EXIT_FAILURE);
	}
};
int main( ) {
	Sudoku sudoku;
	
	cout << "\n \t *************************************************************************************************";
	cout << "\n \t **************************************BUENVENIDOS************************************************";
	cout << "\n \t **Este juego está compuesto por una cuadrícula de 9x9 casillas,dividida en regiones de         **";
	cout <<	"\n \t **3x3 casillas. Partiendo de algunos números ya dispuestos en algunas de las casillas, hay que **";
	cout <<	"\n \t **completar las casillas vacías con dígitos del 1 al 9                                         **";
	cout << "\n \t **                                                                                             **";
	cout << "\n \t **********************************REGLAS DEL SUDOKU**********************************************";
	cout << "\n \t **Regla 1: Hay que completar las casillas vacías con un solo numeros del 1 al 9.                **";
	cout << "\n \t **Regla 2: En una misma fila no puede haber números repetidos.                                 **";
	cout << "\n \t **Regla 3: En una misma columna no puede haber números repetidos.                              **";
	cout << "\n \t **Regla 4: En una misma región no puede haber números repetidos.                               **";
	cout << "\n \t **Regla 5: La solución de un sudoku es única.                                                  **";
	cout << "\n \t **Regla 6: Es imposible cambiar los numeros puestos por la computadora.                        **";
	cout << "\n \t **Regla 7: Para salir del juego digite (100) en alguno de los datos solicitados.               **";
	cout << "\n \t **Regla 8: Para comparar si gano el juego o no dijite (200) en alguno de los datos solicitados.**";
	cout << "\n \t *************************************************************************************************";
	cout << "\n \t *************************************************************************************************"<<endl<<endl;
	system("pause");
	system("cls");
	cout<<"\n \t **********************************************";
	cout<<"\n \t **Bienvenido al juego es hora de divertirse.**";
	cout<<"\n \t **********************************************"<<endl;
	sudoku.llenarMatriz();
	sudoku.JUGAR();
	system("pause");
	system("cls");
	return 0;
}
