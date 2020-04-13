/******************************************************************************/


/***************************TODO LIST*************************************/
/*
 * 0- HOW TO TOKENIZE:
 *
 * 	0.1-	https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
 *
 * 	0.2-	https://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c
 *
 * 	0.3-	http://www.cplusplus.com/reference/cstring/strtok/
 *
 *	---
 *
 * 1-Empezar con la Logica Real del Juego, en la Clase Estática: card_manager (CardManager).
 *
 * 	.1-	Podría Inicializar tooodooo como ya lo hace actualmente.
 *
 * 	.2-	Luego:
 *
 * 		.1-	Programar:  'ReadGameFromFileAndPlayOneLineP1vsP2( myFile, int lineNumberToReadAndPlayAGame )'
 * 		.2-	A (.1) se le puede poner en un Loop, de manera que ese M'etodo que lo Englobe:
 *
 * 			.1-	Lea cada L'inea del Archivo...
 * 			.2-	Imprima por Pantalla el RESULTADO + Alguna DATA de Prueba (que me sirva a mi).
 *
 *
 *		.3-	Simplificación:
 *
 *			.1-	Dada una entrada type String (i.e.: la LÍNEA DE TEXTO del JUEGO).
 *
 *				.1-	Verificar para cada PLAYER <P1, P2>:
 *
 *				{
 *					.1-	Qué MANO (HAND) tiene?  <Identificar el HAND_TYPE, según Algoritmos que estén
 *
 *						BUSCANDO PATRONES>.
 *
 *
 *					.2-	ACÁ QUEDEEEEEEEEEE!!
 *
 *					LISTO
 *					_____
 *
 *					1-	VERIFICAR	ROYAL 		FLUSH
 *					2-	VERIFICAR	STRAIGHT 	FLUSH
 *
 *					FALTA: (voy por...)
 *					_____
 *
 *					3-	VERIFICAR	FOUR OF A KIND
 *					...
 *					y el resto (HASTA llegar a HIGH CARD).
 *
 *			SetHandAndHandTypeAttributesForFourOfAKind	ACAAAAAAAAAQUEDEEEEEEEEEEEE
 *
 *
 *				}
 *
 *
 *			NOTA:	Deseo usar 40 líneas para el Resultado de P1, 40 para P2 y separarlas por 5 líneas
 *			TOTAL:	85 Líneas... para un Juego.
 *
 */

///falta:

//	Invocar todo desde un Métdo GENERALIZADOR, que lo invoque todo desde arriba.............
//.......puedo usar un ARRAY DE STRINGS,
//.......en Sustitución de un cada READLINE/* LEE UNA LINEA DEL TEXTO...*/( .TXT INPUT ).

// ////////DESPUÉS:	CAMBIAR ESE FOR { .... READLINE }
///////////=> Por =>
/////////////////////// FOR { READLINE DE osstream, readLine, etc...}

// LISTO: 	Los PrintWithFormat(...)

/////->>>>>>>>>>Solo falta:  EL Mtodo General que LOS ENSAMBLA E IMPRIME TODO EL "OUTPUT GENERALIZADO".

//-----quede eeeeeeeennnnnnn:

////////CABECERA DE TODO OUTPUT::::::::::::---listo

//1- EMBELLECER MAS LA TABLA: TOTALES	---listo!

//2- poNERLE nombres de cartas en espanol: ATRIBUTO EN CARD (y  #defines con cada nombre +
//.......ocnstructor + get, etc). SINGULAR Y PLURAL	---listo!

//3- IDEM CON:  CARD TYPE su Nombre en ESPANOL LITERAL (largo)	---listo!

//zz-	POnerlo para .TXT INPUT y OUTPUT otro .TXT..........

///////////////quedee ennnnnnnnnnn:
//
//	1-	Poner todas las funciones de "util_functions.hpp" en: "card_manager.hpp": para evitar el bug del LINKER (1900), y (2100)	---listo!

//	2-	Quede en: Ahora ponerlo con VERDADERO TRATAMIENTO de FILE.TXT:
//		.1-	Reading:	(si no existe decirlo y ABORTAR EJECUCION)
//		.2-	WRITING:	(si no existe: CREARLO y escribir allí todo tu OUTPUT).

