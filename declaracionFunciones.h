#pragma once
#include <vector>
#include <string>
#include <windows.h>

using namespace std;
//Prototipos de funciones
///MENU
// actualizarEstadisticas(): inserta un nuevo resultado en el ranking TOP‑4
void actualizarEstadisticas(string jugador[4], int puntaje[4], int& numEstadisticas, const string& nombreNuevo, int puntajeNuevo);

// mostrarEstadisticas(): muestra por pantalla el ranking TOP‑4 actual
void mostrarEstadisticas(const string jugador[4], const int puntaje[4], int numEstadisticas);

// creditos(): imprime los apellidos, nombres, legajos y nombre de equipo
void creditos();

// confirmarSalida(): pide confirmacion al usuario y devuelve true si confirma salir
bool confirmarSalida();

//---------------------------------------------------------------

///PARTIDA GENERAL del juego
// juego(): ejecuta la partida y devuelve el nombre del vencedor y su puntaje
//Devuele el resultado final: "Jugador 1 ?GANA!" / "Jugador 2 ?GANA!" / ?Empate! y almacena al jugador que tuvo el mayor puntaje historico
void partidaJuego(string jugadores[4], int puntajes[4], int &numEstadisticas);

///Dibujo de dados
void dibujarDados(int dado);

///Tirar dados (Seis caras)
int tirarDadoSeis();

///Tirar dados (Doce caras)
int tirarDadoDoce();

///RONDA del juego
//Determina quien juega
void rondaJuego (int &stockP1, int &stockP2, int &puntosP1, int &puntosP2, int p1dados, int p2dados, string jugador1, string jugador2);

///RONDA de Jugador 1
//Modifica stock y puntos
void turnoJugador1(int &stockP1, int &stockP2, int &puntosP1, int &puntosP2, string jugador1, string jugador2);

///RONDA de Jugador 2
//Modifica stock y puntos
void turnoJugador2(int &stockP2, int &stockP1, int &puntosP2, int &puntosP1, string jugador2, string jugador1);

//mensaje ganador
void mensajeGanador();
//mensaje de empate
void mensajeEmpate();
//mensaje de espera
void mensajeEspera();












