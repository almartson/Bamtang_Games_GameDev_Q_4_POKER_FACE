#include "card_manager.hpp"
#include <string>
#include <iostream>
//
#include "util_functions.hpp"
//
// Includes with Test-Purposes:
//
#include "test_functions.hpp"



//// Constructor 0: Empty default
////
/////CardManager::CardManager() {}


// Constructor 1
//
// Nope, it is STATIC!!!!	CardManager::CardManager(const Player &myPlayerOne, const Player &myPlayerTwo  /* , Card myCardList[ _MAX_CARDS_COUNT ], CardType myCardCardTypeList[ _MAX_CARD_TYPE_COUNT ]*/ )
//{ }


// Destructors
//
CardManager::~CardManager()
{
  //std::cout << "CardManager::_myID = " << CardManager::_myID << "\n";
  //std::cout << "this = (Original Object Memory Address & =) " << this << "\n";
  //std::cout << "CardManager::_myNext = " << CardManager::_myNext << "\n\n";
}


//**************************** Methods*********************************//

/*************************** Initialization ***************************/

  /**
   * Initializes all GameObjects and Plays the Game... ("..Of L O V E?!  nope!: THIS Game! Poker!").
   *
   * EXCEPTION: It does not initialize the two Players' HANDS.
   */
void CardManager::InitializeGameObjectsToPlayLater(const Player &myPlayerOne, const Player &myPlayerTwo)
{

  // 1- Initialization of Array of HAND TYPES:   ARRAY [ HAND Value ] = 'NAME OF HAND IN A PRINTER FRIENDLY FASHION'
  // 1- ENGLISH
  //
  /////CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ENGLISH = { _HIGH_CARD_NAME_ENG, _ONE_PAIR_NAME_ENG, _TWO_PAIRS_NAME_ENG, _THREE_OF_A_KIND_NAME_ENG, _STRAIGHT_NAME_ENG, _FLUSH_NAME_ENG, _FULL_HOUSE_NAME_ENG, _FOUR_OF_A_KIND_NAME_ENG, _STRAIGHT_FLUSH_NAME_ENG, _ROYAL_FLUSH_NAME_ENG };
  //
  const string AUX_ARRAY_ENG [_TOTAL_HAND_TYPES] = { _HIGH_CARD_NAME_ENG, _ONE_PAIR_NAME_ENG, _TWO_PAIRS_NAME_ENG, _THREE_OF_A_KIND_NAME_ENG, _STRAIGHT_NAME_ENG, _FLUSH_NAME_ENG, _FULL_HOUSE_NAME_ENG, _FOUR_OF_A_KIND_NAME_ENG, _STRAIGHT_FLUSH_NAME_ENG, _ROYAL_FLUSH_NAME_ENG };
  //
  // Copy the contents of the Const Array inside the Attribute of this Class:
  //
  UtilFunctions::CopyArrayAToOtherArrayB( AUX_ARRAY_ENG, CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ENGLISH );
  //
  //
  // 2- SPANISH
  //
  //
  /////CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL = { _HIGH_CARD_NAME_ESP, _ONE_PAIR_NAME_ESP, _TWO_PAIRS_NAME_ESP, _THREE_OF_A_KIND_NAME_ESP, _STRAIGHT_NAME_ESP, _FLUSH_NAME_ESP, _FULL_HOUSE_NAME_ESP, _FOUR_OF_A_KIND_NAME_ESP, _STRAIGHT_FLUSH_NAME_ESP, _ROYAL_FLUSH_NAME_ESP };
  //
  const string AUX_ARRAY_ESP [_TOTAL_HAND_TYPES] = { _HIGH_CARD_NAME_ESP, _ONE_PAIR_NAME_ESP, _TWO_PAIRS_NAME_ESP, _THREE_OF_A_KIND_NAME_ESP, _STRAIGHT_NAME_ESP, _FLUSH_NAME_ESP, _FULL_HOUSE_NAME_ESP, _FOUR_OF_A_KIND_NAME_ESP, _STRAIGHT_FLUSH_NAME_ESP, _ROYAL_FLUSH_NAME_ESP };
  //
  // Copy the contents of the Const Array inside the Attribute of this Class:
  //
  UtilFunctions::CopyArrayAToOtherArrayB( AUX_ARRAY_ESP, CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL );


  // (*this.) == this->
  //
  // 2- Players in the Game:
  //
  CardManager::_myPlayerList[ _PLAYER_ONE_ARRAY_INDEX ] = myPlayerOne;
  //
  CardManager::_myPlayerList[ _PLAYER_TWO_ARRAY_INDEX ] = myPlayerTwo;
  //
  //
  // 2- Different Types of Cards
  //...in the Game (All of them): C, S, H, D.
  // We may avoid using a For-Loop this time, because there are only four (4) types: S Spades, Diamonds D, Clubs C & Hearts H.
  //
  for (int i = 0; i < _MAX_CARD_TYPE_COUNT; i++)
  {

    // Fill in the Attributes:
    // 1- Types
    //
    if ( i == _CARD_TYPE_INDEX_SPADE )
    {
      // First Type
      //
      CardType  myCardTypeOneSpade(i, _CARD_TYPE_NAME_SPADE, _CARD_TYPE_LONG_NAME_SPADE);
      //
      CardManager::_myCardTypeList[ i ] = myCardTypeOneSpade;

    }//End if
    //
    if ( i == _CARD_TYPE_INDEX_CLUB )
    {
      // Second Type
      //
      CardType  myCardTypeTwoClub(i, _CARD_TYPE_NAME_CLUB, _CARD_TYPE_LONG_NAME_CLUB);
      //
      CardManager::_myCardTypeList[ i ] = myCardTypeTwoClub;

    }//End if
    //
    if ( i == _CARD_TYPE_INDEX_HEART )
    {
      // Third Type
      //
      CardType  myCardTypeThreeHeart(i, _CARD_TYPE_NAME_HEART, _CARD_TYPE_LONG_NAME_HEART);
      //
      CardManager::_myCardTypeList[ i ] = myCardTypeThreeHeart;

    }//End if
    //
    if ( i == _CARD_TYPE_INDEX_DIAMOND )
    {
      // Fourth Type
      //
      CardType  myCardTypeFourthDiamond(i, _CARD_TYPE_NAME_DIAMOND, _CARD_TYPE_LONG_NAME_DIAMOND);
      //
      CardManager::_myCardTypeList[ i ] = myCardTypeFourthDiamond;

    }//End if

  }//End for
  //
  // * List of Cards (52)
  //
  // 3- Cards in the Game (All of them = 52):
  //
  string cardShortName 					= _CARD_2_NAME;
  string cardLongNameSpanishSingular	= _CARD_2_LONG_NAME_ESP_SING;
  string cardLongNameSpanishPlural		= _CARD_2_LONG_NAME_ESP_PLURAL;
  //
  int cardValue 		= _CARD_2_VALUE;
  CardType* myCardType	= nullptr;	// = NULL;	// = CardManager::_myCardTypeList[cardIndex];
  //
  // Calculated Card INDEX: (from 0 to .. 13).
  //
  int cardIndex = 0;
  //
  for (int i = 0; i < _MAX_CARDS_COUNT; i++)
  {

    // Populate the Card List:
    /////////////////////
	//
	// Card Index:
	//
	cardIndex = (i % _MAX_CARDS_PER_TYPE_COUNT);
	//
    // 1- Types
    //
    // Type of Card
    //
    myCardType = (&_myCardTypeList[ i / _MAX_CARDS_PER_TYPE_COUNT ]);
    //
    // 2- Name & Value:
    //
    if ( cardIndex == (_CARD_2_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

      // Values, attributes:
      //
      cardShortName 				= _CARD_2_NAME;
	  cardLongNameSpanishSingular	= _CARD_2_LONG_NAME_ESP_SING;
	  cardLongNameSpanishPlural		= _CARD_2_LONG_NAME_ESP_PLURAL;
	  //
      cardValue = _CARD_2_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_3_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_3_NAME;
		cardLongNameSpanishSingular	= _CARD_3_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_3_LONG_NAME_ESP_PLURAL;
		//
		cardValue = _CARD_3_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_4_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_4_NAME;
		cardLongNameSpanishSingular	= _CARD_4_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_4_LONG_NAME_ESP_PLURAL;
		//
		cardValue = _CARD_4_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_5_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_5_NAME;
		cardLongNameSpanishSingular	= _CARD_5_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_5_LONG_NAME_ESP_PLURAL;
		//
		cardValue = _CARD_5_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_6_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_6_NAME;
		cardLongNameSpanishSingular	= _CARD_6_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_6_LONG_NAME_ESP_PLURAL;
		//
		cardValue = _CARD_6_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_7_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_7_NAME;
		cardLongNameSpanishSingular	= _CARD_7_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_7_LONG_NAME_ESP_PLURAL;
		//
		cardValue 					= _CARD_7_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_8_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_8_NAME;
		cardLongNameSpanishSingular	= _CARD_8_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_8_LONG_NAME_ESP_PLURAL;
		//
		cardValue 					= _CARD_8_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_9_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_9_NAME;
		cardLongNameSpanishSingular	= _CARD_9_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_9_LONG_NAME_ESP_PLURAL;
		//
		cardValue 					= _CARD_9_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_10_T_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_10_T_NAME;
		cardLongNameSpanishSingular	= _CARD_10_T_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_10_T_LONG_NAME_ESP_PLURAL;
		//
		cardValue 					= _CARD_10_T_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_J_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_J_NAME;
		cardLongNameSpanishSingular	= _CARD_J_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_J_LONG_NAME_ESP_PLURAL;
		//
		cardValue 					= _CARD_J_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_Q_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_Q_NAME;
		cardLongNameSpanishSingular	= _CARD_Q_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_Q_LONG_NAME_ESP_PLURAL;
		//
		cardValue 					= _CARD_Q_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_K_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_K_NAME;
		cardLongNameSpanishSingular	= _CARD_K_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_K_LONG_NAME_ESP_PLURAL;
		//
		cardValue 					= _CARD_K_VALUE;

    }//End if
    else if ( cardIndex == (_CARD_A_VALUE - _CARD_2_INDEX_TO_ARRAY_CONVERTER) )
    {

		// Values, attributes:
		//
		cardShortName 				= _CARD_A_NAME;
		cardLongNameSpanishSingular	= _CARD_A_LONG_NAME_ESP_SING;
		cardLongNameSpanishPlural	= _CARD_A_LONG_NAME_ESP_PLURAL;
		//
		cardValue 					= _CARD_A_VALUE;

    }//End if
    else    // Exception, That is not a Card!
    {

		// Type of Card
		//
		myCardType = nullptr;	  //	NULL;
		//
		// Values, attributes:
		//
		cardShortName 				= "";
		cardLongNameSpanishSingular	= "";
		cardLongNameSpanishPlural	= "";
		//
		cardValue = 0;


      // Write the Exception:
      //
      std::cout << "\n\nException, [ cardIndex = " << cardIndex << " ] is not Valid 'Value' or 'Number' for a Card!" << std::endl;

    }//End if
    /////////////////////

    // IN THE END: WE ASSIGN the value:
    //
    //CardManager::_myCardList[ cardIndex ] = new myCard( i, name, value, myCardType, nullptr);
    //
    Card  myCard( i, cardShortName, cardLongNameSpanishSingular, cardLongNameSpanishPlural, cardValue, myCardType );

    //Card(const int &id, const string &shortName, const string &longNameSpanishSingular, const string &longNameSpanishPlural, const int &value, CardType* myCardType)
    //
    CardManager::_myCardList[ i ] = myCard;

  }//End for

  return;

}//End Method



/**
 * Initializes Players' HANDS.
 * It uses a String Character Line, as INPUT.
 *
 * 1-	It Tokenizes (i.e.: splits...) the INPUT variable 'myGameLineString',
 * ...into: two arrays of strings: myGameP1 && myGameP2.
 *
 * 2-	It calls to the necessary Methods for each Player (P1 and P2): To Construct the HAND (of P1 and P2).
 */
void CardManager::ConstructPlayersHandsToPlayLater(Player &myPlayerOne, Player &myPlayerTwo, const string &myGameLineString )
{

	// 1-	It Tokenizes (i.e.: splits...) the INPUT variable 'myGameLineString'
	//
    // Build CARDS' HAND, beginning from: STRING LINE INPUT.
    //
    /// myGameLineString ===//// Example: const string str = "1S 2S 3S 4S 5S 6S 7S 8S 9S TS";

	// Delimiter for the String Line:
	//
    const char delimiter = ' ';
    //
    // Array Size: 10... because it will have ALL the CARDS.
    //
    /////const size_t _TOTAL_CARDS_READ_FROM_INPUT = _TOTAL_CARDS_READ_FROM_INPUT_LINE;
    //
    string myArrayOfStringCardsInThisGame [ _TOTAL_CARDS_READ_FROM_INPUT_LINE ];
    //
    // Tokenize and get an array of ALL CARDS:
    //
	UtilFunctions::TokenizeStringSplitIntoCArray( myGameLineString, delimiter, myArrayOfStringCardsInThisGame );


//    /////////////////debug///////////
//    //
//    std::cout << endl;
//    //
//    for (int i = 0; i < 10; i++)
//    {
//
//    	std::cout << "------->myArrayOfStringCardsInThisGame[ " << i << " ]  = " << myArrayOfStringCardsInThisGame[ i ] << endl;
//
//    }//End for
//    //end///////////////debug///////////


    // Split further, to get two (2) arrays: myGameP1 && myGameP2.
    //
    string myGameP1[ _MAX_CARDS_PER_HAND ];
    string myGameP2[ _MAX_CARDS_PER_HAND ];
    //
    // Split into 2 ARRAYS:
    //
	UtilFunctions::SplitBigArrayIntoTwoArrays( myArrayOfStringCardsInThisGame, myGameP1, myGameP2 );


    // 2-	It calls to the necessary Methods for each Player (P1 and P2):
    //...To Construct the HAND (of P1 and P2).
    //
    // P1
    //
    CardManager::ConstructPlayerHand( myPlayerOne, myGameP1 );
    //
    // P2
    //
    CardManager::ConstructPlayerHand( myPlayerTwo, myGameP2 );

}//End Method


/**
 * Initializes Players' HANDS.
 * It uses a String CHaracter Line, as INPUT. It is already Tokenized, in the form:
 *   [CARD NAME] [CARD TYPE]
 *
 *   Example: { 6D  7S  TH  7C  AH }	=	{ 6 of HEART | 7 of SPADE | 10 of HEART | ACE of HEART }
*/
void CardManager::ConstructPlayerHand(Player &myPlayer, const string (&myArrayOfStringsCards)[ _MAX_CARD_PER_HAND_COUNT ] )
{

  // Construct every Card Object in the List (Pointers):
  //
  for (int i = 0; i < _MAX_CARD_PER_HAND_COUNT; i++)
  {

	  // Construct A Pointer To Card & Card Type:
	  //
	  CardManager::ConstructPlayerCardCardType( myPlayer, i, myArrayOfStringsCards[i].substr(0, 1) /* CARD SHORT NAME */, myArrayOfStringsCards[i].substr(1, 1) /* TYPE OF CARD*/ );

  }//End for

}//End Method


/**
 * Initializes Players' HANDS.
 * It uses a String CHaracter Line, as INPUT. It is already Tokenized, in the form:
 *   [CARD NAME] [CARD TYPE]
 *
 *   Example: { 6D  7S  TH  7C  AH }	=	{ 6 of HEART | 7 of SPADE | 10 of HEART | ACE of HEART }
*/
void CardManager::ConstructPlayerCardCardType(Player &myPlayer, const int &cardIndexInPlayerHand, const string &cardName, const string &cardTypeShortName )
{

	// Construct Pointers to:
	//
	// Player's HAND:
	//
	Hand*	myPtrHand = myPlayer.GetMyHand();
	//
	// 1-	 Player's CARD:
	//
	Card* (* myPtrArrayOfCards)[ _MAX_CARD_PER_HAND_COUNT ] = myPtrHand->GetArrayOfCardsFromMyHand();
	//
	// 1-	Set the Card's VALUE, the CARD ITSELF:
	//
	(* myPtrArrayOfCards)[cardIndexInPlayerHand] = CardManager::GetCard( cardName, cardTypeShortName );

	// NOTE:
	// 2- CARD TYPE (that is in Player's HAND): it is ALREADY SETTED, because is comes from a Pointer
	//...to the STATIC (and GLOBAL) VARIABLE:
	//......CardManager::GetCardType( cardTypeShortName );			linked to:
	//......CardManager::GetCard( cardName, cardTypeShortName );
	//
	///// Do not uncomment, it is just a reference: CardType*  myPtrCardType = CardManager::GetCardType( cardTypeShortName );

}//End Method



/******************PLAY THE GAME!********************/


/**
 * Plays the Game, in Console version.
 *
 * It is Test Version, with just
 *
 * 	1-	INPUT: 	some HARDCODED Values.
 *
 * 	2-	OUTPUT:	print out to Console.
 */
void CardManager::PlayTheGameConsoleVersion
(	const std::string inputLinesArraySize[],
	const int arraySize,
	Player &myPlayerP1, Player &myPlayerP2
)
{

    /**
     * Prints out the end game output. Just the HEADER:
     *
     * It has two independent modes:
     *  1-  Print to Console
     *  2-  Print to a Variable, and THEN to a Text File (Input Text File)
     */
	CardManager::PrintAllOutputGameOverJustHeader ( _OUTPUT_MAX_STRING_OR_ARRAY_SIZE,

		_OUTPUT_FIRST_SHORT_TOTAL_CHAR_SECTION /*const int &firstShortTotalCharactersSection*/		/* 8 */,
		_OUTPUT_SECOND_AND_THIRD_TOTAL_CHAR_SECTION /*const int &secondAndThirdTotalCharactersSection*/		/* 55 */,
		_OUTPUT_FOURTH_FINAL_TOTAL_CHAR_SECTION /*const int &fourthFinalShortTotalCharactersSection*/	/* 9 */,

			true /*const bool &printOutToConsole*/, true /*const bool &printOutToTextFile*/

		/**Input ostream Text File**/
	);
	//
//	// Print a Blank Line:
//	//
//	std::cout << std::endl;

	// Number of Victories
	//
	int p1WinsCount = 0;
	int p2WinsCount = 0;


	// Loop through each Line, to PLAY A GAME WITH THOSE CARDS specified in EVERY LINE (string):
	//
	for (int i = 0; i < arraySize; i++)
	{

		// Construct the Player's Hand of Cards with the INPUT LINE of String:
		//....because EACH LINE is a different GAME:
		//
		const string myGameStringLine1 = inputLinesArraySize[ i ];
		//
		//
		// Construct P1 and P2 HANDS,
		//   Note: Only: This HAND Attributte will be filled: Card (* _myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ];
		//
		//...but not 'HAND TYPE' (that will be Setted in the Next Step:
		//...discoverying the TYPE OF HAND of EACH Player: Playing the Game):
		//
		CardManager::ConstructPlayersHandsToPlayLater(myPlayerP1, myPlayerP2, myGameStringLine1);


		std::cout << std::flush;

		// Print Players' Cards Data (Card to Play the Game, not the Hand OR HAND TYPE attributes.
		//
		//   AT THIS POINT OF THE GAME:
		//
		//...IT DOESN'T EVEN KNOW THE NAME OF THE HAND YET:
		//... => It has to DISCOVER IT by PLAYING THE GAME)
		//
	//	PrintPlayerCardsDetails( myPlayerP1 );
	//	PrintPlayerCardsDetails( myPlayerP2 );


		/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n"<< std::flush;


		/**
		 * If the Player has been Initialized (and His HAND -> CARDS: are already BUILT),
		 * ...but Its Cards had not been read (i.e.: He has not stated to Play the Game):
		 *
		 * ...1- This Method Gets (discovers...) the Type of HAND...
		 *
		 * DISCARD THIS: <<  ...IN OTHER Method: This will be done: >>
		 *
		 *	THIS WILL BE DONE inside this Method:
		 *
		 * --------------------------------------
		 *
		 * ...2- Hierarchy Value (among other Attributes, such as NAME), of the Object:
		 *
		 * 			Player->_myHand->_myHandType ... ->_hierarchyValue;
		 */
		CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );
		//
		/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP2 );\n"<< std::flush;
		//
		CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP2 );


		/////& std::cout << "\n*************************END OF:*********\n -> ENDED:  CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n"<< std::flush;

		std::cout << std::flush;



