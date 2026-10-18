#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Marcador global
int partidas = 0;
int ganadas = 0;
int perdidas = 0;

// Prototipos
string elegirPalabraAleatoria();
string aMayusculas(string s);
bool palabraValida(string p);
char leerLetra(string usadas);
string crearOculta(string palabra);
string actualizarOculta(string palabra, string oculta, char letra);
void dibujarAhorcado(int errores);
bool jugarPartida(string palabra);
string leerPalabraSecreta();
int leerOpcion();
void mostrarMarcador();

// Convierte una cadena a mayusculas
string aMayusculas(string s) {
    for (int i = 0; i < (int)s.length(); i++) {
        s[i] = toupper((unsigned char)s[i]);
    }
    return s;
}

// Valida la palabra secreta
bool palabraValida(string p) {
    if (p.length() < 4 || p.length() > 12) {
        return false;
    }

    for (int i = 0; i < (int)p.length(); i++) {
        if (p[i] < 'A' || p[i] > 'Z') {
            return false;
        }
    }

    return true;
}

// Elige una palabra al azar usando rand() y switch
string elegirPalabraAleatoria() {
    int numero = rand() % 10;

    switch (numero) {
        case 0: return "CASA";
        case 1: return "PERRO";
        case 2: return "GATO";
        case 3: return "CODIGO";
        case 4: return "COMPUTADORA";
        case 5: return "VENTANA";
        case 6: return "ESCUELA";
        case 7: return "MUSICA";
        case 8: return "PELOTA";
        case 9: return "CAMINO";
        default: return "CASA";
    }
}

// Lee una palabra secreta hasta que sea valida
string leerPalabraSecreta() {
    string palabra;

    while (true) {
        cout << "Escriba la palabra secreta (4 a 12 letras): ";

        // Si se acaba la entrada (Ctrl+D / Ctrl+Z), se sale del programa
        if (!getline(cin, palabra)) {
            exit(0);
        }

        palabra = aMayusculas(palabra);

        if (palabraValida(palabra)) {
            return palabra;
        }

        cout << "Error: use entre 4 y 12 letras de la A a la Z,";
        cout << " sin numeros, espacios, tildes ni enie.\n";
    }
}

// Crea la palabra oculta
string crearOculta(string palabra) {
    string oculta = "";

    for (int i = 0; i < (int)palabra.length(); i++) {
        oculta += '_';
    }

    return oculta;
}

// Descubre todas las posiciones de una letra
string actualizarOculta(string palabra, string oculta, char letra) {
    for (int i = 0; i < (int)palabra.length(); i++) {
        if (palabra[i] == letra) {
            oculta[i] = letra;
        }
    }

    return oculta;
}

// Dibuja el ahorcado segun los errores
// 1 cabeza, 2 tronco, 3 brazo izq., 4 brazo der., 5 pierna izq., 6 pierna der.
void dibujarAhorcado(int errores) {
    cout << "\n +---+\n";

    cout << " |   ";
    if (errores >= 1) cout << "O";

    cout << "\n |  ";
    if (errores >= 3) cout << "/";
    else cout << " ";
    if (errores >= 2) cout << "|";
    if (errores >= 4) cout << "\\";

    cout << "\n |  ";
    if (errores >= 5) cout << "/";
    else cout << " ";
    if (errores >= 6) cout << " \\";

    cout << "\n===\n";
}

// Lee y valida una letra que no se haya utilizado
char leerLetra(string usadas) {
    string entrada;

    while (true) {
        cout << "Letra: ";

        if (!getline(cin, entrada)) {
            exit(0);
        }

        if (entrada.length() != 1) {
            cout << "Error: escriba una sola letra (A-Z).\n";
            continue;
        }

        char letra = toupper((unsigned char)entrada[0]);

        if (letra < 'A' || letra > 'Z') {
            cout << "Error: solo se permiten letras de la A a la Z.\n";
            continue;
        }

        bool repetida = false;

        for (int i = 0; i < (int)usadas.length(); i++) {
            if (usadas[i] == letra) {
                repetida = true;
                break;
            }
        }

        if (repetida) {
            cout << "Ya usaste la letra " << letra << ".\n";
            continue;
        }

        return letra;
    }
}

// Controla una partida completa
bool jugarPartida(string palabra) {
    palabra = aMayusculas(palabra);

    string oculta = crearOculta(palabra);
    string usadas = "";
    int errores = 0;

    while (errores < 6 && oculta != palabra) {
        dibujarAhorcado(errores);

        cout << "\nPalabra: ";

        for (int i = 0; i < (int)oculta.length(); i++) {
            cout << oculta[i] << " ";
        }

        cout << "\nUsadas: ";

        if (usadas == "") {
            cout << "Ninguna";
        } else {
            cout << usadas;
        }

        cout << "\nIntentos restantes: " << 6 - errores << "\n";

        char letra = leerLetra(usadas);
        usadas += letra;

        if (palabra.find(letra) != string::npos) {
            oculta = actualizarOculta(palabra, oculta, letra);
            cout << "Correcto: la letra " << letra
                 << " esta en la palabra.\n";
        } else {
            errores++;
            cout << "Incorrecto. Has perdido un intento.\n";
        }
    }

    dibujarAhorcado(errores);

    cout << "\nPalabra: ";

    for (int i = 0; i < (int)oculta.length(); i++) {
        cout << oculta[i] << " ";
    }

    cout << "\n";

    if (oculta == palabra) {
        cout << "\nFELICIDADES, GANASTE.\n";
        cout << "Adivinaste la palabra: " << palabra << "\n";
        return true;
    }

    cout << "\nPERDISTE. Se acabaron los 6 intentos.\n";
    cout << "La palabra secreta era: " << palabra << "\n";
    return false;
}

// Lee una opcion valida del menu
int leerOpcion() {
    string entrada;

    while (true) {
        cout << "\n===== JUEGO DEL AHORCADO =====\n";
        cout << "1. Jugar contra la computadora\n";
        cout << "2. Dos jugadores\n";
        cout << "3. Ver marcador\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!getline(cin, entrada)) {
            exit(0);
        }

        if (entrada.length() != 1 ||
            entrada[0] < '1' || entrada[0] > '4') {
            cout << "Error: introduzca un numero entero del 1 al 4.\n";
            continue;
        }

        return entrada[0] - '0';
    }
}

// Muestra el marcador
void mostrarMarcador() {
    cout << "\n===== MARCADOR =====\n";
    cout << "Partidas jugadas: " << partidas << "\n";
    cout << "Partidas ganadas: " << ganadas << "\n";
    cout << "Partidas perdidas: " << perdidas << "\n";
}

// Programa principal
int main() {
    srand((unsigned int)time(0));

    int opcion;
    string palabra;

    do {
        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                palabra = elegirPalabraAleatoria();

                cout << "\nLa computadora ha elegido una palabra.\n";
                partidas++;

                if (jugarPartida(palabra)) {
                    ganadas++;
                } else {
                    perdidas++;
                }
                break;

            case 2:
                cout << "\nJUGADOR 1: escriba la palabra secreta.\n";
                palabra = leerPalabraSecreta();

                // Oculta la palabra en la consola
                for (int i = 0; i < 30; i++) {
                    cout << "\n";
                }

                cout << "JUGADOR 2: adivine la palabra.\n";
                partidas++;

                if (jugarPartida(palabra)) {
                    ganadas++;
                } else {
                    perdidas++;
                }
                break;

            case 3:
                mostrarMarcador();
                break;

            case 4:
                cout << "\nGracias por jugar.\n";
                mostrarMarcador();
                break;
        }
    } while (opcion != 4);

    return 0;
}
