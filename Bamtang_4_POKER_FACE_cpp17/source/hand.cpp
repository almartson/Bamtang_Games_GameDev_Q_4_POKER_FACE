#include "hand.hpp"
#include <iostream>

// Constructor 1
//
Hand::Hand(const int &id, Card * (* myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ],
		  std::vector< Card* > &myDefinitionCardsThatDefineTheHandTypeName,
		  std::vector< Card* > &myNotDefinitionCards,
		  HandType*  myHandType)
{

  // Simple Attributes:
  //
  this->_id = id;
  this->_outputMyGameLine1 = "";
  this->_outputMyGameLine2 = "";
  //
  // 1- These are the Player's Cards:
  //
  // Copy Array: Item by item:		_myCardsToPlayHand
  //
  ////Unnecessary, because they are POINTERS!:  Hand::CopyArrayOfCards( this->_myCardsToPlayHand, myCardsToPlayHand );
  //
  // Pointers assignment:
  //
  this->_myCardsToPlayHand = myCardsToPlayHand;


  // 2- Define the Cards that are MOST IMPORTANT for the HAND NAME:
  //...(..and their Types are the CARD_TYPES to use for the HAND NAME, too...)
  //
  // Copy Array: Item by item:		myDefinitionCardsThatDefineTheHandTypeName
  //

  ////Unnecessary, because they are POINTERS!: Hand::CopyArrayOfCards( this->_myDefinitionCardsThatDefineTheHandTypeName, myDefinitionCardsThatDefineTheHandTypeName );
  //
  // Pointers assignment:
  //
  this->_myDefinitionCardsThatDefineTheHandTypeName = myDefinitionCardsThatDefineTheHandTypeName;


  // 3- Define the TYPE of Hand, its NAME and TOTAL VALUE:
  //
  this->_myHandType = myHandType;


  // zzz- OTHER attributes:
  //
  this->_myNotDefinitionCards = myNotDefinitionCards;
  //
  // Pointer to CARD*	: To Help to write the FINAL WINNER and LOSER's details:
  //
  // .1-	Highest DIFFERENT CARD
  //		...COMPARING: (HAND-DEFINITION):	 Card	{ P1 vs P2 }
  //		...and then:
  //		...COMPARING: (Not HAND-DEFINITION): Card	{ P1 vs P2 }
  //
  this->_myPtrToHighestDifferentCard = nullptr;

}//End Constructor


// Destructors
//
Hand::~Hand()
{
  //std::cout << "this->_myID = " << this->_myID << "\n";
  //std::cout << "this = (Original Object Memory Address & =) " << this << "\n";
  //std::cout << "this->_myNext = " << this->_myNext << "\n\n";
}


//**************************** Methods*********************************//

/**
 * Copies an Array of CARDs, into another. Pointer Shallow Copy (Not Deep).
 */
void Hand::CopyArrayOfCards( Card *  (* myArrayTarget)[ _MAX_CARD_PER_HAND_COUNT ], Card * (* myStartingArray)[ _MAX_CARD_PER_HAND_COUNT ] )
{

	for (int i = 0; i < _MAX_CARD_PER_HAND_COUNT; i++)
	{

		(*myArrayTarget)[ i ] = (*myStartingArray)[ i ];

	}//End for

}//End Function


/******************** GETTERs & SETTERs ***********************/

int &Hand::GetId()
{

	return this->_id;

}//End Method

void Hand::SetId(const int &id)
{

	this->_id = id;

}//End Method


const string &Hand::GetOutputMyGameLine1 ()
{

	return this->_outputMyGameLine1;

}//End Method

void Hand::SetOutputMyGameLine1 (const string &outputMyGameLine1)
{

	this->_outputMyGameLine1 = outputMyGameLine1;

}//End Method


const string &Hand::GetOutputMyGameLine2 ()
{

	return this->_outputMyGameLine2;

}//End Method

void Hand::SetOutputMyGameLine2 (const string &outputMyGameLine2)
{

	this->_outputMyGameLine2 = outputMyGameLine2;

}//End Method


/**
 * GET: _myPtrToHighestDifferentCard
 */
Card* &Hand::GetMyPtrToHighestDifferentCard()
{
	return this->_myPtrToHighestDifferentCard;

}//End Method

/**
 * SET: _myPtrToHighestDifferentCard
 */
void Hand::SetMyPtrToHighestDifferentCard(Card* &myPtrToHighestDifferentCard)
{
	this->_myPtrToHighestDifferentCard = myPtrToHighestDifferentCard;

}//End Method


/**
 * The 'Hand Type' that defines the Global Value, and Name of THIS HAND.
 */
HandType*  Hand::GetMyHandType()
{

  return ( this->_myHandType );

}//Ed Method


/**
 * Using the Hand, it GETS a CARD if it is there.
 * If it is not there: It returns nullptr;	 //	NULL
 * INPUT Parameter: Value.
 * Inside-Class INPUT value (this->attribute):   Card  _myCardsToPlayHand[ _MAX_CARD_PER_HAND_COUNT ]
 */
