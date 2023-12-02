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
Nodo *crearNodo(int n);
void insertarNodo(Nodo *&,int); 
Nodo *arbol=NULL;
void mostrarArbol(Nodo *,int );


int main(){
menu();

getch();
return 0;
}

//Nuestrtro menu
void menu(){
	int dato, opcion, contador=0;	
	do{
		std::cout<<"\n	Digite la opcion que desea realizar";
		std::cout<<"\n	1. Insertar un nuevo nodo";
		std::cout<<"\n	2. Mostrar arbol";
		std::cout<<"\n	3. Salir";
		std::cout<<"\n\n	Su opcion: ";
		std::cin>>opcion;
		
		switch(opcion){
			case 1: 
			{			
			std::cout<<"\n	Ingrese su dato: ";
			std::cin>>dato;
			bool insertarIzq=true;
			insertarNodo(arbol,dato);
			}break;
			
			case 2:
				{				
				std::cout<<"\n Mostrar arbol\n\n";
				mostrarArbol(arbol,contador);
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
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	return nuevo_nodo;
}

//Aqui insertamos el nodo
void insertarNodo(Nodo *&arbol, int n){
	//Si nuestro arbol esta vacio, vamos a crear un nodo	
	if(arbol==NULL){
		arbol = crearNodo(n);
	}
	
	else{
		//Si nuestro nodo izquiero esta vacio, insertaremos el nodo ahi.
		if(arbol->izq==NULL){
			insertarNodo(arbol->izq,n);
		}//de lo contrario, si nuestro nodo izquierdo tiene un dato, insertaremos el nodo en el derecho
		else if(arbol->der==NULL){
			insertarNodo(arbol->der,n);	
			}
			//si ambos estan llenos, in
			else{
				insertarNodo(arbol->izq, n);
			}
	}
} 

void mostrarArbol(Nodo *arbol,int cont){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0; i<cont;i++){
		std::cout<<"  ";	
		}
		std::cout<<arbol->dato<<"\n";
		mostrarArbol(arbol->izq,cont+1);		
	}
}