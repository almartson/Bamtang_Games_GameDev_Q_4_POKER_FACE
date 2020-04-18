/******************************************************************************
  Bamtang Games Entrance Test.

  Question number 4.

  4. POKER FACE

  [Spanish original Question:]

En esta versión simplificada del juego de Poker, existen 4 tipos de cartas (abreviaciones entre paréntesis):

	Tréboles (C), Espadas (S), Corazones (H) y Diamantes (D).

Hay 13 cartas por cada tipo, dando un total de 52 cartas, las cartas ordenadas de menor valor a mayor valor son:

	2, 3, 4, 5, 6, 7, 8, 9, 10 (T), Jack (J), Reina (Q), Rey (K), Ace (A).

Una mano consiste de 5 cartas. Existen 10 clases de manos, ordenadas de menor a mayor son:

	1-	HIGH CARD: El valor de la carta de mayor valor
	2-	ONE PAIR: Dos cartas del mismo valor (un par)
	3-	TWO PAIRS: Dos pares diferentes.
	4-	THREE OF A KIND: Tres cartas del mismo valor
	5-	STRAIGHT: Todas las cartas son valores consecutivos
	6-	FLUSH: Todas las cartas son del mismo tipo
	7-	FULL HOUSE: Tres cartas del mismo valor y un par
	8-	FOUR OF A KIND: Cuatro cartas del mismo valor
	9-	STRAIGHT FLUSH: Todas las cartas son valores consecutivos del mismo tipo
	10-	ROYAL FLUSH: 10, Jack, Queen, King, Ace, del mismo tipo

Si dos jugadores tienen manos de la misma clase entonces la mano que esta conformada por cartas de mayor valor gana;
por ejemplo un par de ochos le gana a un par de cincos (ver ejemplo 1 más abajo).

Si aun así hay empate, por ejemplo, ambos jugadores tiene un par de reinas, entonces las cartas de mayor valor de cada mano
son comparadas (ver ejemplo 4 de abajo);
si las cartas de mayor valor son iguales, las cartas que le siguen de mayor valor son comparadas, y así sucesivamente.

Ejemplos:

Mano        Jugador 1       Jugador 2           Ganador

1       5H 5C 6S 7S KD      2C 3S 8S 8D TD      Jugador 2
		Par de cincos       Par de ochos
2       5D 8C 9S JS AC      2C 5C 7D 8S QH      Jugador 1
		HIGH CARD Ace       HIGH CARD Queen
3       2D 9C AS AH AC      3D 6D 7D TD QD      Jugador 2
		Tres Aces           FLUSH de diamantes
4       4D 6S 9H QH QC      3D 6D 7H QD QS      Jugador 1
		Par de reinas       Par de reinas
		Máxima carta 9      Máxima carta 7
5       2H 2D 4C 4D 4S      3C 3D 3S 9S 9D      Jugador 1
		Full House de 4     Full House de 3

Verifica tu código con el archivo de jugadas: poker.txt, el cual contiene 1000 manos aleatorias
entregadas a dos jugadores. Cada línea del archivo contiene 10 cartas (separadas por un solo espacio):
 las primeras cinco son las cartas del jugador 1 y el resto son las del jugador 2.
De las 1000 manos en este archivo el jugador 1 gana 376 manos.

Crea todas las funciones necesarias para resolver este problema de una modo genérico
 (por ejemplo: con otro archivo de jugadas).
Asume que todas las manos son válidas, sin caracteres inválidos ni cartas repetidas, que las manos
no están ordenadas y que por cada línea existe un claro vencedor.

(6 PUNTOS)

	NOTAS del desarrollador:

	1-	El tipo de Póker acá referido es la variante conocida como: 'Texas Póker'.
	2-	Los archivos de texto, tanto de ENTRADA (i.e.: INPUT) como de SALIDA (i.e.: OUTPUT) se trabajarán
desde la misma ubicación del archivo (.exe) ejecutable.
	3-	El nombre del archivo de texto de ENTRADA es una variable GLOBAL, definida más abajo bajo el Nombre '_INPUT_FILE_SHORT_NAME'

*******************************************************************************
   By:	 Alejandro E. Almarza Martín
*******************************************************************************
*******************************************************************************/
/***************************TODO LIST******************************************
 *
 * 1- To clean the Code.
 * 2- Everything the Main Statement asked for, is already done.
 *
 ******************************************************************************/
/*************************************Global Constants******************************************/

#define _INPUT_FILE_SHORT_NAME		"poker.txt"
#define _OUTPUT_FILE_SHORT_NAME		"pokerOutput.txt"

