#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 
#include<cstdlib>
#include<string.h>
#include<Windows.h>


using namespace std;
void venta();
void leer();
void modificar();
void eliminar();
void salir();
void menu();


int main() {
	menu();
	return 0;
	system("PAUSE");
}
void gotoxy(int x, int y) 
{
	COORD coord;
	coord.X = x; coord.Y = y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord);
}


void menu() {
	int opcion = 0;
	while (opcion != 6) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//blanco
		system("color 70");
		gotoxy(5, 2); cout << "  ________________________________\n";
		gotoxy(5, 3); cout << " |         --> MENU <--          |\n";
		gotoxy(5, 4); cout << " | 1. INGRESAR VENTA	            |\n";
		gotoxy(5, 5); cout << " | 2. CONSULTA LA VENTA          |\n";
		gotoxy(5, 6); cout << " | 3. ELIMINAR DATO DE VTA       |\n";
		gotoxy(5, 7); cout << " | 4. MODIFICAR CANTIDAD VTA     | \n";
		gotoxy(5, 8); cout << " | 			                    |\n";
		gotoxy(5, 9); cout << " | 6. SALIDA                     |\n";
		gotoxy(5, 10); cout << "  ________________________________\n";
		cout << "Que deseas hacer? ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			system("cls");
			venta();
			break;
		case 2:
			system("cls");
			leer();
			system("pause");
			break;
		case 3:
			system("cls");
		eliminar();
			system("pause");
			break;
		case 4:
			system("cls");
			modificar();
			system("pause");
			break;
		case 5:
			system("cls");
		///	modificar();
			system("pause");
			break;
		case 6:
			system("cls");
		//	salir();
			break;
		default:
			system("cls");
			cout << "¡Opcion Incorrecta!" << endl;
			break;
		}
	}

	system("pause");
}


void venta(){
	int dia;
	string modelo;
	float cant;
	int venta=0;
	ofstream vta;

	system("CLS");
		cout << "----------------------------------------\n";
		cout << "INGRESE LA VENTA DE LOS CUADERNOS       \n";
		cout << "----------------------------------------\n";
		cout<<"INGRESE EL DIA DE LA COMPRA: "<<endl;
	cin>>dia;
	fflush(stdin);
	
	cout<<"MODELO 1=10.00"<<endl;
	cout<<"MODELO 2=15.00"<<endl;
	cout<<"MODELO 3=18.50"<<endl;
	cout<<"MODELO 4=25.00"<<endl;
	
	cout<<"Indique el modelo de la compra:         "<<endl;
	getline(cin,modelo);
	fflush(stdin);	
	cout<<"Indique la cantidad de cuadernos:         "<<endl;
	cin>>cant;
	

	try {
		vta.open("ventas.txt",ios::app);
		vta<<dia <<"\t"<<modelo<<"\t"<<cant<<endl; 
		vta.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
} 	

void leer(){
int dia;
	float modelo;
	float cant;	
	string linea;
	int vt,vt1,vt2,vt3;
	float tlvta=0,tlvta1=0,tlvta2=0,tlvta3=0 ;
	float totaldeventa;
	
	
	ifstream vta;	
	try{
		vta.open("ventas.txt",ios::in);	

		cout<<"Datos del archivo:"<<endl;
			cout<<"MODELO 1=10.00"<<endl;
	cout<<"MODELO 2=15.00"<<endl;
	cout<<"MODELO 3=18.50"<<endl;
	cout<<"MODELO 4=25.00"<<endl;
	cout<<"\n"<<endl;
	
		cout<<" DIA|"<<"    MODELO   |"<<"CANTIDAD|"<<endl;	

		while (vta>>dia>>modelo>>cant){
			cout<<setw(4)<<dia<<""<<setw(6)<<modelo<<""<<setw(8)<<cant<<""<<endl;		
			if (modelo==1){
				vt=cant*10;
				tlvta+=vt;
					cout<<" valor de la venta de modelo 1 es:  "<<setw(5)<<vt<<endl;
			}
			else if(modelo==2){
				vt1=cant*15;
				tlvta1+=vt1;
				cout<<"valor de la venta de modelo 2 es:  "<<setw(5)<<vt1<<endl;
			}
			else if(modelo==3){
				vt2=cant*18.50;
				tlvta2+=vt2;
				cout<<"valor de la venta de modelo 3 es:  "<<setw(5)<<vt2<<endl;
			}
			else if(modelo==4){
				vt3=cant*25;
				tlvta3+=vt3;	
				cout<<"valor de la venta de modelo 4 es:  "<<setw(5)<<vt3<<endl;
			}
				totaldeventa+=vt+vt1+vt2+vt3;
							
		}	
		vta.close();	
		cout<<"\n"<<endl;
		cout<<"__________VENTA TOTAL_________________"<<endl;
		cout<<"|VENTA TOTAL DE MES MODELO 1       : "<<setw(3)<<tlvta<<endl;
		cout<<"|VENTA TOTAL DE MES MODELO 2       : "<<setw(3)<<tlvta1<<endl;
		cout<<"|VENTA TOTAL DE MES MODELO 3       : "<<setw(3)<<tlvta2<<endl;
		cout<<"|VENTA TOTAL DE MES MODELO 4       : "<<setw(3)<<tlvta3<<endl;
		cout<<"|TOTALES DE VENTA MES ES           : "   <<setw(3)<<totaldeventa<<endl;
		
		
		
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}
void eliminar(){
	ifstream vta_a;	 
	ofstream vtas_n; 
	float modelo; 	 
   	int cant;
	int aux,dia,flag,icant;

	
	remove("Temporal.txt");
	
	vta_a.open("ventas.txt",ios::in);	
	vtas_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (vta_a>>dia>>modelo>>cant){
		if(aux==dia){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=dia)
			vtas_n<<dia<<"\t"<<modelo<<"\t"<<cant<<endl;					
	}
	vta_a.close();
	vtas_n.close();
	
	if (flag==1){
		remove("ventas.txt");
		rename("Temporal.txt","ventas.txt");
	}	
	system("Pause");
}

void modificar(){
	ifstream vta_a; 
	ofstream vtas_n; 
	char respuesta;
	 float modelo;
	int cant,icant;	
	  	 string linea;
   	
	int aux,dia,flag;
	remove("Temporal.txt");
	
	vta_a.open("ventas.txt",ios::in);
	vtas_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese dia al que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese cantidad a modificar: "<<endl;
		cin>>icant;
		
		cout<<"\n\nEsta Seguro? S / N"<<endl;
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	
	while (vta_a>>dia>>modelo>>cant){
		if(aux==dia){
			vtas_n<<setw(4)<<dia<<""<<setw(6)<<modelo<<""<<setw(8)<<icant<<""<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=dia)
			vtas_n<<setw(4)<<dia<<""<<setw(6)<<modelo<<""<<setw(8)<<cant<<""<<endl;					
	}
	vta_a.close();
	vtas_n.close();
	
	if (flag==1){
		remove("ventas.txt");
		rename("Temporal.txt","ventas.txt");
	}	
	system("Pause");
}

