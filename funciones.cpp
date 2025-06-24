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
    cout << "¡Bienvenido a Enfrendados!";
    rlutil::msleep(1000);
    rlutil::setColor(rlutil::YELLOW);
    cout <<"\n\n¿Cómo se juega?"<<endl;
    rlutil::msleep(1000);
    rlutil::setColor(rlutil::WHITE);
    cout << "\nEnfrendados es un emocionante juego de dados para dos jugadores donde competirán para acumular la mayor cantidad de puntos ";
    cout <<"\nen tres rondas. Cada jugador tiene un conjunto de dados y deberá seguir las instrucciones en cada turno para lograr ";
    cout <<"\ncombinaciones que sumen el número objetivo." <<endl;
    rlutil::setColor(rlutil::YELLOW);
    cout <<"\nResumen de las reglas principales:"<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout <<"\n- Datos: Cada jugador inicia con 6 dados de seis caras y, en cada turno, se lanzan 2 dados de doce caras que definen el número objetivo." <<endl;

    cout <<"\n- El objetivo del turno: Seleccionar una combinación de dados del stock cuyo suma de caras iguale el número objetivo."<<endl;

    cout <<"\n- Puntuación: Si logras igualar el número objetivo, ganas puntos igual a ese número multiplicado por la cantidad de dados usados y transferís ";
    cout <<"\n  esos dados al oponente."<<endl;

    cout <<"\n- Penalización: Si no logras la suma, debes recibir un dado de tu oponente, si tiene más de uno en su stock."<<endl;

    cout <<"\n- Ganador automático: Si en alguna tirada terminas sin dados, ganas automáticamente y obtienes 10,000 puntos."<<endl;

    cout <<"\n- Final del juego: Después de tres rondas, gana quien tenga más puntos, o hay empate si ambos tienen la misma puntuación."<<endl;

    rlutil::setColor(rlutil::YELLOW);
    cout <<"\n\n¡Prepárate para desafiar a tu oponente en un juego estratégico y lleno de azar!" <<endl;
    rlutil::msleep(1000);
    cout <<"\n¿Listo para comenzar? ¡Que tenga buena suerte!";
    rlutil::setColor(rlutil::WHITE);
    cout << endl << "\nPresioná una tecla para continuar...";
    rlutil::anykey();
    rlutil::cls();

    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::setColor(rlutil::BLACK);
    cout << "¡QUE COMIENCE EL JUEGO!" << endl;
    cout << endl;
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);

    rlutil::showcursor();
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
        rlutil::msleep(1000);
        rlutil::setColor(rlutil::WHITE);
        cout << endl;
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


    ///EVALUA SI HUBO GANADOR O EMPATE
    if (puntosP1 == puntosP2){

        if(puntosP1 >= maxHistorico){
         maxHistorico = puntosP1;
         ganador = jugador1 + " y " + jugador2;
        }
        rlutil::msleep(1000);
        cout << endl;
        mensajeEmpate();
        cout << endl;
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        cout << endl << "\n" << jugador1 << " finalizó con: " << stockP1 << " dados stock y " << puntosP1 << " puntos." << endl;
        cout << "\n" << jugador2 << " finalizó con: " << stockP2 << " dados stock y " << puntosP2 << " puntos." << endl;
      return;
    }

    if (puntosP1 >= 10000 || puntosP1 > puntosP2){

     //se actualizan las estadisticas si es necesario
      if(puntosP1 >= maxHistorico){
      maxHistorico = puntosP1;
      ganador = jugador1;
      }
        rlutil::msleep(1000);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(30, 3);
        cout << endl << jugador1 << " es el/la ganador/a!";
        rlutil::resetColor();

        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        cout << endl <<  "\n" << jugador1 << " finalizó con: " << stockP1 << " dados stock y " << puntosP1 << " puntos." << endl;
        cout << "\n" << jugador2 << " finalizó con: " << stockP2 << " dados stock y " << puntosP2 << " puntos." << endl;
        cout <<endl;
        cout <<endl;
        mensajeGanador();
        cout <<endl;
        return;
    }

    if (puntosP2 >= 10000 || puntosP2 > puntosP1){

     //se actualizan las estadisticas si es necesario
      if(puntosP2 >= maxHistorico){
      maxHistorico = puntosP2;
      ganador = jugador2;
      }

        rlutil::msleep(1000);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(30, 3);
        cout << endl << jugador2 << " es el/la ganador/a!";
        rlutil::resetColor();

        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        cout << endl <<  "\n" << jugador2 << " finalizó con: " << stockP2 << " dados stock y " << puntosP2 << " puntos." << endl;
        cout << "\n" << jugador1 << " finalizó con: " << stockP1 << " dados stock y " << puntosP1 << " puntos." << endl;
        cout <<endl;
        cout <<endl;
        mensajeGanador();
        cout <<endl;
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
    // Se tiran los dos dados de 12 caras para obtener el n£mero de Dados Objetivo
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    cout << "\n-------------------------------------------------------" << endl;
    rlutil::setColor(rlutil::LIGHTRED);
    cout << "Turno de: " << jugador1 << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "\nStock actual de dados: " << stockP1;
    cout << endl;
    int numObjetivo;
    int dadoDoceUno = tirarDadoDoce();
    int dadoDoceDos = tirarDadoDoce();

    numObjetivo = dadoDoceUno + dadoDoceDos;

    //Muestra el numero objetivo lanzado
    rlutil::msleep(500);
    rlutil::hidecursor();
    rlutil::setColor(rlutil::WHITE);
    cout << "\nPresiona ENTER para lanzar tus dados de doce caras..." << endl;
    rlutil::anykey();
    rlutil::msleep(1000);
    rlutil::setColor(rlutil::YELLOW);
    cout << "\nNumero objetivo: " << dadoDoceUno << " + " << dadoDoceDos << " = " << numObjetivo << endl;
    cout << "-------------------------------------------------------" << endl;

    // Se tiran los dados de 6 caras del jugador 1
    int dadosTotP1[12] = {}; // vector hasta 12 elementos como maximo

    for (int i = 0; i < stockP1; i++) {
        dadosTotP1[i] = tirarDadoSeis();
    }

    int sumaStock = 0, sumaDados = 0, eleccion;


    int dadosSeleccionados[stockP1] = {}; // Guarda los dados elegidos
    int cantidadSeleccionados = 0; // Cuántos dados fueron seleccionados
    int sumaDadosSeleccionados = 0; // Suma los dados que vamos eligiendo
    bool penalizacion = false;

    rlutil::showcursor();

   while (true) {
         //Muestra dados y numObjetivo
         rlutil::msleep(500);
         rlutil::setColor(rlutil::YELLOW);
         cout << "Tus dados: " << endl;
         cout << endl;
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

         //Si ingresa 0 finaliza la ronda y no suma puntos
         if (eleccion == -1) {
             rlutil::setColor(rlutil::RED);
             cout << "\nRonda finalizada por el jugador, no suma puntos." << endl;
            penalizacion = true;
            Beep(300, 500);

            //Verifica si es posible que el jugador pierda o no un dado dependiendo del stock del contricante
            if (stockP2 > 1){
               cout << "\n" << jugador2 << " pierde un dado y " << jugador1 << " recibe uno por penalización." << endl;
               Beep(300, 500);
               stockP2--;
               stockP1++;
               break;
            }
            else {
               cout << "\n" << jugador2 << " no puede perder más dados (solo tiene 1). No se aplica penalización." << endl;
            }

               break;
         }

         //Si el indice es menor a 0 o mayor a la cantidad de dado o un dado ya elegido (=0)
         if (eleccion < 0 || eleccion >= stockP1 || dadosTotP1[eleccion] == 0){
             rlutil::setColor(rlutil::RED);
             cout << "\nDado ya elegido o fuera de rango de selección." << endl;
             Beep(300, 500);
             continue;
         }


          //Guardar el valor del dado seleccionado para ir mostrandolo en cada elección
         dadosSeleccionados[cantidadSeleccionados] = dadosTotP1[eleccion];
         cantidadSeleccionados++;
         sumaDadosSeleccionados += dadosTotP1[eleccion];

         sumaStock += dadosTotP1[eleccion];  //Suma los valores de los dados elegidos y los almacena en sumaStock
         dadosTotP1[eleccion] = 0;           //Cada dado elegido lo iguala a 0 para que no aparezcan nuevamente
         sumaDados++;                        //Contador de la cantidad de dados elegidos
         //Imprime en pantalla lo que va eligiendo y su suma

         rlutil::setColor(rlutil::LIGHTBLUE);
         cout << "\n● Numero Objetivo: " << numObjetivo << endl;
         rlutil::setColor(rlutil::GREEN);
         cout <<"\nElegiste: ";
         for (int i = 0; i < cantidadSeleccionados; i++) {
                 if (eleccion == -1){ //Si elige 0 para finalizar la ronda no imprime nada
                     break;
                 }
                 cout << dadosSeleccionados[i]; //Imprime el valor del dado
                 if (i != cantidadSeleccionados - 1) { //Si no es el ultimo dado seleccionado
                         cout << " + ";                //Imprime +
                 }
             }
             cout << " = " << sumaDadosSeleccionados;   //Imprime el igual a suma provisoria

         rlutil::setColor(rlutil::WHITE);

         cout << "\n-------------------------------------------------------" << endl;


         if (sumaStock == numObjetivo){ //TIRADA EXITOSA si los dados elegidos sumaron igual al numero objetivo

             rlutil::setBackgroundColor(rlutil::BLACK);
             rlutil::setColor(rlutil::LIGHTGREEN);
             cout << "¡TIRADA EXITOSA!";  //Imprime el mensaje

             rlutil::setBackgroundColor(rlutil::BLACK);
             rlutil::setColor(rlutil::WHITE);
             cout << endl;
             cout << "\n● Numero Objetivo: " << numObjetivo << endl;
             cout << "● Combinación elegida: ";      //Imprime los dados que elegiste y su suma

             for (int i = 0; i < cantidadSeleccionados; i++) {
                 cout << dadosSeleccionados[i];
                 if (i != cantidadSeleccionados - 1) { //Si no es el ultimo dado seleccionado
                         cout << " + ";                //Imprime +
                 }
             }
                 cout << " = " << sumaStock << endl;   //Imprime el igual al total
             break;
         }
         //Si la suma de los dados elegidos es mayor al numero objetivo ocurre la penalizacion
         if (sumaStock > numObjetivo ){  ///PENALIZACIÓN
             rlutil::setBackgroundColor(rlutil::BLACK);
             rlutil::setColor(rlutil::RED);
             cout << endl << "Sufres una PENALIZACIÓN por elegir mal tus dados y NO sumarás puntos." << endl;
             Beep(300, 500);
             penalizacion = true;

            //Verifica si es posible que el jugador pierda o no un dado dependiendo del stock del contricante
            if (stockP2 > 1){
               cout << "\n" << jugador2 << " pierde un dado y " << jugador1 << " recibe uno por penalización." << endl;
               Beep(300, 500);
               stockP2--;
               stockP1++;

            }
            else {
               cout << "\n" << jugador2 << " no puede perder más dados (solo tiene 1). No se aplica penalización." << endl;
            }

             rlutil::setBackgroundColor(rlutil::BLACK);
             rlutil::setColor(rlutil::WHITE);
             break;
         }
     }


    ///Muestra en pantalla el Resultado
    //TIRADA EXITOSA
    if (!penalizacion && sumaStock == numObjetivo) {
        stockP1 -= sumaDados;
        if (stockP1 == 0) {
            puntosP1 += 10000; // premio
            return;
        }
        puntosP1 += sumaDados * numObjetivo;
        stockP2 += sumaDados;

    }


    rlutil::msleep(700);
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);

   if (penalizacion) {
        cout << "\n● No sumaste puntos por penalización." << endl;
        cout << "● Puntos: 0" << endl;

    } else if (sumaStock == numObjetivo && sumaDados > 0) {
        cout << "● Dados elegidos: " << sumaDados << endl;
        cout << "● Puntos: " << numObjetivo << " * " << sumaDados << " = " << numObjetivo * sumaDados << endl;
        cout << "● Transfiere " << sumaDados << " dados a " << jugador2 << endl;
    }

   cout << "\n-------------------------------------------------------" << endl;

   rlutil::setColor(rlutil::YELLOW);
   cout << "Fin del turno de " << jugador1 << endl;
   cout << endl << "=> "<< jugador1 << ": " << stockP1 << " dados stock restantes y " << puntosP1 << " pts." << endl;
   cout << endl << "=> "<< jugador2 << ": " << stockP2 << " dados stock restantes y " << puntosP2 << " pts." << endl;

    // Pausa para ver el resumen
    rlutil::hidecursor();
   cout << "\nPresiona una tecla para continuar..." << endl;
   rlutil::anykey();
   rlutil::msleep(10);
   cout<<endl;
   mensajeEspera();
   cout<<endl;
   rlutil::msleep(2000);
   rlutil::cls();

}