/***END**********************************Global Constants******************************************/

// OOP - UML data structure design:
//
#include "card.hpp"
#include "card_manager.hpp"
#include "card_type.hpp"
#include "hand.hpp"
#include "hand_type.hpp"
#include "player.hpp"
//
// File Management & Utility Functions:
//
#include "fileManager.h"
//
// Includes with Test-Purposes:
//
///// #include "test_functions.hpp"
//
// Other tools:
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/********************STATIC MEMBER VARIABLES (i.e.: Class Attributes) DECLARATION***********************/
//
Player CardManager::_myPlayerList[_MAX_PLAYERS_COUNT];
CardType CardManager::_myCardTypeList[_MAX_CARD_TYPE_COUNT];
Card CardManager::_myCardList[_MAX_CARDS_COUNT];
string CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ENGLISH[_TOTAL_HAND_TYPES]; // = { _HIGH_CARD_NAME_ENG, _ONE_PAIR_NAME_ENG, _TWO_PAIRS_NAME_ENG, _THREE_OF_A_KIND_NAME_ENG, _STRAIGHT_NAME_ENG, _FLUSH_NAME_ENG, _FULL_HOUSE_NAME_ENG, _FOUR_OF_A_KIND_NAME_ENG, _STRAIGHT_FLUSH_NAME_ENG, _ROYAL_FLUSH_NAME_ENG };
string CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL[_TOTAL_HAND_TYPES]; // = { _HIGH_CARD_NAME_ESP, _ONE_PAIR_NAME_ESP, _TWO_PAIRS_NAME_ESP, _THREE_OF_A_KIND_NAME_ESP, _STRAIGHT_NAME_ESP, _FLUSH_NAME_ESP, _FULL_HOUSE_NAME_ESP, _FOUR_OF_A_KIND_NAME_ESP, _STRAIGHT_FLUSH_NAME_ESP, _ROYAL_FLUSH_NAME_ESP };


