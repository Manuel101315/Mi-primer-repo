#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// --- Definición de códigos de color ANSI ---
const string RESET   = "\033[0m";
const string ROJO    = "\033[1;31m";
const string VERDE   = "\033[1;32m";
const string AMARILLO= "\033[1;33m";
const string AZUL    = "\033[1;34m";
const string CIAN    = "\033[1;36m";
const string MAGENTA = "\033[1;35m";

// Prototipos de funciones
string elegirPalabraAleatoria();
string aMayusculas(string s);
bool palabraValida(string p);
char leerLetra(string &usadas);
string crearOculta(string palabra);
string actualizarOculta(string palabra, string oculta, char letra);
void dibujarAhorcado(int errores);
bool jugarPartida(string palabra);
void jugarModoJuego(int modo, int &partidasJugadas, int &partidasGanadas, int &partidasPerdidas);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int opcion = 0;
    int partidasJugadas = 0;
    int partidasGanadas = 0;
    int partidasPerdidas = 0;

    do {
        cout << CIAN << "\n==============================\n";
        cout << "      JUEGO DEL AHORCADO      \n";
        cout << "==============================\n" << RESET;
        cout << "1. Jugar contra la computadora (5 rondas)\n";
        cout << "2. Dos jugadores (5 rondas)\n";
        cout << "3. Ver marcador global\n";
        cout << "4. Salir\n";
        cout << AMARILLO << "Seleccione una opcion (1-4): " << RESET;

        if (!(cin >> opcion)) {
            cout << ROJO << "Error: Debe ingresar un numero entero.\n" << RESET;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');

        switch (opcion) {
            case 1:
                jugarModoJuego(1, partidasJugadas, partidasGanadas, partidasPerdidas);
                break;
            case 2:
                jugarModoJuego(2, partidasJugadas, partidasGanadas, partidasPerdidas);
                break;
            case 3:
                cout << CIAN << "\n--- MARCADOR GLOBAL ---\n" << RESET;
                cout << "Partidas jugadas : " << partidasJugadas << "\n";
                cout << VERDE << "Partidas ganadas : " << partidasGanadas << "\n" << RESET;
                cout << ROJO << "Partidas perdidas: " << partidasPerdidas << "\n" << RESET;
                break;
            case 4:
                cout << MAGENTA << "\nSaliendo del juego...\n" << RESET;
                cout << CIAN << "--- MARCADOR FINAL ---\n" << RESET;
                cout << "Partidas jugadas : " << partidasJugadas << "\n";
                cout << VERDE << "Partidas ganadas : " << partidasGanadas << "\n" << RESET;
                cout << ROJO << "Partidas perdidas: " << partidasPerdidas << "\n" << RESET;
                cout << MAGENTA << "¡Gracias por jugar!\n" << RESET;
                break;
            default:
                cout << ROJO << "Error: Opcion fuera de rango (1-4).\n" << RESET;
        }

    } while (opcion != 4);

    return 0;
}

// Función que controla las 5 rondas para ambos modos de juego
void jugarModoJuego(int modo, int &partidasJugadas, int &partidasGanadas, int &partidasPerdidas) {
    int totalRondas = 5;
    int rondasGanadasSesion = 0;
    int rondasPerdidasSesion = 0;

    cout << CIAN << "\n=== INICIANDO SERIE DE " << totalRondas << " RONDAS ===" << RESET << "\n";

    for (int r = 1; r <= totalRondas; r++) {
        cout << AMARILLO << "\n--- RONDA " << r << " DE " << totalRondas << " ---" << RESET << "\n";
        string palabra = "";

        if (modo == 1) {
            // Contra la computadora
            palabra = elegirPalabraAleatoria();
        } else {
            // Dos jugadores
            bool valida = false;
            do {
                cout << AMARILLO << "Jugador 1, escriba la palabra secreta para la ronda " << r << " (4-12 letras): " << RESET;
                getline(cin, palabra);
                palabra = aMayusculas(palabra);
                if (palabraValida(palabra)) {
                    valida = true;
                } else {
                    cout << ROJO << "Palabra invalida. Debe tener entre 4 y 12 caracteres y solo letras de la A a la Z.\n" << RESET;
                }
            } while (!valida);

            // Ocultar palabra con saltos de línea
            for (int i = 0; i < 50; i++) {
                cout << "\n";
            }
        }

        // Jugar la ronda actual
        partidasJugadas++;
        bool ganoRonda = jugarPartida(palabra);

        if (ganoRonda) {
            rondasGanadasSesion++;
            partidasGanadas++;
        } else {
            rondasPerdidasSesion++;
            partidasPerdidas++;
        }

        if (r < totalRondas) {
            cout << CIAN << "\nPresione ENTER para pasar a la siguiente ronda..." << RESET;
            string pausa;
            getline(cin, pausa);
        }
    }

    // Resumen de la sesión de 5 rondas
    cout << MAGENTA << "\n==============================\n";
    cout << "     FIN DE LA SERIE DE JUEGO     \n";
    cout << "==============================\n" << RESET;
    cout << "Rondas ganadas : " << VERDE << rondasGanadasSesion << RESET << " / " << totalRondas << "\n";
    cout << "Rondas perdidas: " << ROJO << rondasPerdidasSesion << RESET << " / " << totalRondas << "\n";
}