//		/**
//		 * [ Call this Method to see The HAND of the FULLY CONSTRUCTED Player, BEFORE TRYING TO Finally Play ]
//		 * Prints data about CARDS in a PLAYERs HAND.
//		 */
//		PrintPlayerHandAndHandTypeCardsDetails( myPlayerP1 );
//		/**
//		 * [ Call this Method to see The HAND of the FULLY CONSTRUCTED Player, BEFORE TRYING TO Finally Play ]
//		 * Prints data about CARDS in a PLAYERs HAND.
//		 */
//		PrintPlayerHandAndHandTypeCardsDetails( myPlayerP2 );


		/******************PLAY THE GAME!*********(JUST ONE LINE OF CARDS-DATA...)***********/

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
		bool easyOrHardVictory = true;
		//
		Player* myPtrToWinnerPlayer = /* WINNER Player */  CardManager::PlayTheGameTexasPoker( myPlayerP1, myPlayerP2, easyOrHardVictory, false /*printDebugPreliminarOutputDetailsOrNot */ );
		//
		// Declare variable to state who the winer is, in clearer terms:
		//
		const bool p1Wins = ( (myPtrToWinnerPlayer) ?
				( ( (*myPtrToWinnerPlayer).GetId() == myPlayerP1.GetId() ) /* P1 won?? */
						? true /* P1 won */ : false /* P1 DIDN'T win */ )
				: false /* Ptr is NULL => P1 did not win, Nor P2 did */);
		//
		const bool p2Wins = ( (myPtrToWinnerPlayer) ?
				( ( (*myPtrToWinnerPlayer).GetId() == myPlayerP2.GetId() ) /* P2 won?? */
						? true /* P2 won */ : false /* P2 DIDN'T win */ )
				: false /* Ptr is NULL => P2 did not win, Nor P1 did */);
		//
		// Wins count:
		//
		p1WinsCount += ( (p1Wins) ? 1 : 0 );
		p2WinsCount += ( (p2Wins) ? 1 : 0 );
		//
		// (Old - Debug Mode) Print to Console Routine:
		//
//		if ( myPtrToWinnerPlayer )	 // Not nullptr
//		{
//
//			// Print out who the Winner is:
//			//
//			if ( (*myPtrToWinnerPlayer).GetId() == myPlayerP1.GetId() )
//			{
//				// P1 WON
//				//
//				std::cout << "\n**(From main() Method:)*******P1 WINS!!!!********\n\n";
//				std::cout << ( myPlayerP1.GetMyHand() )->GetOutputMyGameLine1() << "\n";
//				std::cout << ( myPlayerP1.GetMyHand() )->GetOutputMyGameLine2() << "\n";
//				std::cout << "\n*********P1 WINS!!!!********\n\n";
//
//			}//End if ( (*myPtrToWinnerPlayer).GetId() == myPlayerP1.GetId() )
//			else
//			{
//
//				// P2 WON
//				//
//				std::cout << "\n**(From main() Method:)*******P2 WINS!!!!********\n\n";
//				std::cout << ( myPlayerP2.GetMyHand() )->GetOutputMyGameLine1() << "\n";
//				std::cout << ( myPlayerP2.GetMyHand() )->GetOutputMyGameLine2() << "\n";
//				std::cout << "\n*********P2 WINS!!!!********\n\n";
//
//			}//End else of if ( (*myPtrToWinnerPlayer).GetId() == myPlayerP1.GetId() )
//
//		}//End if Validation
//	//	else
//	//	{
//	//		// It is a Draw, it is already thought of, in: ''  there is a Print out for thah,
//	//		//....copy that inside a Method and USE IT!
//	//	}//End else del if
		//
		// Get myGameStringLine1 for P1, and for P2:
		//
	    const std::string myGameStringLineForP1 = myGameStringLine1.substr( 0, ( myGameStringLine1.size() / 2 ) );
	    const std::string myGameStringLineForP2 = myGameStringLine1.substr( ( myGameStringLine1.size() / 2 ) + 1 ,  ( myGameStringLine1.size() - 1 ) );
		//
		// Print the results in a Professional manner:
		//
	    /**
	     * Prints out the end game output.
	     *
	     * It has tow independent modes:
	     *  1-  Print to Console
	     *  2-  Print to a Variable, and THEN to a Text File (Input Text File)
	     */
		CardManager::PrintAllOutputGameOver ( myPlayerP1, myPlayerP2, p1Wins, p2Wins, _OUTPUT_MAX_STRING_OR_ARRAY_SIZE, (i + 1) /*const int &lineNumber*/,
				myGameStringLineForP1 /*const std::string &myGameLineP1*/,
				myGameStringLineForP2 /*const std::string &myGameLineP2*/,

				(! easyOrHardVictory) /*const bool &printSecondLineItWasAlmostATie*/,

				_OUTPUT_FIRST_SHORT_TOTAL_CHAR_SECTION /*const int &firstShortTotalCharactersSection*/		/* 8 */,
				_OUTPUT_SECOND_AND_THIRD_TOTAL_CHAR_SECTION /*const int &secondAndThirdTotalCharactersSection*/		/* 55 */,
				_OUTPUT_FOURTH_FINAL_TOTAL_CHAR_SECTION /*const int &fourthFinalShortTotalCharactersSection*/	/* 9 */,

				true /*const bool &printOutToConsole*/, true /*const bool &printOutToTextFile*/

			/**Input ostream Text File**/
		);

	}//End for

	// Print TOTALS:
	//
	  /**
	   * Prints out HOW MANY VICTORIES there are: for P1 and P2.
	   *
	   * It has two independent modes:
	   * 	1-	Print to Console
	   * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
	   */
	  CardManager::PrintTotalsVictoriesOutputGameOver
	  (
		_OUTPUT_LINE_TOTALES_2_SEPARATOR,
		p1WinsCount, p2WinsCount,

		_OUTPUT_MAX_STRING_OR_ARRAY_SIZE,

		_OUTPUT_FIRST_SHORT_TOTAL_CHAR_SECTION /*const int &firstShortTotalCharactersSection*/		/* 8 */,
		_OUTPUT_SECOND_AND_THIRD_TOTAL_CHAR_SECTION /*const int &secondAndThirdTotalCharactersSection*/		/* 55 */,
		_OUTPUT_FOURTH_FINAL_TOTAL_CHAR_SECTION /*const int &fourthFinalShortTotalCharactersSection*/	/* 9 */,

		true /*const bool &printOutToConsole*/, true /*const bool &printOutToTextFile*/,
		true /*const bool &printNewLineAtTheBeginning*/, true /*const bool &printNewLineAtTheEnd*/

		/**Input ostream Text File**/
	  );

}//End Method



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
Player* /* WINNER Player */  CardManager::PlayTheGameTexasPoker( Player &myP1, Player &myP2, bool &easyOrHardVictory, const bool &printDebugPreliminarOutputDetailsOrNot )
{

	// 0- Values to help to return:
	//
	bool p1Wins = false, p2Wins = false;
	//
	// Also return: If they had the same type of Hand (i.e.: EASY VICTORY), or Different (I.E.: HARD VICTORY)
	//
	easyOrHardVictory = true;
	//
	// WINNER Player:
	//
	Player* myPtrToWinnerPlayer = nullptr;


	//	1-	Get HANDS VALUE:
	//	(NOTE: It was already Setted in Method: 'CalculateAndDiscoverAndSetHandTypeFromPlayerCards(...)')
	//
	const int myP1HandValue = ((myP1.GetMyHand())->GetMyHandType())->GetHierarchyValue();
	const int myP2HandValue = ((myP2.GetMyHand())->GetMyHandType())->GetHierarchyValue();


	// Who wins?
	//	2-	Compare <<a grosso modo>> the VALUES of each Player Hand:
	//
	if ( myP1HandValue > myP2HandValue)
	{

		// P1 WINS!
		//
		p1Wins = true;
		//
		//p2Wins = false;
		//
		if ( printDebugPreliminarOutputDetailsOrNot )
		{

			// Print to File or CONSOLE A LINE: Stating the details of the "EASY" Victory:
			//
			CardManager::DeclareEasyVictory( myP1, myP2, p1Wins, p2Wins );

		}//End if ( printDebugPreliminarOutputDetailsOrNot )


		// Return WINNER: P1
		//
		myPtrToWinnerPlayer = &myP1;

	}//End if ( myP1HandValue > myP2HandValue)
	else if ( myP1HandValue < myP2HandValue)
	{

		// P2 WINS!
		//
		p2Wins = true;
		//
		//p1Wins = false;
		//
		//
		if ( printDebugPreliminarOutputDetailsOrNot )
		{

			// Print to File or CONSOLE A LINE: Stating the details of the "EASY" Victory:
			//
			CardManager::DeclareEasyVictory( myP1, myP2, p1Wins, p2Wins );

		}//End if ( printDebugPreliminarOutputDetailsOrNot )


		// Return WINNER: P2
		//
		myPtrToWinnerPlayer = &myP2;

	}//End if ( myP1HandValue > myP2HandValue)
	else
	{
		// myP1 == myP2		=>	TIE / DRAW:
		//
		// State that it was NOT EASY:
		//
		easyOrHardVictory = false;

		// REASON:	Same TYPE OF HAND:  (i.e.: TWO PAIRS vs TWO PAIRS, etc...)
		//
		// We have to UN-TIE this:
		// NOTE: FULL HOUSE Type of Hand: needs a different SORTING METHOD, (FOR 'Hand Definitory Cards'),
		// ...So we need to sear for the 'NAME OF HAND' or the value, to make a distinction:
		//
		// largest = ((a > b) ? a : b);
		//
		const int p1SortOrderNumber = ( ( myP1HandValue == _FULL_HOUSE_VALUE ) ?  0 /* No Sorting */ : -1 /* Sort Desc */ );
		const int p2SortOrderNumber = ( ( myP2HandValue == _FULL_HOUSE_VALUE ) ?  0 /* No Sorting */ : -1 /* Sort Desc */ );
		//
		// Call the COMPARE CARDS + SORT: Method:
		//
		myPtrToWinnerPlayer = CardManager::CompareHandDefinitionCards( myP1, myP2, p1SortOrderNumber, p2SortOrderNumber );

		// If this is NULL / nullptr, there is no Winner <= because it IS A TIE-DRAW.
		//...(this would mean: Both of them have the same HAND... (which was already TRUE by entering
		//
		//....this BLOCK, BUT    ALSO:
		//
		//...=>>>>>> with the same VALUES in their CARDS  -  HAND DEFINITION Cards ).
		//
		if (! myPtrToWinnerPlayer)	 //	== NULL / nullptr
		{
			// DRAW: Let's compare the rest of the CARDS in the HAND
			//...(i.e.: called the 'not-definition Cards')
			//
			myPtrToWinnerPlayer = CardManager::CompareHandNotDefinitionCards( myP1, myP2 );

			// NOTE: In this case, the DETAILS to be Printed out are a PARAGRAPH
			//...with 2 Lines, in size.

		}//End if (! myPtrToWinnerPlayer)	 //	== NULL / nullptr
		// else {} 	// Not necessary


		// Check for the Winner in the end
		//
		if ( myPtrToWinnerPlayer )
		{

			// There is a WINNER:
			//
			p1Wins = ( myPtrToWinnerPlayer->GetId() == 1 );
			p2Wins = ( myPtrToWinnerPlayer->GetId() == 2 );


			// Return WINNER: myPtrToWinnerPlayer  (See at the bottom...)


		}//End if ( myPtrToWinnerPlayer )
		else
		{
			// Declare a DRAW!
			//
			p1Wins = false;
			p2Wins = false;


			// Return no-WINNER: myPtrToWinnerPlayer == NULL  (See at the bottom...)


		}//End else of if ( myPtrToWinnerPlayer )


		// Debug Output:
		//
		if ( printDebugPreliminarOutputDetailsOrNot )
		{

			// Print to File or CONSOLE TWO (2) LINEs: Stating the details of the "DIFFICULT" Victory:
			//
			CardManager::DeclareHardVictory( myP1, myP2, p1Wins, p2Wins );

		}//End if ( printDebugPreliminarOutputDetailsOrNot )


	}//End else of if ( myP1HandValue > myP2HandValue)


	// Return the WINNER, or nullptr if there is not one:
	//
	return myPtrToWinnerPlayer;

}//End Method



/**
 * Prints out the end game output.
 *
 * It has two independent modes:
 * 	1-	Print to Console
 * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
 */
