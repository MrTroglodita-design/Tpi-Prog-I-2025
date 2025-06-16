#include <string>
#include <iomanip>
#include "rlutil.h"
#include "declaracionFunciones.h"
using namespace std;

//Resultado aleatorio luego de tirar un dado de seis caras
int tirarDadoSeis(){
    return (rand() % 6) + 1;
}
//Resultado aleatorio luego de tirar un dado de doce caras
int tirarDadoDoce(){
    return (rand() % 12) + 1;
}

void partidaJuego(string &ganador, int &maxHistorico){
   string jugador1, jugador2;
   cout << "Ingrese el nombre del jugador 1: " << endl;
   cin >> jugador1;
   cout << "Ingrese el nombre del jugador 2: " << endl;
   cin >> jugador2;
   int stockP1 = 6, stockP2 = 6, turno = 0, puntosP1 = 0, puntosP2 = 0, p1dados6, p2dados6;
   do{
   p1dados6 = tirarDadoSeis();
   p2dados6 = tirarDadoSeis();
   }while(p1dados6 == p2dados6);
   cout << "Dados de " << jugador1 <<": "<< p1dados6 << endl;
   cout << "Dados de " << jugador2 <<": "<< p2dados6 << endl;
   do{
      turno++;
      cout << "Ronda N°" << turno << endl << endl;
      rondaJuego(stockP1, stockP2, puntosP1, puntosP2, p1dados6, p2dados6, jugador1, jugador2);

   }while(turno == 3 || stockP1 != 0 || stockP2 != 0 || puntosP1 > 10000 || puntosP2 > 10000);

   if (puntosP1 > maxHistorico){
      maxHistorico = puntosP1;
      ganador = jugador1;
   }
   if (puntosP2 > maxHistorico){
      maxHistorico = puntosP2;
      ganador = jugador2;
   }
   if (puntosP1 == puntosP2){
      cout << endl << "Empate!";
      return;
   }
   else if (puntosP1 >= 10000){
      cout << endl << jugador1 << " es el ganador!";
      return;
   }
   else if (puntosP2 >= 10000){
      cout << endl << jugador2 << " es el ganador!";
      return;
   }
   else if (puntosP1 > puntosP2){
      cout << endl << jugador1 << " es el ganador!";
      return;
   }
   else{
      cout << endl << jugador2 << " es el ganador!";
      return;
   }
}


void rondaJuego (int &stockP1, int &stockP2, int &puntosP1, int &puntosP2, int p1dados6, int p2dados6, string jugador1, string jugador2){
   int dadosTotP1[12] = {};
   int dadosTotP2[12] = {};


   //Verifica quien empieza segun la tirada de dados inicial
   if (p1dados6 > p2dados6){
         turnoJugador1(stockP1, stockP2, puntosP1, puntosP2, jugador1);
   }
   else{
         turnoJugador2(stockP2, stockP1, puntosP2, puntosP1, jugador2);
   }

   //Sigue el siguiente  jugador pero antes comprueba si el primero que jugó gano con una tirada exitosa.
   if(stockP1 == 0 || stockP2 == 0){
      return;
   }
   else{
      if (p1dados6 > p2dados6){
         turnoJugador2(stockP2, stockP1, puntosP2, puntosP1, jugador2);
         return;
      }
      else{
         turnoJugador1(stockP1, stockP2, puntosP1, puntosP2, jugador1);
         return;
      }
   }
}

