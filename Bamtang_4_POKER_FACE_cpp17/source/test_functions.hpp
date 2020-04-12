#ifndef TEST_FUNCTIONS_H		// Guard for not including twice the same API / LIB.
#define TEST_FUNCTIONS_H

// Default C++ Includes:
//
#include <string>
#include <iostream>

// Custom includes
//
#include "card.hpp"
#include "card_manager.hpp"
#include "card_type.hpp"
#include "hand.hpp"
#include "hand_type.hpp"
#include "player.hpp"


using namespace std;


/********************STATIC MEMBER VARIABLES (i.e.: Class Attributes) DECLARATION***********************/
//
//Player CardManager::_myPlayerList[_MAX_PLAYERS_COUNT];
//CardType CardManager::_myCardTypeList[_MAX_CARD_TYPE_COUNT];
//Card CardManager::_myCardList[_MAX_CARDS_COUNT];
//string CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ENGLISH[_TOTAL_HAND_TYPES]; // = { _HIGH_CARD_NAME_ENG, _ONE_PAIR_NAME_ENG, _TWO_PAIRS_NAME_ENG, _THREE_OF_A_KIND_NAME_ENG, _STRAIGHT_NAME_ENG, _FLUSH_NAME_ENG, _FULL_HOUSE_NAME_ENG, _FOUR_OF_A_KIND_NAME_ENG, _STRAIGHT_FLUSH_NAME_ENG, _ROYAL_FLUSH_NAME_ENG };
//string CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL[_TOTAL_HAND_TYPES]; // = { _HIGH_CARD_NAME_ESP, _ONE_PAIR_NAME_ESP, _TWO_PAIRS_NAME_ESP, _THREE_OF_A_KIND_NAME_ESP, _STRAIGHT_NAME_ESP, _FLUSH_NAME_ESP, _FULL_HOUSE_NAME_ESP, _FOUR_OF_A_KIND_NAME_ESP, _STRAIGHT_FLUSH_NAME_ESP, _ROYAL_FLUSH_NAME_ESP };



void PrintGameObjectsData()
{

	std::cout.flush();
	// Test:
	//
	size_t arraySize = sizeof(CardManager::_myCardList)/sizeof(CardManager::_myCardList[0]);
	//
	for (size_t i = 0; i < arraySize; i++)
	{

		// Create a tmp aux variable:
		//
		Card myCard;
		myCard = CardManager::_myCardList[ i ];

		std::cout << i << " ** CardManager::_myCardList[ " << i << " ] = " << myCard.GetId() << endl;
		//
		std::cout << "       -> CardManager::_myCardList[ " << i << " ]._id = " <<  myCard.GetId() << endl;
		std::cout << "       -> CardManager::_myCardList[ " << i << " ]._name = " <<  myCard.GetShortName() << endl;
		std::cout << "       -> CardManager::_myCardList[ " << i << " ]._shortName = " <<  myCard.GetShortName() << endl;
		std::cout << "       -> CardManager::_myCardList[ " << i << " ]._longNameSpanishSingular = " <<  myCard.GetLongNameEspanishSingular() << endl;
		std::cout << "       -> CardManager::_myCardList[ " << i << " ]._longNameSpanishPlural = " <<  myCard.GetLongNameEspanishPlural() << endl;
		std::cout << "       -> CardManager::_myCardList[ " << i << " ]._value = " <<  myCard.GetValue() << endl;
		//
		//////////////
		// Print all CLass-Object Data:
		//
		char* pt = (char*)&myCard;
		//
		// Memory Address of this CARD Object:
		//
		printf("\n+++++Memory Address of this CARD object:+++++\n");
		//
		for (size_t i = 0; i < sizeof(myCard); ++i)
		{
		    printf("%1x", *(pt + i));
		}
		printf("\n\n");
		//
		//////////////
		//
		// CardType DATA (associated with THIS Card):
		//
		// Create a tmp aux variable:
		//
		CardType myTempAux = myCard.GetMyCardType();
		//
		std::cout << i << "       ##### CARD TYPE::::::::: CardType For THIS Card:\n->" << endl;
		//
		std::cout << "          ->-> CardManager::_myCardTypeList[ " << i << " ]._myCardType._id = " <<  myTempAux.GetId() << endl;
		std::cout << "          ->-> CardManager::_myCardTypeList[ " << i << " ]._myCardType._shortName = " <<  myTempAux.GetShortName() << endl;
		std::cout << "          ->-> CardManager::_myCardTypeList[ " << i << " ]._myCardType._longName = " <<  myTempAux.GetLongName() << endl;
		//
		//////////////
		// Print all Class-Object Data: FOR 'CardType DATA':
		//
		char* pt2 = (char*)&myTempAux;
		//
		// Memory Address of this CARD TYPE object:
		//
		printf("\n          ->-> +++++Memory Address of this CARD TYPE Object:+++++\n          ->-> ");
		//
		for (size_t i = 0; i < sizeof(myTempAux); ++i)
		{
		    printf("%1x", *(pt2 + i));
		}
		printf("\n\n");

		//////////////

	}//End for

	// Test:
	//
	arraySize = sizeof(CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL)/sizeof(CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL[0]);
	//
	for (size_t i = 0; i < arraySize; i++)
	{

		// Create a tmp aux variable:
		//
		string myTempAuxString = CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL[ i ];

		std::cout << i << " +++++ CardManager::_ARRAY_OF_HAND_TYPES_PRINTER_FRIENDLY_NAMES_ESPANOL[ " << i << " ] = " << myTempAuxString << endl;
		//
		//////////////
		// Print all CLass-Object Data:
		//
		char* pt = (char*)&myTempAuxString;

		for (size_t i = 0; i < sizeof(myTempAuxString); ++i)
		{
		    printf("%1x", *(pt + i));
		}
		printf("\n");

		//////////////

	}//End for


	// Test:
	//
	arraySize = sizeof(CardManager::_myCardTypeList)/sizeof(CardManager::_myCardTypeList[0]);
	//
	for (size_t i = 0; i < arraySize; i++)
	{

		// Create a tmp aux variable:
		//
		CardType myTempAux = CardManager::_myCardTypeList[ i ];

		std::cout << i << " ##### CardManager::_myCardTypeList[ " << i << " ] =>>>>>>> " << endl;
		//
		std::cout << "       -> CardManager::_myCardTypeList[ " << i << " ]._id = " <<  myTempAux.GetId() << endl;
		std::cout << "       -> CardManager::_myCardTypeList[ " << i << " ]._shortName = " <<  myTempAux.GetShortName() << endl;
		std::cout << "       -> CardManager::_myCardTypeList[ " << i << " ]._longName = " <<  myTempAux.GetLongName() << endl;
		//
		//////////////
		// Print all CLass-Object Data:
		//
		char* pt = (char*)&myTempAux;

		for (size_t i = 0; i < sizeof(myTempAux); ++i)
		{
		    printf("%1x", *(pt + i));
		}
		printf("\n\n");

		//////////////

	}//End for

	std::cout.flush();

}//End Function



