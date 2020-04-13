#ifndef CARD_MANAGER_H		// Guard for not including twice the same API / LIB.
#define CARD_MANAGER_H

// Default C++ Includes:
//
#include <string>
#include <vector>
//
//	From Util_Functions
/// Does not work in Visual C++:  bits/stdc++.h
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	 // Sort an array according to other (array) using pair in STL. + // Also: For a 'Tokenizer' Method:
//
#include <sstream> 	// Number to String
//
// Formating the cout Output:
//
#include <iomanip>       // std::setfill, std::setw
//
// My Custom Includes:
//
#include "player.hpp"
#include "card.hpp"
#include "card_type.hpp"
#include "hand_type.hpp"


using namespace std;


/**************Global Variables********************/

#define _MAX_PLAYERS_COUNT     2
//
#define _PLAYER_ONE_ARRAY_INDEX     0
#define _PLAYER_TWO_ARRAY_INDEX     1
//
#define _MAX_CARDS_COUNT               52
#define _MAX_CARDS_PER_TYPE_COUNT      13
#define _MAX_CARD_TYPE_COUNT			4
//
// Hand & 'HAND TYPE':
//
#define _TOTAL_CARDS_READ_FROM_INPUT_LINE	10
#define _MAX_CARDS_PER_HAND				5
//
//
// OUTPUT of the GAME (CARDS and CARD TYPE)
//
// Line 2 of OUTPUT:	'Máxima Carta'
//
#define _OUTPUT_LINE__1_SECTION_1_MANO		"Mano"
#define _OUTPUT_LINE__1_SECTION_2_JUGADOR_1	"Jugador 1"
#define _OUTPUT_LINE__1_SECTION_3_JUGADOR_2	"Jugador 2"
#define _OUTPUT_LINE__1_SECTION_4_GANADOR	"Ganador"
//
#define _OUTPUT_LINE_0_WINNER_ESP			"Jugador"
#define _OUTPUT_LINE_2_BEGINNING			"Maxima Carta:"
#define _OUTPUT_LINE_2_ENDING_TIE			"EMPATE"  	//"NINGUNO, porque es un EMPATE."
//
// Totales:
//
#define _OUTPUT_LINE_TOTALES_2_SEPARATOR	"******************************************************************************"
#define _OUTPUT_LINE_TOTALES_1				"Totales"
//
// OUTPUT: Array Sizes
//
#define _OUTPUT_MAX_STRING_OR_ARRAY_SIZE				70
#define _OUTPUT_FIRST_SHORT_TOTAL_CHAR_SECTION			8
#define _OUTPUT_SECOND_AND_THIRD_TOTAL_CHAR_SECTION		50
#define _OUTPUT_FOURTH_FINAL_TOTAL_CHAR_SECTION			9
//
// Hand Types:
//
// 1- Total Number:
//
#define _TOTAL_HAND_TYPES				10
//
// 2- Types:
//
#define _HIGH_CARD_VALUE		0
#define _ONE_PAIR_VALUE			1
#define _TWO_PAIRS_VALUE		2
#define _THREE_OF_A_KIND_VALUE	3
#define _STRAIGHT_VALUE			4
#define _FLUSH_VALUE			5
#define _FULL_HOUSE_VALUE		6
#define _FOUR_OF_A_KIND_VALUE	7
#define _STRAIGHT_FLUSH_VALUE	8
#define _ROYAL_FLUSH_VALUE		9
//
// HAND TYPE NAMES (Pure, in English)
//
#define _HIGH_CARD_NAME			"HIGH CARD"
#define _ONE_PAIR_NAME			"ONE PAIR"
#define _TWO_PAIRS_NAME			"TWO PAIRS"
#define _THREE_OF_A_KIND_NAME	"THREE OF A KIND"
#define _STRAIGHT_NAME			"STRAIGHT"
#define _FLUSH_NAME				"FLUSH"
#define _FULL_HOUSE_NAME		"FULL HOUSE"
#define _FOUR_OF_A_KIND_NAME	"FOUR OF A KIND"
#define _STRAIGHT_FLUSH_NAME	"STRAIGHT FLUSH"
#define _ROYAL_FLUSH_NAME		"ROYAL FLUSH"
//
// HAND TYPE NAMES (Printer Friendly):	 ENGLISH
//
#define _HIGH_CARD_NAME_ENG			"HIGH CARD:"						// [..HIGHEST 'Card Number', ..Card Type in Hand]
#define _ONE_PAIR_NAME_ENG			"ONE PAIR of"						// [..Card Number in PAIR]
#define _TWO_PAIRS_NAME_ENG			"TWO PAIRS:"						// [..Card Number in PAIR ONE, ..Card Number in PAIR TWO]
#define _THREE_OF_A_KIND_NAME_ENG	"THREE OF A KIND:"					// [..Card Number in the Triple]
#define _STRAIGHT_NAME_ENG			"STRAIGHT w/best card:"				// [..Card Number]
#define _FLUSH_NAME_ENG				"FLUSH of"							// [..Type Of Card]
#define _FULL_HOUSE_NAME_ENG		"FULL HOUSE of"						// [..Card Number in the Triple]
#define _FOUR_OF_A_KIND_NAME_ENG	"FOUR OF A KIND:"					// [..Card Number]
#define _STRAIGHT_FLUSH_NAME_ENG	"STRAIGHT FLUSH w/best card:"		// [..Card Number , Type Of Card]
#define _ROYAL_FLUSH_NAME_ENG		"ROYAL FLUSH of"					// [..Type Of Card]
//
// HAND TYPE NAMES (Printer Friendly):	 ESPAÑOL
//
#define _HIGH_CARD_NAME_ESP			"HIGH CARD:"						// [..HIGHEST 'Card Number', ..Card Type in Hand]
#define _ONE_PAIR_NAME_ESP			"PAR de"							// [..Card Number in PAIR]
#define _TWO_PAIRS_NAME_ESP			"DOS PARES:"						// [..Card Number in PAIR ONE, ..Card Number in PAIR TWO]
#define _THREE_OF_A_KIND_NAME_ESP	"TRES"								// [..Card Number in the Triple]
#define _STRAIGHT_NAME_ESP			"STRAIGHT, mejor carta:"			// [..Card Number]
#define _FLUSH_NAME_ESP				"FLUSH de"							// [..Type Of Card]
#define _FULL_HOUSE_NAME_ESP		"FULL HOUSE de"						// [..Card Number in the Triple]
#define _FOUR_OF_A_KIND_NAME_ESP	"CUATRO"							// [..Card Number]
#define _STRAIGHT_FLUSH_NAME_ESP	"STRAIGHT FLUSH, mejor carta:"		// [..Card Number , Type Of Card]
#define _ROYAL_FLUSH_NAME_ESP		"ROYAL FLUSH de"					// [..Type Of Card]
//
// ARRAY [ _TOTAL_HAND_TYPES = 10 ] OF Hand Type:
//
/////Nope, defined inside the Class: #define _ARRAY_OF_HAND_TYPES [ _TOTAL_HAND_TYPES ] = { _HIGH_CARD_VALUE, _ONE_PAIR_VALUE, _TWO_PAIRS_VALUE, _THREE_OF_A_KIND_VALUE, _STRAIGHT_VALUE, _FLUSH_VALUE, _FULL_HOUSE_VALUE, _FOUR_OF_A_KIND_VALUE, _STRAIGHT_FLUSH_VALUE, _ROYAL_FLUSH_VALUE }
//
// Types of Cards:
//
#define _CARD_TYPE_NAME_SPADE     		"S"     // S
#define _CARD_TYPE_LONG_NAME_SPADE		"ESPADAS"     // S
#define _CARD_TYPE_LONG_NAME_ENG_SPADE	"SPADE"     // S
#define _CARD_TYPE_INDEX_SPADE    		0     // 0
//
#define _CARD_TYPE_NAME_CLUB      		"C"     // C
#define _CARD_TYPE_LONG_NAME_CLUB		"TREBOLES"
#define _CARD_TYPE_LONG_NAME_ENG_CLUB	"CLUB"
#define _CARD_TYPE_INDEX_CLUB     		1     // 1
//
#define _CARD_TYPE_NAME_HEART			"H"     // H
#define _CARD_TYPE_LONG_NAME_HEART		"CORAZONES"
#define _CARD_TYPE_LONG_NAME_ENG_HEART	"HEART"
#define _CARD_TYPE_INDEX_HEART			2     // 2
//
#define _CARD_TYPE_NAME_DIAMOND			"D"     // D
#define _CARD_TYPE_LONG_NAME_DIAMOND	"DIAMANTES"
#define _CARD_TYPE_LONG_NAME_ENG_DIAMOND	"DIAMOND"
#define _CARD_TYPE_INDEX_DIAMOND		3     // 3
//
// Names And Values of Cards:
//
/**
 * Number to Convert 'VALUE OF CARD' -> TO -> 'ARRAY INDEX'.
 * e.g.: _CARD_3_VALUE has INDEX => _CARD_3_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER = 3 - 2 = 1 = [ 1 ].
*/
#define _CARD_2_INDEX_TO_ARRAY_CONVERTER 2
//
#define _CARD_2_NAME              "2"
#define _CARD_2_LONG_NAME_ESP_SING	  "dos"
#define _CARD_2_LONG_NAME_ESP_PLURAL  "doses"
#define _CARD_2_VALUE             2
//
#define _CARD_3_NAME              "3"
#define _CARD_3_LONG_NAME_ESP_SING	  "tres"
#define _CARD_3_LONG_NAME_ESP_PLURAL  "treses"
#define _CARD_3_VALUE             3
//
#define _CARD_4_NAME              "4"
#define _CARD_4_LONG_NAME_ESP_SING	  "cuatro"
#define _CARD_4_LONG_NAME_ESP_PLURAL  "cuatros"
#define _CARD_4_VALUE             4
//
#define _CARD_5_NAME              "5"
#define _CARD_5_LONG_NAME_ESP_SING	  "cinco"
#define _CARD_5_LONG_NAME_ESP_PLURAL  "cincos"
#define _CARD_5_VALUE             5
//
#define _CARD_6_NAME              "6"
#define _CARD_6_LONG_NAME_ESP_SING	  "seis"
#define _CARD_6_LONG_NAME_ESP_PLURAL  "seises"
#define _CARD_6_VALUE             6
//
#define _CARD_7_NAME              "7"
#define _CARD_7_LONG_NAME_ESP_SING	  "siete"
#define _CARD_7_LONG_NAME_ESP_PLURAL  "sietes"
#define _CARD_7_VALUE             7
//
#define _CARD_8_NAME              "8"
#define _CARD_8_LONG_NAME_ESP_SING	  "ocho"
#define _CARD_8_LONG_NAME_ESP_PLURAL  "ochos"
#define _CARD_8_VALUE             8
//
#define _CARD_9_NAME              "9"
#define _CARD_9_LONG_NAME_ESP_SING	  "nueve"
#define _CARD_9_LONG_NAME_ESP_PLURAL  "nueves"
#define _CARD_9_VALUE             9
//
#define _CARD_10_T_NAME           "T"
#define _CARD_10_T_LONG_NAME_ESP_SING		"diez"
#define _CARD_10_T_LONG_NAME_ESP_PLURAL		"dieces"
#define _CARD_10_T_VALUE          10
//
//
#define _CARD_J_NAME              "J"
#define _CARD_J_LONG_NAME_ESP_SING	  "Jota"
#define _CARD_J_LONG_NAME_ESP_PLURAL  "Jotas"
#define _CARD_J_VALUE             11
//
#define _CARD_Q_NAME              "Q"
#define _CARD_Q_LONG_NAME_ESP_SING	  "Reina"
#define _CARD_Q_LONG_NAME_ESP_PLURAL  "Reinas"
#define _CARD_Q_VALUE             12
//
#define _CARD_K_NAME              "K"
#define _CARD_K_LONG_NAME_ESP_SING	  "Rey"
#define _CARD_K_LONG_NAME_ESP_PLURAL  "Reyes"
#define _CARD_K_VALUE             13
//
#define _CARD_A_NAME              "A"
#define _CARD_A_LONG_NAME_ESP_SING	  "As"
#define _CARD_A_LONG_NAME_ESP_PLURAL  "Ases"
#define _CARD_A_VALUE             14