void CardManager::PrintAllOutputGameOver
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
)
{

    std::cout << flush;

    // Preparation: Variables:
    //
    //  0.1-  Create the Output Char * (or char []): copy the string in there:
    //
	std::string myOutputString = "";
    //
    // 0.2-     winnerPlayerNumber, Number of player who won:
    //
    const int winnerPlayerNumberLocal = ( (p1Wins) ? 1 /* P1 won */ : ( (p2Wins) ? 2  /* P2 won */ : ( 0  /* No one won: DRAW */ ) ) );
    const std::string winnerPlayerNumberAsString = UtilFunctions::NumberToString ( winnerPlayerNumberLocal );


	//	1-	Line 0
	//		.1-	Prints Game Number #.  Section Space = 8 Chars (Total).
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myOutputString,
			lineNumber, firstShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            true /* new line at the beginning */, false /* new line at the end */ );

	//		.2-	Prints P1's Cards initial 'INPUT STRING' (e.g.: "AD 3H 5S 9C JD" ) + Spaces
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myOutputString,
			myGameLineP1, secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );

	//		.3-	Prints P2's Cards initial 'INPUT STRING' (e.g.: "AD 3H 5S 9C JD" ) + Spaces
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myOutputString,
			myGameLineP2, secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );


	//		.4-	Prints out: Who the WINNER IS. (e.g.: "Jugador 1"  OR  "Jugador 2") + Nothing else, endline.
	//		Section Total Chards = 9
	//_OUTPUT_LINE_0_WINNER_ESP
	//
	std::string myWinnerLine0NumberOutput = "";
	//
	// Consider DRAW-cases, too:
	//
	if ( winnerPlayerNumberLocal > 0 )
	{
		// Someone WON!
		//
		myWinnerLine0NumberOutput +=_OUTPUT_LINE_0_WINNER_ESP;
		myWinnerLine0NumberOutput += " ";
		myWinnerLine0NumberOutput += winnerPlayerNumberAsString;

	}
	else
	{
		// No one won.. it is a DRAW!
		//
		myWinnerLine0NumberOutput += _OUTPUT_LINE_2_ENDING_TIE;

	}//End else of
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myOutputString,
			myWinnerLine0NumberOutput, fourthFinalShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, true /* new line at the end */ );


	///////////////////////////////////
	//
	//	1-	Line 1
	//		.1-	A Section of ONLYSPACES, to serve as a TABBED space.
	//		Section Space = 8 Chars (Total).
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myOutputString,
			"", firstShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );

	//		.2-	[ "P1_OUTPUT_LINE_1" ] Prints P1's "NAME OF HAND", i.e.: "GAME OUTPUT_LINE_1" (e.g.: "Par de Q" )
	//			+ Spaces   (to fill the space).
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces (myOutputString,
			(*( myP1.GetMyHand() )).GetOutputMyGameLine1(), secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );

	//		.3-	[ "P2_OUTPUT_LINE_1" ] Prints P2's "NAME OF HAND", i.e.: "GAME OUTPUT_LINE_2" (e.g.: "Par de Q" )
	//			+ Spaces   (to fill the space).
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces (myOutputString,
			(*( myP2.GetMyHand() )).GetOutputMyGameLine1(), secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, true /* new line at the end */ );


	///////////////////////////////////
	//
	//	2-	Line 2	:	Note: 	It does not have to be PRINTED ALLWAYS...
	//					...		Condition:	Just Print it when you have a TIE..: "in a Hard Virtory".
	//					...		I mean: When P1 and P2 have the same "TYPE OF HAND".
	//
	if ( printSecondLineItWasAlmostATie )
	{

		//		.1-	A Section of ONLYSPACES, to serve as a TABBED space.
		//		Section Space = 8 Chars (Total).
		//
		UtilFunctions::PrintVariableAndThenFillWithSpaces (myOutputString,
				"", firstShortTotalCharactersSection,
				printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
	            false /* new line at the beginning */, false /* new line at the end */ );


		//		.2-	[ "P1_OUTPUT_2_LINE_2" ] Prints P1's "Máxima Carta:...", i.e.: "GAME OUTPUT_2_LINE_2"
		//			(e.g.: "Máxima Carta: 7" )
		//			+ Spaces   (to fill the space).
		//		Section Total Chards = 55
		//
		UtilFunctions::PrintVariableAndThenFillWithSpaces (myOutputString,
				(*( myP1.GetMyHand() )).GetOutputMyGameLine2(), secondAndThirdTotalCharactersSection + 1,
				printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
	            false /* new line at the beginning */, false /* new line at the end */ );


		//		.3-	[ "P2_OUTPUT_2_LINE_2" ] Prints P2's "Máxima Carta:...", i.e.: "GAME OUTPUT_2_LINE_2"
		//			(e.g.: "Máxima Carta: 7" )
		//			+ Spaces   (to fill the space).
		//		Section Total Chards = 55
		//
		UtilFunctions::PrintVariableAndThenFillWithSpaces (myOutputString,
				(*( myP2.GetMyHand() )).GetOutputMyGameLine2(), secondAndThirdTotalCharactersSection,
				printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
	            false /* new line at the beginning */, true /* new line at the end */ );

	}//End if ( printSecondLineItWasAlmostATie )

}//End Method



/**
 * Prints out HOW MANY VICTORIES there are: for P1 and P2.
 *
 * It has two independent modes:
 * 	1-	Print to Console
 * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
 */
void CardManager::PrintTotalsVictoriesOutputGameOver
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
)
{

    std::cout << flush;

    // Preparation: Variables:
    //
    //  0.1-  Create the Output Char * (or char []): copy the string in there:
    //
	std::string myStringStoreTheOutputLineSectionsHereFinal = "";


    //	-1	Line -1: Separator Line: "*************************************"
    //
    PrintASeparatorLine ( mySeparator,
    		arraySize,
    		firstShortTotalCharactersSection 		/* 8 */,
    		secondAndThirdTotalCharactersSection		/* 55 */,
    		fourthFinalShortTotalCharactersSection	/* 9 */,

    		true /*printOutToConsole*/, true /*printOutToTextFile*/,
    		printNewLineAtTheBeginning /*printNewLineAtTheBeginning*/, false /*printNewLineAtTheEnd*/

    	/**Input ostream Text File**/
    );


	//	0-	Line 0:	HEADER
	//		.1-	Prints MANO  (Hand) Title.	Section Space = 8 Chars (Total).
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			_OUTPUT_LINE_TOTALES_1, firstShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            true /* new line at the beginning */, false /* new line at the end */ );

	//		.2-	Prints P1's Won GAMES (TOTAL) + Spaces
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			p1Victories, secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );

	//		.3-	Prints P2's Won GAMES (TOTAL) + Spaces
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			p2Victories, secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );


	//		.4-	Prints out: Who the WINNER IS. (e.g.: "Jugador 1"  OR  "Jugador 2") + Nothing else, endline.
	//		Section Total Chards = 9
	//
	// Calculate the FINAL WINNER
	//
	std::string winnerPlayerNumberLocal = ( (p1Victories > p2Victories) ? "1" /* P1 won */ : ( (p1Victories < p2Victories) ? "2"  /* P2 won */ : ( ""  /* No one won: DRAW */ ) ) );
	//
	std::string myWinnerLine0NumberOutput = "";
	//
	// Consider DRAW-cases, too:
	//
	if ( winnerPlayerNumberLocal != "" )
	{
		// Someone WON!
		//
		myWinnerLine0NumberOutput =_OUTPUT_LINE_0_WINNER_ESP;
		myWinnerLine0NumberOutput += " ";
		myWinnerLine0NumberOutput += winnerPlayerNumberLocal;

	}
	else
	{
		// No one won.. it is a DRAW!
		//
		myWinnerLine0NumberOutput += _OUTPUT_LINE_2_ENDING_TIE;

	}//End else of
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			myWinnerLine0NumberOutput, fourthFinalShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, true /* new line at the end */ );


    //	ZZ-	Line : Last: Separator Line: "*************************************"
    //
    PrintASeparatorLine ( mySeparator,
    		arraySize,
    		firstShortTotalCharactersSection 		/* 8 */,
    		secondAndThirdTotalCharactersSection		/* 55 */,
    		fourthFinalShortTotalCharactersSection	/* 9 */,

    		true /*printOutToConsole*/, true /*printOutToTextFile*/,
    		false /*printNewLineAtTheBeginning*/, printNewLineAtTheEnd /*printNewLineAtTheEnd*/

    	/**Input ostream Text File**/
    );

}//End Method



/**
 * Prints out a SEPARATOR Line.
 *
 * It has two independent modes:
 * 	1-	Print to Console
 * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
 */
void CardManager::PrintASeparatorLine
(
	const std::string &charSeparator,
	const int &arraySize,

	const int &firstShortTotalCharactersSection 		/* 8 */,
	const int &secondAndThirdTotalCharactersSection		/* 55 */,
	const int &fourthFinalShortTotalCharactersSection	/* 9 */,

	const bool &printOutToConsole,  const bool &printOutToTextFile,
	const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd

	/**Input ostream Text File**/
)
{

    std::cout << flush;

    // Preparation: Variables:
    //
    //  0.1-  Create the Output Char * (or char []): copy the string in there:
    //
	std::string myStringStoreTheOutputLineSectionsHereFinal = "";
    //
	//	0-	Line 0:	HEADER
	//		.1-	Prints MANO  (Hand) Title.	Section Space = 8 Chars (Total).
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			charSeparator, firstShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
			printNewLineAtTheBeginning /* new line at the beginning */, false /* new line at the end */ );

	//		.2-	Prints P1's Won GAMES (TOTAL) + Spaces
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			charSeparator, secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );

	//		.3-	Prints P2's Won GAMES (TOTAL) + Spaces
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			charSeparator, secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );


	//		.4-	Prints out: Who the WINNER IS. (e.g.: "Jugador 1"  OR  "Jugador 2") + Nothing else, endline.
	//		Section Total Chards = 9
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			charSeparator, fourthFinalShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, printNewLineAtTheEnd /* new line at the end */ );

}//End Method



/**
 * Prints out HEADER of the TABLE of the end game output.
 *
 * It has two independent modes:
 * 	1-	Print to Console
 * 	2-	Print to a Variable, and THEN to a Text File (Input Text File)
 */
void CardManager::PrintAllOutputGameOverJustHeader
(
	const int &arraySize,

	const int &firstShortTotalCharactersSection 		/* 8 */,
	const int &secondAndThirdTotalCharactersSection		/* 55 */,
	const int &fourthFinalShortTotalCharactersSection	/* 9 */,

	const bool &printOutToConsole,  const bool &printOutToTextFile
	/*const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd*/

	/**Input ostream Text File**/
)
{

    std::cout << flush;

    // Preparation: Variables:
    //
    //  0.1-  Create the Output Char * (or char []): copy the string in there:
    //
	std::string myStringStoreTheOutputLineSectionsHereFinal = "";
    //
	//	0-	Line -1:	HEADER
	//		.1-	Prints MANO  (Hand) Title.	Section Space = 8 Chars (Total).
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			_OUTPUT_LINE__1_SECTION_1_MANO, firstShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );

	//		.2-	Prints P1's Name (e.g.: "Jugador 1" ) + Spaces
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			_OUTPUT_LINE__1_SECTION_2_JUGADOR_1, secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );

	//		.3-	Prints P2's Name (e.g.: "Jugador 2" ) + Spaces
	//		Section Total Chards = 55
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			_OUTPUT_LINE__1_SECTION_3_JUGADOR_2, secondAndThirdTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, false /* new line at the end */ );


	//		.4-	Prints out: The TITLE of Who the WINNER IS. (e.g.:	"Ganador") + Nothing else, endline.
	//		Section Total Chards = 9
	//
	UtilFunctions::PrintVariableAndThenFillWithSpaces ( myStringStoreTheOutputLineSectionsHereFinal,
			_OUTPUT_LINE__1_SECTION_4_GANADOR, fourthFinalShortTotalCharactersSection,
			printOutToConsole /* Print to console */, printOutToTextFile /* Print to Text File */,
            false /* new line at the beginning */, true /* new line at the end */ );

}//End Method



/**
 *	It prints out {TO CONSOLE} the DETAILS OF THE VICTORY: In ONE LINE (according to the CONVENTION	)
 *	(Once the game was Player, and there is a Winner).
 *
 *	const bool &p1Wins, const bool &p2Wins:
 *
 *	1-	If those are all: TRUE => THEN there is a TIE (DRAW).
 *
 *	2-	If those are DIFFERENT (true, false... or: false, true): THEN there is a WINNER and a LOSER.
 */
void CardManager::DeclareEasyVictory( Player &myP1, Player &myP2, const bool &p1Wins, const bool &p2Wins )
{
	std::cout << flush;

	int winnerPlayerNumber = 0;

	if (p1Wins != p2Wins)
	{

		// Declare EASY VICTORY
		//
		std::cout << "\nEASY VICTORY:\nGanador:\n->\nJUGADOR << P";


		if ( p1Wins )
		{
			// p1Wins
			//
			winnerPlayerNumber = 1;

			std::cout << winnerPlayerNumber <<" >>\n -> \n";

			// Print OUTPUT LINE 1:
			//
			std::cout << myP1.GetMyHand()->GetOutputMyGameLine1() <<"\n";
			//
			// Loser data:	P2
			//
			std::cout << "\n Loser data: << P2 >>\n ->\n";
			std::cout << myP2.GetMyHand()->GetOutputMyGameLine1() <<"\n";

		}
		else
		{
			// p2Wins
			//
			winnerPlayerNumber = 2;

			std::cout << winnerPlayerNumber <<" >>\n -> \n";

			// Print OUTPUT LINE 1:
			//
			std::cout << myP2.GetMyHand()->GetOutputMyGameLine1() <<"\n";
			//
			// Loser data:	P1
			//
			std::cout << "\n Loser data: << P1 >>\n ->\n";
			std::cout << myP1.GetMyHand()->GetOutputMyGameLine1() <<"\n";

		}//End else

//		// Declare EASY VICTORY
//		//
//		std::cout << "\nEASY VICTORY:\nGanador:\n->\nJUGADOR << P" << winnerPlayerNumber <<" >>\n";

	}
//	else
//	{
//		// DRAW:
//		// We just have to keep comparing the NOT-DEFINITION CARDS...
//
//	}//End else

}//End Method


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
void CardManager::DeclareHardVictory( Player &myP1, Player &myP2, const bool &p1Wins, const bool &p2Wins )
{
	std::cout << flush;

	int winnerPlayerNumber = 0;

	if (p1Wins != p2Wins)
	{

		// Declare HARD VICTORY:
		//
		std::cout << "\nHARD VICTORY:\nGanador:\n->\nJUGADOR << P";


		if ( p1Wins )
		{
			// p1Wins
			//
			winnerPlayerNumber = 1;

			std::cout << winnerPlayerNumber <<" >>\n -> \n";

			// Print OUTPUT LINE 1 & 2:
			//
			std::cout << myP1.GetMyHand()->GetOutputMyGameLine1() <<"\n";
			std::cout << myP1.GetMyHand()->GetOutputMyGameLine2() <<"\n";
			//
			// P2:
			//
			std::cout << "\n Loser data: << P2 >>\n ->\n";
			//
			// Print OUTPUT LINE 1 & 2:
			//
			std::cout << myP2.GetMyHand()->GetOutputMyGameLine1() <<"\n";
			std::cout << myP2.GetMyHand()->GetOutputMyGameLine2() <<"\n";
		}
		else
		{
			// p2Wins
			//
			winnerPlayerNumber = 2;

			std::cout << winnerPlayerNumber <<" >>\n -> \n";

			// Print OUTPUT LINE 1 & 2:
			//
			std::cout << myP2.GetMyHand()->GetOutputMyGameLine1() <<"\n";
			std::cout << myP2.GetMyHand()->GetOutputMyGameLine2() <<"\n";
			//
			// P1:
			//
			std::cout << "\n Loser data: << P1 >>\n ->\n";
			std::cout << myP1.GetMyHand()->GetOutputMyGameLine1() <<"\n";
			std::cout << myP1.GetMyHand()->GetOutputMyGameLine2() <<"\n";

		}//End else

	}
	else
	{
		// DRAW:
		//
		std::cout << "\nHARD VICTORY:\nGanador:\n->\nJUGADOR << P Ninguno >>\n";
		std::cout << "\n->\nIt is a DRAW! ( Es un EMPATE! )\n";

	}//End else

	//
	//
	////std::cout << "\nOUTPUT\n";

}//End Method



