#include "player.hpp"
//#include <iostream>


// Constructor 0: Empty default
//
Player::Player()
{

	this->_id = 0;

	// Set ALL Pointers (of this Class) to	nullptr;	 //	NULL
	//
	CreatePointersAndAssociatedObjects( false );

}//End Constructor


// Constructor 1
//
Player::Player(const int &id)
{
	// Note: (*this.) is EQUAL to: this->
	//
	this->_id = id;

	// Create Pointer and Objects. Leave them COnstructed, but with empty or 'Mock-like' values.
	//
	CreatePointersAndAssociatedObjects( true );
}

/**
 * Constructor friend:
 * if (initializeToNewOrNULL == TRUE) ---> It creates this Object's asscociated objects and Pointers
 * if (initializeToNewOrNULL == FALSE) ---> It sets all Pointers to:  nullptr;	 //	NULL
 */
void Player::CreatePointersAndAssociatedObjects( const bool &initializeToNewOrNULL )
{

	// Initialization mode:
	//
	if( initializeToNewOrNULL )
	{

		// It initializes to NEW every POINTER:
		//
		// Create an Object and a Pointer to it:
		//
		// Sub-Object needed to Build the HAND object:
		//
		/////Card *		myCardsToPlayHand[ _MAX_CARD_PER_HAND_COUNT ];
		/////Card *		(* myPtrCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ] = &myCardsToPlayHand;
		//
		Card *		(* myPtrCardsToPlayHand) = new Card * [ _MAX_CARD_PER_HAND_COUNT ];
		//
		/////Card * 		myDefinitionCardsThatDefineTheHandTypeName[ _MAX_CARD_PER_HAND_COUNT ];
		/////Card * 		(* myPtrDefinitionCardsThatDefineTheHandTypeName)[ _MAX_CARD_PER_HAND_COUNT ] = &myDefinitionCardsThatDefineTheHandTypeName;
		//
		///// BEFORE IT WAS: Card * 		(* myPtrDefinitionCardsThatDefineTheHandTypeName) = new Card * [ _MAX_CARD_PER_HAND_COUNT ];
		//
		//	Newer IMPLMENTATION:	VECTORS		e.g.: Pointer [ v=new vector<int>(a); ]
		//
		std::vector< Card* >	myDefinitionCardsThatDefineTheHandTypeName;
		//
		/////Card * 		myNotDefinitionCards[ _MAX_CARD_PER_HAND_COUNT ];
		/////Card *		(* myPtrNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] = &myNotDefinitionCards;
		//
		///// BEFORE IT WAS: Card *		(* myPtrNotDefinitionCards) = new Card * [ _MAX_CARD_PER_HAND_COUNT ];
		//
		//	Newer IMPLMENTATION:	VECTORS
		//
		std::vector< Card* >	myNotDefinitionCards;
		//
		/////HandType	myHandType( 0, 0, "IT IS NOT CORRECTLY SETTED YET", "IT IS NOT CORRECTLY SETTED YET" );
		/////HandType*	myPtrHandType = &myHandType;
		//
		HandType*	myPtrHandType = new HandType( 0, 0, "IT IS NOT CORRECTLY SETTED YET", "IT IS NOT CORRECTLY SETTED YET" );
		//
		// Now I can Contruct the Main object that groupes everybody:
		//
		Hand *	myHand = new Hand( 1,
				(Card *	(*)[ _MAX_CARD_PER_HAND_COUNT ]) myPtrCardsToPlayHand,
				myDefinitionCardsThatDefineTheHandTypeName,
				myNotDefinitionCards,
				myPtrHandType );
		//
		// Make this Object's Pointer: To POINT to => the HAND Object we have just created:
		//
		this->_myHand = myHand; 	 //&myHand;

	}//End if( initializeToNewOrNULL )
	else
	{

		// Set POINTERS to [nullptr;	 //	NULL]
		// Make this Object's Pointer: To POINT to => [nullptr;	 //	NULL].
		//
		this->_myHand = nullptr;	 //	NULL;

	}//End else if( initializeToNewOrNULL )

}//End Constructor


// Destructors
//
Player::~Player()
{
  //std::cout << "this->_myID = " << this->_myID << "\n";
  //std::cout << "this = (Original Object Memory Address & =) " << this << "\n";
  //std::cout << "this->_myNext = " << this->_myNext << "\n\n";
}


//**************************** Methods*********************************//


// _myID
//
int Player::GetId()
{

	return this->_id;

}//End Method


void Player::SetId(const int &id)
{
	this->_id = id;

}//End Method


Hand*  Player::GetMyHand()
{

 	return ( this->_myHand );

}//End Method


void Player::SetMyHand( Hand* myHand )
{

	this->_myHand = myHand;

}//End Method