string elegirPalabraAleatoria() {
    int n = rand() % 8;
    string palabra = "";
    switch (n) {
        case 0: palabra = "PROGRAMA"; break;
        case 1: palabra = "COMPUTADORA"; break;
        case 2: palabra = "AHORCADO"; break;
        case 3: palabra = "VARIABLE"; break;
        case 4: palabra = "FUNCION"; break;
        case 5: palabra = "CONSOLA"; break;
        case 6: palabra = "PUNTERO"; break;
        case 7: palabra = "DESARROLLO"; break;
    }
    return palabra;
}

string aMayusculas(string s) {
    string resultado = "";
    for (int i = 0; i < s.length(); i++) {
        resultado += toupper(s[i]);
    }
    return resultado;
}

bool palabraValida(string p) {
    if (p.length() < 4 || p.length() > 12) {
        return false;
    }
    for (int i = 0; i < p.length(); i++) {
        if (p[i] < 'A' || p[i] > 'Z') {
            return false;
        }
    }
    return true;
}

char leerLetra(string &usadas) {
    string entrada;
    char letra;

    while (true) {
        cout << AMARILLO << "Letra: " << RESET;
        getline(cin, entrada);

        if (entrada.length() != 1) {
            cout << ROJO << "Error: escriba una sola letra (A-Z).\n" << RESET;
            continue;
        }

        letra = toupper(entrada[0]);

        if (letra < 'A' || letra > 'Z') {
            cout << ROJO << "Error: escriba una sola letra (A-Z).\n" << RESET;
            continue;
        }

        bool repetida = false;
        for (int i = 0; i < usadas.length(); i++) {
            if (usadas[i] == letra) {
                repetida = true;
                break;
            }
        }

        if (repetida) {
            cout << AMARILLO << "Ya usaste la letra " << letra << ".\n" << RESET;
            continue;
        }

        usadas += letra;
        return letra;
    }
}

string crearOculta(string palabra) {
    string oculta = "";
    for (int i = 0; i < palabra.length(); i++) {
        oculta += "_";
        if (i < palabra.length() - 1) {
            oculta += " ";
        }
    }
    return oculta;
}

string actualizarOculta(string palabra, string oculta, char letra) {
    for (int i = 0; i < palabra.length(); i++) {
        if (palabra[i] == letra) {
            oculta[i * 2] = letra;
        }
    }
    return oculta;
}

void dibujarAhorcado(int errores) {
    cout << ROJO;
    cout << "+---+\n";
    cout << "|   " << (errores >= 1 ? "O" : "") << "\n";
    cout << "|   " << (errores >= 3 ? "/" : " ") << (errores >= 2 ? "|" : " ") << (errores >= 4 ? "\\" : "") << "\n";
    cout << "|   " << (errores >= 5 ? "/" : " ") << " " << (errores >= 6 ? "\\" : "") << "\n";
    cout << "===\n";
    cout << RESET;
}

bool jugarPartida(string palabra) {
    int errores = 0;
    string usadas = "";
    string oculta = crearOculta(palabra);
    int intentosMaximos = 6;

    while (errores < intentosMaximos) {
        cout << "\n";
        dibujarAhorcado(errores);
        cout << CIAN << oculta << RESET << "\n";
        cout << "Usadas: " << AMARILLO << usadas << RESET 
             << " | Intentos restantes: " << (intentosMaximos - errores == 1 ? ROJO : VERDE) 
             << (intentosMaximos - errores) << RESET << "\n";

        char letra = leerLetra(usadas);

        bool acierto = false;
        for (int i = 0; i < palabra.length(); i++) {
            if (palabra[i] == letra) {
                acierto = true;
                break;
            }
        }

        if (acierto) {
            oculta = actualizarOculta(palabra, oculta, letra);
            
            bool gano = true;
            for (int i = 0; i < oculta.length(); i++) {
                if (oculta[i] == '_') {
                    gano = false;
                    break;
                }
            }

            if (gano) {
                cout << "\n";
                dibujarAhorcado(errores);
                cout << CIAN << oculta << RESET << "\n";
                cout << VERDE << "¡Felicidades! Has ganado esta ronda. La palabra era: " << palabra << RESET << "\n";
                return true;
            }
        } else {
            errores++;
            if (errores == intentosMaximos) {
                cout << "\n";
                dibujarAhorcado(errores);
                cout << ROJO << "Has perdido esta ronda. La palabra secreta era: " << palabra << RESET << "\n";
                return false;
            }
        }
    }
    return false;
}
