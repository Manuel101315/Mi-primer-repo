/*realice un programa que permita realizar conversiones entre las unidades de longitud, masa y tiempo. considere las mas usadas valide la entrada por teclado y considere 
la restriccion del ultimo ejercicio. IMPORTANTE; EL USUARIO DEBE SELECCIONAR LAS UNIDADES QUE DESEA COVERTIR , su porgrama debe de permitir la ejecucion de de origen
y destino de las salidas , ajuste la interfaz visual en la entrada con colores llamtivos e incluya las unidades del sistema internacional y 
las mas conocidas de temperatura*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Configurar la consola en Windows para habilitar colores ANSI y caracteres especiales
    system("chcp 65001 > nul"); 
    system("mode con cols=95 lines=40"); 

    char repetir = 's';

    // Códigos de colores ANSI para una interfaz vibrante
    string colorCyan = "\033[1;36m";
    string colorVerde = "\033[1;32m";
    string colorAmarillo = "\033[1;33m";
    string colorMagenta = "\033[1;35m";
    string colorRojo = "\033[1;31m";
    string colorBlanco = "\033[1;37m";
    string resetColor = "\033[0m";

    while (repetir == 's' || repetir == 'S') {
        system("cls"); // Limpiar pantalla

        int categoria = 0;

        // Título principal con dos colores
        cout << "\n\n";
        cout << colorCyan << "\t    ==================================================" << resetColor << endl;
        cout << colorCyan << "\t    " << colorAmarillo << ">> CONVERSOR MULTI-UNIDADES PROFESIONAL <<" << colorCyan << "    " << resetColor << endl;
        cout << colorCyan << "\t    ==================================================" << resetColor << endl << endl;

        // Menú de categorías principal
        cout << colorMagenta << "    Seleccione la categoria de conversion:" << resetColor << endl;
        cout << "    [1] Longitud (km, m, cm, mm, um, nm, mi, yd, ft, in)" << endl;
        cout << "    [2] Masa (t, kg, g, mg, ug, lb, oz)" << endl;
        cout << "    [3] Tiempo (año, dias, h, min, s, ms)" << endl;
        cout << "    [4] Temperatura (°C, °F, K)" << endl;
        cout << colorAmarillo << "\n    Ingrese una opcion (1-4): " << resetColor;
        cin >> categoria;

        // ==========================================
        // 1. LONGITUD
        // ==========================================
        if (categoria == 1) {
            int origen = 0, destino = 0;
            double valor = 0, valorBase = 0, resultado = 0;
            string simboloOrigen = "", simboloDestino = "";

            cout << "\n    " << colorCyan << "--- UNIDADES DE LONGITUD ---" << resetColor << endl;
            cout << "    1. Kilometros (km)" << endl;
            cout << "    2. Metros (m)" << endl;
            cout << "    3. Centimetros (cm)" << endl;
            cout << "    4. Milimetros (mm)" << endl;
            cout << "    5. Micrometros (um)" << endl;
            cout << "    6. Nanometros (nm)" << endl;
            cout << "    7. Millas (mi)" << endl;
            cout << "    8. Yardas (yd)" << endl;
            cout << "    9. Pies (ft)" << endl;
            cout << "    10. Pulgadas (in)" << endl;

            cout << colorAmarillo << "\n    Elija unidad de origen (1-10): " << resetColor;
            cin >> origen;
            cout << colorAmarillo << "    Elija unidad de destino (1-10): " << resetColor;
            cin >> destino;
            cout << colorAmarillo << "    Ingrese el valor a convertir: " << resetColor;
            cin >> valor;

            if (origen == 1) { valorBase = valor * 1000.0; simboloOrigen = "km"; }
            else if (origen == 2) { valorBase = valor * 1.0; simboloOrigen = "m"; }
            else if (origen == 3) { valorBase = valor * 0.01; simboloOrigen = "cm"; }
            else if (origen == 4) { valorBase = valor * 0.001; simboloOrigen = "mm"; }
            else if (origen == 5) { valorBase = valor * 0.000001; simboloOrigen = "um"; }
            else if (origen == 6) { valorBase = valor * 0.000000001; simboloOrigen = "nm"; }
            else if (origen == 7) { valorBase = valor * 1609.344; simboloOrigen = "mi"; }
            else if (origen == 8) { valorBase = valor * 0.9144; simboloOrigen = "yd"; }
            else if (origen == 9) { valorBase = valor * 0.3048; simboloOrigen = "ft"; }
            else if (origen == 10) { valorBase = valor * 0.0254; simboloOrigen = "in"; }
            else valorBase = -1;

            if (valorBase != -1) {
                if (destino == 1) { resultado = valorBase / 1000.0; simboloDestino = "km"; }
                else if (destino == 2) { resultado = valorBase / 1.0; simboloDestino = "m"; }
                else if (destino == 3) { resultado = valorBase / 0.01; simboloDestino = "cm"; }
                else if (destino == 4) { resultado = valorBase / 0.001; simboloDestino = "mm"; }
                else if (destino == 5) { resultado = valorBase / 0.000001; simboloDestino = "um"; }
                else if (destino == 6) { resultado = valorBase / 0.000000001; simboloDestino = "nm"; }
                else if (destino == 7) { resultado = valorBase / 1609.344; simboloDestino = "mi"; }
                else if (destino == 8) { resultado = valorBase / 0.9144; simboloDestino = "yd"; }
                else if (destino == 9) { resultado = valorBase / 0.3048; simboloDestino = "ft"; }
                else if (destino == 10) { resultado = valorBase / 0.0254; simboloDestino = "in"; }
                else resultado = -1;
            }

            if (valorBase == -1 || resultado == -1) {
                cout << colorRojo << "\n    [X] Opciones de unidades invalidas.\n" << resetColor;
            } else {
                cout << "\n\n";
                cout << colorVerde << "\t    ==================================================================" << resetColor << endl;
                cout << colorVerde << "\t    * " << colorBlanco << valor << " (" << simboloOrigen << ") equivalen a " << resultado << " (" << simboloDestino << ")" << colorVerde << " *" << resetColor << endl;
                cout << colorVerde << "\t    ==================================================================" << resetColor << endl;
            }

        } 
        // ==========================================
        // 2. MASA
        // ==========================================
        else if (categoria == 2) {
            int origen = 0, destino = 0;
            double valor = 0, valorBase = 0, resultado = 0;
            string simboloOrigen = "", simboloDestino = "";

            cout << "\n    " << colorCyan << "--- UNIDADES DE MASA ---" << resetColor << endl;
            cout << "    1. Toneladas (t)" << endl;
            cout << "    2. Kilogramos (kg)" << endl;
            cout << "    3. Gramos (g)" << endl;
            cout << "    4. Miligramos (mg)" << endl;
            cout << "    5. Microgramos (ug)" << endl;
            cout << "    6. Libras (lb)" << endl;
            cout << "    7. Onzas (oz)" << endl;

            cout << colorAmarillo << "\n    Elija unidad de origen (1-7): " << resetColor;
            cin >> origen;
            cout << colorAmarillo << "    Elija unidad de destino (1-7): " << resetColor;
            cin >> destino;
            cout << colorAmarillo << "    Ingrese el valor a convertir: " << resetColor;
            cin >> valor;

            if (origen == 1) { valorBase = valor * 1000.0; simboloOrigen = "t"; }
            else if (origen == 2) { valorBase = valor * 1.0; simboloOrigen = "kg"; }
            else if (origen == 3) { valorBase = valor * 0.001; simboloOrigen = "g"; }
            else if (origen == 4) { valorBase = valor * 0.000001; simboloOrigen = "mg"; }
            else if (origen == 5) { valorBase = valor * 0.000000001; simboloOrigen = "ug"; }
            else if (origen == 6) { valorBase = valor * 0.45359237; simboloOrigen = "lb"; }
            else if (origen == 7) { valorBase = valor * 0.028349523; simboloOrigen = "oz"; }
            else valorBase = -1;

            if (valorBase != -1) {
                if (destino == 1) { resultado = valorBase / 1000.0; simboloDestino = "t"; }
                else if (destino == 2) { resultado = valorBase / 1.0; simboloDestino = "kg"; }
                else if (destino == 3) { resultado = valorBase / 0.001; simboloDestino = "g"; }
                else if (destino == 4) { resultado = valorBase / 0.000001; simboloDestino = "mg"; }
                else if (destino == 5) { resultado = valorBase / 0.000000001; simboloDestino = "ug"; }
                else if (destino == 6) { resultado = valorBase / 0.45359237; simboloDestino = "lb"; }
                else if (destino == 7) { resultado = valorBase / 0.028349523; simboloDestino = "oz"; }
                else resultado = -1;
            }

            if (valorBase == -1 || resultado == -1) {
                cout << colorRojo << "\n    [X] Opciones de unidades invalidas.\n" << resetColor;
            } else {
                cout << "\n\n";
                cout << colorVerde << "\t    ==================================================================" << resetColor << endl;
                cout << colorVerde << "\t    * " << colorBlanco << valor << " (" << simboloOrigen << ") equivalen a " << resultado << " (" << simboloDestino << ")" << colorVerde << " *" << resetColor << endl;
                cout << colorVerde << "\t    ==================================================================" << resetColor << endl;
            }

        } 
        // ==========================================
        // 3. TIEMPO
        // ==========================================
        else if (categoria == 3) {
            int origen = 0, destino = 0;
            double valor = 0, valorBase = 0, resultado = 0;
            string simboloOrigen = "", simboloDestino = "";

            cout << "\n    " << colorCyan << "--- UNIDADES DE TIEMPO ---" << resetColor << endl;
            cout << "    1. Años (año)" << endl;
            cout << "    2. Dias (dias)" << endl;
            cout << "    3. Horas (h)" << endl;
            cout << "    4. Minutos (min)" << endl;
            cout << "    5. Segundos (s)" << endl;
            cout << "    6. Milisegundos (ms)" << endl;

            cout << colorAmarillo << "\n    Elija unidad de origen (1-6): " << resetColor;
            cin >> origen;
            cout << colorAmarillo << "    Elija unidad de destino (1-6): " << resetColor;
            cin >> destino;
            cout << colorAmarillo << "    Ingrese el valor a convertir: " << resetColor;
            cin >> valor;

            if (origen == 1) { valorBase = valor * 31536000.0; simboloOrigen = "año"; }
            else if (origen == 2) { valorBase = valor * 86400.0; simboloOrigen = "dias"; }
            else if (origen == 3) { valorBase = valor * 3600.0; simboloOrigen = "h"; }
            else if (origen == 4) { valorBase = valor * 60.0; simboloOrigen = "min"; }
            else if (origen == 5) { valorBase = valor * 1.0; simboloOrigen = "s"; }
            else if (origen == 6) { valorBase = valor * 0.001; simboloOrigen = "ms"; }
            else valorBase = -1;

            if (valorBase != -1) {
                if (destino == 1) { resultado = valorBase / 31536000.0; simboloDestino = "año"; }
                else if (destino == 2) { resultado = valorBase / 86400.0; simboloDestino = "dias"; }
                else if (destino == 3) { resultado = valorBase / 3600.0; simboloDestino = "h"; }
                else if (destino == 4) { resultado = valorBase / 60.0; simboloDestino = "min"; }
                else if (destino == 5) { resultado = valorBase / 1.0; simboloDestino = "s"; }
                else if (destino == 6) { resultado = valorBase / 0.001; simboloDestino = "ms"; }
                else resultado = -1;
            }

            if (valorBase == -1 || resultado == -1) {
                cout << colorRojo << "\n    [X] Opciones de unidades invalidas.\n" << resetColor;
            } else {
                cout << "\n\n";
                cout << colorVerde << "\t    ==================================================================" << resetColor << endl;
                cout << colorVerde << "\t    * " << colorBlanco << valor << " (" << simboloOrigen << ") equivalen a " << resultado << " (" << simboloDestino << ")" << colorVerde << " *" << resetColor << endl;
                cout << colorVerde << "\t    ==================================================================" << resetColor << endl;
            }

        } 
        // ==========================================
        // 4. TEMPERATURA
        // ==========================================
        else if (categoria == 4) {
            int origen = 0, destino = 0;
            double valor = 0, celsiusBase = 0, resultado = 0;
            string simboloOrigen = "", simboloDestino = "";

            cout << "\n    " << colorCyan << "--- UNIDADES DE TEMPERATURA ---" << resetColor << endl;
            cout << "    1. Celsius (°C)" << endl;
            cout << "    2. Fahrenheit (°F)" << endl;
            cout << "    3. Kelvin (K)" << endl;

            cout << colorAmarillo << "\n    Elija unidad de origen (1-3): " << resetColor;
            cin >> origen;
            cout << colorAmarillo << "    Elija unidad de destino (1-3): " << resetColor;
            cin >> destino;
            cout << colorAmarillo << "    Ingrese el valor a convertir: " << resetColor;
            cin >> valor;

            // Convertir origen a Celsius como base de temperatura
            if (origen == 1) { celsiusBase = valor; simboloOrigen = "°C"; }
            else if (origen == 2) { celsiusBase = (valor - 32.0) * 5.0 / 9.0; simboloOrigen = "°F"; }
            else if (origen == 3) { celsiusBase = valor - 273.15; simboloOrigen = "K"; }
            else celsiusBase = -999;

            // Convertir de Celsius a destino
            if (celsiusBase != -999) {
                if (destino == 1) { resultado = celsiusBase; simboloDestino = "°C"; }
                else if (destino == 2) { resultado = (celsiusBase * 9.0 / 5.0) + 32.0; simboloDestino = "°F"; }
                else if (destino == 3) { resultado = celsiusBase + 273.15; simboloDestino = "K"; }
                else resultado = -999;
            }

            if (celsiusBase == -999 || resultado == -999) {
                cout << colorRojo << "\n    [X] Opciones de unidades invalidas.\n" << resetColor;
            } else {
                cout << "\n\n";
                cout << colorVerde << "\t    ==================================================================" << resetColor << endl;
                cout << colorVerde << "\t    * " << colorBlanco << valor << " (" << simboloOrigen << ") equivalen a " << resultado << " (" << simboloDestino << ")" << colorVerde << " *" << resetColor << endl;
                cout << colorVerde << "\t    ==================================================================" << resetColor << endl;
            }

        } else {
            cout << colorRojo << "\n    [X] Categoria invalida. Intente de nuevo.\n" << resetColor;
        }

        // Preguntar si desea repetir
        cout << "\n" << colorAmarillo << "    ¿Deseas realizar otra conversion? (s/n): " << resetColor;
        cin >> repetir;
        cout << endl;
    }

    cout << colorCyan << "\n    ¡Gracias por usar el conversor! Hasta luego.\n\n" << resetColor;

    return 0;
}