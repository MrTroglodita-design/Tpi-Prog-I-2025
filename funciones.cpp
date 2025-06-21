#include <string>
#include <windows.h>
#include <iomanip>
#include "rlutil.h"
#include "declaracionFunciones.h"
using namespace std;

//Dibujar dados
void dibujarDados(int dado){
    switch (dado) {
        case 1: {
            cout << "-----";
            cout << "\n|   |";
            cout << "\n| o |";
            cout << "\n|   |";
            cout << "\n-----";
            break;
        }
        case 2: {
            cout << "-----";
            cout << "\n|o  |";
            cout << "\n|   |";
            cout << "\n|  o|";
            cout << "\n-----";
            break;
        }
        case 3: {
            cout << "-----";
            cout << "\n|o  |";
            cout << "\n| o |";
            cout << "\n|  o|";
            cout << "\n-----";
            break;
        }
        case 4: {
            cout << "-----";
            cout << "\n|o o|";
            cout << "\n|   |";
            cout << "\n|o o|";
            cout << "\n-----";
            break;
        }
        case 5: {
            cout << "-----";
            cout << "\n|o o|";
            cout << "\n| o |";
            cout << "\n|o o|";
            cout << "\n-----";
            break;
        }
        case 6: {
            cout << "-----";
            cout << "\n|o o|";
            cout << "\n|o o|";
            cout << "\n|o o|";
            cout << "\n-----";
            break;
        }
    }
}

//Resultado aleatorio luego de tirar un dado de seis caras
int tirarDadoSeis(){
    return (rand() % 6) + 1;
}
//Resultado aleatorio luego de tirar un dado de doce caras
int tirarDadoDoce(){
    return (rand() % 12) + 1;
}