// This was the DEBUG, PRINT-TO-CONSOLE Version. D not un-comment. Just in case there is anything to be debuged.
//
//int main()
//{
//
//	std::cout << "\n***************************************\nBy: Alejandro E. Almarza Martin";
//	std::cout << "\n***************************************\n\n";
//	std::cout << "Bamtang Games Entrance Test:\nANSWER TO THE C++ GAME DEV EXAM QUESTION: __4__ POKER FACE.\n\n";
//	std::cout << "OBSERVATIONs:\n\n";
//	std::cout << "1-   The INPUT and OUTPUT Path of the Files (String) are HARDCODED, meaning that It is inside the Script: main.cpp.\n\n";
//	std::cout << "2-   The Files will be read and written in the SAME PATH that this executable (.exe) has.\n";
//	std::cout << "\n---\n\n";
//	//
//	// 1-	INPUT:	Name of the File to Read from:
//	//
//	const string _inputFileName = "poker.txt";
//
//	// 2-	OUTPUT: Name of the File to Write the Output of the Game to:
//	//
//	const string _outputFileName = "pokerOutput.txt";
//	//
//	std::cout << "3-   INPUT FILE to find and read the games from: ->       " << _inputFileName << "\n\n";
//	std::cout << "4-   OUPUT FILE to create and write the games results: -> " << _outputFileName << "\n";
//	std::cout << "\n---\n";
//	std::cout << "\n03/2020\n\n***************************************\n";
//	std::cout << "\nVerbose OUTPUT:\n";
//
//	// 1- Players:
//	//	P1
//	//
//	Player myPlayerP1(1);
//	//
//	//	P2
//	//
//	Player myPlayerP2(2);
//
//	// 2- Card Manager: Logic of the Game: Construct the Card and CardType Objects Infraestructure:
//	//
//	CardManager::InitializeGameObjectsToPlayLater(myPlayerP1, myPlayerP2);
//
//
//	// Print Test Data to see if the Structure of the UML - Classes and Objects are being loaded correctly:
//	//
////	PrintGameObjectsData();
//	//
//	std::cout << std::flush;
//
//
//
//	// 3- Card Manager: Logic of the Game: Construct the 'Hand' and 'HandType' Objects Infraestructure:
//	//
////	const string myGameStringLine1 = "5H 5C 6S 7S KD 2C 3S 8S 8D TD";
////	const string myGameStringLine1 = "5D 8C 9S JS AC 2C 5C 7D 8S QH";
////	const string myGameStringLine1 = "2D 9C AS AH AC 3D 6D 7D TD QD";
////	const string myGameStringLine1 = "4D 6S 9H QH QC 3D 6D 7H QD QS";
////	const string myGameStringLine1 = "2H 2D 4C 4D 4S 3C 3D 3S 9S 9D";
////	const string myGameStringLine1 = "7H 7D KC KD 2S 8H 8D KH KS 2D";	// P2: EMPATE,Gana por valor de SEGUNDO PAR...
////	const string myGameStringLine1 = "7H 7D KC KD 2S 7S 7C KH KS 3S";	// P2: EMPATE, resuelve comparando la ULTIMA CARTA: 'NOT DEFINITION'.
////	const string myGameStringLine1 = "7H 7D KC KD 2S 7S 7C KH KS 2D";	// EMPATE TWO PAIRS completo
////	const string myGameStringLine1 = "TD JD QD KD AD 9H TH JH QH KH";	// P1: ROYAL VS STRAIGHT (FLUSHES ambos).
////	const string myGameStringLine1 = "7H 7D 7S 7C 2S 2D 3S 4H 5C 6D";	// P1: FOUR OF A KIND VS STRAIGHT normal.
////	const string myGameStringLine1 = "7H 7D 7S 7C 2S 2D 3D 4D 5D 6C";	// P1: FOUR OF A KIND VS STRAIGHT normal,
//	//
//	//////...PERO CON CARTAS de IGUAL TIPO... sigue siend un STRAIGHT Normal.
//	//
////	const string myGameStringLine1 = "7H 7D 7S 7C 2S 2D 3D 4D 5D 6D";	// P2: FOUR OF A KIND VS STRAIGHT FLUSH
//
//
//	// Input Game Lines:
//	//
//	const string myGameInputLines[] =
//	{
//
//		"2H 2D 4C 4D 4S 3C 3D 3S 9S 9D",
//		"7H 7D KC KD 2S 8H 8D KH KS 2D",	/*// P2: EMPATE,Gana por valor de SEGUNDO PAR...*/
//		"7H 7D KC KD 2S 7S 7C KH KS 3S",	/*// P2: EMPATE, resuelve comparando la ULTIMA CARTA: 'NOT DEFINITION'.*/
//		"7H 7D KC KD 2S 7S 7C KH KS 2D",	/*// EMPATE TWO PAIRS completo*/
//		"TD JD QD KD AD 9H TH JH QH KH",	/*// P1: ROYAL VS STRAIGHT (FLUSHES ambos).*/
//		"7H 7D 7S 7C 2S 2D 3S 4H 5C 6D",	/*// P1: FOUR OF A KIND VS STRAIGHT normal.*/
//		"7H 7D 7S 7C 2S 2D 3D 4D 5D 6C",	/*// P1: FOUR OF A KIND VS STRAIGHT normal,
//		//
//		//////...PERO CON CARTAS de IGUAL TIPO... sigue siend un STRAIGHT Normal.
//		//*/
//		"7H 7D 7S 7C 2S 2D 3D 4D 5D 6D"		/*// P2: FOUR OF A KIND VS STRAIGHT FLUSH*/ ,
//
//		"5H 5C 6S 7S KD 2C 3S 8S 8D TD",
//		"5D 8C 9S JS AC 2C 5C 7D 8S QH",
//		"2D 9C AS AH AC 3D 6D 7D TD QD",
//		"4D 6S 9H QH QC 3D 6D 7H QD QS",
//		//
//		"5D 8C 9S JS AC 2D 3S 4H 5C 6D",
//		"2D 3S 4H 5C 6D 2C 5C 7D 8S QH",
//		//
//		"2C 5C 7D 8S QC 9H TH JH QH KH",
//		"2C 5C 7D QC 8S 9H TH JH QH KH",
//		//
//		"2C 5C 7D 8S QH 9H TH JH QH KH",
//		"2C 5C 7D 8S QD 9H TH JH QH KH",
//		"2C 5C 7D 8S QS 9H TH JH QH KH",
//		//
//		"2D 3D 4D 5D 6C 7H 7D 7S 7C 2S"		/*// P2: FOUR OF A KIND VS STRAIGHT FLUSH*/
//
//	};
//
//	// Size of that Array:
//	//
//	const int inputLinesArraySize = sizeof( myGameInputLines ) / sizeof( myGameInputLines [0] );
//
//
//	//////////////
//	//
//	// Call the Main Function to Play the Game:		(Console Version	OUTPUT).
//	//
//	///// Debug version: CardManager::PlayTheGameConsoleVersion ( myGameInputLines, inputLinesArraySize, myPlayerP1, myPlayerP2 );
//	//
//	// Call the Main Function to Play the Game:		(Console Version	OUTPUT).
//	//
//	CardManager::PlayTheGameOutputToFileVersion(myGameInputLines, inputLinesArraySize, myPlayerP1, myPlayerP2, _outputFileName);
//	//
//	/////////////
//
//
//	// Pause Console:
//	//
//	std::cout << "\n\n\nBy: Alejandro E. Almarza Martin\n\n";
//	std::cout << CardManager::GetTerminatorASCII() << endl;
//	std::cout << "\nPress the <ENTER> key to Terminate the Program.";
//	// Pause:
//	//
//	cin.get();
//
//	return 0;
//}