/***************** Forward declarations & Function prototypes **********************/

class Player;
class CardType;
class Card;
///// Substitution: Two Arrays of Names wit Values as [Key = 0....10] (In English and Spanish): class HandType;


/***************** This Class Definition **********************/

class CardManager
{
  
  public:
  
  // Attr
  //
  // static const int _id;


  // Pointers
  //
  /** List of Players (2)
  **/
  static Player _myPlayerList[ _MAX_PLAYERS_COUNT ]; // = nullptr;


  /** List of CardType (4) avaliable
  **/
  static CardType _myCardTypeList[ _MAX_CARD_TYPE_COUNT ]; // = nullptr;


  /** List of Cards (52)
  **/
  static Card _myCardList[ _MAX_CARDS_COUNT ]; // = nullptr;


  /** List of 'Hand Types' (10) (Avaliable): 		HIGH CARD, ..., ROYAL FLUSH.
  **/
  ///// Substitution: Two Arrays of Names wit Values as [Key = 0....10] (In English and Spanish): 	static HandType (&_myHandTypeList)[ _TOTAL_HAND_TYPES ]; // = nullptr;
  //
  //enum myEnum { arrsize = _TOTAL_HAND_TYPES };

  /**
   * Array of HAND TYPES, (Printer Friendly). [ ENGLISH ]
   * e.g.: "ONE PAIR of" [ Fives], "HIGH CARD" [ Ace]
   */
  static string _ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ENGLISH [ /*arrsize*/ _TOTAL_HAND_TYPES ];	// = { _HIGH_CARD_NAME_ENG, _ONE_PAIR_NAME_ENG, _TWO_PAIRS_NAME_ENG, _THREE_OF_A_KIND_NAME_ENG, _STRAIGHT_NAME_ENG, _FLUSH_NAME_ENG, _FULL_HOUSE_NAME_ENG, _FOUR_OF_A_KIND_NAME_ENG, _STRAIGHT_FLUSH_NAME_ENG, _ROYAL_FLUSH_NAME_ENG };

