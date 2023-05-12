#include <iostream>
#include <locale>
#include <vector>
using namespace std;

//Ejercicios 1
int repeticiones(char c, string palabra) {
	int cont = 0;
	for (char letra : palabra) {
		if (letra == c) {
			//Cada char si es igual se va sumando al contador
			cont++;
		}
	}
	return cont;
}

int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else { //Caso Base
		return n * factorial(n - 1);
	}
}

int Ejercicio_1() {
	string palabra;
	cout << "Ingrese PALABRA para calcular permutaciones: ";
	cin >> palabra;

	//Verificar que la String sea mayor que 6
	if (palabra.length() < 6) {
		cout << "Palabra debe ser MAYOR O IGUAL a 6!\n"
			<< "Ingrese una nueva palabra...\n\n";
		return 0;
	}

	//Salida de Reps
	cout << "Letras que se repiten y el número de veces:" << endl;
	vector<char> letras_Rep;
	for (char letra : palabra) {
		int reps = repeticiones(letra, palabra);
		if(reps > 1 && find(letras_Rep.begin(), letras_Rep.end(), letra) == letras_Rep.end()) {
			cout << letra << ": " << reps << " veces" << endl;
			letras_Rep.push_back(letra);
		}
	}

	// Permutaciones con Factorial
	int total_permutaciones = factorial(palabra.length());
	for (char letra = 'A'; letra <= 'Z'; letra++) {
		int reps = repeticiones(letra, palabra);
		if (reps > 1) {
			total_permutaciones /= factorial(reps);
		}
	}

	cout << "Número de permutaciones: " << total_permutaciones << endl << endl;
	return 0;
}

//Ejercicio 2
int num_repeticiones(char c, const string& palabra) {
	int cont = 0;
	for (char letra : palabra) {
		if (letra == c) {
			cont++;
		}
	}
	return cont;
}

string buscar_secuencia(const string& cadena) {
	string secuencia_repetida;
	string secuencia_actual;

	for (char c : cadena) {
		if (secuencia_actual.empty() || c == secuencia_actual.back()) {
			secuencia_actual += c;
		}
		else {
			if (secuencia_actual.length() > secuencia_repetida.length()) {
				secuencia_repetida = secuencia_actual;
			}
			secuencia_actual = string(1, c);
		}
	}

	if (secuencia_actual.length() > secuencia_repetida.length()) {
		secuencia_repetida = secuencia_actual;
	}

	return secuencia_repetida;
}

void analizar_cadena_adn(const string& cadena) {
	double total = cadena.length();
	
	//Valores de Adenina
	double adenina = num_repeticiones('A', cadena);
	double porcentaje_adenina = (adenina / total) * 100;

	//Valores de Citosina
	double citosina = num_repeticiones('C', cadena);
	double porcentaje_citosina = (citosina / total) * 100;

	//Valores de Guanina
	double guanina = num_repeticiones('G', cadena);
	double porcentaje_guanina = (guanina / total) * 100;

	//Valores de Timina
	double timina = num_repeticiones('T', cadena);
	double porcentaje_timina = (timina / total) * 100;

	string secuencia_repetida = buscar_secuencia(cadena);

	cout << "Total de nucleótidos: " << total << endl;
	cout << "Numero de Ocurrencias de cada Nucleotico: \n";
	cout << "Adenina (A): " << adenina << endl;
	cout << "Citosina (C): " << citosina << endl;
	cout << "Guanina (G): " << guanina << endl;
	cout << "Timina (T): " << timina << endl << endl;
	
	cout << "Análisis de la cadena de ADN:" << endl;
	cout << "Adenina (A): (" << porcentaje_adenina << "%)" << endl;
	cout << "Citosina (C): (" << porcentaje_citosina << "%)" << endl;
	cout << "Guanina (G): (" << porcentaje_guanina << "%)" << endl;
	cout << "Timina (T): (" << porcentaje_timina << "%)" << endl;
	cout << "Secuencia más larga de nucleótidos consecutivos que se repiten: " << secuencia_repetida << endl << endl;
}

int Ejercicio_2() {
	string cadena;

	cout << "Ingrese una cadena de ADN: ";
	cin >> cadena;

	analizar_cadena_adn(cadena);

	return 0;
}

// Menu de Opciones
int menu() {
	setlocale(LC_ALL, "spanish");
	int opcion = 0;

	do {
		cout << "------- MENU ------- \n"
			<< "1) Permutaciones con Repeticion\n"
			<< "2) Analisis de ADN\n\n"
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
			cout << "- 1) Permutaciones con Repeticion - \n";
			Ejercicio_1();
		}
			  break;

		case 2: {
			cout << "- 2) Análisis de ADN - \n";
			Ejercicio_2();
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
	setlocale(LC_ALL, "spanish");
	menu();
}
