#include <string>
#include <windows.h>
#include <iomanip>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include "rlutil.h"
#include <cctype>    // tolower
#include "declaracionFunciones.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Imprime UTF 8 en Windows
    // ---------------------------------------------------
    // 1) Declaracion de arrays en main

    string jugadores[4] = {"", "", "", ""};  //    jugador[] guarda nombres de hasta 4 ganadores
    int    puntajes[4] = {};   //    puntaje[] guarda puntajes correspondientes
    int    numEstadisticas = 0;        // contador de cuantos puestos validos hay


    // ---------------------------------------------------
    // 2) Variables de control del bucle principal
    bool   salir      = false;    // controla salida del menu
    string ganador;               // nombre del ganador de la ultima partida
    int    puntPartida;           // puntaje obtenido en la ultima partida

    // ---------------------------------------------------
    // 3) Bucle principal del menu

    while (!salir) {
        rlutil::cls();

        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::YELLOW);

        cout << "███████╗███╗   ██╗███████╗██████╗ ███████╗███╗   ██╗██████╗  █████╗ ██████╗  ██████╗ ███████╗" << endl;
        cout << "██╔════╝████╗  ██║██╔════╝██╔══██╗██╔════╝████╗  ██║██╔══██╗██╔══██╗██╔══██╗██╔═══██╗██╔════╝" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "█████╗  ██╔██╗ ██║█████╗  ██████╔╝█████╗  ██╔██╗ ██║██║  ██║███████║██║  ██║██║   ██║███████╗" << endl;
        cout << "██╔══╝  ██║╚██╗██║██╔══╝  ██╔══██╗██╔══╝  ██║╚██╗██║██║  ██║██╔══██║██║  ██║██║   ██║╚════██║" << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "███████╗██║ ╚████║██║     ██║  ██║███████╗██║ ╚████║██████╔╝██║  ██║██████╔╝╚██████╔╝███████║" << endl;
        cout << "╚══════╝╚═╝  ╚═══╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚══════╝" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl << "Bienvenidos a Enfrendados, un juego en el que interviene el azar y las matematicas. ¡Suerte!" << endl;

        rlutil::setColor(rlutil::YELLOW);
        // Mostrar opciones al usuario
        cout << "\n=========================="<< endl;
        cout << "1) JUGAR             " << endl;
        cout << "2) ESTADÍSTICAS      " << endl;
        cout << "3) CRÉDITOS          " << endl;
        cout << "==========================" << endl;
        cout << "0) SALIR" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "\n=> Elige tu opción: ";
        rlutil::resetColor();


        int opc;
        cin >> opc;  // Leer opcion elegida
        rlutil::cls();
        // Procesar opcion

        switch (opc) {

            case 1: {
                srand(time(0)); // Inicializa con la hora actual (solo una vez)

                // 1) Llamar a partidaJuego(): se ejecuta la partida y se obtiene nombre del vencedor y su puntaje

                partidaJuego(jugadores, puntajes, numEstadisticas);

                // 2) Actualizar ranking TOP 4 en los arrays
                actualizarEstadisticas(jugadores, puntajes, numEstadisticas, ganador, puntPartida);

                cout << "\nPresiona una tecla para volver al menú principal...";
                rlutil::anykey();
                break;
            }
            case 2:
                // Mostrar el TOP 4 actual
                mostrarEstadisticas(jugadores, puntajes, numEstadisticas);
                cout << "\nPresiona una tecla para volver al menú principal...";
                rlutil::anykey();
                break;

            case 3:
                // Mostrar creditos del equipo
                creditos();
                cout << "\nPresiona una tecla para volver al menú principal...";
                rlutil::anykey();
                break;

            case 0:
                // Preguntar confirmacion de salida
                if (confirmarSalida())
                    salir = true;
                    // Mensaje final antes de terminar programa
                    cout << "\n¡HASTA LA PRÓXIMA!" << endl;
                break;

            default:
                // Opcion invalida: volver a mostrar menu
                cout << "Opcion invalida. Intente otra vez." << endl;
                cout << "Presiona una tecla para continuar...";
                rlutil::anykey();
                break;
        }
    }


    return 0;
}


