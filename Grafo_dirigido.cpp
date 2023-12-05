#include <iostream>
#include <conio.h>
#include <stdlib.h>

//Definicion de la estructura del nodo
struct Nodo {
        int dato;
        Nodo* der;
        Nodo* izq;      
};

//Aqui declaramos nuestras partes del programa
void menu();
Nodo *crearNodo(int n,Nodo*&);
void insertarNodo(Nodo *&, Nodo *&,Nodo *& ,int); 
Nodo *grafo=NULL;
void mostrarGrafo(Nodo * );

int main(){
menu();

getch();
return 0;
}

//Nuestrtro menu
void menu(){
	Nodo *primerNodo = NULL;
    Nodo *ultimoNodo = NULL;
	
	int dato, opcion, contador=0;	
	do{
		std::cout<<"\n	Digite la opcion que desea realizar";
		std::cout<<"\n	1. Insertar un nuevo nodo";
		std::cout<<"\n	2. Mostrar ";
		std::cout<<"\n	3. Salir";
		std::cout<<"\n\n	Su opcion: ";
		std::cin>>opcion;
		
		switch(opcion){
			case 1: 
			{			
			std::cout<<"\n	Ingrese su dato: ";
			std::cin>>dato;			
			insertarNodo(grafo, primerNodo, ultimoNodo, dato);
			}break;
			
			case 2:
				{				
				std::cout<<"\n Mostrar grafo\n\n";
				mostrarGrafo(grafo);
				std::cout<<"\n";
				system("Pause");
				}break;
			case 3: 
			{
				std::cout<<"\n	Ha selecionado salir del programa, hasta luego.\n\n";
			}		
			
		}
		system("cls");
	}while(opcion!=3);
}

//Aqui creamos los nodos
Nodo *crearNodo(int n, Nodo*& ultimoNodo){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	
	return nuevo_nodo;
}

//Aqui insertamos el nodo
void insertarNodo(Nodo *&grafo, Nodo *&primerNodo, Nodo *&ultimoNodo, int n){
	Nodo *nuevoNodo = crearNodo(n, ultimoNodo);

    // Si el grafo está vacío, el nuevo nodo se convierte en el primer y último nodo
    if (grafo == NULL) {
        grafo = nuevoNodo;
        primerNodo = nuevoNodo;
        ultimoNodo = nuevoNodo;
    } else {
        // Si el grafo no está vacío, conectamos el último nodo con el nuevo nodo
        ultimoNodo->der = nuevoNodo;
        nuevoNodo->izq = ultimoNodo;

        // vams a tener el último nodo al nuevo nodo
        ultimoNodo = nuevoNodo;

        // Conectamos el primer nodo con el nuevo último nodo
        primerNodo->izq = nuevoNodo;
        nuevoNodo->der = primerNodo;
    }
	
	}


void mostrarGrafo(Nodo *primerNodo){
	if(grafo==NULL){
		return;
	}
	Nodo* actual = primerNodo;

    do {
        std::cout << actual->dato << " ";
        actual = actual->der;
    } while (actual != nullptr && actual != primerNodo);
	
}