/**
 *	It compares the CARDs. Steps:
 *
 *	1-	Sorts the ARRAYS out [ MANDATORY ], in an Descendent way (i.e.: From { BIGGER to...smaller }).
 *	2-	Compares the VALUES of each CARD (in the sorted Arrays, from [0].. to [n]): one by one.
 *	3-	The Player with an array with Bigger CARDS: Wins.
 *
 *	Return values:
 *	(a)
 *		1-	WINNER			[thus RETURNING a POINTER to the WINNER-PLAYER: {&myPx} ]
 *		2-	LOSER, 	or
 *		3-	A DRAW.			[thus RETURNING a [NULL / nullptr] POINTER]
 *
 *	(b)
 *		The Arrays already SORTED, Desc. { myP1PtrCards AND myP2PtrCards }
 *
 *	(c)
 *		The last INPUT is a POINTER to the HIGHEST CARD that MAKES THE DIFFERENCE between P1 and P2 's HANDs.
 *		(i.e.: The WINNER CARD).
 *		1-	For P1
 *		2-	For P2
 *		(one ot those tow: will be the WINNER, the other will be the LOSER.
 *		Check it with:  CARD->VALUE )
 *
 *	NOTE:
 *
 *	1-	The VECTORS MUST be the same .SIZE(), or it will throw an ERROR.
 *
 *
 *	Aditional Parameters:	P1 and P2 have:
 *
 *	@sortCardsOrder	->	0	:	False.	Not to SORT
 *					->	> 0 :	True.	SORT ASCENDING  [ 1, 2, 3... 100000 ]
 *					->	< 0 :	True.	SORT DESCENDING [ 100000000, 5, 1 ]
 */
Player* CardManager::CompareCards( Player &myP1, Player &myP2, std::vector < Card* > &myP1PtrCards, std::vector < Card* > &myP2PtrCards , const int &sortP1CardsOrder, const int &sortP2CardsOrder )
{

	// Return Pointer:
	//
	// 1-	WINNER Player:
	//
	Player* myPtrPlayerWinner 		= nullptr;

	// 2-	The last INPUT is a POINTER to the HIGHEST CARD that MAKES THE DIFFERENCE
	//		...between P1 and P2 's HANDs.
	//		(i.e.:
	//				1-	The WINNER CARD,
	//				2-	and the LOSER CARD).


	// 3-	Validation:	Size MUST be equal, for P1 and P2:
	//
	const int vectorP1Size = myP1PtrCards.size();
	const int vectorP2Size = myP2PtrCards.size();
	//
	if (! ( ( vectorP1Size > 0 ) && ( vectorP2Size > 0 ) && ( vectorP1Size == vectorP2Size ) ) )
	{

		// Not valid.
		//
		std::cout << "\n\n************ERROR**************\n->\n-> In:   Player* CardManager::CompareCards( Player &myP1, Player &myP2, std::vector < Card* > &myP1PtrCards, std::vector < Card* > &myP2PtrCards, Card* myPtrToHighDifferentCardP1, Card* myPtrToHighDifferentCardP2 ) \n-> It did not pass the VALIDATION:  Validation:	Size MUST be equal, for P1 and P2\n-> Returning: nullptr";


		// Return: that it failed:
		//
		return myPtrPlayerWinner;

	}//End if Validation


	//...1-	Sorts the ARRAYS out [ MANDATORY ], in an Descendent way.
	// ...ACCORDING TO THE input PARAMETERS:
	//	P1
	//
	if ( sortP1CardsOrder != 0 )	 // Yes, please, SORT
	{

		// ( sortP1CardsOrder > 0 ) : Means: 'Sort Asc'
		//
		UtilFunctions::SortVectorOfPointerToCards( myP1PtrCards, ( sortP1CardsOrder > 0 ) );

	}//End if
	//
	//	P2
	//
	if ( sortP2CardsOrder != 0 )	 // Yes, please, SORT
	{

		// ( sortP2CardsOrder > 0 ) : Means: 'Sort Asc'
		//
		UtilFunctions::SortVectorOfPointerToCards( myP2PtrCards, ( sortP2CardsOrder > 0 ) );

	}//End if


	// Compare CARDS:
	//
	for (int i = 0; i < vectorP1Size; i++)
	{

		// Auxiliar variable, with values:
		// POINTERS:
		//
//		myPtrToHighDifferentCardP1	= myP1PtrCards.at( i );
//		myPtrToHighDifferentCardP2	= myP2PtrCards.at( i );
		//
		// VALUES (of those CARDS Pointed to..):
		//
		const int myP1CardValue 	= (myP1PtrCards.at( i ))->GetValue(); 	// myPtrToHighDifferentCardP1->GetValue();	 // (myP1PtrCards[ i ])->GetValue();
		const int myP2CardValue 	= (myP2PtrCards.at( i ))->GetValue();		// (myP2PtrCards[ i ])->GetValue();

//		std::cout << "\nEjecutando:::::::::( DENTRO DE METODO: 'CardManager::CompareCards(...):::: CARTA::VALOR:::myPtrToHighDifferentCardP1->GetValue() = "<< myP1CardValue << "\nCARTA::NOMBRE:::myPtrToHighDifferentCardP1->GetName() = " << myPtrToHighDifferentCardP1->GetName() << "\n -> CARTA::TIPO:::myPtrToHighDifferentCardP1->GetName() = " << " NULLISIMO SEGMENTATION FAULT con un CORE DUMPED !!!! voy a dejar de usar auxiliares porque se mueren al terminar la ejecucion del Bloque {} donde t=estoy trabajandolos \n";	///*(myPtrToHighDifferentCardP1->GetMyCardTypeNonConst()).GetLongName()*/
//		std::cout << "\nEjecutando:::::::::( DENTRO DE METODO: 'CardManager::CompareCards(...):::: CARTA::VALOR:::myPtrToHighDifferentCardP2->GetValue() = "<< myP2CardValue << "\nCARTA::NOMBRE:::myPtrToHighDifferentCardP2->GetName() = " << myPtrToHighDifferentCardP2->GetName() << "\n -> CARTA::TIPO:::myPtrToHighDifferentCardP2->GetName() = " << " NULLISIMO SEGMENTATION FAULT con un CORE DUMPED !!!! voy a dejar de usar auxiliares porque se mueren al terminar la ejecucion del Bloque {} donde t=estoy trabajandolos \n";	///*(myPtrToHighDifferentCardP2->GetMyCardTypeNonConst()).GetLongName()*/

		// Compare CARDS ( V A L U E S ):
		//
		if ( myP1CardValue != myP2CardValue )
		{

			// Is Bigger?
			//
			if ( myP1CardValue > myP2CardValue )
			{

				// P1 WINS:
				//
				myPtrPlayerWinner = &myP1;


			}//End if ( myP1CardValue > myP2CardValue )
			else	 // ( myP1CardValue < myP2CardValue )
			{

				// P2 WINS:
				//
				myPtrPlayerWinner = &myP2;

			}//End else of if ( myP1CardValue > myP2CardValue )


			// Return, cause' you found a WINNER:
			//
			// SET:  HIGHEST P1 (different) CARD:
			//
			( myP1.GetMyHand() )->SetMyPtrToHighestDifferentCard( (myP1PtrCards.at( i )) );
			//
			// SET:  HIGHEST P2 (different) CARD:
			//
			( myP2.GetMyHand() )->SetMyPtrToHighestDifferentCard( (myP2PtrCards.at( i )) );
			//
			return myPtrPlayerWinner;


		}//End if ( myP1CardValue != myP2CardValue )

	}//End For


	// No WINNER:
	//
	// POINTERS:
	//
//	myPtrToHighDifferentCardP1 	= nullptr;
//	myPtrToHighDifferentCardP2 	= nullptr;
	//
	return nullptr;	 // return nullprt; // NULL;

	// Note: And these will be NULL-nullptr TOO:
	//
	///// myPtrToHighDifferentCardP1 	= nullptr;
	///// myPtrToHighDifferentCardP2 	= nullptr;

}//End Method


/**
 *	It compares the (Players') CARDs which are classified as 'HAND DEFINITION cards'.
 *	tHAT WAY: IT DEFINES a
 *		1-	WINNER			[thus RETURNING a POINTER to the WINNER-PLAYER: {&myPx} ]
 *		2-	LOSER, 	or
 *		3-	A DRAW.			[thus RETURNING a NULL POINTER]
 *
 *	PARAMETER: P1 AND P2: EACH ONE HAVE A:
 *
 *	@sortCardsOrder	->	0	:	False.	Not to SORT
 *					->	> 0 :	True.	SORT ASCENDING  [ 1, 2, 3... 100000 ]
 *					->	< 0 :	True.	SORT DESCENDING [ 100000000, 5, 1 ]
 */
Player* CardManager::CompareHandDefinitionCards( Player &myP1, Player &myP2, const int &sortP1CardsOrder, const int &sortP2CardsOrder )
{

	// WINNER Player:
	//
	Player* myWinnerPlayer = nullptr;
	//
	// Get the HAND- DEFINITION CARDS: (Pointer to the Array...)
	// P1
	//
	/// Before it was:	 Card* (*myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ] = ( myP1.GetMyHand() )->GetMyDefinitionCardsThatDefineTheHandTypeName();
	//
	// Reference (Shortcut) to the Vector: P1
	//
	std::vector< Card* > &myP1PtrCards = ( myP1.GetMyHand() )->GetMyDefinitionCardsThatDefineTheHandTypeName();
	//
	// P2
	//
	/// Before it was:	 Card* (*myP2PtrCards)[ _MAX_CARD_PER_HAND_COUNT ] = ( myP2.GetMyHand() )->GetMyDefinitionCardsThatDefineTheHandTypeName();
	//
	// Reference (Shortcut) to the Vector: P2
	//
	std::vector< Card* > &myP2PtrCards = ( myP2.GetMyHand() )->GetMyDefinitionCardsThatDefineTheHandTypeName();


	// Call the Method to SORT CARDS: (Desc.)
	//
	//	1-	CARD* myPtrToHighDifferentCardP1 && myPtrToHighDifferentCardP2:   Highest DIFFERENT CARD in Hand
	//	Declare to use them:
	//
//	Card* myPtrToHighDifferentCardP1 = myP1.GetMyHand()->GetMyPtrToHighDifferentCardOfDefinitionCards();		// dont use this: better to use a myP1.GETPtrCARD()...
//	Card* myPtrToHighDifferentCardP2 = myP2.GetMyHand()->GetMyPtrToHighDifferentCardOfDefinitionCards();		// dont use this: better to use a myP1.GETPtrCARD()...
//	//
//	myPtrToHighDifferentCardP1 = nullptr;
//	myPtrToHighDifferentCardP2 = nullptr;


	//	ZZ-	FINAL:	Call the SORTER + WINNER DEFINER + Card VALUE returner: Method:
	//
	///// myWinnerPlayer = CardManager::CompareCards( myP1, myP2, myP1PtrCards, myP2PtrCards, myP1.GetMyHand()->GetMyPtrToHighestDifferentCard() /*myPtrToHighDifferentCardP1*/, myP2.GetMyHand()->GetMyPtrToHighestDifferentCard() /*myPtrToHighDifferentCardP2*/ );
	//
	myWinnerPlayer = CardManager::CompareCards( myP1, myP2, myP1PtrCards, myP2PtrCards, sortP1CardsOrder, sortP2CardsOrder );


	// SET:  HIGHEST P1 (different) CARD:
	//
	//		WARNING NOTE: 	OJOOOOO: It is possible that
	//....I need to create it with ""NEWWWWWWWW"".
	//....Because if it GOES OUT OF SCOPE, I will be deleted.
	//
	//	BUT: I may be wrong, beacause IT BELONGS TO 'myP1' and 'myP2', which are GLOBAL..:
	//
	// There is a Winner, so there is  a NOT-NULL Comparison of CARDS:
	//...returned by 'CardManager::CompareCards( ....'
	//
//	( myP1.GetMyHand() )->SetMyPtrToHighDifferentCardOfDefinitionCards( myPtrToHighDifferentCardP1 );
//	//
//	// SET:  HIGHEST P2 (different) CARD:
//	//
//	( myP2.GetMyHand() )->SetMyPtrToHighDifferentCardOfDefinitionCards( myPtrToHighDifferentCardP2 );


/////ESTO EXPLOTA, EL VALOR YA NO EXISTE:::::::	std::cout << "\nEjecutado::::LISTO::pruebaaaaa:::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' ):::TIPO DE CARTA::::myP1.GetMyHand()->GetMyPtrToHighDifferentCardOfDefinitionCards()->GetName() = "<< myP1.GetMyHand()->GetMyPtrToHighDifferentCardOfDefinitionCards()->GetName() << "\n";

	//
	if ( myWinnerPlayer  /* && myPtrToHighDifferentCardP1 && myPtrToHighDifferentCardP2 */ ) 	// There is a Winner, so there is  a NOT-NULL Comparison of CARDS.
	{

		// Set other Attributes: Name in 'Printer Friendly' Version:
		//
		//	Set the OUTPUT of LINE 2... ['Máxima Carta' ' ' 'NOMBRE_DE_CARTA']
		//
		/////& std::cout << "\n ANTES DE LLAMAR A : CardManager::SetFinalOutputOfLine2( myP1, myP2 ); \nEn: 'CompareHandDefinitionCards (...)'";
		//
		CardManager::SetFinalOutputOfLine2( myP1, myP2 );
		//
		/////&std::cout << "\n DESPUES DE LLAMAR A : CardManager::SetFinalOutputOfLine2( myP1, myP2 ); \nEn: 'CompareHandDefinitionCards (...)'";


//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::\n:::::::: CardManager::SetFinalOutputOfLine2( myP1, myP2 )"<< "\n";
//
//		// P1
//		//
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::::CARTA::NOMBRE:::myPtrToHighDifferentCardP1->GetName() = "<< myP1.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetName() << "\n";
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::::CARTA::VALOR:::myPtrToHighDifferentCardP1->GetValue() = "<< myP1.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetValue() << "\n";
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' ):::TIPO DE CARTA::::(myPtrToHighDifferentCardP1->GetMyCardTypeNonConst()).GetLongName() = "<< (myP1.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetMyCardTypeNonConst()).GetLongName() << "\n";
//		//
//		// P2
//		//
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::::CARTA::NOMBRE:::myPtrToHighDifferentCardP2->GetName() = "<< myP2.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetName() << "\n";
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::::CARTA::VALOR:::myPtrToHighDifferentCardP2->GetValue() = "<< myP2.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetValue() << "\n";
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' ):::TIPO DE CARTA::::(myPtrToHighDifferentCardP2->GetMyCardTypeNonConst()).GetLongName() = "<< (myP2.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetMyCardTypeNonConst()).GetLongName() << "\n";

	}
//	else
//	{
//
//		// There is NO Winner: 	 So all POINTERS ARE NULL.
//		//
//	}//ENd else of if ( myWinnerPlayer ) 	// There is a Winner, so there is  a NOT-NULL Comparison of CARDS.


	// Return: The Winner Player.
	//
	return myWinnerPlayer;

}//End Method


/**
 *	It compares the (Players') CARDs which are classified as 'HAND NOT-DEFINITION cards'.
 *	tHAT WAY: IT DEFINES a
 *		1-	WINNER			[thus RETURNING a POINTER to the WINNER-PLAYER: {&myPx} ]
 *		2-	LOSER, 	or
 *		3-	A DRAW.			[thus RETURNING a NULL-nullptr POINTER]
 */
