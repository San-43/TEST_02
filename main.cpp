/// Sandro Martínez Pérez
/// Cuenta::475218

#include <iostream>
#include <clocale>
#include <limits>

double temperatura(double c);
void figura();
void caracter(char tecla);
void salir();
double valor();

using namespace std;

int main() {
    char option, tecla;
    double c;
    bool isBack = true;
    char band;

    setlocale(LC_ALL, "spanish");

    do {
        system("cls");
        system("color 0c");

        cout << "\t\t" << "+---------------++------------------++----------------------+" << endl;
        cout << "\t\t" << "|---------------||     MENU     ||--------------------------|" << endl;
        cout << "\t\t" << "+----------++---++------------------++---++-----------------+" << endl;
        cout << "\t\t" << "|----------|| T) - t) TEMPERATURA              ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------------+" << endl;
        cout << "\t\t" << "|----------|| F) - f) FIGURA                   ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------------+" << endl;
        cout << "\t\t" << "|----------|| E) - e) TECLA                    ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------------+" << endl;
        cout << "\t\t" << "|----------|| Q) - q) SALIR                    ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------------+" << endl << endl;
        cout << "\tOPCIÓN A ELEGIR: ";
        cin >> option;

        switch (option) {
            case 'T': case 't':
                cin.ignore(numeric_limits<int>::max(), '\n');
                c = valor();
                cout << c << " grados Celcius equivalen a " << temperatura(c) << " grados Fahrenheit." << endl;
                cout << endl;
                system("pause");

                break;
            case 'F': case 'f':
                cin.ignore(numeric_limits<int>::max(), '\n');
                figura();
                cout << endl;
                system("pause");

                break;
            case 'E': case 'e':
                cin.ignore(numeric_limits<int>::max(), '\n');
                system("cls");
                cout << "Pulse una tecla!!!";
                cin >> tecla;
                caracter(tecla);
                cout << endl;
                system("pause");

                break;
            case 'Q': case 'q':
                salir();
                isBack = false;
                break;
            default:
                cin.ignore(numeric_limits<int>::max(), '\n');
                cout << "Opción incorrecta, verifique las opciones a seleccionar en el inicio del programa.\n\n";
                system("pause");
                continue;
        }
        system("cls");
        if (isBack) {
            cout << "Desea regresar al programa? S o s para SI, cualquier otra tecla para no." << endl;
            cin >> band;
            if (band == 'S' || band == 's') {
                cin.ignore(numeric_limits<int>::max(), '\n');
                continue;
            } else {
                cout << "\n\n BYE!!!";
                return 0;
            }
        }

    } while(isBack);

    return 0;
}

double temperatura(double c) {
    return (c*1.8 + 32);
}

void figura() {
    for (int i = 1; i < 10; i += 2) {
        for (int j = 0; j < i; j+= 2) {
            cout << i;
        }
        cout << endl;
    }
}

void caracter(char tecla) {
    system("cls");

    if (isalpha(tecla) != 0) {

        if (tecla >= 'a' && tecla <= 'z') {
            cout << "La tecla pulsada es una letra en minúsculas." << endl;
        } else {
            cout << "La tecla pulsada es una letra en mayúsculas." << endl;
        }
    } else if (isdigit(tecla) != 0) {
        cout << "La tecla pulsada es un número." << endl;
    } else {
        cout << "La tecla pulsada es un caracter especial." << endl;
    }
    cin.ignore(numeric_limits<int>::max(), '\n');
}

void salir() {
    cout << "GRACIAS POR USAR MI APLICACIÓN\n" << endl;
    cout << "\t\t\tAtte. Sandro Martínez Pérez\n\n";
    system("pause");
}

double valor() {
    double x;

    system("cls");
    cout << "Ingrese los grados celcius a convertir: ";
    do {
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nError... Valor incorrecto... Solo se admiten números\n";
            cout << "Ingrese los grados celcius a convertir: ";
        }else {
            cout << endl;
            break;
        }
    }while (true);

    return x;
}