  /**
   * Array of HAND TYPES, (Printer Friendly). [ ESPAÑOL ]
   * e.g.: "PAR de" [ Fives], "HIGH CARD" [ Ace]
   */
  static string _ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL [ /*arrsize*/ _TOTAL_HAND_TYPES ]; 	// = { _HIGH_CARD_NAME_ESP, _ONE_PAIR_NAME_ESP, _TWO_PAIRS_NAME_ESP, _THREE_OF_A_KIND_NAME_ESP, _STRAIGHT_NAME_ESP, _FLUSH_NAME_ESP, _FULL_HOUSE_NAME_ESP, _FOUR_OF_A_KIND_NAME_ESP, _STRAIGHT_FLUSH_NAME_ESP, _ROYAL_FLUSH_NAME_ESP };

  
  // Methods
  //
  public:
  //
  // Constructors
  //
  // CardManager();
  //
  ///// Nope, it is STATIC!::  CardManager(const Player &myPlayerOne, const Player &myPlayerTwo);
  // SUBSTITUTE:  InitializeGameObjectsAndPlayTheGame(const Player &myPlayerOne, const Player &myPlayerTwo);

  
  // Destructors
  //
  ~CardManager();

  //*************************** Methods ***************************//


/*************************** Initialization ***************************/

  /**
   * Initializes all GameObjects and Plays the Game... ("..Of L O V E?!  nope!: THIS Game! Poker!").
   *
   * EXCEPTION: It does not initialize the two Players' HANDS.
   */
  static void InitializeGameObjectsToPlayLater(const Player &myPlayer, const Player &myPlayerTwo);