void turnoJugador2(int &stockP2, int &stockP1, int &puntosP2, int &puntosP1, string jugador2, string jugador1){
    // Se tiran los dos dados de 12 caras para obtener el n£mero de Dados Objetivo
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    cout << "\n-------------------------------------------------------" << endl;
    rlutil::setColor(rlutil::LIGHTRED);
    cout << "Turno de: " << jugador2 << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "\nStock actual de dados: " << stockP2;
    cout << endl;
    int numObjetivo;
    int dadoDoceUno = tirarDadoDoce();
    int dadoDoceDos = tirarDadoDoce();

    numObjetivo = dadoDoceUno + dadoDoceDos;

    //Muestra el numero objetivo lanzado
    rlutil::msleep(500);
    rlutil::hidecursor();
    rlutil::setColor(rlutil::WHITE);
    cout << "\nPresiona ENTER para lanzar tus dados de doce caras..." << endl;
    rlutil::anykey();
    rlutil::msleep(1000);
    rlutil::setColor(rlutil::YELLOW);
    cout << "\nNumero objetivo: " << dadoDoceUno << " + " << dadoDoceDos << " = " << numObjetivo << endl;
    cout << "-------------------------------------------------------" << endl;

    // Se tiran los dados de 6 caras del jugador 2
    int dadosTotP2[12] = {}; // vector hasta 12 elementos como maximo

    for (int i = 0; i < stockP2; i++) {
        dadosTotP2[i] = tirarDadoSeis();
    }

    int sumaStock = 0, sumaDados = 0, eleccion;


    int dadosSeleccionados[stockP2] = {}; // Guarda los dados elegidos
    int cantidadSeleccionados = 0; // Cuántos dados fueron seleccionados
    int sumaDadosSeleccionados = 0; // Suma los dados que vamos eligiendo
    bool penalizacion = false;

    rlutil::showcursor();

   while (true) {
         //Muestra dados y numObjetivo
         rlutil::msleep(500);
         rlutil::setColor(rlutil::YELLOW);
         cout << "Tus dados: " << endl;
         cout << endl;
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

         //Si ingresa 0 finaliza la ronda y no suma puntos
         if (eleccion == -1) {
             rlutil::setColor(rlutil::RED);
             cout << "\nRonda finalizada por el jugador, no suma puntos." << endl;
            penalizacion = true;
            Beep(300, 500);

            //Verifica si es posible que el jugador pierda o no un dado dependiendo del stock del contricante
            if (stockP1 > 1){
               cout << "\n" << jugador1 << " pierde un dado y " << jugador2 << " recibe uno por penalización." << endl;
               Beep(300, 500);
               stockP1--;
               stockP2++;
               break;
            }
            else {
               cout << "\n" << jugador1 << " no puede perder más dados (solo tiene 1). No se aplica penalización." << endl;
            }

               break;
         }

         //Si el indice es menor a 0 o mayor a la cantidad de dado o un dado ya elegido (=0)
         if (eleccion < 0 || eleccion >= stockP2 || dadosTotP2[eleccion] == 0){
             rlutil::setColor(rlutil::RED);
             cout << "\nDado ya elegido o fuera de rango de selección." << endl;
             Beep(300, 500);
             continue;
         }


          //Guardar el valor del dado seleccionado para ir mostrandolo en cada elección
         dadosSeleccionados[cantidadSeleccionados] = dadosTotP2[eleccion];
         cantidadSeleccionados++;
         sumaDadosSeleccionados += dadosTotP2[eleccion];

         sumaStock += dadosTotP2[eleccion];  //Suma los valores de los dados elegidos y los almacena en sumaStock
         dadosTotP2[eleccion] = 0;           //Cada dado elegido lo iguala a 0 para que no aparezcan nuevamente
         sumaDados++;                        //Contador de la cantidad de dados elegidos
         //Imprime en pantalla lo que va eligiendo y su suma

         rlutil::setColor(rlutil::LIGHTBLUE);
         cout << "\n● Numero Objetivo: " << numObjetivo << endl;
         rlutil::setColor(rlutil::GREEN);
         cout <<"\nElegiste: ";
         for (int i = 0; i < cantidadSeleccionados; i++) {
                 if (eleccion == -1){ //Si elige 0 para finalizar la ronda no imprime nada
                     break;
                 }
                 cout << dadosSeleccionados[i]; //Imprime el valor del dado
                 if (i != cantidadSeleccionados - 1) { //Si no es el ultimo dado seleccionado
                         cout << " + ";                //Imprime +
                 }
             }
             cout << " = " << sumaDadosSeleccionados;   //Imprime el igual a suma provisoria

         rlutil::setColor(rlutil::WHITE);

         cout << "\n-------------------------------------------------------" << endl;


         if (sumaStock == numObjetivo){ //TIRADA EXITOSA si los dados elegidos sumaron igual al numero objetivo

             rlutil::setBackgroundColor(rlutil::BLACK);
             rlutil::setColor(rlutil::LIGHTGREEN);
             cout << "¡TIRADA EXITOSA!";  //Imprime el mensaje

             rlutil::setBackgroundColor(rlutil::BLACK);
             rlutil::setColor(rlutil::WHITE);
             cout << endl;
             cout << "\n● Numero Objetivo: " << numObjetivo << endl;
             cout << "● Combinación elegida: ";      //Imprime los dados que elegiste y su suma

             for (int i = 0; i < cantidadSeleccionados; i++) {
                 cout << dadosSeleccionados[i];
                 if (i != cantidadSeleccionados - 1) { //Si no es el ultimo dado seleccionado
                         cout << " + ";                //Imprime +
                 }
             }
                 cout << " = " << sumaStock << endl;   //Imprime el igual al total
             break;
         }
         //Si la suma de los dados elegidos es mayor al numero objetivo ocurre la penalizacion
         if (sumaStock > numObjetivo ){  ///PENALIZACIÓN
             rlutil::setBackgroundColor(rlutil::BLACK);
             rlutil::setColor(rlutil::RED);
             cout << endl << "Sufres una PENALIZACIÓN por elegir mal tus dados y NO sumarás puntos." << endl;
             Beep(300, 500);
             penalizacion = true;

            //Verifica si es posible que el jugador pierda o no un dado dependiendo del stock del contricante
            if (stockP1 > 1){
               cout << "\n" << jugador1 << " pierde un dado y " << jugador2 << " recibe uno por penalización." << endl;
               Beep(300, 500);
               stockP1--;
               stockP2++;

            }
            else {
               cout << "\n" << jugador1 << " no puede perder más dados (solo tiene 1). No se aplica penalización." << endl;
            }

             rlutil::setBackgroundColor(rlutil::BLACK);
             rlutil::setColor(rlutil::WHITE);
             break;
         }
     }


    ///Muestra en pantalla el Resultado
    //TIRADA EXITOSA
    if (!penalizacion && sumaStock == numObjetivo) {
        stockP2 -= sumaDados;
        if (stockP2 == 0) {
            puntosP2 += 10000; // premio
            return;
        }
        puntosP2 += sumaDados * numObjetivo;
        stockP1 += sumaDados;

    }


    rlutil::msleep(700);
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);

   if (penalizacion) {
        cout << "\n● No sumaste puntos por penalización." << endl;
        cout << "● Puntos: 0" << endl;

    } else if (sumaStock == numObjetivo && sumaDados > 0) {
        cout << "● Dados elegidos: " << sumaDados << endl;
        cout << "● Puntos: " << numObjetivo << " * " << sumaDados << " = " << numObjetivo * sumaDados << endl;
        cout << "● Transfiere " << sumaDados << " dados a " << jugador1 << endl;
    }

   cout << "\n-------------------------------------------------------" << endl;

   rlutil::setColor(rlutil::YELLOW);
   cout << "Fin del turno de " << jugador2 << endl;
   cout << endl << "=> "<< jugador2 << ": " << stockP2 << " dados stock restantes y " << puntosP2 << " pts." << endl;
   cout << endl << "=> "<< jugador1 << ": " << stockP1 << " dados stock restantes y " << puntosP1 << " pts." << endl;

    // Pausa para ver el resumen
    rlutil::hidecursor();
   cout << "\nPresiona una tecla para continuar..." << endl;
   rlutil::anykey();
   rlutil::msleep(10);
   cout<<endl;
   mensajeEspera();
   cout<<endl;
   rlutil::msleep(2000);
   rlutil::cls();
}
//------------------------------------------------------------------------------------------------------