void turnoJugador1(int &stockP1, int &stockP2, int &puntosP1, int &puntosP2, string jugador1){
    // Se tiran los dos dados de 12 caras para obtener el n£mero de Dados Objetivo
    cout << "Turno jugador: " << jugador1;
    int numObjetivo;
    int dadoDoceUno = tirarDadoDoce();
    int dadoDoceDos = tirarDadoDoce();
    numObjetivo = dadoDoceUno + dadoDoceDos;
    // Se tiran los dados de 6 caras del jugador 1
    int dadosTotP1[6]; // array fijo

    for (int i = 0; i < stockP1; i++) {
        dadosTotP1[i] = tirarDadoSeis();
    }

    int sumaStock = 0, sumaDados = 0, eleccion, corte = 0;
    //CONDICION DE CORTE PARA VER SI ES POSIBLE LLEGAR O NO AL NUM OBJETIVO
   for(int i = 0; i < stockP1; i++){
         corte += dadosTotP1[i];
   }

    if (numObjetivo < corte){
    // Mostrar dados y permitir selecci¢n
    while (true) {
        cout << "\n Numero objetivo: " << numObjetivo << endl;
        cout << "Tus dados: ";
        for (int i = 0; i < stockP1; i++) {
            if (dadosTotP1[i] != 0)
                cout << "[" << i << "]:" << dadosTotP1[i] << " ";
        }
        cout << endl;

        cout << "Elegi un dado (indice): ";
        cin >> eleccion;

        if (eleccion < 0 || eleccion >= stockP1 || dadosTotP1[eleccion] == 0) {
            cout << "Eleccion invalida. Probar de nuevo.\n";
            continue;
        }

        sumaStock += dadosTotP1[eleccion];
        dadosTotP1[eleccion] = 0;
        sumaDados++;

        if (sumaStock >= numObjetivo) break;
    }
    }
    else {
      cout << endl<< "Imposible llegar al numero objetivo con tus numeros." << endl;
      if (stockP2>1){
         stockP2--;
         stockP1++;
         return;
      }
      else{
         return;
    }
    }
    // Resultado
    if (sumaStock == numObjetivo) {
        stockP1 -= sumaDados;
        if (stockP1 == 0) {
            puntosP1 += 10000; // premio
            return;
        }
        puntosP1 += sumaDados * numObjetivo;
        stockP2 += sumaDados;
    } else if (sumaStock > numObjetivo) {
      cout << endl << "PENALIZACION" << endl;
        if (stockP2 > 1) {
            stockP2--;
            stockP1++;
        }
    }
   cout << "\nFin del turno del Jugador 1.\n";
   cout << "Stock Jugador 1: " << stockP1 << endl;
   cout << "Stock Jugador 2: " << stockP2 << endl;
   cout << "Puntos Jugador 1: " << puntosP1 << endl;
   cout << "Puntos Jugador 2: " << puntosP2 << endl;
}

void turnoJugador2(int &stockP2, int &stockP1, int &puntosP2, int &puntosP1, string jugador2){
    // Se tiran los dos dados de 12 caras para obtener el n£mero de Dados Objetivo

    cout << "Turno jugador: " << jugador2;
    int numObjetivo;
    int dadoDoceUno = tirarDadoDoce();
    int dadoDoceDos = tirarDadoDoce();
    numObjetivo = dadoDoceUno + dadoDoceDos;

    // Se tiran los dados de 6 caras del jugador 1
    int dadosTotP2[6]; // array fijo
    for (int i = 0; i < stockP2; i++) {
        dadosTotP2[i] = tirarDadoSeis();
    }


    int sumaStock = 0, sumaDados = 0, eleccion, corte = 0;

   //CONDICION DE CORTE PARA VER SI ES POSIBLE LLEGAR O NO AL NUM OBJETIVO
   for(int i = 0; i < stockP2; i++){
   corte += dadosTotP2[i];
   }

    if (numObjetivo < corte){
    // Mostrar dados y permitir selecci¢n
    while (true) {
        cout << "\n Numero objetivo: " << numObjetivo << endl;
        cout << "Tus dados: ";
        for (int i = 0; i < stockP2; i++) {
            if (dadosTotP2[i] != 0)
                cout << "[" << i << "]:" << dadosTotP2[i] << " ";
        }
        cout << endl;

        cout << "Elegi un dado (indice): ";
        cin >> eleccion;

        if (eleccion < 0 || eleccion >= stockP2 || dadosTotP2[eleccion] == 0) {
            cout << "Eleccion invalida. Probar de nuevo.\n";
            continue;
        }

        sumaStock += dadosTotP2[eleccion];
        dadosTotP2[eleccion] = 0;
        sumaDados++;

        if (sumaStock >= numObjetivo) break;
    }
    }
    else {
      cout << endl<< "Imposible llegar al numero objetivo con tus numeros." << endl;
      if (stockP1>1){
         stockP1--;
         stockP2++;
         return;
      }
      else{
         return;
      }
    }
    // Resultado
    if (sumaStock == numObjetivo) {
        stockP2 -= sumaDados;
        if (stockP2 == 0) {
            puntosP2 += 10000; // premio
            return;
        }
        puntosP2 += sumaDados * numObjetivo;
        stockP1 += sumaDados;
    } else if (sumaStock > numObjetivo) {
       cout << endl << "PENALIZACION" << endl;
        if (stockP1 > 1) {
            stockP1--;
            stockP2++;
        }
    }
   cout << "\nFin del turno del Jugador 2.\n";
   cout << "Stock Jugador 1: " << stockP1 << endl;
   cout << "Stock Jugador 2: " << stockP2 << endl;
   cout << "Puntos Jugador 1: " << puntosP1 << endl;
   cout << "Puntos Jugador 2: " << puntosP2 << endl;

}