void partidaJuego(string &ganador, int &maxHistorico){
    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::setColor(rlutil::BLACK);
    cout << "¡QUE COMIENCE EL JUEGO!" << endl;
    cout << endl;
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);

   ///Se piden los nombres de cada jugador
   string jugador1, jugador2;
   int x = 36;
   int y = 3;
   cout << "Ingrese el nombre del Jugador/a 1: " << endl;
   rlutil::locate(x,y);
   cin >> jugador1;
   cout << "Ingrese el nombre del Jugador/a 2: " << endl;
   rlutil::locate(x,y+1);
   cin >> jugador2;

   cout << endl;
   rlutil::cls();
   rlutil::setBackgroundColor(rlutil::YELLOW);
   rlutil::setColor(rlutil::BLACK);
   cout << "VEAMOS QUIÉN EMPIEZA..." << endl;
   rlutil::msleep(1000);
   rlutil::resetColor();

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    int p1dados6, p2dados6; //Dados de cada jugador
    rlutil::hidecursor();
   ///Se lanzan los dados de seis caras para ver quién comienza la partida
   do{
        p1dados6 = tirarDadoSeis(); //dados jugador 1
        p2dados6 = tirarDadoSeis(); //dados jugador 2

   } while (p1dados6 == p2dados6); //Si son iguales vuelve a lanzar
        cout << endl;
        cout << jugador1 << " presioná una tecla para lanzar tu dado." << endl;
        rlutil::anykey();
        rlutil::msleep(2000);
        rlutil::setColor(rlutil::YELLOW);
        cout << endl << "=> " << jugador1 <<" lanzó: "<< p1dados6 << endl;
        dibujarDados(p1dados6);
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << jugador2 << " presioná una tecla para lanzar tu dado." << endl;
        rlutil::anykey();
        rlutil::msleep(2000);
        rlutil::setColor(rlutil::YELLOW);
        cout << endl << "=> " << jugador2 <<" lanzó: "<< p2dados6 << endl;
        dibujarDados(p2dados6);
        cout << endl;
        cout << "--------------------------------------------------------------------" << endl;

        ///Si dados p1 es mayor que dados p2 comienza JUGADOR 1, else JUGADOR 2
        rlutil::setColor(rlutil::YELLOW);
        rlutil::msleep(1500);
        if (p1dados6 > p2dados6){
            cout << endl;
            cout << "¡"<< jugador1 << " comienza!" << endl;
        } else {
            cout << endl;
            cout << "¡"<< jugador2 << " comienza!"<< endl;
        }
   rlutil::setColor(rlutil::WHITE);
   cout << endl << "Presioná una tecla para continuar...";
   rlutil::anykey();
   rlutil::cls();

   rlutil::showcursor();
   int stockP1 = 6, stockP2 = 6, turno = 0, puntosP1 = 0, puntosP2 = 0;
   ///COMIENZA LA PARTIDA
   do{
      turno++;
      rlutil::cls();
      //Se muestra el n° de ronda
        rlutil::setBackgroundColor(rlutil::YELLOW);
        rlutil::setColor(rlutil::BLACK);
        cout << endl << "========= RONDA N°" << turno << " =========" << endl;

        //Llamamos a la funcion rondaJuego
        rondaJuego(stockP1, stockP2, puntosP1, puntosP2, p1dados6, p2dados6, jugador1, jugador2);

    } while(turno < 3 && stockP1 != 0 && stockP2 != 0 && puntosP1 < 10000 && puntosP2 < 10000); //Condiciones de corte
        rlutil::cls();


    ///EVALUA EL MAX HISTORICO PARA AGREGARLO A ESTADISTICAS
    if (puntosP1 > maxHistorico){
      maxHistorico = puntosP1;
      ganador = jugador1;
    }
    if (puntosP2 > maxHistorico){
      maxHistorico = puntosP2;
      ganador = jugador2;
    }

    ///EVALUA SI HUBO GANADOR O EMPATE
    if (puntosP1 == puntosP2){
        rlutil::msleep(1000);
        rlutil::setBackgroundColor(rlutil::YELLOW);
        rlutil::setColor(rlutil::BLACK);
      cout << endl << "\n¡Empate!";
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
      cout << endl << "\n" << jugador1 << " finalizó con: " << stockP1 << " dados stock y " << puntosP1 << " puntos." << endl;
      cout << endl <<  "\n" << jugador2 << " finalizó con: " << stockP2 << " dados stock y " << puntosP2 << " puntos." << endl;
      return;
    }

    if (puntosP1 >= 10000 || puntosP1 > puntosP2){
        rlutil::msleep(1000);
        rlutil::setBackgroundColor(rlutil::YELLOW);
        rlutil::setColor(rlutil::BLACK);
        cout << endl << "\n¡" << jugador1 << " es el/la ganador/a!";
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        cout << endl <<  "\n" << jugador1 << " finalizó con: " << stockP1 << " dados stock y " << puntosP1 << " puntos." << endl;
        cout << endl <<  "\n" << jugador2 << " finalizó con: " << stockP2 << " dados stock y " << puntosP2 << " puntos." << endl;
        return;
    }

    if (puntosP2 >= 10000 || puntosP2 > puntosP1){
        rlutil::msleep(1000);
        rlutil::setBackgroundColor(rlutil::YELLOW);
        rlutil::setColor(rlutil::BLACK);
        cout << endl << "\n¡" << jugador2 << " es el/la ganadora!";
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        cout << endl << "\n" <<  jugador2 << " finalizó con: " << stockP2 << " dados stock y " << puntosP2 << " puntos." << endl;
        cout << endl <<  "\n" << jugador1 << " finalizó con: " << stockP1 << " dados stock y " << puntosP1 << " puntos." << endl;
        return;
    }
}


void rondaJuego (int &stockP1, int &stockP2, int &puntosP1, int &puntosP2, int p1dados6, int p2dados6, string jugador1, string jugador2){
      //Verifica quien empieza segun la tirada de dados inicial
   if (p1dados6 > p2dados6){

         turnoJugador1(stockP1, stockP2, puntosP1, puntosP2, jugador1, jugador2);
   }
   else{

         turnoJugador2(stockP2, stockP1, puntosP2, puntosP1, jugador2, jugador1);
   }

   //Sigue el siguiente  jugador pero antes comprueba si el primero que jugó gano con una tirada exitosa.
   if(stockP1 == 0 || stockP2 == 0){
      return;
   }
   else{
      if (p1dados6 > p2dados6){

         turnoJugador2(stockP2, stockP1, puntosP2, puntosP1, jugador2, jugador1);
         return;
      }
      else{

         turnoJugador1(stockP1, stockP2, puntosP1, puntosP2, jugador1, jugador2);
         return;
      }
   }
}