/**
 * Prints data about CARDS in a PLAYERs HAND.
 */
void PrintPlayerCardsDetails( Player &myPlayer )
{

	std::cout.flush();
	std::cout << "\n\n\n\n **************** PrintPlayerCardsDetails( Player &myPlayer ) ****************\n\n **************** PrintPlayerCardsDetails( Player &myPlayer ) ****************\n\n **************** PrintPlayerCardsDetails( Player &myPlayer ) ****************" << std::endl;
	std::cout << "\n**************** PrintPlayerCardsDetails( Player <<<P" << myPlayer.GetId() << ">>> ) ****************\n\n" << std::flush;

	// Test:
	//
	//size_t arraySize = _MAX_CARDS_PER_HAND;
	//
	for (int i = 0; i < _MAX_CARDS_PER_HAND; i++)
	{

		// Create a tmp aux variable:
		//
		Card*  myPtrToCard;
		myPtrToCard = (*(myPlayer.GetMyHand())->GetArrayOfCardsFromMyHand())[ i ];

		std::cout << "\n\n **************** Player:   P" << myPlayer.GetId() << "****************" << std::endl;
		//
		std::cout << i << " ** myPlayer..._myCardList[ " << i << " ] = " << myPtrToCard->GetId() << endl;
		//
		std::cout << "       -> myPlayer..._myCardList[ " << i << " ]._id = " <<  myPtrToCard->GetId() << endl;
		std::cout << "       -> myPlayer..._myCardList[ " << i << " ]._shortName = " <<  myPtrToCard->GetShortName() << endl;
		std::cout << "       -> myPlayer..._myCardList[ " << i << " ]._longNameSpanishSingular = " <<  myPtrToCard->GetLongNameEspanishSingular() << endl;
		std::cout << "       -> myPlayer..._myCardList[ " << i << " ]._longNameSpanishPlural = " <<  myPtrToCard->GetLongNameEspanishPlural() << endl;
		//
		std::cout << "       -> myPlayer..._myCardList[ " << i << " ]._value = " <<  myPtrToCard->GetValue() << endl;
		//
		//////////////
		// Print all CLass-Object Data:
		//
		char* pt = (char*)&(*myPtrToCard);
		//
		// Memory Address of this CARD Object:
		//
		printf("\n+++++Memory Address of this CARD object:+++++\n");
		//
		for (size_t i = 0; i < sizeof(*myPtrToCard); ++i)
		{
		    printf("%1x", *(pt + i));
		}
		printf("\n\n");
		//
		//////////////
		//
		// CardType DATA (associated with THIS Card):
		//
		// Create a tmp aux variable:
		//
		CardType myTempAux = myPtrToCard->GetMyCardTypeNonConst();
		//
		std::cout << i << "       ##### CARD TYPE::::::::: CardType For THIS Card:\n->" << endl;
		//
		std::cout << "          ->-> myPlayer..._myCardList[ " << i << " ]._myCardType._id = " <<  myTempAux.GetId() << endl;
		std::cout << "          ->-> myPlayer..._myCardList[ " << i << " ]._myCardType._shortName = " <<  myTempAux.GetShortName() << endl;
		std::cout << "          ->-> myPlayer..._myCardList[ " << i << " ]._myCardType._longName = " <<  myTempAux.GetLongName() << endl;
		//
		//////////////
		// Print all Class-Object Data: FOR 'CardType DATA':
		//
		char* pt2 = (char*)&myTempAux;
		//
		// Memory Address of this CARD TYPE object:
		//
		printf("\n          ->-> +++++Memory Address of this CARD TYPE Object:+++++\n          ->-> ");
		//
		for (size_t i = 0; i < sizeof(myTempAux); ++i)
		{
		    printf("%1x", *(pt2 + i));
		}
		printf("\n\n");

		//////////////

	}//End for

	std::cout.flush();

}//End Method



