#include <iostream>
using namespace std;

//Ejercicios 1


// Menu de Opciones
int menu() {
	setlocale(LC_ALL, "spanish");
	int opcion = 0;

	do {
		cout << "------- MENU ------- \n"
			<< "1)  \n"
			<< "2)  \n\n"
			<< "0) SALIDA \n\n";

		cout << ">> Ingrese una opcion del menu: ";
		cin >> opcion;

		cout << "La opcion escojida es :" << opcion << endl << endl;

		switch (opcion) {
		case 0: {
			cout << "Gracias por participar!\n"
				<< "Feliz dia :D";
		}
			  break;

		case 1: {
			cout << "- 1)  - \n";

		}
			  break;

		case 2: {
			cout << "- 2)  - \n";
			
		}
			  break;

		default: {
			cout << "Valor digitado no es valido\n\n";
		}
			   break;

		}

	} while (opcion != 0);

	return opcion;
}

int main()
{
	menu();
}
