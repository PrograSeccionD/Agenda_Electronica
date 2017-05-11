#include "stdafx.h"
#include <iostream>
#include "string"
#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h>
#define MAXCARACTER 50
#define MAX_Person 50
#define MAX_Contact 50

using namespace std;

struct Contacto{
	char con_nombre[MAXCARACTER];
	char con_apellido[MAXCARACTER];
	int con_telefono;
};
struct VariosContactos{
	int nContacto;
	Contacto ListContact[MAX_Contact];
};
struct Persona {
	char per_nombre[MAXCARACTER];
	char per_apellido[MAXCARACTER];
	int  per_telefono;
	VariosContactos P;
};
struct Persona lista[MAX_Person];
struct Persona aux;

void registrar_contactos(int nper, int ncon){
	for (int i = 0; i<ncon; i++){
		cout << "\n\tContacto " << i + 1 << endl;
		cin.ignore();
		cout << "\t\tNombre   : ";
		cin.getline(lista[nper].P.ListContact[i].con_nombre, MAXCARACTER);

		cout << "\t\tApellido   : ";
		cin.getline(lista[nper].P.ListContact[i].con_apellido, MAXCARACTER);

		cout << "\t\tTelefono : ";
		cin >> lista[nper].P.ListContact[i].con_telefono;
	}
}
void registrar_personas(int n){
	for (int i = 0; i<n; i++){
		cout << "\nPERSONA " << i + 1 << "\n"; cin.ignore();  
		cout << "   Nombres   : "; cin.getline(lista[i].per_nombre, MAXCARACTER);
		cout << "   Apellidos : "; cin.getline(lista[i].per_apellido, MAXCARACTER);
		cout << "   Telefono  : "; cin >> lista[i].per_telefono;
		cout << "\n   > Numero de Contactos: "; cin >> lista[i].P.nContacto;
		registrar_contactos(i, lista[i].P.nContacto);
	}
}
void datos_persona(int x, int num){
	if (num>0){
		cout << endl << endl;
		cout << "\t" << lista[x].per_nombre << ' ' << lista[x].per_apellido << endl;
		cout << "   Telefono      :  " << lista[x].per_telefono << endl;
	}else
		cout << "\n\tRegistro vacio..!";
}
void contactos_x_persona(int x, int num){
	if (num>0){
		cout << endl << endl;
		cout << "   Contactos de " << lista[x].per_nombre << ' ' << lista[x].per_apellido << endl << endl;

		for (int i = 0; i<lista[x].P.nContacto; i++){
			cout << "\n   Contacto " << i + 1 << endl;
			cout << "\tNombre   : " << lista[x].P.ListContact[i].con_nombre << endl;
			cout << "\tApellido : " << lista[x].P.ListContact[i].con_apellido << endl;
			cout << "\tTelefono : " << lista[x].P.ListContact[i].con_telefono << endl;
		}
		cout << endl;
	}
	else
		cout << "\n\tRegistro vacio..!";
}
void mostrar_contactos(int nper){
	cout << "   Contactos: \n\n";
	for (int i = 0; i<lista[nper].P.nContacto; i++){
		cout << "\t- " << lista[nper].P.ListContact[i].con_nombre<< endl;
	}
}
void mostrar_personas(int num){
	if (num>0){
		cout << "\n\nMostrando lista de Personas\n";
		for (int i = 0; i<num; i++){
			cout << endl << endl;
			cout << i + 1 << ". " << lista[i].per_nombre << ' ' << lista[i].per_apellido << endl;
			cout << "   Telefono   :  " << lista[i].per_telefono << endl;
			mostrar_contactos(i);
			cout << endl;
		}
	}else
		cout << "\n\tRegistro vacio..!";
}
void eliminar_persona(int x, int &num){
	if (num>0){
		for (int i = x; i<num - 1; i++)
			lista[i] = lista[i + 1];
		num--;
	}else
		cout << "\n\tRegistro vacio..!";
}
void buscar_persona(int num){
	int contador = 0;
	if (num>0){
		for (int i = 0; i<num; i++){
			if (lista[i].per_telefono == aux.per_telefono){
				cout << "\n\n La persona es " << lista[i].per_nombre << " "
					<< lista[i].per_apellido << " con numero de telefono "
					<< lista[i].per_telefono << endl;
				contador = 1;
				break;
			}
		}
	}else
		cout << "\n\tRegistro vacio..!";
	if (contador == 0)
		cout << "\n\n\tLa persona no fue encontrada..!" << endl;
}
void menu(){
	cout << "\n\t\tAGENDA ELECTRONICA\n\n";
	cout << " 1. Registrar personas                         " << endl;
	cout << " 2. Mostrar registro de personas y contactos   " << endl;
	cout << " 3. Mostrar datos de una persona               " << endl;
	cout << " 4. Mostrar contactos de una persona           " << endl;
	cout << " 5. Eliminar persona de la agenda              " << endl;
	cout << " 6. Buscar persona                             " << endl;
	cout << " 7. Salir                                      " << endl;
	cout << "\n Ingrese opcion : ";
}
int main(){
	int num = 0;
	int op = 0; 
	int num_persona;

	do{
		menu();  
		cin >> op;
		switch (op){
		case 1:
			cout << "\n Numero de personas: ";
			cin >> num;
			registrar_personas(num);  cout << endl;
			break;
		case 2:
			mostrar_personas(num);
			break;
		case 3:
			cout << "\n Ingrese numero de persona: ";
			cin >> num_persona;
			datos_persona(num_persona - 1, num);
			break;
		case 4:
			cout << "\n Ingrese numero de persona: ";
			cin >> num_persona;
			contactos_x_persona(num_persona - 1, num);
			break;
		case 5:
			cout << "\n Ingrese numero de persona: ";
			cin >> num_persona;
			eliminar_persona(num_persona - 1, num);
			cout << "\n\n\t\tRegistro eliminado ..!" << endl;
			break;
		case 6:
			cout << "\n Ingrese numero de telefono: ";
			cin >> aux.per_telefono;
			buscar_persona(num);
			break;
		}
		cout << endl << endl;
		system("pause");  
		system("cls");

	} while (op != 7);
	return 0;
}