/**
 * Prints data Vector of < CARD* >:  Definition or NOT DEF <Card*> s
 */
void PrintPlayerVectorOfCards( const int &playerNumber, std::vector <Card*> &myVectorOfCards, const string &nameOfTypeOfCardsToPrint )
{

	std::cout.flush();
	std::cout << "\n\n\n\n **************** PrintPlayerVectorOfCards ( Player " << playerNumber << " ) ****************\n\n **************** PrintPlayerCardsDetails( Player &myPlayer ) ****************\n\n **************** PrintPlayerVectorOfCards( Player &myPlayer ) ****************" << std::endl;
	std::cout << "\n**************** PrintPlayerVectorOfCards( Player <<<P" << playerNumber << ">>> ) ****************\n\n" << std::flush;

	// 1-	{ HAND }		Print Vector of CARDS
	//
	const int myVectorOfCardsSize = myVectorOfCards.size();
	//
	for ( int i = 0; i < myVectorOfCardsSize; i++ )
	{

		// Create a tmp aux variable:
		//
		Card*  myPtrToCard;
		myPtrToCard = myVectorOfCards.at( i );

		std::cout << "\n\n **************** Player:   P" << playerNumber << "****************" << std::endl;
		//
		std::cout << i << " ** myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ] = " << myPtrToCard->GetId() << endl;
		//
		std::cout << "       -> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._id = " <<  myPtrToCard->GetId() << endl;
		std::cout << "       -> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._name = " <<  myPtrToCard->GetShortName() << endl;
		//
		std::cout << "       -> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._shortName = " <<  myPtrToCard->GetShortName() << endl;
		std::cout << "       -> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._longNameSpanishSingular = " <<  myPtrToCard->GetLongNameEspanishSingular() << endl;
		std::cout << "       -> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._longNameSpanishPlural = " <<  myPtrToCard->GetLongNameEspanishPlural() << endl;
		//
		std::cout << "       -> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._value = " <<  myPtrToCard->GetValue() << endl;
		//
		//////////////
		// Print all CLass-Object Data:
		//
		char* pt = (char*)&(*myPtrToCard);
		//
		// Memory Address of this CARD Object:
		//
		printf("\n+++++Memory Address of this CARD object:+++++\n");
		//
		for (size_t i = 0; i < sizeof(*myPtrToCard); ++i)
		{
		    printf("%1x", *(pt + i));
		}
		printf("\n\n");
		//
		//////////////
		//
		// CardType DATA (associated with THIS Card):
		//
		// Create a tmp aux variable:
		//
		CardType myTempAux = myPtrToCard->GetMyCardTypeNonConst();
		//
		std::cout << i << "       ##### CARD TYPE::::::::: CardType For THIS Card:\n->" << endl;
		//
		std::cout << "          ->-> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._myCardType._id = " <<  myTempAux.GetId() << endl;
		std::cout << "          ->-> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._myCardType._shortName = " <<  myTempAux.GetShortName() << endl;
		std::cout << "          ->-> myPlayer..._my " << nameOfTypeOfCardsToPrint << " [ " << i << " ]._myCardType._longName = " <<  myTempAux.GetLongName() << endl;
		//
		//////////////
		// Print all Class-Object Data: FOR 'CardType DATA':
		//
		char* pt2 = (char*)&myTempAux;
		//
		// Memory Address of this CARD TYPE object:
		//
		printf("\n          ->-> +++++Memory Address of this CARD TYPE Object:+++++\n          ->-> ");
		//
		for (size_t i = 0; i < sizeof(myTempAux); ++i)
		{
		    printf("%1x", *(pt2 + i));
		}
		printf("\n\n");

		//////////////
		//
		std::cout.flush();

	}//End for

}//End Method