  /**
   * Initializes Players' HANDS.
   * It uses a String CHaracter Line, as INPUT.
   */
  static void ConstructPlayersHandsToPlayLater(Player &myPlayerOne, Player &myPlayerTwo, const string &myGameLineString );

  /**
   * Initializes Players' HANDS.
   * It uses a String CHaracter Line, as INPUT. It is already Tokenized, in the form:
   *   [CARD NAME] [CARD TYPE]
   *
   *   Example: { 6D  7S  TH  7C  AH }	=	{ 6 of HEART | 7 of SPADE | 10 of HEART | ACE of HEART }
   */
  static void ConstructPlayerHand(Player &myPlayer, const string (&myArrayOfStringsCards)[ _MAX_CARD_PER_HAND_COUNT ] );

  /**
   * Initializes Players' HANDS.
   * It uses a String CHaracter Line, as INPUT. It is already Tokenized, in the form:
   *   [CARD NAME] [CARD TYPE]
   *
   *   Example: { 6D  7S  TH  7C  AH }	=	{ 6 of HEART | 7 of SPADE | 10 of HEART | ACE of HEART }
  */
  static void ConstructPlayerCardCardType(Player &myPlayer, const int &cardIndexInPlayerHand, const string &cardName, const string &cardTypeShortName );


  /*********************PLAY THE GAME!***********************/

  /**
   * Plays the Game, in Console version.
   *
   * It is Test Version, with just
   *
   * 	1-	INPUT: 	some HARDCODED Values.
   *
   * 	2-	OUTPUT:	print out to Console.
   */
  static void PlayTheGameConsoleVersion
  (
		  const std::string inputLinesArraySize[],
		  const int arraySize,
		  Player &myPlayerP1, Player &myPlayerP2
  );


  /**
   * Plays the Game, with the current data that is inside ( Player &myP1, Player &myP2 ):
   *
   * a)	HAND -> CARDS
   * b)	TYPE OF HAND:	_hierarchyValue
   * ->
   * (i.e.: Player->_myHand->_myHandType ... ->_hierarchyValue; )
   * ...
   * ...previously setted in:   'static void CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer );'
   */
  static Player* /* WINNER Player */  PlayTheGameTexasPoker( Player &myP1, Player &myP2, bool &easyOrHardVictory, const bool &printDebugPreliminarOutputDetailsOrNot );


  /**
   * Prints out the end game output.
   *
   * It has tow independent modes:
   * 	1-	Print to Console
   * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
   */
  static void PrintAllOutputGameOver
  (
  	Player &myP1,					Player &myP2,
  	const bool &p1Wins,				const bool &p2Wins,

  	const int &arraySize,
  	const int &lineNumber,
  	const std::string &myGameLineP1,
  	const std::string &myGameLineP2,

  	const bool &printSecondLineItWasAlmostATie,

  	const int &firstShortTotalCharactersSection 		/* 8 */,
  	const int &secondAndThirdTotalCharactersSection		/* 55 */,
  	const int &fourthFinalShortTotalCharactersSection	/* 9 */,

  	const bool &printOutToConsole,  const bool &printOutToTextFile
  	/*const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd*/

  	/**Input ostream Text File**/
  );

  /**
   * Prints out HEADER of the TABLE of the end game output.
   *
   * It has two independent modes:
   * 	1-	Print to Console
   * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
   */
  static void PrintAllOutputGameOverJustHeader
  (
  	const int &arraySize,

  	const int &firstShortTotalCharactersSection 		/* 8 */,
  	const int &secondAndThirdTotalCharactersSection		/* 55 */,
  	const int &fourthFinalShortTotalCharactersSection	/* 9 */,

  	const bool &printOutToConsole,  const bool &printOutToTextFile
  	/*const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd*/

  	/**Input ostream Text File**/
  );

  /**
   * Prints out HOW MANY VICTORIES there are: for P1 and P2.
   *
   * It has two independent modes:
   * 	1-	Print to Console
   * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
   */
  static void PrintTotalsVictoriesOutputGameOver
  (
  	const std::string &mySeparator,
  	const int &p1Victories,
  	const int &p2Victories,

  	const int &arraySize,

  	const int &firstShortTotalCharactersSection 		/* 8 */,
  	const int &secondAndThirdTotalCharactersSection		/* 55 */,
  	const int &fourthFinalShortTotalCharactersSection	/* 9 */,

  	const bool &printOutToConsole,  const bool &printOutToTextFile,
  	const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd

  	/**Input ostream Text File**/
  );

  /**
   * Prints out a SEPARATOR Line.
   *
   * It has two independent modes:
   * 	1-	Print to Console
   * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
   */
  static void PrintASeparatorLine
  (
  	const std::string &charSeparator,
  	const int &arraySize,

  	const int &firstShortTotalCharactersSection 		/* 8 */,
  	const int &secondAndThirdTotalCharactersSection		/* 55 */,
  	const int &fourthFinalShortTotalCharactersSection	/* 9 */,

  	const bool &printOutToConsole,  const bool &printOutToTextFile,
  	const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd

  	/**Input ostream Text File**/
  );