/**
 * Main Function Call.
 */
int main()
{

	std::cout << "\n***************************************\nBy: Alejandro E. Almarza Martin";
	std::cout << "\n***************************************\n\n";
	std::cout << "Bamtang Games Entrance Test:\nANSWER TO THE C++ GAME DEV EXAM QUESTION: __4__ POKER FACE.\n\n";
	std::cout << "OBSERVATIONs:\n\n";
	std::cout << "1-   The INPUT and OUTPUT Path of the Files (String) are HARDCODED, meaning that It is inside the Script: main.cpp\n (as precompiled #define CONSTANTS).\n\n";
	std::cout << "2-   The Files will be read and written in the SAME PATH where this executable (.exe) is.\n";
	std::cout << "\n---\n\n";
	//
	// 1-	INPUT:	Name of the File to Read from:
	//
	const string _inputFileName		= _INPUT_FILE_SHORT_NAME;

	// 2-	OUTPUT: Name of the File to Write the Output of the Game to:
	//
	const string _outputFileName	= _OUTPUT_FILE_SHORT_NAME;
	//
	std::cout << "3-   INPUT FILE to find and read the games from:   ->  -> " << _inputFileName << "\n\n";
	std::cout << "4-   OUPUT FILE to create and write the games results: -> " << _outputFileName << "\n";
	std::cout << "\n---\n";
	std::cout << "\n03/2020\n\n***************************************\n";
	std::cout << "\nVerbose OUTPUT:\n";

	// 1- Players:
	//	P1
	//
	Player myPlayerP1(1);
	//
	//	P2
	//
	Player myPlayerP2(2);

	// 2- Card Manager: Logic of the Game: Construct the Card and CardType Objects Infraestructure:
	//
	CardManager::InitializeGameObjectsToPlayLater(myPlayerP1, myPlayerP2);


	// Print Test Data to see if the Structure of the UML - Classes and Objects are being loaded correctly:
	//
	///// Debug Print-to-Console: // PrintGameObjectsData();
	//
	std::cout << std::flush;


	// 3- Card Manager: Logic of the Game: Construct the 'Hand' and 'HandType' Objects Infraestructure:
	//
	// Input file:
	//
	std::ifstream _inputFile(_inputFileName);
	//
	// Vector of String: The Whole File will be uploaded in this variable:
	//
	std::vector<std::string> myGameInputLines;
	myGameInputLines.clear();
	//
	OpenReadFileToVectorOfString( _inputFile, _inputFileName, myGameInputLines );

	// Size of that Array:
	//
	const int inputLinesArraySize = myGameInputLines.size();


	//////Main Function Call////////
	//
	// Debug:   Call the Main Function to Play the Game:		(Console Version	OUTPUT).
	//
	///// Debug version: CardManager::PlayTheGameConsoleVersion ( myGameInputLines, inputLinesArraySize, myPlayerP1, myPlayerP2 );
	//
	if (inputLinesArraySize > 0)
	{

		// Call the Main Function to Play the Game:		(.txt Version	OUTPUT).
		//
		CardManager::PlayTheGameOutputToFileVersion(myGameInputLines, inputLinesArraySize, myPlayerP1, myPlayerP2, _outputFileName);

	}//End if (inputLinesArraySize > 0)
	else
	{

		std::cout << "\n  *   There was an problem when trying to get the Game Lines (Hands of Cards) from the input File...\n  ->  Please check that the File is in the same PATH as the (executable) .exe, and that it contains some lines of data, to be read.\n";

	}//End else
	//
	///END///Main Function Call////////


	// Pause Console:
	//
	std::cout << "\n\n\nBy: Alejandro E. Almarza Martin\n\n";
	std::cout << CardManager::GetTerminatorASCII() << endl;
	std::cout << "\nPress the <ENTER> key to Terminate the Program.";
	//
	// Pause:
	//
	cin.get();

	return 0;
}