void turnoJugador1(int &stockP1, int &stockP2, int &puntosP1, int &puntosP2, string jugador1, string jugador2){
    rlutil::resetColor();
    // Se tiran los dos dados de 12 caras para obtener el n£mero de Dados Objetivo
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    cout << "\n-------------------------------------------------------" << endl;
    cout << "Turno de: " << jugador1 << endl;
    cout << "\nStock actual de dados: " << stockP1;
    cout << endl;
    int numObjetivo;
    int dadoDoceUno = tirarDadoDoce();
    int dadoDoceDos = tirarDadoDoce();

    numObjetivo = dadoDoceUno + dadoDoceDos;

    //Muestra el numero objetivo lanzado
    rlutil::msleep(500);
    rlutil::hidecursor();
    cout << "\npresiona ENTER para lanzar tus dados de doce caras..." << endl;
    rlutil::anykey();
    rlutil::msleep(1000);
    rlutil::setColor(rlutil::YELLOW);
    cout << "\nNumero objetivo: " << dadoDoceUno << " + " << dadoDoceDos << " = " << numObjetivo << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << endl;

    // Se tiran los dados de 6 caras del jugador 1
    int dadosTotP1[12] = {}; // vector hasta 12 elementos como maximo

    for (int i = 0; i < stockP1; i++) {
        dadosTotP1[i] = tirarDadoSeis();
    }

    int sumaStock = 0, sumaDados = 0, eleccion, corte = 0;
    //CONDICION DE CORTE PARA VER SI ES POSIBLE LLEGAR O NO AL NUM OBJETIVO
    for(int i = 0; i < stockP1; i++){
         corte += dadosTotP1[i];  //Suma de todos los dados
    }


    int dadosSeleccionados[stockP1] = {}; // Guarda los dados elegidos
    int cantidadSeleccionados = 0; // Cuántos dados fueron seleccionados
    int sumaDadosSeleccionados = 0; // Suma los dados que vamos eligiendo
    rlutil::showcursor();
    if (numObjetivo <= corte){
        while (true) {
            //Muestra dados y numObjetivo
            rlutil::msleep(500);
            rlutil::setColor(rlutil::YELLOW);
            cout << "Tus dados: ";
            for (int i = 0; i < stockP1; i++) {
                if (dadosTotP1[i] != 0){
                    cout << "[" << i+1 << "]:" << dadosTotP1[i] << "  ";
                }
            }
            //Reliza la seleccion de dados
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << "\nElegi un dado [índice] o 0 para finalizar la ronda => ";
            cin >> eleccion;
            eleccion--;


            //Almacena en un vector los dados elegidos

            if (eleccion == -1) {
                cout << "\nRonda finalizada por el jugador, no suma puntos." << endl;
                Beep(300, 500);
                break;
            }

            if (eleccion < 0 || eleccion >= stockP1 || dadosTotP1[eleccion] == 0){
                cout << "Dado ya elegido o fuera de rango de selección." << endl;
                Beep(300, 500);
                continue;
            }

             //Guardar el valor del dado seleccionado para ir mostrandolo en cada elección
            dadosSeleccionados[cantidadSeleccionados] = dadosTotP1[eleccion];
            cantidadSeleccionados++;
            sumaDadosSeleccionados += dadosTotP1[eleccion];
            cout <<"\nElegiste: ";
            for (int i = 0; i < cantidadSeleccionados; i++) {
                    if (cantidadSeleccionados == -1){
                        break;
                    }
                    cout << dadosSeleccionados[i];
                    if (i != cantidadSeleccionados - 1) { //Si no es el ultimo dado seleccionado
                            cout << " + ";                //Imprime +
                    }
                }
                cout << " = " << sumaDadosSeleccionados;   //Imprime el igual provisorio


            cout << "\n-------------------------------------------------------" << endl;



            sumaStock += dadosTotP1[eleccion];  //Suma los valores de los dados elegidos y los almacena en sumaStock
            dadosTotP1[eleccion] = 0;           //Cada dado elegido lo iguala a 0 para que no aparezcan nuevamente
            sumaDados++;                        //Contador de la cantidad de dados elegidos

            if (sumaStock == numObjetivo){ //TIRADA EXITOSA

                rlutil::setBackgroundColor(rlutil::YELLOW);
                rlutil::setColor(rlutil::BLACK);
                cout << endl << "¡TIRADA EXITOSA!" << endl;

                rlutil::resetColor();
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
                cout << "\nCombinación elegida: ";

                for (int i = 0; i < cantidadSeleccionados; i++) {
                    cout << dadosSeleccionados[i];
                    if (i != cantidadSeleccionados - 1) { //Si no es el ultimo dado seleccionado
                            cout << " + ";                //Imprime +
                    }
                }
                    cout << " = " << sumaStock << endl;   //Imprime el igual al total
                break;
            }
            if (sumaStock > numObjetivo){  ///PENALIZACIÓN
                rlutil::setBackgroundColor(rlutil::YELLOW);
                rlutil::setColor(rlutil::BLACK);
                cout << endl << "Sufres una PENALIZACIÓN por elegir mal tus dados y NO sumarás puntos." << endl;
                Beep(300, 500);
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
                break;
            }
        }

    } else {
        //Muestra dados y numObjetivo
        rlutil::msleep(500);
        rlutil::setColor(rlutil::YELLOW);
        cout << "Tus dados: ";
        for (int i = 0; i < stockP1; i++) {
            if (dadosTotP1[i] != 0){
                cout << "[" << i+1 << "]:" << dadosTotP1[i] << "  ";
            }
        }
        rlutil::msleep(1000);
        cout << endl<< "\nNo es posible llegar al numero objetivo con tus dados." << endl;
        Beep(300, 500);
        if (stockP1 > 1){
            for(int i = 0; i < stockP1; i++){
            cout << dadosTotP1[i];
            if (i < 5){
              cout << " + ";
            }
        }
         cout << " = " << corte << endl;
        } else {
         for(int i = 0; i < stockP1; i++){
            cout << dadosTotP1[i];
         }
        }


        if (stockP2 > 1){
            cout << "\n" << jugador2 << " pierde un dado y " << jugador1 << " recibe uno por penalización." << endl;
            Beep(300, 500);
            stockP2--;
            stockP1++;

        }
        else {
            cout << "\n" << jugador1 << " no puede perder más dados (solo tiene 1). No se aplica penalización." << endl;

            }
    }

    ///Muestra en pantalla el Resultado
    if (sumaStock == numObjetivo) {
        stockP1 -= sumaDados;
        if (stockP1 == 0) {
            puntosP1 += 10000; // premio
            return;
        }
        puntosP1 += sumaDados * numObjetivo;
        stockP2 += sumaDados;
    } else if (sumaStock > numObjetivo) {
        cout << endl;
        cout << jugador2 << " pierde un dado y " << jugador1 << " recibe uno por penalización." << endl;
        Beep(300, 500);
        if (stockP2 > 1) {
            stockP2--;
            stockP1++;
        }
        return;
    }
    rlutil::msleep(700);
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
   cout << "\n● Dados Objetivo: " << numObjetivo << endl;
   cout << "\n● Dados elegidos: " << sumaDados << " dados" << endl;
   if (sumaDados < 0){
    cout << "\n● Puntos: " << numObjetivo << " * " << sumaDados << " = 0" << endl;
   } else {
    cout << "\n● Puntos: " << numObjetivo << " * " << sumaDados << " = " << numObjetivo*sumaDados << endl;
   }
   cout << "\n● Transfiere " << sumaDados << " dados a " << jugador2 << endl;
   rlutil::setColor(rlutil::YELLOW);
   cout << "\nFin del turno de " << jugador1 << endl;
   cout << endl << "=> "<< jugador1 << ": " << stockP1 << " dados stock restantes y " << puntosP1 << " pts." << endl;
   cout << endl << "=> "<< jugador2 << ": " << stockP2 << " dados stock." << endl;

    // Pausa para ver el resumen
   cout << "\nPresiona una tecla para continuar...";
   rlutil::anykey();



}