  /**
   *	It prints out {TO CONSOLE} the DETAILS OF THE VICTORY.
   *	(Once the game was Player, and there is a Winner).
   *
   *	const bool &p1Wins, const bool &p2Wins:
   *
   *	1-	If those are all: TRUE => THEN there is a TIE (DRAW).
   *	Nevertheless: It is not designed for a tie.
   *
   *	2-	If those are DIFFERENT (true, false... or: false, true): THEN there is a WINNER and a LOSER.
   */
  static void DeclareEasyVictory( Player &myP1, Player &myP2, const bool &p1Wins, const bool &p2Wins );

  /**
   *	It prints out {TO CONSOLE} the DETAILS OF THE VICTORY: In TWO (2) LINEs (according to the CONVENTION	)
   *	(Once the game was Player, and there is a Winner).
   *
   *	const bool &p1Wins, const bool &p2Wins:
   *
   *	1-	If those are all: TRUE => THEN there is a TIE (DRAW).
   *	Nevertheless: It is not designed for a tie, so it will just Print: It is a DRAW!
   *
   *	2-	If those are DIFFERENT (true, false... or: false, true): THEN there is a WINNER and a LOSER.
   */
  static void DeclareHardVictory( Player &myP1, Player &myP2, const bool &p1Wins, const bool &p2Wins );


  /**
   *	It compares the CARDs. Steps:
   *
   *	1-	Copies the arrays and Sorts them out, in an Ascendent way.
   *	2-	Compares the VALUES of each CARD (in the sorted Arrays, from [0].. to [n]): one by one.
   *	3-	The Player with an array with Bigger CARDS: Wins.
   *
   *	Return values:
   *		1-	WINNER			[thus RETURNING a POINTER to the WINNER-PLAYER: {&myPx} ]
   *		2-	LOSER, 	or
   *		3-	A DRAW.			[thus RETURNING a NULL POINTER]
   */
  static Player* CompareCards( Player &myP1, Player &myP2, std::vector < Card* > &myP1PtrCards, std::vector < Card* > &myP2PtrCards , const int &sortP1CardsOrder, const int &sortP2CardsOrder );
  //
  ///static Player* CompareCards( Player &myP1, Player &myP2, std::vector < Card* > &myP1PtrCards, std::vector < Card* > &myP2PtrCards, Card* (&myPtrToHighDifferentCardP1), Card* (&myPtrToHighDifferentCardP2) );

  /**
   *	It compares the (Players') CARDs which are classified as 'HAND DEFINITION cards'.
   *	tHAT WAY: IT DEFINES a
   *		1-	WINNER			[thus RETURNING a POINTER to the WINNER-PLAYER: {&myPx} ]
   *		2-	LOSER, 	or
   *		3-	A DRAW.			[thus RETURNING a NULL POINTER]
   *
   *	PARAMETER: @sortCardsOrder	->	0	:	False.	Not to SORT
   *								->	> 0 :	True.	SORT ASCENDING  [ 1, 2, 3... 100000 ]
   *								->	< 0 :	True.	SORT DESCENDING [ 100000000, 5, 1 ]
   */
  static Player* CompareHandDefinitionCards( Player &myP1, Player &myP2, const int &sortP1CardsOrder, const int &sortP2CardsOrder );

  /**
   *	It compares the (Players') CARDs which are classified as 'HAND NOT-DEFINITION cards'.
   *	tHAT WAY: IT DEFINES a
   *		1-	WINNER			[thus RETURNING a POINTER to the WINNER-PLAYER: {&myPx} ]
   *		2-	LOSER, 	or
   *		3-	A DRAW.			[thus RETURNING a NULL POINTER]
   */
  static Player* CompareHandNotDefinitionCards( Player &myP1, Player &myP2 );

  /**
   * Creates and Sets the OUTPUT LINE 2 of the Game.
   *
   * It is stored inside the HAND Attribute of each PLAYER Object.
   *
   * [ ( myP1.GetMyHand() )->SetOutputMyGameLine2( _OUTPUT_LINE_2_FINAL_P1...... ); ]
   *
   * It is based in the: NOT DEFINITION CARDS (the HIGHEST DIFFERENT one... between P1 & P2).
   */
  static void SetFinalOutputOfLine2( Player &myP1, Player &myP2 );
  //
  //static void SetFinalOutputOfLine2( Player &myP1, Player &myP2, Card* myP1PtrHighestDifferentCard, Card* myP2PtrHighestDifferentCard );


