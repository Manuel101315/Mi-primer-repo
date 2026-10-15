#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Configurar la consola en Windows para habilitar colores ANSI y caracteres especiales
    system("chcp 65001 > nul"); 
    system("mode con cols=80 lines=25"); 

    char repetir = 's';

    // Códigos de colores ANSI
    string colorCyan = "\033[1;36m";
    string colorVerde = "\033[1;32m";
    string colorAmarillo = "\033[1;33m";
    string colorMagenta = "\033[1;35m";
    string colorRojo = "\033[1;31m";
    string resetColor = "\033[0m";

    // Bucle principal del programa controlado por la variable 'repetir'
    while (repetir == 's' || repetir == 'S') {
        system("cls"); // Limpiar pantalla

        int n = 0;
        string op[10];

        // Presentación centrada y con colores
        cout << "\n\n";
        cout << colorCyan << "\t    ========================================" << resetColor << endl;
        cout << colorCyan << "\t          SIMULADOR DE RULETA VIRTUAL       " << resetColor << endl;
        cout << colorCyan << "\t    ========================================" << resetColor << endl << endl;

        // Pedir cantidad de opciones con validación
        while (n != 2 && n != 3 && n != 4 && n != 10) {
            cout << colorAmarillo << "    Elige el numero de opciones (2, 3, 4 o 10): " << resetColor;
            cin >> n;
            if (n != 2 && n != 3 && n != 4 && n != 10) {
                cout << colorRojo << "    [X] Opcion invalida. Intenta nuevamente.\n\n" << resetColor;
            }
        }

        cout << "\n" << colorMagenta << "    ----------------------------------------" << resetColor << endl;
        cout << colorMagenta << "    Ingresa las opciones (palabras, numeros o signos):" << resetColor << endl;
        cout << colorMagenta << "    ----------------------------------------" << resetColor << endl;

        // Ingresar las opciones
        for (int i = 0; i < n; i++) {
            cout << "    Opcion " << (i + 1) << ": ";
            cin >> op[i];
        }

        // Simulación visual de giro
        cout << "\n    Girando la ruleta";
        for (int i = 0; i < 3; i++) {
            cout << ".";
            for (long long j = 0; j < 200000000; j++); // Pausa visual
        }
        cout << endl;

        // Girar ruleta de forma aleatoria
        srand(time(0));
        int ganador = rand() % n;

        // Mostrar resultado destacado centrado y en color verde brillante
        cout << "\n\n";
        cout << colorVerde << "\t    ========================================" << endl;
        cout << colorVerde << "\t       ¡EL GANADOR ES: " << op[ganador] << " !       " << endl;
        cout << colorVerde << "\t    ========================================" << resetColor << endl << endl;

        // Preguntar si desea repetir de forma clara y segura
        cout << colorAmarillo << "    ¿Deseas jugar otra vez? (s/n): " << resetColor;
        cin >> repetir;
        cout << endl;
    }

    cout << colorCyan << "\n    ¡Gracias por usar la ruleta! Hasta luego.\n\n" << resetColor;

    return 0;
}