void turnoJugador2(int &stockP2, int &stockP1, int &puntosP2, int &puntosP1, string jugador2, string jugador1){
    rlutil::resetColor();
    // Se tiran los dos dados de 12 caras para obtener el n£mero de Dados Objetivo
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    cout << "\n-------------------------------------------------------" << endl;
    cout << "Turno de: " << jugador2 << endl;
    cout << "\nStock actual de dados: " << stockP2;
    cout << endl;
    int numObjetivo;
    int dadoDoceUno = tirarDadoDoce();
    int dadoDoceDos = tirarDadoDoce();

    numObjetivo = dadoDoceUno + dadoDoceDos;

    //Muestra el numero objetivo lanzado
    rlutil::msleep(500);
    rlutil::hidecursor();
    cout << "\npresiona ENTER para lanzar tus dados de doce caras..." << endl;
    rlutil::anykey();
    rlutil::msleep(1000);
    rlutil::setColor(rlutil::YELLOW);
    cout << "\nNumero objetivo: " << dadoDoceUno << " + " << dadoDoceDos << " = " << numObjetivo << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << endl;

    // Se tiran los dados de 6 caras del jugador 1
    int dadosTotP2[12] = {}; // vector hasta 12 elementos como maximo

    for (int i = 0; i < stockP2; i++) {
        dadosTotP2[i] = tirarDadoSeis();
    }

    int sumaStock = 0, sumaDados = 0, eleccion, corte = 0;
    //CONDICION DE CORTE PARA VER SI ES POSIBLE LLEGAR O NO AL NUM OBJETIVO
    for(int i = 0; i < stockP2; i++){
         corte += dadosTotP2[i];  //Suma de todos los dados
    }


    int dadosSeleccionados[stockP2] = {}; // Guarda los dados elegidos
    int cantidadSeleccionados = 0; // Cuántos dados fueron seleccionados
    int sumaDadosSeleccionados = 0; // Suma los dados que vamos eligiendo
    rlutil::showcursor();
    if (numObjetivo <= corte){
        while (true) {
            //Muestra dados y numObjetivo
            rlutil::msleep(500);
            rlutil::setColor(rlutil::YELLOW);
            cout << "Tus dados: ";
            for (int i = 0; i < stockP2; i++) {
                if (dadosTotP2[i] != 0){
                    cout << "[" << i+1 << "]:" << dadosTotP2[i] << "  ";
                }
            }
            //Reliza la seleccion de dados
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << "\nElegi un dado [índice] o 0 para finalizar la ronda => ";
            cin >> eleccion;
            eleccion--;

            //Almacena en un vector los dados elegidos

            if (eleccion == -1) {
                cout << "\nRonda finalizada por el jugador, no suma puntos." << endl;
                Beep(300, 500);
                break;
            }

            if (eleccion < 0 || eleccion >= stockP2 || dadosTotP2[eleccion] == 0){
                cout << "Dado ya elegido o fuera de rango de selección." << endl;
                Beep(300, 500);
                continue;
            }

            //Guardar el valor del dado seleccionado
            dadosSeleccionados[cantidadSeleccionados] = dadosTotP2[eleccion];
            cantidadSeleccionados++;
            sumaDadosSeleccionados += dadosTotP2[eleccion];
            cout <<"\nElegiste: ";
            for (int i = 0; i < cantidadSeleccionados; i++) {
                    if (cantidadSeleccionados == -1){
                        break;
                    }
                    cout << dadosSeleccionados[i];
                    if (i != cantidadSeleccionados - 1) { //Si no es el ultimo dado seleccionado
                            cout << " + ";                //Imprime +
                    }
                }
                cout << " = " << sumaDadosSeleccionados;   //Imprime el igual provisorio

            cout << "\n-------------------------------------------------------" << endl;



            sumaStock += dadosTotP2[eleccion];  //Suma los valores de los dados elegidos y los almacena en sumaStock
            dadosTotP2[eleccion] = 0;           //Cada dado elegido lo iguala a 0 para que no aparezcan nuevamente
            sumaDados++;                        //Contador de la cantidad de dados elegidos

            if (sumaStock == numObjetivo){ //TIRADA EXITOSA

                rlutil::setBackgroundColor(rlutil::YELLOW);
                rlutil::setColor(rlutil::BLACK);
                cout << endl << "¡TIRADA EXITOSA!" << endl;

                rlutil::resetColor();
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
                cout << "\nCombinación elegida: ";

                for (int i = 0; i < cantidadSeleccionados; i++) {
                    cout << dadosSeleccionados[i];
                    if (i != cantidadSeleccionados - 1) { //Si no es el ultimo dado seleccionado
                            cout << " + ";                //Imprime +
                    }
                }
                    cout << " = " << sumaStock << endl;   //Imprime el igual al total
                break;
            }
            if (sumaStock > numObjetivo){  //PENALIZACIÓN
                rlutil::setBackgroundColor(rlutil::YELLOW);
                rlutil::setColor(rlutil::BLACK);
                cout << endl << "Sufres una PENALIZACIÓN por elegir mal tus dados y NO sumarás puntos." << endl;
                Beep(300, 500);
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
                break;
            }
        }

    } else {
        //Muestra dados y numObjetivo
        rlutil::msleep(500);
        rlutil::setColor(rlutil::YELLOW);
        cout << "Tus dados: ";
        for (int i = 0; i < stockP2; i++) {
            if (dadosTotP2[i] != 0){
                cout << "[" << i+1 << "]:" << dadosTotP2[i] << "  ";
            }
        }
        rlutil::msleep(1000);
        cout << endl<< "\nNo es posible llegar al numero objetivo con tus dados." << endl;
        Beep(300, 500);
        if (stockP2 > 1){
            for(int i = 0; i < stockP2; i++){
            cout << dadosTotP2[i];
            if (i < 5){
              cout << " + ";
            }
        }
         cout << " = " << corte << endl;
        } else {
         for(int i = 0; i < stockP2; i++){
            cout << dadosTotP2[i];
         }
        }

        if (stockP1 > 1){
            cout << "\n" << jugador1 << " pierde un dado y " << jugador2 << " recibe uno por penalización." << endl;
            Beep(300, 500);
            stockP1--;
            stockP2++;

        }
        else {
            cout << "\n" << jugador1 << " no puede perder más dados (solo tiene 1). No se aplica penalización." << endl;

            }
    }

    ///Muestra en pantalla el Resultado
    if (sumaStock == numObjetivo) {
        stockP2 -= sumaDados;
        if (stockP2 == 0) {
            puntosP2 += 10000; // premio
            return;
        }
        puntosP2 += sumaDados * numObjetivo;
        stockP1 += sumaDados;
    } else if (sumaStock > numObjetivo) {
        cout << endl;
        cout << jugador1 << " pierde un dado y " << jugador2 << " recibe uno por penalización." << endl;
        Beep(300, 500);
        if (stockP1 > 1) {
            stockP1--;
            stockP2++;
        }
         return;
    }
    rlutil::msleep(700);
    rlutil::setBackgroundColor(rlutil::BLACK);
   rlutil::setColor(rlutil::WHITE);
   cout << "\n● Dados Objetivo: " << numObjetivo << endl;
   cout << "\n● Dados elegidos: " << sumaDados << " dados" << endl;
   if (sumaDados < 0){
    cout << "\n● Puntos: " << numObjetivo << " * " << sumaDados << " = 0" << endl;
   } else {
    cout << "\n● Puntos: " << numObjetivo << " * " << sumaDados << " = " << numObjetivo*sumaDados << endl;
   }
   cout << "\n● Transfiere " << sumaDados << " dados a " << jugador1 << endl;
   rlutil::msleep(700);
   rlutil::setColor(rlutil::YELLOW);
   cout << "\nFin del turno de " << jugador2 << endl;
   cout << endl << "=> " << jugador2 << ": " << stockP2 << " dados stock restantes y " << puntosP2 << " pts." << endl;
   cout << endl << "=> " << jugador1<< ": " << stockP1 << " dados stock." << endl;

    // Pausa para ver el resumen
   cout << "\nPresiona una tecla para continuar...";
   rlutil::anykey();

}