/**
 * [ Call this Method to see The HAND of the FULLY CONSTRUCTED Player, BEFORE TRYING TO Finally Play ]
 * Prints data about CARDS in a PLAYERs HAND.
 */
void PrintPlayerHandAndHandTypeCardsDetails( Player &myPlayer )
{

	std::cout.flush();
	std::cout << "\n\n\n\n **************** PrintPlayerHandAndHandTypeCardsDetails ( Player &myPlayer ) ****************\n\n **************** PrintPlayerCardsDetails( Player &myPlayer ) ****************\n\n **************** PrintPlayerHandAndHandTypeCardsDetails( Player &myPlayer ) ****************" << std::endl;
	std::cout << "\n**************** PrintPlayerCardsDetails( Player <<<P" << myPlayer.GetId() << ">>> ) ****************\n\n" << std::flush;

	// Create a tmp aux variable:
	//
	Hand*  myPtrToHand = myPlayer.GetMyHand();
	std::vector <Card *> (& myRefToVectorOfCardsHandDefinition) = myPtrToHand->GetMyDefinitionCardsThatDefineTheHandTypeName();


	// { HAND }
	//
	// 1-=======HAND===DEFINITION CARDS===========
	/**
	 * Prints data Vector of < CARD* >:  Definition or NOT DEF <Card*> s
	 */
	PrintPlayerVectorOfCards( myPlayer.GetId(), myRefToVectorOfCardsHandDefinition, "HAND===DEFINITION CARDS" );


	// { HAND }
	//
	// 1-=======HAND===NOT - DEFINITION CARDS===========
	//
	std::vector <Card *> (& myRefToVectorOfNotDefinitionCards) = myPtrToHand->GetMyNotDefinitionCards();
	/**
	 * Prints data Vector of < CARD* >:  Definition or NOT DEF <Card*> s
	 */
	PrintPlayerVectorOfCards( myPlayer.GetId(), myRefToVectorOfNotDefinitionCards, "HAND===NOT - DEFINITION CARDS" );


	// { HAND }
	//
	//	.2-	OUTPUT LINE 1 & 2
	//
	std::cout.flush();
	std::cout << "\n	//	.2-	OUTPUT LINE 1 & 2:\n	myPtrToHand->GetOutputMyGameLine1() = " << myPtrToHand->GetOutputMyGameLine1() << std::endl;
	std::cout << "\n	//	.2-	OUTPUT LINE 1 & 2:\n	myPtrToHand->GetOutputMyGameLine2() = " << myPtrToHand->GetOutputMyGameLine2() << std::endl;


	// 2-	{ HAND TYPE }	Print HAND TYPE Attributes:
	//
	HandType* myHandType = myPtrToHand->GetMyHandType();
	//
	//		.1-	id
	//
	std::cout << "\n	// 2-	{ HAND TYPE }	Print HAND TYPE Attributes:\n	myHandType->GetId() = " << myHandType->GetId() << std::endl;
	//
	//		.2-	hierarchy value
	//
	std::cout << "\n	// 2-	{ HAND TYPE }	Print HAND TYPE Attributes:\n	myHandType->GetHierarchyValue() = " << myHandType->GetHierarchyValue() << std::endl;
	//
	//		.3-	name
	//
	std::cout << "\n	// 2-	{ HAND TYPE }	Print HAND TYPE Attributes:\n	myHandType->GetName() = " << myHandType->GetName() << std::endl;
	//
	//		.4-	Printer Friendly Name
	//
	std::cout << "\n	// 2-	{ HAND TYPE }	Print HAND TYPE Attributes:\n	myHandType->GetPrinterFriendlyName()) = " << myHandType->GetPrinterFriendlyName() << std::endl;

	std::cout.flush();

}//End Method


#endif