Player* CardManager::CompareHandNotDefinitionCards( Player &myP1, Player &myP2 )
{

	// WINNER Player:
	//
	Player* myWinnerPlayer = nullptr;
	//
	// Get the NOT-HAND- DEFINITION CARDS: (Pointer to the Array...)
	// P1
	//
	/// Before it was:	 Card* (*myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ] = ( myP1.GetMyHand() )->GetMyNotDefinitionCards();
	//
	//	Reference (Shortcut) to the Vector: P1
	//
	std::vector< Card* > &myP1PtrCards = ( myP1.GetMyHand() )->GetMyNotDefinitionCards();
	//
	// P2
	//
	/// Before it was:	 Card* (*myP2PtrCards)[ _MAX_CARD_PER_HAND_COUNT ] = ( myP2.GetMyHand() )->GetMyNotDefinitionCards();
	//
	//	Reference (Shortcut) to the Vector: P2
	//
	std::vector< Card* > &myP2PtrCards = ( myP2.GetMyHand() )->GetMyNotDefinitionCards();


	// Call the Method to SORT CARDS: (Desc.)
	//
	//	1-	CARD* myPtrToHighDifferentCardP1 && myPtrToHighDifferentCardP2:   Highest DIFFERENT CARD in Hand
	//	Declare to use them:
	//
//	Card* myPtrToHighDifferentCardP1 = myP1.GetMyHand()->GetMyPtrToHighDifferentCardOfNotDefinitionCards();		// dont use this: better to use a myP1.GETPtrCARD()...
//	Card* myPtrToHighDifferentCardP2 = myP2.GetMyHand()->GetMyPtrToHighDifferentCardOfNotDefinitionCards();		// dont use this: better to use a myP1.GETPtrCARD()...
//	//
//	myPtrToHighDifferentCardP1 = nullptr;
//	myPtrToHighDifferentCardP2 = nullptr;


	//	ZZ-	FINAL:	Call the SORTER + WINNER DEFINER + Card VALUE returner: Method:
	//
	///// myWinnerPlayer = CardManager::CompareCards( myP1, myP2, myP1PtrCards, myP2PtrCards, myP1.GetMyHand()->GetMyPtrToHighestDifferentCard() /*myPtrToHighDifferentCardP1*/, myP1.GetMyHand()->GetMyPtrToHighestDifferentCard() /*myPtrToHighDifferentCardP2*/ );
	//
	myWinnerPlayer = CardManager::CompareCards( myP1, myP2, myP1PtrCards, myP2PtrCards, -1 /* Sort Desc for: P1 */, -1 /* Sort Desc for: P2 */ );


	// SET:  HIGHEST P1 (different) CARD:
	//
	//		WARNING NOTE: 	OJOOOOO: It is possible that
	//....I need to create it with ""NEWWWWWWWW"".
	//....Because if it GOES OUT OF SCOPE, I will be deleted.
	//
	//	BUT: I may be wrong, beacause IT BELONGS TO 'myP1' and 'myP2', which are GLOBAL..:
	//
	// There is a Winner, so there is  a NOT-NULL Comparison of CARDS:
	//...returned by 'CardManager::CompareCards( ....'
	//
//	( myP1.GetMyHand() )->SetMyPtrToHighDifferentCardOfDefinitionCards( myPtrToHighDifferentCardP1 );
//	//
//	// SET:  HIGHEST P2 (different) CARD:
//	//
//	( myP2.GetMyHand() )->SetMyPtrToHighDifferentCardOfDefinitionCards( myPtrToHighDifferentCardP2 );

	//
	if ( myWinnerPlayer  /* && myPtrToHighDifferentCardP1 && myPtrToHighDifferentCardP2 */ ) 	// There is a Winner, so there is  a NOT-NULL Comparison of CARDS.
	{

		// Set other Attributes: Name in 'Printer Friendly' Version:
		//
		//	Set the OUTPUT of LINE 2... ['Máxima Carta' ' ' 'NOMBRE_DE_CARTA']
		//
		/////& std::cout << "\n ANTES DE LLAMAR A : CardManager::SetFinalOutputOfLine2( myP1, myP2 ); \nEn: 'CompareHandDefinitionCards (...)'";
		//
		CardManager::SetFinalOutputOfLine2( myP1, myP2 );
		//
		/////& std::cout << "\n DESPUES DE LLAMAR A : CardManager::SetFinalOutputOfLine2( myP1, myP2 ); \nEn: 'CompareHandDefinitionCards (...)'";


//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::\n:::::::: CardManager::SetFinalOutputOfLine2( myP1, myP2 )"<< "\n";
//
//		// P1
//		//
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::::CARTA::NOMBRE:::myPtrToHighDifferentCardP1->GetName() = "<< myP1.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetName() << "\n";
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::::CARTA::VALOR:::myPtrToHighDifferentCardP1->GetValue() = "<< myP1.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetValue() << "\n";
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' ):::TIPO DE CARTA::::(myPtrToHighDifferentCardP1->GetMyCardTypeNonConst()).GetLongName() = "<< (myP1.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetMyCardTypeNonConst()).GetLongName() << "\n";
//		//
//		// P2
//		//
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::::CARTA::NOMBRE:::myPtrToHighDifferentCardP2->GetName() = "<< myP2.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetName() << "\n";
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' )::::CARTA::VALOR:::myPtrToHighDifferentCardP2->GetValue() = "<< myP2.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetValue() << "\n";
//		std::cout << "\nEjecutado::::LISTO:::::( DENTRO DE METODO: 'Player* CardManager::CompareHandDefinitionCards(...)' ):::TIPO DE CARTA::::(myPtrToHighDifferentCardP2->GetMyCardTypeNonConst()).GetLongName() = "<< (myP2.GetMyHand()->GetMyPtrToHighestDifferentCard()->GetMyCardTypeNonConst()).GetLongName() << "\n";

	}
//	else
//	{
//
//		// There is NO Winner: 	 So all POINTERS ARE NULL.
//		//
//	}//ENd else of if ( myWinnerPlayer ) 	// There is a Winner, so there is  a NOT-NULL Comparison of CARDS.


	// Return: The Winner Player.
	//
	return myWinnerPlayer;

}//End Method



/**
 * Creates and Sets the OUTPUT LINE 2 of the Game.
 *
 * It is stored inside the HAND Attribute of each PLAYER Object.
 *
 * [ ( myP1.GetMyHand() )->SetOutputMyGameLine2( _OUTPUT_LINE_2_FINAL_P1...... ); ]
 *
 * It is based in the: NOT DEFINITION CARDS (the HIGHEST DIFFERENT one... between P1 & P2).
 */
void CardManager::SetFinalOutputOfLine2( Player &myP1, Player &myP2 )
{

	// Pointers to Highest Different CARDS:		P1
	//
	Card* (&myP1PtrHighestDifferentCard) = (*myP1.GetMyHand()).GetMyPtrToHighestDifferentCard();
	//
	// Pointers to Highest Different CARDS:		P2
	//
	Card* (&myP2PtrHighestDifferentCard) = (*myP2.GetMyHand()).GetMyPtrToHighestDifferentCard();


	// Set other Attributes: Name in 'Printer Friendly' Version:
	// 		In:  CASE OF A draw, WITH not-definition cards:
	//
	//	Set the OUTPUT of LINE 2... ['Máxima Carta' ' ' 'NOMBRE_DE_CARTA']
	//
	string _OUTPUT_LINE_2_FINAL_P1 = _OUTPUT_LINE_2_BEGINNING;
	_OUTPUT_LINE_2_FINAL_P1 += " ";
	//
	string _OUTPUT_LINE_2_FINAL_P2 = _OUTPUT_LINE_2_BEGINNING;
	_OUTPUT_LINE_2_FINAL_P2 += " ";
	//
	//
	if ( ( (! myP1PtrHighestDifferentCard) && (! myP2PtrHighestDifferentCard) )
			|| ( ( (myP1PtrHighestDifferentCard->GetValue()) == (myP2PtrHighestDifferentCard->GetValue()) ) ) )
	{
		// Invalid: TIE: DRAW:
		//
		//	Set the OUTPUT of LINE 2... DRAW, EMPATE.
		//	P1:
		//
		_OUTPUT_LINE_2_FINAL_P1 += _OUTPUT_LINE_2_ENDING_TIE;
		//
		//	P2:
		//
		_OUTPUT_LINE_2_FINAL_P2 += _OUTPUT_LINE_2_ENDING_TIE;

	}//End if ( (! myP1PtrCard) && (! myP2PtrCard) )
	else
	{

//		// Compare values:
//		//
//		if ( ( myP1PtrHighestDifferentCard->GetValue() > myP2PtrHighestDifferentCard->GetValue() ) )
//		{
//
//			// P1 WON
//			//
//		}//End if ( ( myP1PtrHighestDifferentCard->GetValue() > myP2PtrHighestDifferentCard->GetValue() ) )
//		else
//		{
//			// P2 WON
//			//
//		}//End else

		//	Set the OUTPUT of LINE 2... ['Máxima Carta' ' ' 'NOMBRE_DE_CARTA']
		//	P1:
		//
		_OUTPUT_LINE_2_FINAL_P1 += myP1PtrHighestDifferentCard->GetShortName();
		//
		//	P2:
		//
		_OUTPUT_LINE_2_FINAL_P2 += myP2PtrHighestDifferentCard->GetShortName();

	}//End else


	//	Set the OUTPUT of LINE 2... ['Máxima Carta' ' ' 'NOMBRE_DE_CARTA']
	//	P1:
	//
	( myP1.GetMyHand() )->SetOutputMyGameLine2( _OUTPUT_LINE_2_FINAL_P1 );
	//
	//	P2:
	//
	( myP2.GetMyHand() )->SetOutputMyGameLine2( _OUTPUT_LINE_2_FINAL_P2 );

}//End Method



/**
 * If the Player has been Initialized (and His HAND -> CARDS: are already BUILT),
 * ...but Its Cards had not been read (i.e.: He has not stated to Play the Game):
 *
 * ...1- This Method Gets (discovers...) the Type of HAND...
 *
 * DISCARD THIS: <<  ...IN OTHER Method: This will be done: >>
 *
 *	THIS WILL BE DONE inside this Method:
 *
 * --------------------------------------
 *
 * ...2- Hierarchy Value (among other Attributes, such as NAME), of the Object:
 *
 * 			Player->_myHand->_myHandType ... ->_hierarchyValue;
 */
void CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )
{
//	// Pointer to HandType, to be returned at the end of the Method:
//	//
//	HandType*	myPtrToHandType = nullptr;  	// NULL;// = myPlayer.GetMyHand() -> /* Because It is a Pointer (* this ). */ GetMyHandType();
//	//
//	// Build New 'HandType' Object:  (NOTE: HAND must have been initialized BEFORE... from a READLINE
//	//..of the INPUT .TXT)
//	//
//	HandType myHandType( 0 /*myPlayer.GetId()*/, 0, "DO NOT HAVE A HAND!", "I, Sir.: DO NOT HAVE A HAND!" );
//	//
//	// Ptr -> MyHand...
//	//
//	myPtrToHandType = &myHandType;


	// Start  by Trying to Identify the Name of the HAND TYPE:
	//
	// 9	-	ROYAL FLUSH
	//
	if ( CardManager::VerifyRoyalFlushHandType( *(myPlayer.GetMyHand()) ) )
	{

		/////& std::cout << "\n**********************************\n -> DENTRO DE: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (INICIANDO) -> ANTES DE ENTRAR EN: SetHandAndHandTypeAttributesForRoyalFlush()\n"<< std::flush;

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForRoyalFlush( myPlayer );

		/////& std::cout << "\n99999999999999999999999999999\n -> DENTRO DE: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> SALIDO RECIÉN DE: SetHandAndHandTypeAttributesForRoyalFlush()\n"<< std::flush;

	}//End if 	ROYAL 		FLUSH
	// 8	-	STRAIGHT 	FLUSH
	//
	else if ( CardManager::VerifyStraightFlushHandType( *(myPlayer.GetMyHand()) ) )
	{

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForStraightFlush( myPlayer );

		/////& std::cout << "\n888888888888888888888888888888\n -> DENTRO DE:: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForStraightFlush( myPlayer )\n"<< std::flush;

	}//End if  STRAIGHT FLUSH
	// 7	-	FOUR OF A KIND
	//
	else if ( CardManager::VerifyFourOfAKind( *(myPlayer.GetMyHand()) ) )
	{

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForFourOfAKind( myPlayer );

		/////& std::cout << "\n77777777777777777777777777777777\n -> DENTRO DE:: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForFourOfAKind( myPlayer )\n"<< std::flush;

	}//End if  FOUR OF A KIND
	// 6	-	FULL HOUSE
	//
	else if ( CardManager::VerifyFullHouse( *(myPlayer.GetMyHand()) ) )
	{

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForFullHouse( myPlayer );

		/////& std::cout << "\n6666666666666666666666666666666666\n -> DENTRO DE:: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForFullHouse( myPlayer )\n"<< std::flush;

	}//End if  FULL HOUSE
	// 5	-	FLUSH
	//
	else if ( CardManager::VerifyFlush( *(myPlayer.GetMyHand()) ) )
	{

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForFlush( myPlayer );

		/////& std::cout << "\n5555555555555555555555555555555555555\n -> DENTRO DE: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForFlush( myPlayer )\n"<< std::flush;

	}//End if  FLUSH
	// 4	-	STRAIGHT
	//
	else if ( CardManager::VerifyStraight( *(myPlayer.GetMyHand()) ) )
	{

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForStraight( myPlayer );

		/////& std::cout << "\n444444444444444444444444444444444444444\n -> DENTRO DE: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForStraight( myPlayer )\n"<< std::flush;

	}//End if  STRAIGHT
	// 3	-	THREE OF A KIND
	//
	else if ( CardManager::VerifyThreeOfAKind( *(myPlayer.GetMyHand()) ) )
	{

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForThreeOfAKind( myPlayer );

		/////& std::cout << "\n333333333333333333333333333333333333333\n -> DENTRO DE: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForThreeOfAKind( myPlayer )\n"<< std::flush;

	}//End if  THREE OF A KIND
	// 2	-	TWO PAIRS
	//
	else if ( CardManager::VerifyTwoPairs( *(myPlayer.GetMyHand()) ) )
	{

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForTwoPairs( myPlayer );

		/////& std::cout << "\n2222222222222222222222222222222222222\n -> DENTRO DE:: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForTwoPairs( myPlayer )\n"<< std::flush;

	}//End if  TWO PAIRS
	// 1	-	ONE PAIR
	//
	else if ( CardManager::VerifyOnePair( *(myPlayer.GetMyHand()) ) )
	{

		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForOnePair( myPlayer );

		/////& std::cout << "\n111111111111111111111111111111111111111\n -> DENTRO DE:: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForOnePair( myPlayer )\n"<< std::flush;

	}//End if  ONE PAIR
	else
	{
		/////& std::cout << "\n00000000000000000000000000000\n -> DENTRO DE: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> INICIÓ: CardManager::SetHandAndHandTypeAttributesForHighCard( myPlayer )\n"<< std::flush;

		// 0	-	Hierarchycal Value = 0	-	HIGH CARD
		//
		// Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
		//
		CardManager::SetHandAndHandTypeAttributesForHighCard( myPlayer );

		/////& std::cout << "\n00000000000000000000000000000\n -> TERMINÓ: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForHighCard( myPlayer )\n"<< std::flush;

	}//End Else = HIGH CARD.

}//End Method


	/**10-	****************ROYAL FLUSH****************** VALUE = 9**/

/**
 * Verifies if the HAND TYPE is: ROYAL FLUSH.
 * Return: True (if it is!)... False: If Not.
 */
const bool CardManager::VerifyRoyalFlushHandType( Hand & myHand )
{

	// Return value:
	//
	bool allCardsAreOfTheSameType = false, allCardsAreSortedInAscendingOrder = false;


	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (INICIANDO) -> Dentro en: const bool CardManager::VerifyRoyalFlushHandType( Hand & myHand )\n"<< std::flush;


	// Work tooooodoo:
	//
	// 1- Verify: Same Type:
	//
	allCardsAreOfTheSameType = VerifyAllCardsAreTheSameType( (*(myHand.GetArrayOfCardsFromMyHand()) ) );


	// 2- Verify: Ascending ORDER
	// 	.1- Initial Card Value for the validation:
	//
	const int INITIAL_CARD_VALUE_IN_ROYAL_FLUSH = _CARD_10_T_VALUE;
	//
	allCardsAreSortedInAscendingOrder = VerifyAllCardsAreSortedInPerfectAscendingOrder( myHand, INITIAL_CARD_VALUE_IN_ROYAL_FLUSH );


	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: const bool CardManager::VerifyRoyalFlushHandType( Hand & myHand )\n"<< std::flush;


	// Return the veredict:
	//
	return ( allCardsAreOfTheSameType && allCardsAreSortedInAscendingOrder );

}//End Method



/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForRoyalFlush( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:
	//					All Cards, but in Descendent ORDER.
	//
	Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();

	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	UtilFunctions::SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );

	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_ROYAL_FLUSH_NAME_ESP" + " " + Type Of Card
	//				Example:	"ROYAL FLUSH of HEART"
	//
	string outputLine1 = _ROYAL_FLUSH_NAME_ESP;
	outputLine1 += " ";
	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//						All Cards, but in Descendent ORDER.
	//	There are not. nullptr.
	//
	/// Before it was:	 Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	// New implementation:
	//
	std::vector< Card* > &myPtrHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does not have 'NOT DEFINITION CARDS'.
	//
	myPtrHandNotDefinitionCards.clear();


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _ROYAL_FLUSH_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _ROYAL_FLUSH_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _ROYAL_FLUSH_NAME_ESP );

	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForRoyalFlush( Player &myPlayer )\n"<< std::flush;

}//End Method


	/**9-	****************STRAIGHT FLUSH****************** VALUE = 8**/