//------------------------------------------------------------------------------------------------------


// ------------------------------------------------------------------------
// actualizarEstadisticas()
// Inserta un nuevo registro en los arrays jugador[] y puntaje[] para mantener orden descendente por puntaje,
//y recorta a los primeros 4.

void actualizarEstadisticas(string jugador[4],int puntaje[4],int &nEstad,const string &nombreNuevo,int puntajeNuevo)
{
    // 1) Determinar posicion donde insertar el nuevo puntaje
    int pos = nEstad;  // por defecto al final de los existentes
    for (int i = 0; i < nEstad; ++i) {
        if (puntajeNuevo > puntaje[i]) {
            pos = i;
            break;
        }
    }

    // 2) Desplazar los elementos desde el final hasta la posicion pos para hacer espacio al nuevo registro
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
    cout << "================= CREDITOS ===============" << endl;
    cout << "----- EQUIPO ------" << endl;
    cout << "* Camila Ariadna Gamboa (Legajo: 32347)"     << endl;
    cout << "* Santiago Sosa  (Legajo:32544)"             << endl;
    cout << "* Agustin Juarez (Legajo:33205) "            << endl;
    cout << "* Avila Reina Juan Esteban (Legajo: 32887)"  << endl;
    cout << "=========================================="  << endl;
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
        // pasar a minúscula
        r = tolower(r);
        if (r != 's' && r != 'n') {
            cout << "Entrada invalida. Por favor ingresa 's' o 'n'." << endl;
        }
    } while (r != 's' && r != 'n');

    return (r == 's');
}