Card*  Hand::GetCardFromMyHandWithValue( const int &cardValue )
{

	// Auxiliary pointer to Card:
	//
	Card* myPtrToCard = nullptr;	 //	NULL


	// Check every Card value:
	//
	for (int i = 0; i < _MAX_CARD_PER_HAND_COUNT; i++)
	{

		// Update Card Pointer:
		//
		myPtrToCard = (*(this->_myCardsToPlayHand))[ i ];

		// Check every Card value:
		//
		if ( myPtrToCard->GetValue() == cardValue )
		{

			// Found it:
			//
			return myPtrToCard;

		}//End if ( myPtrToCard->GetValue() == cardValue )

	}//End for

	// If it was not found, return nullptr;	 //	NULL
	//
	return nullptr;	 //	NULL

}//End Method


/**
 * Using the Hand, it GETS a CARD if it is there.
 * If it is not there: It returns nullptr;	 //	NULL
 * INPUT Parameter: Index (0.. N-1) of the Array.
 * Inside-Class INPUT value (this->attribute):   Card  _myCardsToPlayHand[ _MAX_CARD_PER_HAND_COUNT ]
 */
Card*  Hand::GetCardFromMyHandWithIndexInArray( const int &cardIndexInArray )
{

	// Return a Pointer to the CARD with that [ index ] (from the array in this Object - Class):
	//
	return (*(this->_myCardsToPlayHand))[ cardIndexInArray ];

}//End Method



/**
 * Gets an Array of all Cards in the Player's Hand.
 * Getter for this attribute:	 Card  _myCardsToPlayHand[ _MAX_CARD_PER_HAND_COUNT ]
 */
Card * (* Hand::GetArrayOfCardsFromMyHand()) [ _MAX_CARD_PER_HAND_COUNT ]
{

	return ( this->_myCardsToPlayHand );

}//End Method


/**
 * Gets an Array of HAND-DEFINITION-CARDS in the Player's Hand.
 * Getter for this attribute:
 * 		std::vector< Card* >	_myDefinitionCardsThatDefineTheHandTypeName
 */
std::vector< Card* > &Hand::GetMyDefinitionCardsThatDefineTheHandTypeName()
{

	return ( this->_myDefinitionCardsThatDefineTheHandTypeName );

}//End Method

/**
 * Sets an Array of HAND-DEFINITION-CARDS in the Player's Hand.
 * Setter for this attribute:
 * 		std::vector< Card* > 	_myDefinitionCardsThatDefineTheHandTypeName
 */
void Hand::SetMyDefinitionCardsThatDefineTheHandTypeName( std::vector< Card* > &myDefinitionCardsThatDefineTheHandTypeName )
{

	this->_myDefinitionCardsThatDefineTheHandTypeName = myDefinitionCardsThatDefineTheHandTypeName;

}//End Method

/**
 * Sets an Array of HAND-DEFINITION-CARDS in the Player's Hand.
 * Setter for this attribute:
 * 		std::vector< Card* > 	_myDefinitionCardsThatDefineTheHandTypeName
 */
void Hand::SetMyDefinitionCardsThatDefineTheHandTypeName( Card * (& myDefinitionCardsThatDefineTheHandTypeName )[ _MAX_CARD_PER_HAND_COUNT ] )
{

	// Clear the array before.
	//
	this->_myDefinitionCardsThatDefineTheHandTypeName.clear();
	//
	// Set the values:
	//
	this->_myDefinitionCardsThatDefineTheHandTypeName.insert( this->_myDefinitionCardsThatDefineTheHandTypeName.end(), &myDefinitionCardsThatDefineTheHandTypeName[0], &myDefinitionCardsThatDefineTheHandTypeName[ _MAX_CARD_PER_HAND_COUNT ] );

}//End Method


/**
 * Gets an Array of NOT-DEFINITION Cards in the Player's Hand.
 * Getter for this attribute:
 * 		std::vector< Card* > 	_myNotDefinitionCards
 */
std::vector< Card* > &Hand::GetMyNotDefinitionCards()
{

	return ( this->_myNotDefinitionCards );

}//End Method

/**
 * Sets an Array of NOT-DEFINITION-CARDS in the Player's Hand.
 * Setter for this attribute:
 * 		std::vector< Card* > 	_myNotDefinitionCards
 */
void Hand::SetMyNotDefinitionCards( std::vector< Card* > &myNotDefinitionCards )
{

	// Clear it:
	//
	this->_myNotDefinitionCards.clear();
	//
	// Set:
	//
	this->_myNotDefinitionCards = myNotDefinitionCards;

}//End Method

/**
 * Sets an Array of NOT-DEFINITION-CARDS in the Player's Hand.
 * Setter for this attribute:
 * 		std::vector< Card* > 	_myNotDefinitionCards
 */
void Hand::SetMyNotDefinitionCards( Card * (&myNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] )
{

	// Clear it:
	//
	this->_myNotDefinitionCards.clear();
	//
	// Set the values:
	//
	this->_myNotDefinitionCards.insert( this->_myNotDefinitionCards.end(), &myNotDefinitionCards[0], &myNotDefinitionCards[ _MAX_CARD_PER_HAND_COUNT ] );

}//End Method






