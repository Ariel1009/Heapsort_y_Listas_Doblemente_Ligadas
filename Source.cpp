#include <iostream>
#include<string.h>
#include<Windows.h>
using namespace std;

struct datos;
void insertarDatos(char[], int, int, int);
void menu();
void mostrarDatos();
int contadorNodos(datos*, int);
//void ListaToArray(datos* ,datos*, int& );
//void ListaToArray(datos*, int&);

void heapify(datos [], int , int );
void heapSort(datos [], int );
void printArray(datos [], int );

struct datos {
	char nombre[40];
	int edad;
	int ID;
	int calificacion;
	datos* siguiente;
	datos* anterior;
}*origen, * aux;

datos* arrayDatos;

int cn = 0;

int main() {
	menu();
	return 0;
}

void insertarDatos(char nombre[], int edad, int ID, int calificacion) {
	datos* nuevos_datos = new datos;
	strcpy_s(nuevos_datos->nombre, nombre);
	nuevos_datos->edad = edad;
	nuevos_datos->ID = ID;
	nuevos_datos->calificacion = calificacion;

	if (origen == NULL) {
		origen = nuevos_datos;
		origen->siguiente = NULL;
		origen->anterior = NULL;
		aux = origen;
	}
	else
	{
		aux->siguiente = nuevos_datos;
		nuevos_datos->siguiente = NULL;
		nuevos_datos->anterior = origen;
		aux = nuevos_datos;
	}

	// contador cn=cn+1;
	//cn 
	cout << "Elemento insertado" << endl;
}

void menu() {
	int op;
	char nombre[40];
	int edad;
	int ID = 0;
	int temp = 0;
	int calificacion;
	//int final;
	int indice = 0;

	do
	{
		cout << "1. Insertar elementos" << endl;
		cout << "2. Mostrar lista" << endl;
		cout << "3. Ordenar Lista" << endl;
		cout << "4. Mostrar nueva lista" << endl;
		cout << "5. Salir" << endl;
		cout << "Escoje una opcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Ingrese su nombre: ";
			cin >> nombre;
			cout << endl << "Ingrese su edad: ";
			cin >> edad;
			cout << endl << "Ingrese su calificacion: ";
			cin >> calificacion;
			ID++;
			insertarDatos(nombre, edad, ID, calificacion);
			system("pause");
			break;
		case 2:
			mostrarDatos();
			cn=contadorNodos(origen, temp);
			cout << "La lista tiene "<<cn<<" elementos"<<endl;
			system("pause");
			break;
		case 3:
			arrayDatos = new datos[cn];
			if (origen != NULL) {
				while (origen!=NULL) {
					strcpy_s(arrayDatos[indice].nombre, origen->nombre);
					arrayDatos[indice].calificacion = origen->calificacion;
					arrayDatos[indice].edad = origen->edad;
					indice++;
					origen = origen->siguiente;
				}
			}
			//ListaToArray(origen,inicio);
			heapSort(arrayDatos, cn);
			system("pause");
			break;
		case 4:
			printArray(arrayDatos, cn);
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (op != 5);
}


void mostrarDatos() {
	datos* actual = new datos;
	actual = origen;

	if (origen != NULL)
	{
		while (actual != NULL) {
			cout << actual->ID << endl;
			cout << actual->nombre << endl;
			cout << actual->edad << endl;
			cout << actual->calificacion << endl;
			actual = actual->siguiente;
		}
	}
	else
	{
		cout << "Lista vacia";
	}
}

int contadorNodos(datos* origen, int cn) {
	if (origen!=NULL) {
		while (origen!=NULL) {
			cn = cn + 1;
			origen = origen->siguiente;
		}
	}
	return cn;
}

//void ListaToArray(datos* origen, int& indice) {
//	if (origen == NULL) {
//		return;
//	}
//	else
//	{
//		strcpy_s(arrayDatos[indice].nombre, origen->nombre);
//		arrayDatos[indice].edad = origen->edad;
//		arrayDatos[indice].calificacion = origen->calificacion;
//		arrayDatos[indice].ID = origen->ID;
//		indice++;
//		ListaToArray(origen->siguiente, indice);
//	}
//}

void heapify(datos arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	//int cl = &arr[l]->calificacion;
	//int cr = arr[r]->calificacion;

	// If left child is larger than root
	if (l < n && arr[l].calificacion < arr[largest].calificacion)//arr[l] > arr[largest] strcmp()<0
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r].calificacion < arr[largest].calificacion)
		largest = r;

	// If largest is not root
	if (largest != i) {
		
		swap(arr[i].nombre, arr[largest].nombre);//arr
		swap(arr[i].calificacion, arr[i].calificacion);
		swap(arr[i].edad, arr[largest].edad);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(datos arr[], int n)  //(datos* lista[], int n)
{
	
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0].nombre, arr[i].nombre);
		swap(arr[0].calificacion, arr[i].calificacion);
		swap(arr[0].edad, arr[i].edad);
		

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void printArray(datos arr[], int n)
{
	int i = 0;
	for (int i = 0; i < n; i++) {
		cout << "Nombre: " << arr[i].nombre << endl;
		cout << "Edad: " << arr[i].edad << endl;
		cout << "Calificacion: " << arr[i].calificacion << endl;
	}
}
/*
 void heapsort(dato* origen) {
 while(origen!=NULL){
 heapify(origen);
 }
 */

/*
heapify(datos* origen){

}
*/