/// creditos()
// Imprime apellidos, nombres, legajos de los integrantes y nombre de equipo
void creditos() {

    // Encabezado
    rlutil::setColor(rlutil::WHITE);
    cout << "===========================================" << endl;
    cout << "             EQUIPO ROCKET                 " << endl;
    cout << "===========================================" << endl;
    rlutil::resetColor();

    rlutil::setColor(rlutil::DARKGREY);
    cout << "                   ^" << endl;
    cout << "                  /^\\\\" << endl;
    cout << "                 /___\\\\" << endl;
    cout << "                |=   =|" << endl;
    cout << "                |     |" << endl;
    cout << "                |     |" << endl;
    cout << "                |     |" << endl;
    cout << "               /|##!##|\\" << endl;
    cout << "              / |##!##| \\" << endl;
    cout << "             /  |##!##|  \\" << endl;
    cout << "            |  / ^ | ^ \\  |" << endl;
    cout << "            | /  ( | )  \\ |" << endl;
    cout << "            |/   ( | )   \\|" << endl;
    rlutil::resetColor();
    rlutil::setColor(rlutil::YELLOW);
    cout << "                ((   ))" << endl;
    rlutil::setColor(rlutil::RED);
    cout << "               ((  :  ))" << endl;
    cout << "                ((   ))" << endl;
    cout << "                 (( ))" << endl;
    cout << "                  ( )" << endl;

    rlutil::resetColor();

    // Créditos del equipo
    rlutil::setColor(rlutil::WHITE);
    cout << "----------      INTEGRANTES      ----------" << endl;
    rlutil::resetColor();

    cout << "* Camila Ariadna Gamboa    (Legajo: 32347)" << endl;
    cout << "* Santiago Sosa            (Legajo: 32544)" << endl;
    cout << "* Agustín Juárez           (Legajo: 33205)" << endl;
    cout << "* Juan Esteban Ávila Reina (Legajo: 32887)" << endl;

    // Pie de página
    rlutil::setColor(rlutil::WHITE);
    cout << "===========================================" << endl;
    rlutil::resetColor();
}