const bool CardManager::VerifyStraightFlushHandType( Hand & myHand )
{

	// Return value:
	//
	bool allCardsAreOfTheSameType = false, allCardsAreSortedInAscendingOrder = false;


	// Work tooooodoo:
	//
	// 1- Verify: Same Type:
	//
	allCardsAreOfTheSameType = VerifyAllCardsAreTheSameType( (* myHand.GetArrayOfCardsFromMyHand() ) );


	// 2- Verify: Ascending ORDER:
	//
	// NOTE: The Card Initial Value must be changed (until a Match is found), testing with values
	//...from 'CARD_2_INITIAL_VALUE' to '_CARD_9_VALUE'.
	//
	// 	.1- Initial Card Value for the validation: _CARD_2_VALUE ...to... (_CARD_10_T_VALUE - 1)
	//
	allCardsAreSortedInAscendingOrder = ( VerifyAllCardsAreSortedInPerfectAscendingOrderAndReturnCardValue( myHand ) > 0 );

	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: CardManager::VerifyStraightFlushHandType( Hand & myHand )\n"<< std::flush;

	// Return the veredict:
	//
	return ( allCardsAreOfTheSameType && allCardsAreSortedInAscendingOrder );

}//End Method


/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForStraightFlush( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:
	//					All Cards, but in Descendent ORDER.
	//
	Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();

	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	UtilFunctions::SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );

	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_STRAIGHT_FLUSH_NAME_ESP" + " " + Type Of Card
	//				Example:	"STRAIGHT FLUSH of HEART"
	//
	string outputLine1 = _STRAIGHT_FLUSH_NAME_ESP;
	outputLine1 += " ";
	outputLine1 += ( (* myPtrHandDefinitionCards )[ 0 ])->GetShortName();
	outputLine1 += " de ";
	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//						All Cards, but in Descendent ORDER.
	//	There are not. nullptr.
	//
	/// Before it was:	Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	//	New Implementation:
	//
	std::vector< Card* > &myPtrHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does not have 'NOT DEFINITION CARDS'.
	//
	myPtrHandNotDefinitionCards.clear();


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _STRAIGHT_FLUSH_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _STRAIGHT_FLUSH_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _STRAIGHT_FLUSH_NAME_ESP );

	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: CardManager::SetHandAndHandTypeAttributesForStraightFlush( Player &myPlayer )\n"<< std::flush;

}//End Method


	/**8-	****************FOUR OF A KIND****************** VALUE = 7**/

/**
 * Verifies that: 	There are FOUR (4) Cards that are the SAME VALUE.
 * NOTE: It is FASTER to Check Cards by Value... rather than by their 'SHORT NAMES'.
 * Return:
 * 	->	True
 * 	->	False
 *
 * 	ALSO RETURNS:
 *
 * 	Updated VECTOR OF CARDS: that define the HAND:  FOUR OF A KIND.
 */
const bool CardManager::VerifyFourOfAKind( Hand & myHand )
{

	/////& std::cout << "\n---------------------->>>>>>>>>\n -> DENTRO DE:: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> 	[[INICIANDO, ojo aca se cae,,.. ver si sale TERMINANDO...]]: const bool CardManager::VerifyFourOfAKind( Hand & myHand )\n"<< std::flush;
	// Verify that there are FOUR (4) OCURRENCES:
	//
	//...and: Save the CARD*s inside the VECTOR:	MyHandCardDefinitions
	//
	//
	std::vector <Card *> myRepeatedPtrCards;
	//
	const int OCURRENCES_NUMBER_FOUR = 4;
	//
	// Search for the Cards*, with a REPEATED VALUE:
	//
	const int cardValueRepeated = VerifySomeOfAKind ( myHand, OCURRENCES_NUMBER_FOUR, -1, myRepeatedPtrCards );

	/////& std::cout << "\n---------------------->>>>>>>>>\n -> DENTRO DE:: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> \n En Metodo:  VerifyFourOfAKind (..)...  \n-> -> 	[[ojo aca se cae,,.. ver si sale TERMINANDO...]]: JUSTO DESPUÉS DE INVOCAR LA LÍNEA:   const int cardValueRepeated = VerifySomeOfAKind ( myHand, 4, -1, myRepeatedPtrCards );\n"<< std::flush;

	//
	// Save that VECTOR as 'MyHandCardDefinitions' from PLAYER: if it is not EMPTY:
	//
	if ( ( ! myRepeatedPtrCards.empty() ) && ( cardValueRepeated > 0 ) )
	{
		// Save inside the Hand: the CARD*s
		//
		myHand.SetMyDefinitionCardsThatDefineTheHandTypeName( myRepeatedPtrCards );

		/////& std::cout << "\n********RETURN TRUE FUNCION:**************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: const bool CardManager::VerifyFourOfAKind( Hand & myHand )"<< std::flush;

		// Return
		//
		return true;

	}//End if ( ! myRepeatedPtrCards.empty() )

	/////& std::cout << "\n*******************RETURN FALSE FUNCION***************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: const bool CardManager::VerifyFourOfAKind( Hand & myHand )"<< std::flush;

	// Return
	//
	return false;

}//End Method



/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForFourOfAKind( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:

	//				It is already correctly FILLED!!!!!!!!!!!!!!!!!!!

	//					All Cards, but in Descendent ORDER.
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//
	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );
	//
	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_FOUR_OF_A_KIND_NAME_ESP" + " " + Value of Card
	//				Example:	"FOUR Aces (A)"
	//
	//				.1-	Condition: Get one of THOSE REPEATED CARDS:
	//
	std::vector < Card* > &myVectorRefToHandDefinitionCards = (myPlayer.GetMyHand())->GetMyDefinitionCardsThatDefineTheHandTypeName();
	//
	//
	string outputLine1 = _FOUR_OF_A_KIND_NAME_ESP;
	outputLine1 += " ";
	/// Before: outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetShortName();	// END of OUTPUT, in this case.
	// Upgrade: Use the LONG Name in SPANISH, in PLURAL:
	//
	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetLongNameEspanishPlural();	// END of OUTPUT, in this case.
	//
//	outputLine1 += " de ";
//	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	// Set that OUTPUT-LINE_1 inside the PLAYER'S OBJECT:
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//						All Cards, but in Descendent ORDER.
	//	There are not. nullptr.
	//
	/// Before it was:	Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	//	New Implementation:
	//
	std::vector< Card* > &myVectorRefToHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does have just ONE  ('NOT DEFINITION CARD').
	//
	myVectorRefToHandNotDefinitionCards.clear();
	//
	// .3-	Let's search for that ONE CARD:
	// =>	It is the ONE DIFFERENT CARD, in the cCOMPARISON between:
	//
	//			Card* (& myReferenceToArrayHandCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//		AND
	//			'myVectorRefToHandDefinitionCards'
	//
	//	Let's COMPARE them!
	//	a)	Reference to HAND CARDS (ALL of them):
	//
	Card* (& myReferenceToArrayHandCards)[ _MAX_CARD_PER_HAND_COUNT ] = (* (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand() );
	//
	//	b)	COMPARISON (described previously):
	//
	//	Compare, and STORE THE RESULT inside the VECTOR:	'myVectorRefToHandNotDefinitionCards'
	//
	UtilFunctions::SetAVectorComparison( (Card* (&) [ _MAX_CARD_PER_HAND_COUNT ]) myReferenceToArrayHandCards, myVectorRefToHandDefinitionCards, myVectorRefToHandNotDefinitionCards, false ); // DIFFERENT Ocurrences <=> Different Elements


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _FOUR_OF_A_KIND_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _FOUR_OF_A_KIND_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _FOUR_OF_A_KIND_NAME_ESP );

}//End Method



	/**7-	****************FULL HOUSE****************** VALUE = 6**/

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
 *
 * 	ALSO RETURNS:
 *
 * 	Updated VECTOR OF CARDS: that define the HAND:  FullHouse.
 *
 */
const bool CardManager::VerifyFullHouse( Hand & myHand )
{

	//	Necessary INPUTS:
	//	Save the REPEATED sCARD*s inside the VECTOR:	MyHandCardDefinitions
	//
	//	1-	3 of a Kind: Repeated Card*s
	//
	std::vector <Card *> myRepeated3OfAKindPtrCards;
	//
	//	2-	PAIR:	2 of a Kind: Repeated Card*s
	//
	std::vector <Card *> myRepeatedPair2OfAKindPtrCards;
	//
	// Necessary INPUTS:
	//
	int countOcurrences = 3, valueToExclude = -1;


	// 1-	There is a THREE OF A KIND (3).
	//
	const int cardValueInThreeOfAKind = VerifySomeOfAKind ( myHand, countOcurrences, valueToExclude, myRepeated3OfAKindPtrCards );


	// 1-	There is a THREE OF A KIND (3).
	//
	if ( cardValueInThreeOfAKind <= 0 )
	{

		/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: const bool CardManager::VerifyFullHouse( Hand & myHand )"<< std::flush;

		// This Hand is not a Full House:
		//
		return false;

	}//End if ( cardValueInThreeOfAKind <= 0)
	else
	{

		// 2-	EXCLUDE that Card VALUE from the next calculations.
		//
		valueToExclude = cardValueInThreeOfAKind;
		//
		// Update Ocurrences => 2, a ONE PAIR:
		//
		countOcurrences = 2;


		// 3-	Discover that there is a ONE PAIR (2) = TWO OF A KIND.
		//
		const int cardValueInOnePair = VerifySomeOfAKind ( myHand, countOcurrences, valueToExclude, myRepeatedPair2OfAKindPtrCards );


		// If there is a PAIR (and there was a TRIPLE...): it is a FULL HOUSE:
		//
		if ( (cardValueInOnePair > 0 ) && (! myRepeated3OfAKindPtrCards.empty() ) && (! myRepeatedPair2OfAKindPtrCards.empty() ) )
		{

			// Full House:
			// Save the (WHALES?!): Not!: Save the all VECTORS ( UNITE THEM FIRST! )
			//
			std::vector< Card* > myVector3Result;
			//
			UtilFunctions::ConcatenateTwoVectorsAandBAndAddToC( myRepeated3OfAKindPtrCards, myRepeatedPair2OfAKindPtrCards, myVector3Result );
			//
			//
			// Save inside the Hand: the CARD*s
			//
			myHand.SetMyDefinitionCardsThatDefineTheHandTypeName( myVector3Result );

			/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: const bool CardManager::VerifyFullHouse( Hand & myHand )"<< std::flush;

			// Return:	It is a FULL HOUSE:
			//
			return true;

		}
		else
		{

			/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: const bool CardManager::VerifyFullHouse( Hand & myHand )"<< std::flush;

			// Return:	It is NOT  (a FULL HOUSE):
			//
			return false;

		}//End Veredict

	}//End else

}//End Method



/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForFullHouse( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:

	//				It is already correctly FILLED!!!!!!!!!!!!!!!!!!!

	//					All Cards, but in Descendent ORDER.
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//
	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );
	//
	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_FULL_HOUSE_NAME_ESP" + " de " + Value of Card
	//				Example:	"FULL HOUSE de 4"
	//
	//				.1-	Condition: 	Get one of THOSE REPEATED CARDS: in the TRIPLE...:
	//					FACT:		TRIPLE Card*(s) are the FIRST three of the Vector:
	//								'myVectorRefToHandDefinitionCards'
	//					Let's use the FIRST ([0]).
	//
	std::vector < Card* > &myVectorRefToHandDefinitionCards = (myPlayer.GetMyHand())->GetMyDefinitionCardsThatDefineTheHandTypeName();
	//
	//
	string outputLine1 = _FULL_HOUSE_NAME_ESP;
	outputLine1 += " ";
	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetShortName();	// END of OUTPUT, in this case.
	//
	///// Not in this case:	outputLine1 += " de ";
	///// Not in this case:	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	// Set that OUTPUT-LINE_1 inside the PLAYER'S OBJECT:
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//						All Cards, but in Descendent ORDER.
	//	There are not. nullptr.
	//
	/// Before it was:	Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	//	New Implementation:
	//
	std::vector< Card* > &myVectorRefToHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:
	//
	myVectorRefToHandNotDefinitionCards.clear();


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _FULL_HOUSE_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _FULL_HOUSE_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _FULL_HOUSE_NAME_ESP );

}//End Method


	/**6-	****************FLUSH****************** VALUE = 5**/

/**
 * Verifies if the HAND TYPE is: FLUSH.
 *
 * All Cards must be the SAME CARD_TYPE.
 *
 * Return:
 * 	->	True (if it is!)...
 * 	->	False: If Not.
 */
const bool CardManager::VerifyFlush( Hand & myHand )
{

	// All Cards must be the SAME CARD_TYPE:
	//
	return VerifyAllCardsAreTheSameType( (* myHand.GetArrayOfCardsFromMyHand() ) );

}//End Method


/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForFlush( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:
	//					All Cards, but in Descendent ORDER.
	//
	Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();

	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	UtilFunctions::SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );

	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_FLUSH_NAME_ESP" + " " + Type Of Card
	//				Example:	"FLUSH de HEART"
	//
	string outputLine1 = _FLUSH_NAME_ESP;
	outputLine1 += " ";
///// NOT IN THIS CASE:		outputLine1 += ( (* myPtrHandDefinitionCards )[ 0 ])->GetName();
///// NOT IN THIS CASE:		outputLine1 += " de ";
	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	// SAVE as Attribute
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//
	//	There are not. nullptr.
	//
	/// Before it was:	Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	//	New Implementation:
	//
	std::vector< Card* > &myPtrHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does not have 'NOT DEFINITION CARDS'.
	//
	myPtrHandNotDefinitionCards.clear();


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _FLUSH_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _FLUSH_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _FLUSH_NAME_ESP );

}//End Method




	/**5-	****************STRAIGHT****************** VALUE = 4**/

/**
 * Verifies if the HAND TYPE is: STRAIGHT.
 *
 * Return:
 * 	->	True (if it is!)...
 * 	->	False: If Not.
*/
const bool CardManager::VerifyStraight( Hand & myHand )
{

	// All Cards must be the SAME CARD_TYPE:
	//
	return ( VerifyAllCardsAreSortedInPerfectAscendingOrderAndReturnCardValue( myHand ) > 0 );

}//End Method



/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForStraight( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:
	//					All Cards, but in Descendent ORDER.
	//
	Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();

	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	UtilFunctions::SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );

	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_STRAIGHT" + " " + Type Of Card
	//				Example:	"STRAIGHT FLUSH of HEART"
	//
	string outputLine1 = _STRAIGHT_NAME_ESP;
	outputLine1 += " ";
	outputLine1 += ( (* myPtrHandDefinitionCards )[ 0 ])->GetShortName();
	outputLine1 += " de ";
	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	// Save the output in the Object:
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );


	//		.3-	FILL IN:	NOT - Definition CARDS:
	//
	//	There are not. nullptr.
	//
	/// Before it was:	Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	//	New Implementation:
	//
	std::vector< Card* > &myPtrHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does not have 'NOT DEFINITION CARDS'.
	//
	myPtrHandNotDefinitionCards.clear();


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _STRAIGHT_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _STRAIGHT_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _STRAIGHT_NAME_ESP );

}//End Method



	/**4-	****************THREE OF A KIND****************** VALUE = 3**/

/**
 * Verifies that: 	There are THREE (3) Cards that are the SAME VALUE.
 * NOTE: It is FASTER to Check Cards by Value... rather than by their 'SHORT NAMES'.
 * Return:
 * 	->	True
 * 	->	False
 *
 * 	ALSO RETURNS:
 *
 * 	Updated VECTOR OF CARDS: that define the HAND:  THREE OF A KIND.
 */
const bool CardManager::VerifyThreeOfAKind( Hand & myHand )
{

	// Verify that there are THREE (3) OCURRENCES:
	//
	//...and: Save the CARD*s inside the VECTOR:	myHand.SetMyDefinitionCardsThatDefineTheHandTypeName(...)
	//
	//
	std::vector <Card *> myRepeatedPtrCards;
	//
	// Search for the Cards*, with a REPEATED VALUE:
	//
	const int cardValueRepeated = VerifySomeOfAKind ( myHand, 3, -1, myRepeatedPtrCards );
	//
	// Save that VECTOR as 'MyHandCardDefinitions' from PLAYER: if it is not EMPTY:
	//
	if ( ( ! myRepeatedPtrCards.empty() ) && ( cardValueRepeated > 0 ) )
	{

		// Save inside the Hand: the CARD*s
		//
		myHand.SetMyDefinitionCardsThatDefineTheHandTypeName( myRepeatedPtrCards );

		/////& std::cout << "\n**********TRUE, es un THREE OF A KIND***********************\n -> TERMINÓ: const bool CardManager::VerifyThreeOfAKind( Hand & myHand )\n"<< std::flush;
		// Return
		//
		return true;

	}//End if ( ! myRepeatedPtrCards.empty() )

	/////& std::cout << "\n****************FALSE, NO es un THREE OF A KIND*****************\n -> TERMINÓ: const bool CardManager::VerifyThreeOfAKind( Hand & myHand )\n"<< std::flush;
	// Return
	//
	return false;

}//End Method


