#include<iostream>
#include<math.h>
#include<string>
#include <cstdlib>

#define Err_Range 0.00001f
using namespace std;

#define PI 3.14159265f
bool escape = true, comparison=true;
char optionMain;
float matrixA[10][10];
float matrixB[10][10];
float matrixC[10][10];

struct array1 {
	float matrix[4][4];
}arregloM[10];
int cont = 0;
float matrixAux[4][4];
float matrixCompound[4][4];
int i=0, j = 0, m = 0, n = 0, o = 0, p = 0,k=0;

struct array2 {
	float matrix[4];
}arregloV[10],arregloP[10];
float matrixV[4][4];


#pragma region Prototipos de funciones
void LengthOfMatrixes();
void SumOfMatrixes();
bool SumLengthCompare();
bool MultLengthCompare();
void FillMArray();
void CalculateCompoundMatrix();
void MatrixVector();
void CalculateQuaternions();
float Validacion();
#pragma endregion

void main() {
	do {
		system("cls");
		cout << "Bienvenido a la calculadora de matrices. Que desea hacer?" << endl;
		cout << "a) Suma de matrices." << endl;
		cout << "b) Resta de matrices." << endl;
		cout << "c) Multiplicacion de matrices." << endl;
		cout << "d) Generación de nuevas coordenadas por quaterniones." << endl;
		cout << "e) Matriz compuesta." << endl;
		cout << "f) Matriz por vector." << endl;
		cout << "g) Salir." << endl;
		cout << "Opcion: ";
		cin >> optionMain;

		system("cls");
		switch (optionMain) {
		case 'a':
		case 'A':{
			LengthOfMatrixes();
			comparison = SumLengthCompare();
			if (comparison) {
			SumOfMatrixes();
			cout << "La suma de las matrices es:" << endl;
			for (i = 0; i < m; i++) {
				j = 0;
				for (j = 0; j < n; j++) {
					cout << matrixC[i][j] << " ";
				}
				cout << endl;
			}
			system("pause");
		}
			else {
			cout << "Error. No se puede ejecutar la operacion por que las matrices tienen diferentes dimensiones." << endl;
			system("pause");
			}
			break;
	     }
		case 'b':
		case 'B': {
			char option;
			LengthOfMatrixes();
			comparison = SumLengthCompare();
			if (comparison) {
				do {
					cout << "1) A-B o 2) B-A ? " << endl;
					cin >> option;
					cout << endl;

					if (option == '1') {
					for (i = 0; i < m; i++) {
							j = 0;
							for (j = 0; j < n; j++) {
								matrixB[i][j] = matrixB[i][j] * -1;
							}
						}
					SumOfMatrixes();
					cout << "La resta de las matrices es:" << endl;
					for (i = 0; i < m; i++) {
						j = 0;
						for (j = 0; j < n; j++) {
							cout << matrixC[i][j] << " ";
						}
						cout << endl;
					}
					}
					else if (option == '2') {
						for (i = 0; i < m; i++) {
							j = 0;
							for (j = 0; j < n; j++) {
								matrixA[i][j] = matrixA[i][j] * -1;
							}
						}
						SumOfMatrixes();
						cout << "La resta de las matrices es:" << endl;
						for (i = 0; i < m; i++) {
							j = 0;
							for (j = 0; j < n; j++) {
								cout << matrixC[i][j] << " ";
							}
							cout << endl;
						}

					}
					else {
						cout << "Error. Opcion no valida. Preparese para ingresar de nuevo" << endl;
					}
					system("pause");
				} while ((option != '1') && (option != '2'));
			}
			else {
				cout << "Error. No se puede efectuar la resta por que las matrices tienen dimensiones diferentes." << endl;
				system("pause");
			}
			break; }
		case 'c':
		case 'C': {
			LengthOfMatrixes();
			comparison = MultLengthCompare();
			if (comparison) {
				for (i = 0; i < m; i++) {
					j = 0;
					for (j = 0; j < p; j++) {
						matrixC[i][j] = 0;
						for (k = 0; k < n; k++) {
							matrixC[i][j] = (matrixA[i][k] * matrixB[k][j]) + matrixC[i][j];
						}
					}
				}
				cout << "La matriz resultante es: " << endl;
				for (i = 0; i < m; i++) {
					j = 0;
					for (j = 0; j < p; j++) {
						cout << matrixC[i][j] << " ";
					}cout << endl;
				}
				system("pause");
			}
			else {
				cout << "Error. Las matrices no se pueden multiplicar por que los renglones y las columnas no coinciden" << endl;
			}
			system("pause");
			break;
		}
		case 'd':
		case 'D': {
			CalculateQuaternions();
		}
			break;
		case 'e':
		case 'E': {
			FillMArray();
			CalculateCompoundMatrix();
			//Impresión de la matriz compuesta
			cout << endl;
			cout << "La matriz compuesta es:" << endl;
			for (i = 0; i < 4; i++) {
				j = 0;
				for (j = 0; j < 4; j++) {
					if (matrixAux[i][j] >= -Err_Range && matrixAux[i][j] <= Err_Range)matrixAux[i][j] = 0;
					cout << matrixAux[i][j] << " ";
				}
				cout << endl;
			}
			system("pause");
		}
			break;
		case'f':
		case'F': {
			MatrixVector();
		}
			 break;
		case 'g':
		case 'G':
			cout << "Saliendo..." << endl;
			system("pause");
			escape = false;
			break;
		default: cout << "Error. Opcion no valida. Regresando al menu principal..." << endl;
			system("pause");
			break;
		}
	} while (escape);
}
void LengthOfMatrixes() {
	system("cls");
	cout << "Cuantos renglones tiene la matriz A? :";
	cin >> m;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> m;

	}
	cout << endl;
	cout << "Cuantas columnas tiene la matriz A? :";
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> n;

	}
	cout << endl;
	cout << "Cuantos renglones tiene la matriz B? :";
	cin >> o;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> o;

	}
	cout << endl;
	cout << "Cuantas columnas tiene la matriz B? :";
	cin >> p;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> p;

	}
	cout << endl;
	cout << "Llenado de la matriz A. "<<endl;
	for (i = 0; i < m; i++) {
		j = 0;
		for (j = 0; j < n; j++) {
			cout << " ";
		
			matrixA[i][j] = Validacion();
			
		}
		cout << endl;
	}
	cout << "Llenado de la matriz b. " << endl;
	for (i = 0; i < o; i++) {
		j = 0;
		for (j = 0; j < p; j++) {
			cout << " ";
			
			matrixB[i][j] = Validacion();
		}
		cout << endl;
	}
}
bool SumLengthCompare() {
	if ((m == o) && (n == p)) {
		return true;
	}
	else {
		return false;
	}
}
bool MultLengthCompare() {
	if (n == o) {
		return true;
	}
	else {
		return false;
	}
}
void SumOfMatrixes() {
	for (i = 0; i < m; i++) {
		j = 0;
		for (j = 0; j < n; j++) {
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
}
void FillMArray() {
	char option = 0;
	cont = 0;

	//Identidad 
	arregloM[cont].matrix[0][0] = 1;
	arregloM[cont].matrix[0][1] = 0;
	arregloM[cont].matrix[0][2] = 0;
	arregloM[cont].matrix[0][3] = 0;

	arregloM[cont].matrix[1][0] = 0;
	arregloM[cont].matrix[1][1] = 1;
	arregloM[cont].matrix[1][2] = 0;
	arregloM[cont].matrix[1][3] = 0;

	arregloM[cont].matrix[2][0] = 0;
	arregloM[cont].matrix[2][1] = 0;
	arregloM[cont].matrix[2][2] = 1;
	arregloM[cont].matrix[2][3] = 0;

	arregloM[cont].matrix[3][0] = 0;
	arregloM[cont].matrix[3][1] = 0;
	arregloM[cont].matrix[3][2] = 0;
	arregloM[cont].matrix[3][3] = 1;
	do {
		cout << "Desea agregar otra matriz? 1.Si/2.No:";
		cin >> option;
		cout << endl;
		if ((option == '1')&&(cont<9)) {
			char op = 0;
			cont = cont + 1;
			do {
				cout << "Que transformación desea agregar?" << endl;
				cout << "1.- Traslacion" << endl;
				cout << "2.- Rotacion" << endl;
				cout << "3.- Escalamiento" << endl;
				cout << "opcion: ";
				cin >> op;
				cout << endl;
				//Llenado de traslación
				if (op == '1') {
					float x=0, y=0, z=0;
					cout << "Ingrese la traslacion en x: ";
					cin >> x;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "solo numeros" << endl;
						cin >> x;

					}
					cout << "Ingrese la traslacion en y: ";
					cin >> y;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "solo numeros" << endl;
						cin >> y;

					}
					cout << "Ingrese la traslacion en z: ";
					cin >> z;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "solo numeros" << endl;
						cin >> z;

					}
					arregloM[cont].matrix[0][0] = 1;
					arregloM[cont].matrix[0][1] = 0;
					arregloM[cont].matrix[0][2] = 0;
					arregloM[cont].matrix[0][3] = x;
					arregloM[cont].matrix[1][0] = 0;
					arregloM[cont].matrix[1][1] = 1;
					arregloM[cont].matrix[1][2] = 0;
					arregloM[cont].matrix[1][3] = y;
					arregloM[cont].matrix[2][0] = 0;
					arregloM[cont].matrix[2][1] = 0;
					arregloM[cont].matrix[2][2] = 1;
					arregloM[cont].matrix[2][3] = z;
					arregloM[cont].matrix[3][0] = 0;
					arregloM[cont].matrix[3][1] = 0;
					arregloM[cont].matrix[3][2] = 0;
					arregloM[cont].matrix[3][3] = 1;
				}
				//Llenado de rotación
				else if (op == '2') {
					char op2 = 0;
					float angle = 0;
					do{
					cout << "En que eje desea rotar?" << endl;
					cout << "1.- Eje x" << endl;
					cout << "2.- Eje y" << endl;
					cout << "3.- Eje z" << endl;
					cin >> op2;
					cout << endl;
					//Rotación en x
					if (op2 == '1') {
						cout << "Ingrese el angulo: ";
						cin >> angle;
						while (cin.fail())
						{
							cin.clear();
							cin.ignore();
							cout << "solo numeros" << endl;
							cin >> angle;

						}
						cout << endl;
						arregloM[cont].matrix[0][0] = 1;
						arregloM[cont].matrix[0][1] = 0;
						arregloM[cont].matrix[0][2] = 0;
						arregloM[cont].matrix[0][3] = 0;
						arregloM[cont].matrix[1][0] = 0;
						arregloM[cont].matrix[1][1] = cos(angle * PI / 180.0f);
						arregloM[cont].matrix[1][2] = -sin(angle * PI / 180.0f);
						arregloM[cont].matrix[1][3] = 0;
						arregloM[cont].matrix[2][0] = 0;
						arregloM[cont].matrix[2][1] = sin(angle * PI / 180.0f);
						arregloM[cont].matrix[2][2] = cos(angle * PI / 180.0f);
						arregloM[cont].matrix[2][3] = 0;
						arregloM[cont].matrix[3][0] = 0;
						arregloM[cont].matrix[3][1] = 0;
						arregloM[cont].matrix[3][2] = 0;
						arregloM[cont].matrix[3][3] = 1;

						cout << "Guardado exitoso!" << endl;
					}
					//Rotación en y
					else if (op2 == '2') {
						cout << "Ingrese el angulo: ";
						cin >> angle;
						while (cin.fail())
						{
							cin.clear();
							cin.ignore();
							cout << "solo numeros" << endl;
							cin >> angle;

						}
						cout << endl;
						arregloM[cont].matrix[0][0] = cos(angle * PI / 180.0f);
						arregloM[cont].matrix[0][1] = 0;
						arregloM[cont].matrix[0][2] = sin(angle * PI / 180.0f);
						arregloM[cont].matrix[0][3] = 0;
						arregloM[cont].matrix[1][0] = 0;
						arregloM[cont].matrix[1][1] = 1;
						arregloM[cont].matrix[1][2] = 0;
						arregloM[cont].matrix[1][3] = 0;
						arregloM[cont].matrix[2][0] = -sin(angle * PI / 180.0f);
						arregloM[cont].matrix[2][1] = 0;
						arregloM[cont].matrix[2][2] = cos(angle * PI / 180.0f);
						arregloM[cont].matrix[2][3] = 0;
						arregloM[cont].matrix[3][0] = 0;
						arregloM[cont].matrix[3][1] = 0;
						arregloM[cont].matrix[3][2] = 0;
						arregloM[cont].matrix[3][3] = 1;
						cout << "Guardado exitoso!" << endl;

					}
					//Rotación en z
					else if (op2 == '3') {
						cout << "Ingrese el angulo: ";
						cin >> angle;
						while (cin.fail())
						{
							cin.clear();
							cin.ignore();
							cout << "solo numeros" << endl;
							cin >> angle;

						}
						cout << endl;
						arregloM[cont].matrix[0][0] = cos(angle * PI / 180.0f);
						arregloM[cont].matrix[0][1] = -sin(angle * PI / 180.0f);
						arregloM[cont].matrix[0][2] = 0;
						arregloM[cont].matrix[0][3] = 0;
						arregloM[cont].matrix[1][0] = sin(angle * PI / 180.0f);
						arregloM[cont].matrix[1][1] = cos(angle * PI / 180.0f);
						arregloM[cont].matrix[1][2] = 0;
						arregloM[cont].matrix[1][3] = 0;
						arregloM[cont].matrix[2][0] = 0;
						arregloM[cont].matrix[2][1] = 0;
						arregloM[cont].matrix[2][2] = 1;
						arregloM[cont].matrix[2][3] = 0;
						arregloM[cont].matrix[3][0] = 0;
						arregloM[cont].matrix[3][1] = 0;
						arregloM[cont].matrix[3][2] = 0;
						arregloM[cont].matrix[3][3] = 1;
						cout << "Guardado exitoso!" << endl;
					}else {
						cout << "Error, opcion no valida." << endl;
						system("pause");
					}

				}while (op2 != '1' && op2 != '2' && op2 != '3');

				}
				//Llenado de escalamiento
				else if (op == '3') {
				float x = 0, y = 0, z = 0;
				cout << "Ingrese el escalamiento en x: ";
				cin >> x;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "solo numeros" << endl;
					cin >> x;

				}
				cout << "Ingrese el escalamiento en y: ";
				cin >> y;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "solo numeros" << endl;
					cin >> y;

				}
				cout << "Ingrese el escalamiento en z: ";
				cin >> z;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "solo numeros" << endl;
					cin >> z;

				}
				arregloM[cont].matrix[0][0] = x;
				arregloM[cont].matrix[0][1] = 0;
				arregloM[cont].matrix[0][2] = 0;
				arregloM[cont].matrix[0][3] = 0;
				arregloM[cont].matrix[1][0] = 0;
				arregloM[cont].matrix[1][1] = y;
				arregloM[cont].matrix[1][2] = 0;
				arregloM[cont].matrix[1][3] = 0;
				arregloM[cont].matrix[2][0] = 0;
				arregloM[cont].matrix[2][1] = 0;
				arregloM[cont].matrix[2][2] = z;
				arregloM[cont].matrix[2][3] = 0;
				arregloM[cont].matrix[3][0] = 0;
				arregloM[cont].matrix[3][1] = 0;
				arregloM[cont].matrix[3][2] = 0;
				arregloM[cont].matrix[3][3] = 1;
				}else {
					cout << "Error, opcion no valida." << endl;
					system("pause");
				}
			} while (op!='1'&&op!='2'&&op!='3');
		}
		if ((option == '1') && (cont >= 9)) {
			cout << "No se pueden ingresar mas matrices" << endl;
			cout << "Terminando el llenado" << endl;
			system("pause");
			cont = 9;
			option = '2';
		}
		else if (option == '2') {
			cout << "Terminando el llenado" << endl;
			system("pause");
			break;
		}
		else {
			cout << "Error, opcion no valida."<<endl;
			system("pause");
		}
	} while (option!='2');
}
void CalculateCompoundMatrix() {
	int first = cont;
	if (cont == 0) {
		cout << "No se llenó ningun elemento en la matriz" << endl;
		system("pause");
		return;
	}
	else {
		for (cont; cont > -1; cont--) {
			if (cont == first) {
				for (i = 0; i < 4; i++) {
					j = 0;
					for (j = 0; j < 4; j++) {
						matrixAux[i][j] = 0;
						for (k = 0; k < 4; k++) {
							matrixAux[i][j] += (arregloM[cont].matrix[i][k] * arregloM[cont - 1].matrix[k][j]);
						}
					}
				}
				cont = cont - 1;
			}
			else {
				//Producto
				for (i = 0; i < 4; i++) {
					j = 0;
					for (j = 0; j < 4; j++) {
						matrixCompound[i][j] = 0;
						for (k = 0; k < 4; k++) {
							matrixCompound[i][j] = (matrixAux[i][k] * arregloM[cont].matrix[k][j]) + matrixCompound[i][j];
						}
					}
				}
				//Asignación de la compuesta a la auxiliar
				for (i = 0; i < 4; i++) {
					for (j = 0; j < 4; j++) {
						matrixAux[i][j] = matrixCompound[i][j];
					}
				}
			}
		}
	}
}
void CalculateQuaternions() {
	float a=0;
	float b=0;
	float c=0;
	float Vx=0;
	float Vy=0;
	float Vz=0;
	float magnitude = 0;
	float s = 0;
	float angle = 0,angles=0,anglec=0;
	float matrixQuat[4][4];
	float vQuat[4];
	float pQuat[4];
	float M2[4][4];

	cout << "Introduzca el angulo:";
	cin >> angle;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> angle;

	}
	angle = angle / 2;
	anglec = angle * PI / 180.0f;
	angles = sin(angle * PI / 180.0f);
	s = cos(anglec);
	cout << "introduzca x: ";
	cin >> Vx;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> Vx;

	}
	cout << "introduzca y: ";
	cin >> Vy;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> Vy;

	}
	cout << "introduzca z: ";
	cin >> Vz;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> Vz;

	}

	magnitude = sqrt((Vx * Vx) + (Vy * Vy) + (Vz * Vz));
	a = (Vx / magnitude) * (angles);
	b = (Vy / magnitude)* (angles);
	c = (Vz / magnitude)* (angles);

	matrixQuat[0][0] = 1-2*b*b-2*c*c;
	matrixQuat[0][1] = 2 * a*b - 2 * s*c;
	matrixQuat[0][2] = 2 * a*c + 2 * s*b;
	matrixQuat[0][3] = 0;

	matrixQuat[1][0] = 2 * a * b + 2 * s * c;
	matrixQuat[1][1] = 1 - 2 * a*a - 2 * c*c;
	matrixQuat[1][2] = 2 * b*c - 2 * s*a;
	matrixQuat[1][3] = 0;

	matrixQuat[2][0] = 2 * a * c - 2 * s * b;
	matrixQuat[2][1] = 2 * b * c + 2 * s * a;
	matrixQuat[2][2] = 1 - 2 * a*a- 2 * b*b;
	matrixQuat[2][3] = 0;

	matrixQuat[3][0] = 0;
	matrixQuat[3][1] = 0;
	matrixQuat[3][2] = 0;
	matrixQuat[3][3] = 1;

	cout << endl;

	cout << "La matriz es:" << endl;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (matrixQuat[i][j] >= -Err_Range && matrixQuat[i][j] <= Err_Range)matrixQuat[i][j] = 0;
			cout << matrixQuat[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	cout << "Introduzca el punto en x: ";
	cin >> vQuat[0];
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> vQuat[0];

	}
	cout << "Introduzca el punto en y: ";
	cin >> vQuat[1];
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> vQuat[1];

	}
	cout << "Introduzca el punto en z: ";
	cin >> vQuat[2];
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "solo numeros" << endl;
		cin >> vQuat[2];

	}
	vQuat[3] = 1;
	//Multiplicación por punto
	for (i = 0; i < 4; i++) {
		pQuat[i] = 0;
		for (k = 0; k < 4; k++) {
			pQuat[i] += (matrixQuat[i][k] * vQuat[k]);
		}

	}
	//Impresión del punto rotado
	cout << "El punto rotado es: " << endl;
	for (i = 0; i < 4; i++) {
		if (pQuat[i] >= -Err_Range && pQuat[i] <= Err_Range)pQuat[i] = 0;
		cout << pQuat[i] << " ";

	}
	system("pause");
}
void MatrixVector() {
	char option = 0;
	int cont2 = -1;
	char opM = 0;
	//agregar puntos
	do {
		cout << "Desea agregar otro punto? 1.Si/2.No:";
		cin >> option;
		cout << endl;
		if (option == '1'&&cont2<9) {
			cont2 = cont2 + 1;
			cout << "Ingrese el valor en x: ";
			cin >> arregloV[cont2].matrix[0];
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> arregloV[cont2].matrix[0];

			}
			cout << "Ingrese el valor en y: ";
			cin >> arregloV[cont2].matrix[1];
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> arregloV[cont2].matrix[1];

			}
			cout << "Ingrese el valor en z: ";
			cin >> arregloV[cont2].matrix[2];
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> arregloV[cont2].matrix[2];

			}
			arregloV[cont2].matrix[3]=1;
		}
		else if (option=='1'&&cont>=9) {
			cout << "No se pueden ingresar mas puntos" << endl;
			cout << "Terminando el llenado" << endl;
			system("pause");
			cont2 = 9;
			option = '2';
		}
		else if (option == '2') {
			cout << "Terminando de llenar los puntos..." << endl;
			system("pause");
		}
		else {
			cout << "error, opcion no válida" << endl;
			system("pause");
		}
	} while (option != '2');
	//agregar la matriz 
	do{
		cout << "Que transformación desea agregar?" << endl;
		cout << "1.- Traslacion" << endl;
		cout << "2.- Rotacion" << endl;
		cout << "3.- Escalamiento" << endl;
		cout << "4.- Matriz Compuesta" << endl;
		cout << "opcion: ";
		cin >> opM;
		cout << endl;
		switch (opM) {
		case'1': {
			float x = 0, y = 0, z = 0;
			cout << "Ingrese la traslacion en x: ";
			cin >> x;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> x;

			}
			cout << "Ingrese la traslacion en y: ";
			cin >> y;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> y;

			}
			cout << "Ingrese la traslacion en z: ";
			cin >> z;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> z;

			}
			matrixV[0][0] = 1;
			matrixV[0][1] = 0;
			matrixV[0][2] = 0;
			matrixV[0][3] = x;
			matrixV[1][0] = 0;
		    matrixV[1][1] = 1;
			matrixV[1][2] = 0;
			matrixV[1][3] = y;
			matrixV[2][0] = 0;
			matrixV[2][1] = 0;
			matrixV[2][2] = 1;
			matrixV[2][3] = z;
			matrixV[3][0] = 0;
			matrixV[3][1] = 0;
			matrixV[3][2] = 0;
			matrixV[3][3] = 1;

			if (cont == -1) {
				cout << "No se ingresaron puntos" << endl;
				system("pause");
			}
			else {
				for (j = 0; j <= cont2; j++) {
					arregloP[j].matrix[0] = arregloV[j].matrix[0] + x;
					arregloP[j].matrix[1] = arregloV[j].matrix[1] + y;
					arregloP[j].matrix[2] = arregloV[j].matrix[2] + z;
					arregloP[j].matrix[3] = 1;
				}


				cout << "Imprimiendo los nuevos puntos:" << endl;
				cout << "Nuevos       Original" << endl;
				for (i = 0; i <= cont2; i++) {
					cout << "El punto: P" << i << endl;
					for (j = 0; j < 4; j++) {
						if (arregloP[i].matrix[j] >= -Err_Range && arregloP[i].matrix[j] <= Err_Range)arregloP[i].matrix[j] = 0;
						cout << arregloP[i].matrix[j] << "         " << arregloV[i].matrix[j] << endl;;
					}
					cout << endl;
				}
				system("pause");
			}

		}
				 break;
		case'2': {
			char op2 = 0;
			float angle = 0;
			do {
				cout << "En que eje desea rotar?" << endl;
				cout << "1.- Eje x" << endl;
				cout << "2.- Eje y" << endl;
				cout << "3.- Eje z" << endl;
				cin >> op2;
				cout << endl;
				//Rotación en x
				if (op2 == '1') {
					cout << "Ingrese el angulo: ";
					cin >> angle;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "solo numeros" << endl;
						cin >> angle;

					}
					matrixV[0][0] = 1;
					matrixV[0][1] = 0;
					matrixV[0][2] = 0;
					matrixV[0][3] = 0;
					matrixV[1][0] = 0;
					matrixV[1][1] = cos(angle * PI / 180.0f);
					matrixV[1][2] = -sin(angle * PI / 180.0f);
					matrixV[1][3] = 0;
					matrixV[2][0] = 0;
					matrixV[2][1] = sin(angle * PI / 180.0f);
					matrixV[2][2] = cos(angle * PI / 180.0f);
					matrixV[2][3] = 0;
					matrixV[3][0] = 0;
					matrixV[3][1] = 0;
					matrixV[3][2] = 0;
					matrixV[3][3] = 1;

				}
				//Rotación en y
				else if (op2 == '2') {
					cout << "Ingrese el angulo: ";
					cin >> angle;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "solo numeros" << endl;
						cin >> angle;

					}
					matrixV[0][0] = cos(angle * PI / 180.0f);
					matrixV[0][1] = 0;
					matrixV[0][2] = sin(angle * PI / 180.0f);
					matrixV[0][3] = 0;
					matrixV[1][0] = 0;
					matrixV[1][1] = 1;
					matrixV[1][2] = 0;
					matrixV[1][3] = 0;
					matrixV[2][0] = -sin(angle * PI / 180.0f);
					matrixV[2][1] = 0;
					matrixV[2][2] = cos(angle * PI / 180.0f);
					matrixV[2][3] = 0;
					matrixV[3][0] = 0;
					matrixV[3][1] = 0;
					matrixV[3][2] = 0;
					matrixV[3][3] = 1;

				}
				//Rotación en z
				else if (op2 == '3') {
					cout << "Ingrese el angulo: ";
					cin >> angle;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "solo numeros" << endl;
						cin >> angle;

					}
					matrixV[0][0] = cos(angle * PI / 180.0f);
					matrixV[0][1] = -sin(angle * PI / 180.0f);
					matrixV[0][2] = 0;
					matrixV[0][3] = 0;
					matrixV[1][0] = sin(angle * PI / 180.0f);
					matrixV[1][1] = cos(angle * PI / 180.0f);
					matrixV[1][2] = 0;
					matrixV[1][3] = 0;
					matrixV[2][0] = 0;
					matrixV[2][1] = 0;
					matrixV[2][2] = 1;
					matrixV[2][3] = 0;
					matrixV[3][0] = 0;
					matrixV[3][1] = 0;
					matrixV[3][2] = 0;
					matrixV[3][3] = 1;
				}
				else {
					cout << "Error, opcion no valida." << endl;
					system("pause");
				}
			}while (op2 != '1' && op2 != '2' && op2 != '3');

			if (cont2 == -1) {
				cout << "No se llenó ningun punto" << endl;
				system("pause");
				return;
			}
			else {
				j = cont2;
				for (j=cont2; j > -1; j--) {

					for (i = 0; i < 4; i++) {
						arregloP[j].matrix[i] = 0;
						for (k = 0; k < 4; k++) {
							arregloP[j].matrix[i] = (matrixV[i][k] * arregloV[j].matrix[k]) + arregloP[j].matrix[i];
						}

					}



				}

				cout << "Imprimiendo los nuevos puntos:" << endl;
				cout << "Nuevos     Originales" << endl;
				for (i = 0; i <= cont2; i++) {
					cout << "El punto: P" << i << endl;
					for (j = 0; j < 4; j++) {
						if (arregloP[i].matrix[j] >= -Err_Range && arregloP[i].matrix[j] <= Err_Range)arregloP[i].matrix[j] = 0;
						cout << arregloP[i].matrix[j] << "     "<<arregloV[i].matrix[j]<<endl;
					}
					cout << endl;
				}
				system("pause");
			}
		}
				 break;
		case '3': {
			float x = 0, y = 0, z = 0;
			cout << "Ingrese el escalamiento en x: ";
			cin >> x;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> x;

			}
			cout << "Ingrese el escalamiento en y: ";
			cin >> y;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> y;

			}
			cout << "Ingrese el escalamiento en z: ";
			cin >> z;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "solo numeros" << endl;
				cin >> z;

			}
			matrixV[0][0] = x;
			matrixV[0][1] = 0;
			matrixV[0][2] = 0;
			matrixV[0][3] = 0;
			matrixV[1][0] = 0;
			matrixV[1][1] = y;
			matrixV[1][2] = 0;
			matrixV[1][3] = 0;
			matrixV[2][0] = 0;
			matrixV[2][1] = 0;
			matrixV[2][2] = z;
			matrixV[2][3] = 0;
			matrixV[3][0] = 0;
			matrixV[3][1] = 0;
			matrixV[3][2] = 0;
			matrixV[3][3] = 1;

			for (j = 0; j <= cont2; j++) {
				arregloP[j].matrix[0] = arregloV[j].matrix[0] * x;
				arregloP[j].matrix[1] = arregloV[j].matrix[1] * y;
				arregloP[j].matrix[2] = arregloV[j].matrix[2] * z;
				arregloP[j].matrix[3] = 1;
			}


			cout << "Imprimiendo los nuevos puntos:" << endl;
			cout << "Nuevos           Originales" << endl;
			for (i = 0; i <= cont2; i++) {
				cout << "El punto: P" << i << endl;
				for (j = 0; j < 4; j++) {
					if (arregloP[i].matrix[j] >= -Err_Range && arregloP[i].matrix[j] <= Err_Range)arregloP[i].matrix[j] = 0;
					cout << arregloP[i].matrix[j] << "       "<<arregloV[i].matrix[j]<<endl;
				}
				cout << endl;
			}
			system("pause");

		}
				  break;
		case'4': {
			FillMArray();
			CalculateCompoundMatrix();
			//Impresión de la matriz compuesta
			cout << endl;
			cout << "La matriz compuesta es:" << endl;
			for (i = 0; i < m; i++) {
				j = 0;
				for (j = 0; j < p; j++) {
					cout << matrixCompound[i][j] << " ";
				}
				cout << endl;
			}
			system("pause");
			//Multiplicar la matriz x el vector
			if (cont2 == -1) {
				cout << "No se llenó ningun punto" << endl;
				system("pause");
				return;
			}
			else {
				for (cont2; cont2 > -1; cont2--) {

					for (i = 0; i < 4; i++) {
						arregloP[cont2].matrix[i] = 0;
						for (k = 0; k < 4; k++) {
							arregloP[cont2].matrix[i] = (matrixV[i][k] * arregloV[cont2].matrix[i]) + arregloP[cont2].matrix[i];
						}

					}



				}
				//Impresión
				cout << "Imprimiendo los nuevos puntos:" << endl;
				cout << "Nuevos           Originales" << endl;
				for (i = 0; i <= cont2; i++) {
					cout << "El punto: P" << i << endl;
					for (j = 0; j < 4; j++) {
						if (arregloP[i].matrix[j] >= -Err_Range && arregloP[i].matrix[j] <= Err_Range)arregloP[i].matrix[j] = 0;
						cout << arregloP[i].matrix[j] << "       " << arregloV[i].matrix[j] << endl;
					}
					cout << endl;
				}
				system("pause");
			}
		}
				 break;
		default:
			break;
		}
	} while (opM != '1' && opM != '2' && opM != '3');
	
	
}