//------------------------------------------------------------------------------------------------------


// ------------------------------------------------------------------------
// actualizarEstadisticas()
// Inserta un nuevo registro en los arrays jugador[] y puntaje[] para
// mantener orden descendente por puntaje, y recorta a los primeros 4.
// ------------------------------------------------------------------------

void actualizarEstadisticas(string jugador[4],int puntaje[4],int& nEstad,const string& nombreNuevo,int puntajeNuevo)
{
    // 1) Determinar posicion donde insertar el nuevo puntaje
    int pos = nEstad;  // por defecto al final de los existentes
    for (int i = 0; i < nEstad; ++i) {
        if (puntajeNuevo > puntaje[i]) {
            pos = i;
            break;
        }
    }

    // 2) Desplazar los elementos desde el final hasta la posicion pos
    //    para hacer espacio al nuevo registro
    int limite = min(nEstad, 3);  // ultimo indice valido es 3
    for (int k = limite; k > pos; --k) {
        jugador[k] = jugador[k - 1];
        puntaje[k] = puntaje[k - 1];
    }

    // 3) Insertar nuevo nombre y puntaje en la posicion correcta
    jugador[pos] = nombreNuevo;
    puntaje[pos] = puntajeNuevo;

    // 4) Si hay menos de 4 registros, incrementar contador
    if (nEstad < 4) ++nEstad;
}


// ------------------------------------------------------------------------
// mostrarEstadisticas()
// Recorre los arrays jugador[] y puntaje[] hasta nEstad y los imprime
// ------------------------------------------------------------------------
void mostrarEstadisticas(const string jugador[4],const int puntaje[4],int nEstad)
{
    cout << "===== TOP 4 JUGADORES =====" << endl;

    if (nEstad == 0) {
        // No hay ningun registro aun
        cout << "No hay estadisticas disponibles." << endl;
    } else {
        // Mostrar cada puesto numerado
        for (int i = 0; i < nEstad; ++i) {
            cout << setw(2) << (i + 1) << ". "
                 << left << setw(15) << jugador[i]
                 << " - " << puntaje[i] << " pts"
                 << endl;
        }
    }

    cout << "===========================" << endl;
}

// ------------------------------------------------------------------------
// creditos()
// Imprime apellidos, nombres, legajos de los integrantes y nombre de equipo
// ------------------------------------------------------------------------
void creditos() {
    cout << "===== CREDITOS =====" << endl;
    cout << "* Camila Ariadna Gamboa (Legajo: 32347)"     << endl;
    cout << "* Santiago sosa  (Legajo:32544)"             << endl;
    cout << "* Agustin Juarez (Legajo:33205) "            << endl;
    cout << "* Avila Reina Juan Esteban (Legajo: 32887)"  << endl;
    cout << "===================="                        << endl;
}

// ------------------------------------------------------------------------
// confirmarSalida()
// Solicita al usuario confirmacion  para salir.
// Devuelve true si ingresa 's' o 'S'.
// ------------------------------------------------------------------------
// confirmarSalida()
// Solicita al usuario confirmacion para salir.
// 's' o 'S' = sí, salir → retorna true
// 'n' o 'N' = no salir    → retorna false
// Sigue preguntando hasta recibir una de esas dos.
bool confirmarSalida() {
    char r;
    do {
        cout << "Seguro que deseas salir? (s/n): ";
        cin >> r;
        // Normalizar a minúscula
        r = tolower(r);
        if (r != 's' && r != 'n') {
            cout << "Entrada invalida. Por favor ingresa 's' o 'n'." << endl;
        }
    } while (r != 's' && r != 'n');

    return (r == 's');
}