/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForThreeOfAKind( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:

	//				It is already correctly FILLED!!!!!!!!!!!!!!!!!!! (function that MADE THAT WORK:
	//
	//			CardManager::VerifyThreeOfAKind(...)
	//
	//			)

	//					All Cards, but in Descendent ORDER.
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//
	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );
	//
	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_THREE_OF_A_KIND_NAME_ESP" + " " + Value of Card
	//				Example:	"THREE Aces (A)", "TRES J"
	//
	//				.1-	Condition: Get one of THOSE REPEATED CARDS:
	//
	std::vector < Card* > &myVectorRefToHandDefinitionCards = (myPlayer.GetMyHand())->GetMyDefinitionCardsThatDefineTheHandTypeName();
	//
	//
	string outputLine1 = _THREE_OF_A_KIND_NAME_ESP;
	outputLine1 += " ";
	//
	/// Before:	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetShortName();	// CARD NUMBER in PAIR 1 [CARDS: 0 1 ]	 // END...
	//	Upgrade: Long Name in Spanish, PLURAL:
	//
	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetLongNameEspanishPlural();	// CARD NUMBER in PAIR 1 [CARDS: 0 1 ]	 // END...
	//
//	outputLine1 += " de ";
//	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	// Set that OUTPUT-LINE_1 inside the PLAYER'S OBJECT:
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//						Cards that are NOT inside the 'HAND DEFINITION' LIST
	//
	/// Before it was:	Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	//	New Implementation:
	//
	std::vector< Card* > &myVectorRefToHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does have just ONE  ('NOT DEFINITION CARD').
	//
	myVectorRefToHandNotDefinitionCards.clear();
	//
	// .3-	Let's search for the DIFFERENT CARDs:
	// =>	TWO (2) DIFFERENT CARDS, in the COMPARISON between:
	//
	//			Card* (& myReferenceToArrayHandCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//		AND
	//			'myVectorRefToHandDefinitionCards'
	//
	//	Let's COMPARE them!
	//	a)	Reference to HAND CARDS (ALL of them):
	//
	Card* (& myReferenceToArrayHandCards)[ _MAX_CARD_PER_HAND_COUNT ] = (* (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand() );
	//
	//	b)	COMPARISON (described previously):
	//
	//	Compare, and STORE THE RESULT inside the VECTOR:	'myVectorRefToHandNotDefinitionCards'
	//
	UtilFunctions::SetAVectorComparison( (Card* (&) [ _MAX_CARD_PER_HAND_COUNT ]) myReferenceToArrayHandCards, myVectorRefToHandDefinitionCards, myVectorRefToHandNotDefinitionCards, false ); // DIFFERENT Ocurrences <=> Different Elements


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _THREE_OF_A_KIND_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _THREE_OF_A_KIND_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _THREE_OF_A_KIND_NAME_ESP );

}//End Method



	/**3-	****************TWO PAIRS****************** VALUE = 2**/

/**
 * Verifies that: 	There are TWO (2) PAIRs: of 2 Cards EACH, (that are the SAME VALUE).
 *
 * *** PAIR ONE
 * *** PAIR TWO
 *
 * Return:
 * 	->	True
 * 	->	False
 *
 * 	ALSO RETURNS:
 *
 * 	Updated VECTOR OF CARDS: that define the HAND.
 */
const bool CardManager::VerifyTwoPairs( Hand & myHand )
{

	//	Necessary INPUTS:
	//	Save the REPEATED sCARD*s inside the VECTOR:	MyHandCardDefinitions
	//
	//	1-	First PAIR 1: Repeated Card*s
	//
	std::vector <Card *> myRepeatedPair1PtrCards;
	//
	//	2-	PAIR:	2 of a Kind: Repeated Card*s
	//
	std::vector <Card *> myRepeatedPair2PtrCards;

	// 0-	Necessary aux Variables
	//
	const int PAIR = 2;

	// 1-	PAIR one:
	//
	const int cardValueOfFirstPair = VerifySomeOfAKind ( myHand, PAIR, -1, myRepeatedPair1PtrCards );


	// Is there a ONE PAIR ?
	//
	if ( cardValueOfFirstPair <= 0 )
	{

		return false;

	}//End if ( cardValueOfFirstPair <= 0 )
	else
	{

		// Is there a SECOND PAIR ?
		//
		const int cardValueOfSecondPair = VerifySomeOfAKind ( myHand, PAIR, cardValueOfFirstPair, myRepeatedPair2PtrCards );


		// If there is a PAIR (and there was another PAIR...): it is a 2 PAIRS!!!!!:
		//
		if ( (cardValueOfSecondPair > 0 ) && (! myRepeatedPair1PtrCards.empty() ) && (! myRepeatedPair2PtrCards.empty() ) )
		{

			// Full House:
			// Save the (WHALES?!): Not!: Save the all VECTORS ( UNITE THEM FIRST! )
			//
			std::vector< Card* > myVector3Result;
			//
			UtilFunctions::ConcatenateTwoVectorsAandBAndAddToC( myRepeatedPair1PtrCards, myRepeatedPair2PtrCards, myVector3Result );
			//
			//
			// Save inside the Hand: the CARD*s
			//
			myHand.SetMyDefinitionCardsThatDefineTheHandTypeName( myVector3Result );

			/////& std::cout << "\n*********************************\n -> TERMINÓ: const bool CardManager::VerifyTwoPairs( Hand & myHand )\n"<< std::flush;
			// Return:	It is THAT Hand!:
			//
			return true;

		}
		else
		{

			/////& std::cout << "\n*********************************\n -> TERMINÓ: const bool CardManager::VerifyTwoPairs( Hand & myHand )\n"<< std::flush;

			// Return:	It is NOT (that Hand).
			//
			return false;

		}//End Veredict

	}//End else

}//End Method



/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForTwoPairs( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:

	//				It is already correctly FILLED!!!!!!!!!!!!!!!!!!! BY the funcion called before:
	//
	//				'CardManager::VerifyTwoPairs( Hand & myHand )'
	//
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//
	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );
	//
	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_TWO_PAIRS_NAME_ESP" + " " + Value of Card
	//				Example:	"FOUR Aces (A)"
	//
	//				.1-	Condition: Get one of THOSE REPEATED CARDS:
	//
	std::vector < Card* > &myVectorRefToHandDefinitionCards = (myPlayer.GetMyHand())->GetMyDefinitionCardsThatDefineTheHandTypeName();
	//
	// #define _TWO_PAIRS_NAME_ESP			"DOS PARES:"						// [..Card Number in PAIR ONE, ..Card Number in PAIR TWO]
	// #define _ONE_PAIR_NAME_ESP			"PAR de"							// [..Card Number in PAIR]

	//"DOS PARES:" + " " + "PAR de" +  CARD NUMBER pair 1 + "; " + "PAR de" +  CARD NUMBER pair 2
	//(_TWO_PAIRS_NAME_ESP + " ")	+=	_ONE_PAIR_NAME_ESP	+= " " +=	CARD NUMBER pair 1	+=	"; "	+=	_ONE_PAIR_NAME_ESP	+= " " +=	CARD NUMBER pair 1
	//
	string outputLine1 =_TWO_PAIRS_NAME_ESP;
	outputLine1 += " ";
	outputLine1 += _ONE_PAIR_NAME_ESP;
	outputLine1 += " ";
	//
	/// Before:	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetShortName();	// CARD NUMBER in PAIR 1 [CARDS: 0 1 ]
	//	Upgrade: Long Name in Spanish, PLURAL:
	//
	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetLongNameEspanishPlural();	// CARD NUMBER in PAIR 1 [CARDS: 0 1 ]
	//
	outputLine1 += "; y ";
	outputLine1 += _ONE_PAIR_NAME_ESP;
	outputLine1 += " ";
	//
	/// Before:	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 2 ) )->GetShortName();	// CARD NUMBER in PAIR 2 [CARDS: 2 3 ]		// END.
	//	Upgrade: Long Name in Spanish, PLURAL:
	//
	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 2 ) )->GetLongNameEspanishPlural();	// CARD NUMBER in PAIR 2 [CARDS: 2 3 ]		// END.
	//
	//
//	outputLine1 += " de ";
//	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	// Set that OUTPUT-LINE_1 inside the PLAYER'S OBJECT:
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//
	/// Before it was:	Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	//	New Implementation:
	//
	std::vector< Card* > &myVectorRefToHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does have just ONE  ('NOT DEFINITION CARD').
	//
	myVectorRefToHandNotDefinitionCards.clear();
	//
	// .3-	Let's search for that ONE CARD:
	// =>	It is the ONE DIFFERENT CARD, in the COMPARISON between:
	//
	//			Card* (& myReferenceToArrayHandCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//		AND
	//			'myVectorRefToHandDefinitionCards'
	//
	//	Let's COMPARE them!
	//	a)	Reference to HAND CARDS (ALL of them):
	//
	Card* (& myReferenceToArrayHandCards)[ _MAX_CARD_PER_HAND_COUNT ] = (* (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand() );
	//
	//	b)	COMPARISON (described previously):
	//
	//	Compare, and STORE THE RESULT inside the VECTOR:	'myVectorRefToHandNotDefinitionCards'
	//
	UtilFunctions::SetAVectorComparison( (Card* (&) [ _MAX_CARD_PER_HAND_COUNT ]) myReferenceToArrayHandCards, myVectorRefToHandDefinitionCards, myVectorRefToHandNotDefinitionCards, false ); // DIFFERENT Ocurrences <=> Different Elements


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _TWO_PAIRS_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _TWO_PAIRS_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _TWO_PAIRS_NAME_ESP );

}//End Method



	/**2-	****************ONE PAIR****************** VALUE = 1**/


/**
 * Verifies that: 	There is an: ONE (1) PAIR: of 2 Cards that are the SAME VALUE.
 *
 * Return:
 * 	->	True
 * 	->	False
 * 	ALSO RETURNS:
 *
 * 	Updated VECTOR OF CARDS: that define the HAND.
 */
const bool CardManager::VerifyOnePair( Hand & myHand )
{

	//	Necessary INPUTS:
	//	Save the REPEATED sCARD*s inside the VECTOR:	MyHandCardDefinitions
	//
	//	1-	First PAIR 1: Repeated Card*s
	//
	std::vector <Card *> myRepeatedPairPtrCards;

	// 1-	PAIR:
	//
	const int cardValueRepeated = VerifySomeOfAKind ( myHand, 2, -1, myRepeatedPairPtrCards );


	// If there is a PAIR (and there was another PAIR...): it is a 2 PAIRS!!!!!:
	//
	if ( (cardValueRepeated > 0 ) && (! myRepeatedPairPtrCards.empty() ) )
	{

		// We have a HAND!
		// Save the (WHALES?!): Not!: Save the the VECTOR.
		//
		// Save inside the Hand: the CARD*s
		//
		myHand.SetMyDefinitionCardsThatDefineTheHandTypeName( myRepeatedPairPtrCards );

		/////& std::cout << "\n*********************************\n -> TERMINÓ: const bool CardManager::VerifyOnePair( Hand & myHand )\n"<< std::flush;

		// Return:	It is THAT Hand!:
		//
		return true;

	}
	else
	{

		/////& std::cout << "\n*********************************\n -> TERMINÓ: const bool CardManager::VerifyOnePair( Hand & myHand )\n"<< std::flush;

		// Return:	It is NOT (that Hand).
		//
		return false;

	}//End Veredict

}//End Method


/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForOnePair( Player &myPlayer )
{

	/////& std::cout << "\n\n -> (INICIANDO): CardManager::SetHandAndHandTypeAttributesForOnePair( Player &myPlayer )\n"<< std::flush;

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:

	//				It is already correctly FILLED!!!!!!!!!!!!!!!!!!! BY the funcion called before:
	//
	//				'CardManager::VerifyTwoPairs( Hand & myHand )'
	//
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//
	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	/// THIS IS NOT NECESSARY IN THIS CASE:		(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );
	//
	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_ONE_PAIR_NAME_ESP" + " " + Value of Card
	//				Example:	"PAR de Aces (A)"
	//
	//				.1-	Condition: Get one of THOSE REPEATED CARDS:
	//
	std::vector < Card* > &myVectorRefToHandDefinitionCards = (myPlayer.GetMyHand())->GetMyDefinitionCardsThatDefineTheHandTypeName();
	//
	// #define _ONE_PAIR_NAME_ESP			"PAR de"							// [..Card Number in PAIR]

	//	"PAR de" +  CARD NUMBER pair 1
	//	(_ONE_PAIR_NAME_ESP + " ")	+=	CARD NUMBER pair 1
	//
	string outputLine1 =_ONE_PAIR_NAME_ESP;
	outputLine1 += " ";
	//
	/// Before:	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetShortName();	// CARD NUMBER in PAIR 1 [CARDS: 0 1 ]	 // END...
	//	Upgrade: Long Name in Spanish, PLURAL:
	//
	outputLine1 += ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetLongNameEspanishPlural();	// CARD NUMBER in PAIR 1 [CARDS: 0 1 ]	 // END...
	//
	//
	/////std::cout << "----\n--\n---\n--\n---------------->( myVectorRefToHandDefinitionCards.at( 0 ) )->GetName(); = [[[[[[[ " << ( myVectorRefToHandDefinitionCards.at( 0 ) )->GetName() << " ]]]]]]]]]\n\n\n\n" ;
	//
//	outputLine1 += " de ";
//	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ])->GetMyCardTypeNonConst()).GetLongName();
	//
	// Set that OUTPUT-LINE_1 inside the PLAYER'S OBJECT:
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//
	/// Before it was:	Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	//	New Implementation:
	//
	std::vector< Card* > &myVectorRefToHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does have THREE: ('NOT DEFINITION CARD's).
	//
	myVectorRefToHandNotDefinitionCards.clear();
	//
	// .3-	Let's search for those THREE CARDs:
	// =>	There are THREE (3) DIFFERENT CARDs, in the COMPARISON between:
	//
	//			Card* (& myReferenceToArrayHandCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();
	//		AND
	//			'myVectorRefToHandDefinitionCards'
	//
	//	Let's COMPARE them!
	//	a)	Reference to HAND CARDS (ALL of them):
	//
	Card* (& myReferenceToArrayHandCards)[ _MAX_CARD_PER_HAND_COUNT ] = (* (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand() );
	//
	//	b)	COMPARISON (described previously):
	//
	//	Compare, and STORE THE RESULT inside the VECTOR:	'myVectorRefToHandNotDefinitionCards'
	//
	UtilFunctions::SetAVectorComparison( (Card* (&) [ _MAX_CARD_PER_HAND_COUNT ]) myReferenceToArrayHandCards, myVectorRefToHandDefinitionCards, myVectorRefToHandNotDefinitionCards, false ); // DIFFERENT Ocurrences <=> Different Elements


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _ONE_PAIR_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _ONE_PAIR_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _ONE_PAIR_NAME_ESP );

}//End Method



	/**1-	****************HIGH CARD****************** VALUE = 0**/


	// If there is no other HAND TYPE that fits the Player's Hand... then it is called:
	// = HIGH CARD.


/**
 * Fully Initialize all HAND and HAND_TYPE:  Attributes & Pointers
 */