/*
En la matriz de traslacion, cuando se van a sacar los nuevos puntos usando el vector,
se suman las x de la matriz con las del vector
En la matriz de rotación si se hace el producto de matrices
En la matriz escalar se multiplican las x con las x's
en la matriz compuesta si es el producto de matrices


*/
float Validacion() {
	float x;
	char buffer[20] = "";
	int car = 0, num = 0, slash = 0, point = 0,r=0;
	bool fraccion = false,falla=false;
	do {
		cin.clear();
		cin.ignore();
		cin >> buffer;
		if (buffer[r] == '\0') {
			cout << "vacio, llene de nuevo" << endl;
			falla == true;
		}
		else {
			while (buffer[r] != '\0') {
				if (buffer[r] == 46) {
					point = point + 1;
				}
				else if (buffer[r] == 47) {
					slash = slash + 1;
				}
				else if (buffer[r] > 47 && buffer[r] < 58) {
					num = num + 1;
				}
				else {
					car = car + 1;
				}
				r++;
			}

			if (car > 0) {
				cout << "Solo numeros. Preparese para ingresar de nuevo" << endl;
				falla = true;
			}
			else if (slash > 1) {
				cout << "Solo un slash en caso de fracciones. Preparese para ingresar de nuevo" << endl;
				falla = true;
			}
			else if (point > 1) {
				cout << "Solo un punto por numero. Preparese para ingresar de nuevo." << endl;
				falla = true;
			}
			else {
				falla = false;
			}
		}

	} while (falla);
	//Validación de la fracción
	if (slash == 1) {
		int t = 0, n=0;
		float a=0, b = 0,c=0;
		while (buffer[t] != '\0') {
			if (buffer[t] == 47) {
				break;
			}
			t++;
		}
		string a1(buffer);
		string b1(buffer);
		n = a1.find('/');
		a = stof(a1.substr(0, n ));
		b = stof(b1.substr(n + 1, b1.length()));
		if (b != 0) {
			c = a / b;
			x = c;
			cin.clear();
			cin.ignore();
			return x;
		}
		else {
			do {
				cout << "Error, el denominador no puede ser cero. Ingrese un denominador válido" << endl;
				cin >> b;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "solo numeros" << endl;
					cin >> b;

				}
			} while (b == 0);
			c = a / b;
			x = c;
			return x;
			
		}


	}
	//Si es un solo numero
	else {
		//Si el numero tiene punto decimal
		if (point == 1) {
			x = stof(buffer);
			return x;
		}
		//Si el numero es entero
		else if (point == 0) {
			x = stoi(buffer);
			return x;
		}

	}



}