  /**
   * If the Player has been Initialized (and His HAND -> CARDS: are already BUILT),
   * ...but Its Cards had not been read (i.e.: He has not stated to Play the Game):
   *
   * ...1- This Method Gets (discovers...) the Type of HAND...
   *
   * ...IN OTHER Method: This will be done:
   *
   * --------------------------------------
   *
   * ...2- Hierarchy Value (among other Attributes, such as NAME), of the Object:
   *
   * 			Player->_myHand->_myHandType ... ->_hierarchyValue;
   */
  static void CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer );


  /**
   * Verifies if the HAND TYPE is: ROYAL FLUSH.
   * Return: True (if it is!)... False: If Not.
   */
  static const bool VerifyRoyalFlushHandType( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForRoyalFlush( Player &myPlayer );


  /**
   * Verifies if the HAND TYPE is: STRAIGHT FLUSH.
   * Return: True (if it is!)... False: If Not.
   */
  static const bool VerifyStraightFlushHandType( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForStraightFlush( Player &myPlayer );


  /**
   * Verifies that: 	There are FOUR (4) Cards that are the SAME VALUE.
   * NOTE: It is FASTER to Check Cards by Value... rather than by their 'SHORT NAMES'.
   * Return:
   * 	->	True
   * 	->	False
   */
  static const bool VerifyFourOfAKind( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForFourOfAKind( Player &myPlayer );


  /**
   * Verifies that:
   *
   * 1-	There is a THREE OF A KIND (3).
   *
   * 2-	EXCLUDE that Card VALUE from the next calculations:
   *
   * 3-	Discover that there is a ONE PAIR (2) = TWO OF A KIND.
   *
   * Return:
   * 	->	True
   * 	->	False
   */
  static const bool VerifyFullHouse( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForFullHouse( Player &myPlayer );


  /**
  * Verifies if the HAND TYPE is: FLUSH.
  *
  * All Cards must be the SAME CARD_TYPE.
  *
  * Return:
  * 	->	True (if it is!)...
  * 	->	False: If Not.
  */
  static const bool VerifyFlush( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForFlush( Player &myPlayer );


  /**
  * Verifies if the HAND TYPE is: STRAIGHT.
  *
  * Return:
  * 	->	True (if it is!)...
  * 	->	False: If Not.
  */
  static const bool VerifyStraight( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForStraight( Player &myPlayer );


  /**
   * Verifies that: 	There are THREE (3) Cards that are the SAME VALUE.
   * NOTE: It is FASTER to Check Cards by Value... rather than by their 'SHORT NAMES'.
   * Return:
   * 	->	True
   * 	->	False
   */
  static const bool VerifyThreeOfAKind( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForThreeOfAKind( Player &myPlayer );


  /**
   * Verifies that: 	There are TWO (2) PAIRs: of 2 Cards EACH, (that are the SAME VALUE).
   *
   * *** PAIR ONE
   * *** PAIR TWO
   *
   * Return:
   * 	->	True
   * 	->	False
   */
  static const bool VerifyTwoPairs( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForTwoPairs( Player &myPlayer );


  /**
   * Verifies that: 	There is an: ONE (1) PAIR: of 2 Cards that are the SAME VALUE.
   *
   * Return:
   * 	->	True
   * 	->	False
   */
  static const bool VerifyOnePair( Hand & myHand );

  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForOnePair( Player &myPlayer );


  /**
   * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
   */
  static void SetHandAndHandTypeAttributesForHighCard( Player &myPlayer );


  /***********UTILITIES for that*****************/

  /**
   * Verifies that all Cards are the same Type: SPADE or HEART or CLUB or DIAMOND.
   */
  static const bool VerifyAllCardsAreTheSameType( Card * (&myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ] );


  /**
   * Verifies that all Cards are the in ASCENDING ORDER (sorted by their 'values').
   * RETURNS:
   * ->	'initialCardValue' of the Sequence 	[i.e.:  "1"...	 FOR SEQUENCE: [1, 2, 3, 4, 5] ].
   * ->	0 if FALSE <=>			There is NOOOOO Sequence.
   */
  static const int VerifyAllCardsAreSortedInPerfectAscendingOrderAndReturnCardValue( Hand &myHand );


  /**
   * Verifies that all Cards are the in ASCENDING ORDER (sorted by their 'values').
   */
  static const bool VerifyAllCardsAreSortedInPerfectAscendingOrder( Hand &myHand, const int &initialCardValue );


  /**
   * Verifies that: 	There are SOME Cards that are the SAME VALUE.
   * NOTE: It is FASTER to Check Cards by Value... rather than by their 'SHORT NAMES'.
   * Return:
   * 	->	CARD VALUE (if it is TRUE!)...
   * 	->	0 ('Number') : If Not.
   */
  static const int VerifySomeOfAKind( Hand & myHand, const int &COUNTED_OCURRENCES, const int &EXCLUDE_THIS_VALUE,
		  	  	  	  std::vector < Card* > &myRepeatedFoundCards );


  /**
   * Verifies that: 	There are SOME Cards that are the SAME VALUE.
   * NOTE: It is FASTER to Check Cards by Value... rather than by their 'SHORT NAMES'.
   * Return:
   * 	->	CARD VALUE (if it is TRUE!)...
   * 	->	0 ('Number') : If Not.
   *
   * 	ALSO RETURNS (see the last PARAMETER: is a REFERENCE to a Vector< Cards* >)
   *
   * 	->	Vector< Cards* > 	->	With the FOUND " Card* " (s)
   *
   * 	(i.e.: the Pointer to Cards { With REPEATED "Card->VALUE" },  FOUND in the Original List:
   * 		-> Card * (* myCardsInThisHand)[ _MAX_CARD_PER_HAND_COUNT )
   */
  static const int CountHowManyCardsAreThereWithThisValue( Card * (* myCardsInThisHand)[ _MAX_CARD_PER_HAND_COUNT ], const int &cardValue, std::vector < Card* > &myFoundCards );


  /*********************GETTERs & SETTERs***********************/


  /**
   * Gets a 'Card' from the CATALOG LIST, given its VALUE and ITS associated CardType SHORT NAME.
   * For example: CARD VALUE = 9 ; CARD TYPE = SPADE (OPTIONS: { S , C , H , D }) => returns => 9S
   */
  static Card* GetCard( const int &cardValue, const string &cardTypeShortName );

  /**
   * Gets a 'Card' from the CATALOG LIST, given its CARD SHORT NAME
   * ...and ITS associated CardType SHORT NAME.
   *
   * For example: CARD SHORT NAME = "9" ; CARD TYPE = SPADE (OPTIONS: { S , C , H , D }) => returns => 9S
   */
  static Card* GetCard( const string &cardShortName, const string &cardTypeShortName );

  /**
   * Gets a 'CardType' from the CATALOG LIST, given its SHORT NAME
   * For example: { S , C , H , D }.
   */
  static CardType* GetCardType( const string &cardTypeShortName );


  /********************UTILITY METHODS that could not be LINKED INSIDE OTHER CLASSES***********************/

	/**
	 * Generic of Generic: Function to copy the contents of any array (of ANY TYPE T1) (i.e: arrayA) into another (i.e: arrayBTarget) (of ANY TYPE T2).
	 */
  template<typename T1, typename T2, std::size_t N>
  static void CopyArrayAToOtherArrayBGenericTypes(T1(&arrayA)[N], T2(&arrayBTarget)[N]);

  /**
   * Generic Function to copy the contents of any array (i.e: arrayA) into another (i.e: arrayBTarget).
   */
  template<typename T, std::size_t N>
  static void CopyArrayAToOtherArrayB(const T(&arrayA)[N], T(&arrayBTarget)[N]);


  /**
   * Generic Function to initialize any array to a VALUE.
   */
  template<typename T, std::size_t N>
  void InitializeArrayWithAValue(const T& value, T(&arr)[N]);

  /**
   * Generic Function to initialize any array to a VALUE.
   */
  template<typename T, std::size_t N>
  static void InitializeArrayOfPointersWithNullptr(T* (&arr)[N]);


  /**
   * Generic Function to TOKENIZE a string, splitting it into an c-style: ARRAY of STRING.
   */
  template<std::size_t N /*= 10*/>
  static void TokenizeStringSplitIntoCArray(const string &line, const char  &delimiter, std::string(&myArrayOfStrings)[N]);


  /**
   * It splits a Big array (bigArray)...: into two arrays: arr1  and arr2.
   * Condition:	_SIZE_BIG_ARRAY >= ( _SIZE_SMALL_ARRAY_1 + _SIZE_SMALL_ARRAY_2 )
   *
   * Type of the Array: C-Style Classic array: e.g.:   int[], double[], string[], char[].
   */
  template<typename T, std::size_t _SIZE_BIG_ARRAY, std::size_t _SIZE_SMALL_ARRAY_1, std::size_t _SIZE_SMALL_ARRAY_2>
  static void SplitBigArrayIntoTwoArrays(const T(&bigArray)[_SIZE_BIG_ARRAY], T(&arr1)[_SIZE_SMALL_ARRAY_1], T(&arr2)[_SIZE_SMALL_ARRAY_2]);


  /************SORTING METHOD**************/


  /**
   * Method Overload:
   * Function to sort Card Object array b[]
   * according to the order defined by a[]
  */
  template<const std::size_t arrayLength>
  static void PairSortObjects(int(&a)[arrayLength], Card* (&myArrayOfCard)[arrayLength], const bool &ascending);


  /*
   * It Sorts an ARRAY OF CARDS, ACCORDING TO THEIR 'VALUES'.
   *
   * Parameters:
   *
   * @myArrayOfCard       Array of Cards
   * @ascending:          TRUE - ASC || FALSE:  Descending.
   *
   * Driver function
  */
  template<const std::size_t arrayLength>
  static void SortCards(Card* (&myArrayOfCard)[arrayLength], const bool &ascending);


  /************SORTING VECTORS of Card* ***************/

  /**
   * Method Overload:
   * Function to sort Card* Object Vector < Card* >: 	std::vector<Card*> b
   * according to the order defined by the 'array of int':  a[]
  */
  template<typename T>
  static /*inline*/ void PairSortObjectsVector(std::vector <int> &a, std::vector< T* > &myArrayOfPtrToObjects, const bool &ascending, const int &arrayLength);


  /*
   * It Sorts a VECTOR of POINTERS TO: CARDS, ACCORDING TO THEIR 'VALUES'.
   *
   * Parameters:
   *
   * @myArrayOfCard       Vector of Cards
   * @ascending:          TRUE - ASC || FALSE:  Descending.
   *
   * Driver function
  */
  static /*inline*/ void SortVectorOfPointerToCards(std::vector< Card* > &myVectorOfCard, const bool &ascending);


  /**
   * Concatenates 'myVector1' + 'myVector2', and populates the result in: 'myVector3'
   */
  template<typename T>
  static void ConcatenateTwoVectorsAandBAndAddToC(std::vector< T* > &myVector1, std::vector< T* > &myVector2, std::vector< T* > &myVector3Result);

  /***END*********SORTING VECTORS of Card* ***************/


  /***END******SORTING METHOD***************/

  /************** VECTOR & ARRAYS COPY & interchangeability *****************/

  /**
   *  MY CUSTOM:  Generic function to find an ELEMENT in vector Of PONTERS to another TYPENAME
   *  ...(i.e.: std::vector < T* >)
   *
   *  It returns the ELEMENT found.
  */
  template <typename T>
  static const bool SearchInArrayAndReturnObjectFound(const std::vector< T* >  & vecOfElements, T* (&element));


  /**
   *  MY CUSTOM:  Generic function to find all 'SIMILAR' or 'All DIFFERENT' ELEMENTs
   * ...in the COMPARISON between:
   *
   *      arrayOfElements     a c-style array of:  " T* "
   *          AND
   *      myVectorList        vector Of PONTERS to another TYPENAME   ...(i.e.: std::vector < T* >)
   *
   *  It returns a VECTOR-LIST of all the ELEMENTs [ Found / NOT Found]:  According to the Booolean Parameter:
   *
   *      -> const bool &getDifferentElementsTrueOrGetSimilarOcurrences
  */
  template <typename T, std::size_t myarraySize>
  static void SetAVectorComparison(T* (&arrayOfElements)[myarraySize], std::vector < T* > &myVectorList, std::vector < T* > &myResultingVectorList, const bool &getGetSimilarOcurrencesTrueOrDifferentElementsFalse);


  /***END*********** VECTOR & ARRAYS COPY & interchangeability *****************/


  /*******************Printing with Format**********************/


  /**
   *  Prints out (to a Variable): a TEXT with a Format, and fillin empty spaces with a desired char
   *  OUTPUT: std::cout (ALSO AN INPUT)
   *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
   */
  static void PrintSectionToVariable(std::stringstream &myStringstreamVariable, const std::string &textToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd);


  /**
   *  Prints out (to a Variable): a NUMBER with a Format, and fillin empty spaces with a desired char
   *  OUTPUT: std::cout (ALSO AN INPUT)
   *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
   */
  static void PrintSectionToVariable(std::stringstream &myStringstreamVariable, const int &numbersToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd);


  /**
   *  Prints out a TEXT with a Format, and fillin empty spaces with a desired char
   *  OUTPUT: std::cout (ALSO AN INPUT)
   *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
   */
  static std::ostream& PrintSection(std::ostream& o, const std::string &textToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd);


  /**
   *  Prints out a NUMBER with a Format, and fillin empty spaces with a desired char
   *  OUTPUT: std::cout (ALSO AN INPUT)
   *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
   */
  static std::ostream& PrintSection(std::ostream& o, const int &numbersToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd);

  /**
   *  Prints out a certain number (INTEGER),
   *  ..then fills the rest of the Section with BLANK SPACES.
   *
   *  OUTPUT:
   *  @printOutToConsole      ->   Prints out to Console
   *  @printOutToATextFile    ->   Prints out to a given TEXT FILE.
   */
  static /*inline*/ void PrintVariableAndThenFillWithSpaces(std::string &myOutputString,
	  const int &numberItemToPrint, const int &totalNumberOfChars,
	  const bool &printOutToConsole, const bool &printOutToATextFile,
	  const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd, const bool &padTextToTheRightOrFalseISLeft);

  /**
   *  Prints out a certain portion of TEXT (Type: 'char []', 'char *', or 'Char Array').
   *  ..then fills the rest of the Section with BLANK SPACES.
   *
   *  OUTPUT:
   *  @printOutToConsole      ->   Prints out to Console
   *  @printOutToATextFile    ->   Prints out to a given TEXT FILE.
   */
  static /*inline*/ void PrintVariableAndThenFillWithSpaces(std::string &myOutputString,
	  const std::string &stringItemToPrint, const int &totalNumberOfChars,
	  const bool &printOutToConsole, const bool &printOutToATextFile,
	  const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd, const bool &padTextToTheRightOrFalseISLeft);

  //EJEMPLO DE INVOCACION Y USO:
  //
  ////  1-  Create the Input String:
  ////
  //string str = "1g 2h 3y 4u 5i 6i 7i";
  ////
  ////  2-  Create the Output Char * (or char []):
  ////
  //char varCharArrayStoreTheOutputHereFinal33333333 [ maxLongSectionCharArraySize + 1 ];
  ////
  //PrintVariableAndThenFillWithSpaces( varCharArrayStoreTheOutputHereFinal33333333, str /*stringItemToPrint*/, 27 /*totalNumberOfChars*/, true, true );


  //// Uses this: #include <sstream>
  //
  /**
   * Convert a NUMBER to String
   */
  template <typename T>
  static std::string NumberToString(T Number);

  /***END****************Printing with Format**********************/


  /********************Miscelaneous**********************/

  /*
   * It returns a Terminator Picture, made with (ANSI) ASCII characters.
  */
  static /*inline*/ const std::string GetTerminatorASCII();


  /***END**************Miscelaneous**********************/

  /****END****************UTILITY METHODS that could not be LINKED INSIDE OTHER CLASSES***********************/

};
#endif