void mostrarEstadisticas(string ganador, int maxHistorico){

    if (maxHistorico > 0){
    // Trofeo en oro
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::YELLOW);
    cout << "              ___________" << endl;
    cout << "             '._==_==_=_.'"<< endl;
    cout << "             .-\\\\:      /-."<< endl;
    cout << "            | (|:.     |) |"<< endl;
    cout << "             '-|:.     |-'"<< endl;
    cout << "               \\\\::.    /"   << endl;
    cout << "                '::. .'"       << endl;
    cout << "                  ) ("        << endl;
    cout << "                _.' '._"      << endl;
    cout << "               `\"\"\"\"\"\"\"`"     << endl;
    cout << "             __|_______|__"    << endl;
    cout << "            |~~~~~~~~~~~~~|"    << endl;


    rlutil::setColor(rlutil::YELLOW);
    cout << "\n============ Campeón histórico ============  " << endl
         << "             " << ganador << ": " << maxHistorico << " pts"
         << endl;

    return;
    }
    else {
         cout << "    .    _    +     .  ______   .          ." << endl;
    cout << " (      /|\\      .    |      \\      .   +" << endl;
    cout << "     . |||||     _    | |   | | ||         ." << endl;
    cout << ".      |||||    | |  _| | | | |_||    ." << endl;
    cout << "   /\\  ||||| .  | | |   | |      |       ." << endl;
    cout << "__||||_|||||____| |_|_____________\\__________" << endl;
    cout << ". |||| |||||  /\\   _____      _____  .   ." << endl;
    cout << "  |||| ||||| ||||   .   .  .         ________" << endl;
    cout << " . \\|`-'|||| ||||    __________       .    ." << endl;
    cout << "    \\__ |||| ||||      .          .     ." << endl;
    cout << " __    ||||`-'|||  .       .    __________" << endl;
    cout << ".    . |||| ___/  ___________             ." << endl;
    cout << "   . _ ||||| . _               .   _________" << endl;
    cout << "_   ___|||||__  _ \\\\--//    .          _" << endl;
    cout << "     _ `---'    .)=\\oo|=(.   _   .   .    ." << endl;
    cout << "_  ^      .  -    . \\.|" << endl;
    cout << "\n==========  Aún no hay ganadores... ========== " << endl;

    }
}