//
/*******************************************************************************/

#include "card.hpp"
#include "card_manager.hpp"
#include "card_type.hpp"
#include "hand.hpp"
#include "hand_type.hpp"
#include "player.hpp"
//
// Includes with Test-Purposes:
//
///// it in [ "card_manager.hpp" ]:	 #i... "test_functions.hpp"

#include <iostream>
#include <string>

using namespace std;


/********************STATIC MEMBER VARIABLES (i.e.: Class Attributes) DECLARATION***********************/
//
Player CardManager::_myPlayerList[_MAX_PLAYERS_COUNT];
CardType CardManager::_myCardTypeList[_MAX_CARD_TYPE_COUNT];
Card CardManager::_myCardList[_MAX_CARDS_COUNT];
string CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ENGLISH[_TOTAL_HAND_TYPES]; // = { _HIGH_CARD_NAME_ENG, _ONE_PAIR_NAME_ENG, _TWO_PAIRS_NAME_ENG, _THREE_OF_A_KIND_NAME_ENG, _STRAIGHT_NAME_ENG, _FLUSH_NAME_ENG, _FULL_HOUSE_NAME_ENG, _FOUR_OF_A_KIND_NAME_ENG, _STRAIGHT_FLUSH_NAME_ENG, _ROYAL_FLUSH_NAME_ENG };
string CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL[_TOTAL_HAND_TYPES]; // = { _HIGH_CARD_NAME_ESP, _ONE_PAIR_NAME_ESP, _TWO_PAIRS_NAME_ESP, _THREE_OF_A_KIND_NAME_ESP, _STRAIGHT_NAME_ESP, _FLUSH_NAME_ESP, _FULL_HOUSE_NAME_ESP, _FOUR_OF_A_KIND_NAME_ESP, _STRAIGHT_FLUSH_NAME_ESP, _ROYAL_FLUSH_NAME_ESP };