void CardManager::SetHandAndHandTypeAttributesForHighCard( Player &myPlayer )
{

	//	1-	FILL IN:	{ HAND }
	//
	//		.1-	Definition CARDS:
	//					All Cards, but in Descendent ORDER.
	//
	Card* (* myPtrHandDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand();

	//	 			.1.1-	Player myPlayer:		Card* (& myP1PtrCards)[ _MAX_CARD_PER_HAND_COUNT ]
	//						Sort Cards (Desc)
	//
	UtilFunctions::SortCards( *myPtrHandDefinitionCards, false );
	//
	//	 				.1.1.1-	Copy this array to:  CARDS that 'define the Hand'.
	//
	(myPlayer.GetMyHand())->SetMyDefinitionCardsThatDefineTheHandTypeName( *myPtrHandDefinitionCards );

	//				.1.2-	Copy the Pointer: to the Player:
	//		It is done, because it is a Pointer.

	//		.2-	OutputMyGameLine1:	"_HIGH_CARD_NAME_ESP" + " " + Type Of Card
	// #define _HIGH_CARD_NAME_ESP			"HIGH CARD"			// [..HIGHEST 'Card Number', ..Card Type in Hand]
	//				Example:	"HIGH CARD 8 de DIAMOND"
	//
	string outputLine1 =_HIGH_CARD_NAME_ESP;
	outputLine1 += " ";
	outputLine1 += ( (* myPtrHandDefinitionCards )[ 0 ] )->GetShortName();
	outputLine1 += " de ";
	outputLine1 += (( (* myPtrHandDefinitionCards )[ 0 ] )->GetMyCardTypeNonConst()).GetLongName();
	//
	(myPlayer.GetMyHand())->SetOutputMyGameLine1( outputLine1 );

	//		.3-	FILL IN:	NOT - Definition CARDS:
	//						None.
	//	There are not. nullptr.
	//
	/// Before it was:	 Card* (* myPtrHandNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	// New implementation:
	//
	std::vector< Card* > &myPtrHandNotDefinitionCards = (myPlayer.GetMyHand())->GetMyNotDefinitionCards();
	//
	// Set everything to   nullptr	:	Because this HAND does not have 'NOT DEFINITION CARDS'.
	//
	myPtrHandNotDefinitionCards.clear();


	//	Hand Type Attributes
	//
	HandType* myPtrHandType = (myPlayer.GetMyHand())->GetMyHandType();

	//	2-	FILL IN:	{ HAND TYPE }
	//
	myPtrHandType->SetId( 1 );
	//
	//		.1-	Hierarchy Value.
	//
	myPtrHandType->SetHierarchyValue( _HIGH_CARD_VALUE );
	//
	//		.2-	_name
	//
	myPtrHandType->SetName( _HIGH_CARD_NAME );
	//
	//		.3-	PrinterFriendlyName
	//
	myPtrHandType->SetPrinterFriendlyName( _HIGH_CARD_NAME_ESP );

}//End Method


/**************** UTILITIES *******************/

/**
 * Verifies that all Cards are the same Type: SPADE or HEART or CLUB or DIAMOND.
 */
const bool CardManager::VerifyAllCardsAreTheSameType( Card * (&myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ] )
{

	// Auxiliar temp variable:
	// Pointer to CARD TYPE:
	//
	CardType*  myCardType = &(myCardsToPlayHand[ 0 ]->GetMyCardTypeNonConst());
	//
	// NAME (short = S, D, H, C) of that CARD TYPE:
	//
	const std::string MY_CARD_TYPE_SHORT_NAME = myCardType->GetShortName();


	// Loop to check if all Cards are the same type:
	//
	for (int i = 1; i < _MAX_CARD_PER_HAND_COUNT; i++)
	{

		// Update Card:
		//
		// Check the Type of EVERY Card:
		//
		if ( MY_CARD_TYPE_SHORT_NAME != myCardsToPlayHand[ i ]->GetMyCardTypeNonConst().GetShortName() )
		{

			// Not equal; end this Loop.
			//
			return false;

		}//End if

	}//End for

	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINÓ: const bool CardManager::VerifyAllCardsAreTheSameType( Card * (&myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ] )"<< std::flush;

	// Are the same type:
	//
	return true;

}//End Method


/**
 * Verifies that all Cards are the in ASCENDING ORDER (sorted by their 'values').
 * RETURNS:
 * ->	'initialCardValue' of the Sequence 	[i.e.:  "1"...	 FOR SEQUENCE: [1, 2, 3, 4, 5] ].
 * ->	0 if FALSE <=>			There is NOOOOO Sequence.
 */
const int CardManager::VerifyAllCardsAreSortedInPerfectAscendingOrderAndReturnCardValue( Hand &myHand )
{

	// Initial Card Value = _CARD_2_VALUE;
	//
	// Loop to check if THAT CARD is there in this Player's Hand:
	//
	for (int initialCardValue = _CARD_2_VALUE; initialCardValue < _CARD_A_VALUE; initialCardValue++)
	{

		// Check every posible value
		//
		if ( VerifyAllCardsAreSortedInPerfectAscendingOrder( myHand, initialCardValue ) )
		{

			/////& std::cout << "\n*********************************\n -> TERMINÓ: const int CardManager::VerifyAllCardsAreSortedInPerfectAscendingOrderAndReturnCardValue( Hand &myHand )\n"<< std::flush;
			// Found (a Sequence):
			//
			return initialCardValue;

		}//End if ( VerifyAllCardsAreSortedInPerfectAscendingOrder

	}//End for

	/////& std::cout << "\n*********************************\n -> TERMINÓ: const int CardManager::VerifyAllCardsAreSortedInPerfectAscendingOrderAndReturnCardValue( Hand &myHand )\n"<< std::flush;

	// Not Found
	//
	return 0;

}//End Method


/**
 * Verifies that all Cards are the in ASCENDING ORDER (sorted by their 'values').
 */
const bool CardManager::VerifyAllCardsAreSortedInPerfectAscendingOrder( Hand &myHand, const int &initialCardValue )
{

	// Loop to check if THAT CARD is there in this Player's Hand:
	//
	for (int i = 0; i < _MAX_CARD_PER_HAND_COUNT; i++)
	{

		// Check: is THAT CARD there?  In this Player's Hand:
		//
		if ( ! myHand.GetCardFromMyHandWithValue( initialCardValue + i ) )
		{

			// It is Not there; end this Loop.
			//
			return false;

		}//End if

	}//End for

	// All Cards' Values Were in Perfect Ascending Order: +1:  1,2,3,4,5,6,7,8,9,10,, ETC...
	//
	return true;

}//End Method


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
const int CardManager::VerifySomeOfAKind( Hand & myHand, const int &COUNTED_OCURRENCES,
											const int &EXCLUDE_THIS_VALUE,
											std::vector < Card* > &myRepeatedFoundCards )
{

	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> -> INICIANDO: CardManager::VerifySomeOfAKind(...)\n"<< std::flush;

	// Initialize the (Reference &, return..) VECTOR to NOTHING:
	//
	myRepeatedFoundCards.clear();

	//
	// * A number of 'COUNTED_OCURRENCES' (Objects)  MUST have the SAME VALUE.
	//
	// Initial Card Value = _CARD_2_VALUE;
	//
	Card * (* myCardsInThisHand )[ _MAX_CARD_PER_HAND_COUNT ] = myHand.GetArrayOfCardsFromMyHand();

	/////& std::cout << "\n---------------------->>>>>>>>>\n -> DENTRO DE:: CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( Player &myPlayer )\n -> -> -> 	[[INICIANDO, ojo aca se cae,,.. ver si sale TERMINANDO...]]::\n \n EN: CardManager::VerifySomeOfAKind (...) ->>> Pudo ejecutar LINEA: Card * (* myCardsInThisHand )[ _MAX_CARD_PER_HAND_COUNT ] = myHand.GetArrayOfCardsFromMyHand();;;;;;;;;;;; \n"<< std::flush;

	//
	// Aux var: Card Value:
	//
	int cardFoundValue = 0;
	//
	// Loop to check if THAT CARD is there in this Player's Hand: A Number of times:
	//
	for (int i = 0; i < _MAX_CARD_PER_HAND_COUNT; i++)
	{

		///// cardFoundValue = i;	 // (*(myHand.GetArrayOfCardsFromMyHand()))[ i ]->GetValue(); //   ->GetValue();
		//
		cardFoundValue = (*(myHand.GetArrayOfCardsFromMyHand()))[ i ]->GetValue(); //   ->GetValue();

		// Check every posible value
		//
		if ( cardFoundValue != EXCLUDE_THIS_VALUE )
		{

			// Count Ocurrences
			//
			if ( CountHowManyCardsAreThereWithThisValue( myCardsInThisHand, cardFoundValue, myRepeatedFoundCards ) == COUNTED_OCURRENCES )
			{

				/////& std::cout << "\n*************VerifySomeOfAKind**** Es decir: '" << COUNTED_OCURRENCES << "of A Kind' ************ => RETURN: TRUE,  [ cardFoundValue = " << cardFoundValue << " ] *********************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINANDO: CardManager::VerifySomeOfAKind(...)\n"<< std::flush;

				// Found it:
				//
				return cardFoundValue;

			}//End if ( CountHowManyCardsAreThereWithThisValue

		}//End if ( cardValue != EXCLUDE_THIS_VALUE )

	}//End for

	/////& std::cout << "\n*****************VerifySomeOfAKind**** Es decir: '" << COUNTED_OCURRENCES << "of A Kind' *****************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINANDO: (CARD OCCURRENCES:  NOT FOUND) CardManager::VerifySomeOfAKind(...)\n"<< std::flush;


	// Not Found: 	Return Zero 0:
	//
	// Initialize the (Reference &, return..) VECTOR to NOTHING:
	//
	myRepeatedFoundCards.clear();
	//
	return 0;

}//End Method


///**
// * Verifies that: 	There are SOME Cards that are the SAME VALUE.
// * NOTE: It is FASTER to Check Cards by Value... rather than by their 'SHORT NAMES'.
// * Return:
// * 	->	CARD VALUE (if it is TRUE!)...
// * 	->	0 ('Number') : If Not.
// */
//const int & CardManager::CountHowManyCardsAreThereWithThisValue( Card * (* myCardsInThisHand)[ _MAX_CARD_PER_HAND_COUNT ], const int &cardValue )
//{
//
//	// * A number of 'COUNTED_OCURRENCES' (Objects)  MUST have the SAME VALUE.
//	// Return Value:
//	//
//	int cardOcurrences = 0;
//
//	// Loop throght all the Player's Cards Hand:
//	//
//	for (int i = 0; i < _MAX_CARDS_PER_HAND; i++)
//	{
//
//		// Count CARD ocurrences inside the PLAYER'S HAND:
//		//
//		if ( ((* myCardsInThisHand )[ i ])->GetValue() == cardValue )
//		{
//
//			// Found +1:	Increment +1
//			//
//			cardOcurrences++;
//
//		}//End if ( (* myCardsInThisHand[ i ]).GetValue() == cardValue )
//
//	}//End for
//
//	// Not Found: 	(Return Zero 0), Otherwise: Return a certain value:
//	//
//	return cardOcurrences;
//
//}//End Method




/**
 * Verifies that: 	There are SOME Cards that are the SAME VALUE.
 * NOTE: It is FASTER to Check Cards by Value... rather than by their 'SHORT NAMES'.
 * Return:
 * 	->	CARD OCURRENCES inside the HAND (if it is TRUE!)...
 * 	->	0 ('Number') : If Not.
 */
const int CardManager::CountHowManyCardsAreThereWithThisValue( Card * (* myCardsInThisHand)[ _MAX_CARD_PER_HAND_COUNT ], const int &cardValue, std::vector < Card* > &myFoundCards )
{

	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (INICIANDO) -> INICIA: CardManager::CountHowManyCardsAreThereWithThisValue(...)\n"<< std::flush;

	// * A number of 'COUNTED_OCURRENCES' (Objects)  MUST have the SAME VALUE.
	// Return Value:
	//
	int cardOcurrences = 0;
	//
	// Initialize the Vector of 'Found Ocurrences of Card wuth that VALUE':
	//
	myFoundCards.clear();


	// Loop throght all the Player's Cards Hand:
	//
	for (int i = 0; i < _MAX_CARDS_PER_HAND; i++)
	{

		// Count CARD ocurrences inside the PLAYER'S HAND:
		//
		if ( ((* myCardsInThisHand )[ i ])->GetValue() == cardValue )
		{

			/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (DENTRO DE): CardManager::CountHowManyCardsAreThereWithThisValue(...)\n -> ENTRÓ EN EL:::::::::::::\nif ( ((* myCardsInThisHand )[ i ])->GetValue() == cardValue ) ....\n -> -> -> ((* myCardsInThisHand )[ "<< i <<" ])->GetValue() = {{{ "<< ((* myCardsInThisHand )[ i ])->GetValue() << " }}}\n" << std::flush;

			// Found +1:	Increment +1
			//
			cardOcurrences++;
			//
			// Insert the < Card* > in the VECTOR:  'Found Cards*'
			//
			myFoundCards.push_back( (* myCardsInThisHand )[ i ] );

			/////& std::cout << "          -> cardOcurrences, luego de procesar esta ITERACION del LOOP FOR = " << cardOcurrences;

		}//End if ( (* myCardsInThisHand[ i ]).GetValue() == cardValue )

	}//End for

	/////& std::cout << "\n**********************************\n -> CardManager::CalculateAndDiscoverAndSetHandTypeFromPlayerCards( myPlayerP1 );\n -> (FINALIZANDO) -> TERMINANDO: CardManager::CountHowManyCardsAreThereWithThisValue(...)\n"<< std::flush;

	// Return the RESULTS: Not Found: 	(Return Zero 0), Otherwise: Return a certain value:
	//
	return cardOcurrences;

}//End Method


/*********************GETTERs & SETTERs***********************/


/**
 * Gets a 'Card' from the CATALOG LIST, given its VALUE and ITS associated CardType SHORT NAME.
 * For example: CARD VALUE = 9 ; CARD TYPE = SPADE (OPTIONS: { S , C , H , D }) => returns => 9S
 */
Card* CardManager::GetCard( const int &cardValue, const string &cardTypeShortName )
{

	std::cout << "\n**********************************\n -> -> (INICIANDO) -> INICIA: CardManager::GetCard( const int &cardValue, const string &cardTypeShortName )\n"<< std::flush;

	for (int i = 0; i < _MAX_CARDS_COUNT; i++ )
	{

		Card* myTempCard = &(CardManager::_myCardList[ i ]);
		CardType* myTempCardType = &( (* myTempCard).GetMyCardTypeNonConst() );

		// Id for the Card = Value
		//
		const int auxCardValue = (* myTempCard).GetValue();
		//
		//  Card Type SHORT Name:
		//
		const string auxCardTypeShortName = (* myTempCardType).GetShortName();


		// Found it?
		//
		if ( (cardValue == auxCardValue) && (cardTypeShortName == auxCardTypeShortName) )
		{

			// Found it:
			//
			return myTempCard;

		}//End if ( cardValue == auxCardValue)

	}//End for

	std::cout << "\n**********************************\n -> -> (TERMINANDO) -> TERMINÓ: CardManager::GetCard( const int &cardValue, const string &cardTypeShortName )\n"<< std::flush;

	//
	// If NOT FOUND: return nullptr-NULL
	//
	return nullptr;	 //	NULL;

}//End Method



/**
 * Gets a 'Card' from the CATALOG LIST, given its CARD SHORT NAME
 * ...and ITS associated CardType SHORT NAME.
 *
    * For example: CARD SHORT NAME = "9" ; CARD TYPE = SPADE (OPTIONS: { S , C , H , D }) => returns => 9S
 */
Card* CardManager::GetCard( const string &cardShortName, const string &cardTypeShortName )
{

	/////& std::cout << "\n**********************************\n -> -> (INICIANDO) -> INICIA: CardManager::GetCard( const string &cardShortName, const string &cardTypeShortName )\n"<< std::flush;

	for (int i = 0; i < _MAX_CARDS_COUNT; i++ )
	{

		Card* myTempCard = &(CardManager::_myCardList[ i ]);
		CardType* myTempCardType = &( (* myTempCard).GetMyCardTypeNonConst() );

		// Id for the Card = ShortName
		//
		const string auxCardShortName = (* myTempCard).GetShortName();
		//
		//  Card Type SHORT Name:
		//
		const string auxCardTypeShortName = (* myTempCardType).GetShortName();


		// Found it?
		//
		if ( (cardShortName == auxCardShortName) && (cardTypeShortName == auxCardTypeShortName) )
		{

			// Found it:
			//
			return myTempCard;

		}//End if ( (cardShortName == auxCardShortName)...

	}//End for

	std::cout << "\n**********************************\n -> -> (TERMINANDO) -> TERMINÓ: CardManager::GetCard( const string &cardShortName, const string &cardTypeShortName )\n"<< std::flush;

	//
	// If NOT FOUND: return nullptr-NULL
	//
	return nullptr;	 //	NULL

}//End Method



/**
 * Gets a 'CardType' from the CATALOG LIST, given its SHORT NAME
 * For example: { S , C , H , D }.
 */
CardType* CardManager::GetCardType( const string &cardTypeShortName )
{

	for (int i = 0; i < _MAX_CARD_TYPE_COUNT; i++ )
	{

		// Aux Variable:
		//
		CardType* myTempCardType = &( CardManager::_myCardTypeList[ i ] );

		//  Card Type SHORT Name:
		//
		const string auxCardTypeShortName = (* myTempCardType).GetShortName();


		// Found it?
		//
		if (cardTypeShortName == auxCardTypeShortName)
		{

			// Found it:
			//
			return myTempCardType;

		}//End if (cardTypeShortName == auxCardTypeShortName)

	}//End for
	//
	// If NOT FOUND: return nullptr-NULL
	//
	return nullptr;	 //	NULL

}//End Method