/// confirmarSalida()
// Solicita al usuario confirmacion  para salir. Devuelve true si ingresa 's' o 'S'.
bool confirmarSalida() {
    char r;
    do {
        cout << "Seguro que deseas salir? (s/n): "; // Solicita al usuario confirmacion para salir.
        cin >> r;
        // pasar a minúscula
        r = tolower(r);
        if (r != 's' && r != 'n') {
            cout << "Entrada invalida. Por favor ingresa 's' o 'n'." << endl;
        }
    } while (r != 's' && r != 'n');

    return (r == 's');
}

void mensajeGanador() {

    rlutil::setColor(rlutil::YELLOW);
    cout << "            (         )      )         (                  (         )      )         (     " << endl;
    cout << "   (  (      )\\ )   ( /(   ( /(         )\\ )     (  (      )\\ )   ( /(   ( /(         )\\ ) " << endl;
    rlutil::setColor(rlutil::RED);
    cout << "   )\\))(   '(()/(   )\\())  )\\())  (    (()/(     )\\))(   '(()/(   )\\())  )\\())  (    (()/( " << endl;
    cout << " ((_)()\\ )  /(_)) ((_)\  ((_)\   )\\    /(_))   ((_)()\\ )  /(_)) ((_)\  ((_)\   )\\    /(_))     " << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << " _(())\\_)  ()(_))  _((_)  _((_) ((_)  (_))     _(())\\_)()(_))    _((_)  _((_) ((_)  (_))   " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << " \\ \\((_)/ /|_ _|  | \\| | | \\| | | __| | _ \\    \\ \\((_)/ /|_ _|  | \\| | | \\| | | __| | _ \\  " << endl;
    cout << "  \\ \\/\\/ /  | |   | .` | | .` | | _|  |   /     \\ \\/\\/ /  | |   | .` | | .` | | _|  |   /  " << endl;
    cout << "   \\_/\\_/  |___|  |_|\\_| |_|\\_| |___| |_|_\\      \\_/\\_/  |___|  |_|\\_| |_|\\_| |___| |_|_\\  " << endl;

}
void mensajeEmpate() {
    rlutil::setColor(rlutil::YELLOW);
    cout << "███████╗███╗   ███╗██████╗  █████╗ ████████╗███████╗" << endl;
    cout << "██╔════╝████╗ ████║██╔══██╗██╔══██╗╚══██╔══╝██╔════╝" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "█████╗  ██╔████╔██║██████╔╝███████║   ██║   █████╗  " << endl;
    cout << "██╔══╝  ██║╚██╔╝██║██╔═══╝ ██╔══██║   ██║   ██╔══╝  " << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "███████╗██║ ╚═╝ ██║██║     ██║  ██║   ██║   ███████╗" << endl;
    cout << "╚══════╝╚═╝     ╚═╝╚═╝     ╚═╝  ╚═╝   ╚═╝   ╚══════╝" << endl;
    rlutil::resetColor();
}
void mensajeEspera() {
    rlutil::setColor(rlutil::WHITE);
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "░░█░░░░█▀▀▀█░█▀▀█░█▀▀▄░▀█▀░█▄░░█░█▀▀█░░" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "░░█░░░░█░░░█░█▄▄█░█░░█░░█░░█░█░█░█░▄▄░░" << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "░░█▄▄█░█▄▄▄█░█░░█░█▄▄▀░▄█▄░█░░▀█░█▄▄█░░" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "█░██░██░██░██░██░██░██░██░██░░░░░░░░░░█" << endl;
    cout << "█░██░██░██░██░██░██░██░██░██░░░░░░░░░░█" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl;
}