int main()
{

	std::cout << "\n***************************************\nBy: Alejandro E. Almarza Martin";
	std::cout << "\n***************************************\n\n";
	std::cout << "Bamtang Games Entrance Test:\nANSWER TO THE C++ GAME DEV EXAM QUESTION: __4__ POKER FACE.\n\n";
	std::cout << "OBSERVATION: The INPUT and OUTPUT File (String) is HARDCODED, meaning that It is inside the Script: main.cpp.\n";
	std::cout << "\n03/2020\n\n***************************************\n";
	std::cout << "\nVerbose OUTPUT:\n";

	// 1-	INPUT:	Name of the File to Read from:
	//
	const string _inputFileName 	= "poker.txt";

	// 2-	OUTPUT: Name of the File to Write the Output of the Game to:
	//
	const string _outputFileName 	= "pokerOutput.txt";


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
//	PrintGameObjectsData();
	//
	std::cout << std::flush;



	// 3- Card Manager: Logic of the Game: Construct the 'Hand' and 'HandType' Objects Infraestructure:
	//
//	const string myGameStringLine1 = "5H 5C 6S 7S KD 2C 3S 8S 8D TD";
//	const string myGameStringLine1 = "5D 8C 9S JS AC 2C 5C 7D 8S QH";
//	const string myGameStringLine1 = "2D 9C AS AH AC 3D 6D 7D TD QD";
//	const string myGameStringLine1 = "4D 6S 9H QH QC 3D 6D 7H QD QS";
//	const string myGameStringLine1 = "2H 2D 4C 4D 4S 3C 3D 3S 9S 9D";
//	const string myGameStringLine1 = "7H 7D KC KD 2S 8H 8D KH KS 2D";	// P2: EMPATE,Gana por valor de SEGUNDO PAR...
//	const string myGameStringLine1 = "7H 7D KC KD 2S 7S 7C KH KS 3S";	// P2: EMPATE, resuelve comparando la ULTIMA CARTA: 'NOT DEFINITION'.
//	const string myGameStringLine1 = "7H 7D KC KD 2S 7S 7C KH KS 2D";	// EMPATE TWO PAIRS completo
//	const string myGameStringLine1 = "TD JD QD KD AD 9H TH JH QH KH";	// P1: ROYAL VS STRAIGHT (FLUSHES ambos).
//	const string myGameStringLine1 = "7H 7D 7S 7C 2S 2D 3S 4H 5C 6D";	// P1: FOUR OF A KIND VS STRAIGHT normal.
//	const string myGameStringLine1 = "7H 7D 7S 7C 2S 2D 3D 4D 5D 6C";	// P1: FOUR OF A KIND VS STRAIGHT normal,
	//
	//////...PERO CON CARTAS de IGUAL TIPO... sigue siend un STRAIGHT Normal.
	//
//	const string myGameStringLine1 = "7H 7D 7S 7C 2S 2D 3D 4D 5D 6D";	// P2: FOUR OF A KIND VS STRAIGHT FLUSH


	// Input Game Lines:
	//
	const string myGameInputLines[] =
	{

		"2H 2D 4C 4D 4S 3C 3D 3S 9S 9D",
		"7H 7D KC KD 2S 8H 8D KH KS 2D",	/*// P2: EMPATE,Gana por valor de SEGUNDO PAR...*/
		"7H 7D KC KD 2S 7S 7C KH KS 3S",	/*// P2: EMPATE, resuelve comparando la ULTIMA CARTA: 'NOT DEFINITION'.*/
		"7H 7D KC KD 2S 7S 7C KH KS 2D",	/*// EMPATE TWO PAIRS completo*/
		"TD JD QD KD AD 9H TH JH QH KH",	/*// P1: ROYAL VS STRAIGHT (FLUSHES ambos).*/
		"7H 7D 7S 7C 2S 2D 3S 4H 5C 6D",	/*// P1: FOUR OF A KIND VS STRAIGHT normal.*/
		"7H 7D 7S 7C 2S 2D 3D 4D 5D 6C",	/*// P1: FOUR OF A KIND VS STRAIGHT normal,
		//
		//////...PERO CON CARTAS de IGUAL TIPO... sigue siend un STRAIGHT Normal.
		//*/
		"7H 7D 7S 7C 2S 2D 3D 4D 5D 6D"		/*// P2: FOUR OF A KIND VS STRAIGHT FLUSH*/ ,

		"5H 5C 6S 7S KD 2C 3S 8S 8D TD",
		"5D 8C 9S JS AC 2C 5C 7D 8S QH",
		"2D 9C AS AH AC 3D 6D 7D TD QD",
		"4D 6S 9H QH QC 3D 6D 7H QD QS",
		//
		"5D 8C 9S JS AC 2D 3S 4H 5C 6D",
		"2D 3S 4H 5C 6D 2C 5C 7D 8S QH",
		//
		"2C 5C 7D 8S QC 9H TH JH QH KH",
		"2C 5C 7D QC 8S 9H TH JH QH KH",
		//
		"2C 5C 7D 8S QH 9H TH JH QH KH",
		"2C 5C 7D 8S QD 9H TH JH QH KH",
		"2C 5C 7D 8S QS 9H TH JH QH KH",
		//
		"2D 3D 4D 5D 6C 7H 7D 7S 7C 2S"		/*// P2: FOUR OF A KIND VS STRAIGHT FLUSH*/

	};

	// Size of that Array:
	//
	const int inputLinesArraySize = sizeof( myGameInputLines ) / sizeof( myGameInputLines [0] );


	//////////////
	//
	// Call the Main Function to Play the Game:		(Console Version	OUTPUT).
	//
	CardManager::PlayTheGameConsoleVersion ( myGameInputLines, inputLinesArraySize, myPlayerP1, myPlayerP2 );
	//
	/////////////


	// Pause Console:
	//
	std::cout << "\n\n\nBy: Alejandro E. Almarza Martin\n\n";
	std::cout << CardManager::GetTerminatorASCII() << endl;
	std::cout << "\nPress the <ENTER> key to Terminate the Program.";
	// Pause:
	//
	cin.get();

	return 0;
}
