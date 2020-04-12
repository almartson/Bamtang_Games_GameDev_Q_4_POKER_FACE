#ifndef HAND_H		// Guard for not including twice the same API / LIB.
#define HAND_H

// Default C++ Includes:
//
#include <string>
#include <vector>
//
// My Custom Includes:
//
///Nope: #include "player.hpp"
#include "card.hpp"			// This DEFINES the Hand. Example: PAIR of: Aces (Card Value = 14)
/////#include "card_type.hpp"	// UNNECESSARY: Explanation: The Type of the Card can be Found By accesing it via the Attribute inside CARD OBJECT: This(CARD)->_myCardType....
///// Original Idea for this Include (DEPRECATED): This DEFINES the Hand. Example: PAIR of: Aces (Card Type = DIAMOND)
#include "hand_type.hpp"
//
// Utility
//
/////#include "util_functions.hpp"

using namespace std;


/**************Global Variables********************/

#define _MAX_CARD_PER_HAND_COUNT   5


/***************** Forward declarations & Function prototypes **********************/

class Card;
class HandType;
/// Nope: class CardType;	// We will access it via CARD Object... this-> _myCardType...



class Hand
{

  private:
  
  // attr

  int _id;

  // I will get the NAME ('Printer Friendly') of the HAND from its Attribute:
  //
  /**
   * LINE 1 (Output),
   * ...in a 'Printer-Friendly' fashion.
   * This will be printed in the end as LINE 1.
   *
   * Example: "HIGH CARD Ace"
   *
   * LINE 1 is:	THE NAME OF THE HAND + CARD (or CARD TYPE) NAME.
   * NOTE:		It will be filled AT THE BEGINNING: because it is the NAME of the HAND
   * ...(EASY VICTORY).
   */
  string _outputMyGameLine1;

  /**
   * LINE 2 (Output),
   * ...in a 'Printer-Friendly' fashion.
   * This will be printed in the end as LINE 2.
   *
   * Example: "Máxima carta 9"
   *
   * LINE 2 is: The MAXIMUM CARD (that does not form part of the HAND) that: in the COMPARISON
   * ...AGAINST the OTHER PLAYER: is BIGGER
   * (i.e.: The WINNER CARD, of the FINAL "BREAK-THE-DRAW" COMPARISON).
   *
   * NOTE:		It will be filled IN THE END of the GAME: because it is only necessary
   * ...when both PLAYERS have:
   * 	1-	...the SAME TYPE OF HAND
   * 	2-	...with the SAME CARDS (i.e.: VALUES are identical)
   *
   * ...and because of that: it is necessary to decide (break the TIE-DRAW) in an:
   * ...(HARD-DIFICULT VICTORY).
   */
  string _outputMyGameLine2;


  //Pointers to other Objects (from Classes)
  //

  /** Cards of the Player:
   * Most important Attribute of the Game, and Class.
  */
  Card* (* _myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ]; // = nullptr;


  /**
   * Cards that support the NAME of the Hand.
   * This will be used to Name the 'Printer Friendly Version' of the Hand.
   *
   * a) Name / Value of the CARD:	this->_myCardsThatDefineTheHandTypeName._value or ._name
   * ->
   * i.e.:	2, 3, 4, 5, 6, 7, 8, 9, 10 (T), Jack (J), Reina (Q), Rey (K), Ace (A).
   * e.g.: Name = "3" ... Value = 3.
   *
   * b) Type of the Card:			We will access it via CARD Object... this-> _myCardType...
   * ->
   * i.e.: C (Club), H (Heart) , D (Diamond), S (Spade).
   *
   * Example: PAIR of: Aces.
   * ..What Cards are part of that PAIR?  <=> (Card Value = 14,  Name = "14")
   *
   * CAUTION: This attribute may have some NULL.
   * We will check / validate with a 'if (this->_myCardsThatDefineTheHandTypeName != NULL)'....
   * Only the ones that are necessary to DEFINE the Name of the HandType: Will be there.
   * ...the rest => will be NULL.
  */
  std::vector< Card* > _myDefinitionCardsThatDefineTheHandTypeName; // = nullptr;
  //
  ////// Before it was:	 Card * (* _myDefinitionCardsThatDefineTheHandTypeName )[ _MAX_CARD_PER_HAND_COUNT ]; // = nullptr;

  /**
   * Pointer to (Card *): The HIGHEST {DIFFERENT} Card that makes this Player WIN, LOSE or DRAW:
   * ..When Comparing the CARDS of the WHOLE HAND:	 Card* (* _myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ]
   */
  Card* _myPtrToHighestDifferentCard;		 // = nullptr;


  /**
   * TL;TD:  In case of a apparent 	'DRAW'
   *
   * Cards that DO NOT support the NAME of the Hand.
   *
   * This Cards are independent to the HAND. They are called: "The Other" Cards.
   *
   * This Attribute will be used to Solve a Draw (i.e.: in the case: P1 & P2
   * ..have the same TYPE OF HAND, and THE SAME CARDS!!! (in the Hand))..
   * ..BUT:
   *
   *   There are OTHER CARDS in every Hand (because Most 'Hands' are defined just by 2 or 3 'Cards')
   *.....so the other 2 or 3 remaining CARDS will be HERE, to be used to DEFINE THE WINNER.
   *
   *
   * USAGE:  Read the comment of the former Attribute '_myDefinitionCardsThatDefineTheHandTypeName',
   * ...up above.
   *
   * CAUTION: This attribute may have some NULL.
   * We will check / validate with a 'if (this->_myNotDefinitionCards != NULL)'....
   * Only the ones that are necessary to DEFINE the Name of the HandType: Will be there.
   * ...the rest => will be NULL.
  */
  std::vector< Card* > _myNotDefinitionCards;	 // = nullptr;

  ///// Before it was:	 Card *  (* _myNotDefinitionCards )[ _MAX_CARD_PER_HAND_COUNT ]; // = nullptr;


  /** The 'Hand Type' that defines the Global Value, and Name of THIS HAND.
  */
  HandType* _myHandType;  //  = NULL; // = nullptr;
  
  
  // methods
  public:
  //
  // Constructors
  //
  // As an: Initialization List:
  //
//  Hand(const int &id,
//	  const Card  (&myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ],
//	  const Card  (&myDefinitionCardsThatDefineTheHandTypeName)[ _MAX_CARD_PER_HAND_COUNT ],
//	  HandType  &myHandType)
//  	  :
//		_id 						(id),
//		//_myCardsToPlayHand			(myCardsToPlayHand),
//		//_myDefinitionCardsThatDefineTheHandTypeName	(myDefinitionCardsThatDefineTheHandTypeName),
//		_myHandType					(myHandType)
//
//  {
//	  // Copy Array: Item by item:		_myCardsToPlayHand
//	  //
//	  CopyArrayAToOtherArrayB( myCardsToPlayHand, this->_myCardsToPlayHand );
//	  //
//	  // Copy Array: Item by item:		_myCardsToPlayHand
//	  //
//	  CopyArrayAToOtherArrayB( myDefinitionCardsThatDefineTheHandTypeName, this->_myDefinitionCardsThatDefineTheHandTypeName );
//
//	  //_myCardsToPlayHand			(myCardsToPlayHand),
//	  //_myDefinitionCardsThatDefineTheHandTypeName	(myDefinitionCardsThatDefineTheHandTypeName),
//
//  }//End Constructor


  Hand(const int &id, Card * (* myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ],
		  std::vector< Card* > &myDefinitionCardsThatDefineTheHandTypeName,
		  std::vector< Card* > &myNotDefinitionCards,
		  HandType*  myHandType);


  // As Objects, not Pointers:
  //
  /*Hand(const int &id, Card  myCardsToPlayHand[ _MAX_CARD_PER_HAND_COUNT ],
  		  Card  myDefinitionCardsThatDefineTheHandTypeName[ _MAX_CARD_PER_HAND_COUNT ],
  		  HandType*  myHandType);*/

  //Destructors
  //
  ~Hand();

  //*************************** Methods ***************************//


  void CopyArrayOfCards( Card *  (* myArrayTarget)[ _MAX_CARD_PER_HAND_COUNT ], Card * (* myStartingArray)[ _MAX_CARD_PER_HAND_COUNT ] );


  /******************** GETTERs & SETTERs ***********************/

  int &GetId();
  void SetId(const int &id);

  const string &GetOutputMyGameLine1 ();
  void SetOutputMyGameLine1 (const string &outputMyGameLine1);

  const string &GetOutputMyGameLine2 ();
  void SetOutputMyGameLine2 (const string &outputMyGameLine2);

  /**
   * myPtrToHighestDifferentCard
   */
  Card*	&GetMyPtrToHighestDifferentCard();
  //
  /**
   * SET: _myPtrToHighestDifferentCard
   */
  void SetMyPtrToHighestDifferentCard(Card* &myPtrToHighestDifferentCard);


  /**
   * The 'Hand Type' that defines the Global Value, and Name of THIS HAND.
   */
  HandType*  GetMyHandType();


  /**
   * Using the Hand, it gets a Card if it is there.
   * If it is not there: It returns NULL.
   * INPUT Parameter: Value.
   * Inside-Class INPUT value (this->attribute):   Card  _myCardsToPlayHand[ _MAX_CARD_PER_HAND_COUNT ]
   */
  Card*  GetCardFromMyHandWithValue( const int &cardValue );


  /**
   * Using the Hand, it GETS a CARD if it is there.
   * If it is not there: It returns NULL.
   * INPUT Parameter: Index (0.. N-1) of the Array.
   * Inside-Class INPUT value (this->attribute):   Card  _myCardsToPlayHand[ _MAX_CARD_PER_HAND_COUNT ]
   */
  Card*  GetCardFromMyHandWithIndexInArray( const int &cardIndexInArray );


  /**
   * Gets an Array of all Cards in the Player's Hand.
   * Getter for this attribute:
   * 		Card* (* _myCardsToPlayHand)[ _MAX_CARD_PER_HAND_COUNT ];
   */
  Card * (* GetArrayOfCardsFromMyHand()) [ _MAX_CARD_PER_HAND_COUNT ];


  /**
   * Gets an Array of HAND-DEFINITION-CARDS in the Player's Hand.
   * Getter for this attribute:
   * 		std::vector< Card* > 	_myDefinitionCardsThatDefineTheHandTypeName
   */
  std::vector< Card* > &GetMyDefinitionCardsThatDefineTheHandTypeName();
  //
  ///// Before: 	Card * (* GetArrayOfCardsThatDefineTheHandTypeName()) [ _MAX_CARD_PER_HAND_COUNT ];

  /**
   * Sets an Array of HAND-DEFINITION-CARDS in the Player's Hand.
   * Setter for this attribute:
   * 		std::vector< Card* > 	_myDefinitionCardsThatDefineTheHandTypeName
   */
  void SetMyDefinitionCardsThatDefineTheHandTypeName( std::vector< Card* > &myDefinitionCardsThatDefineTheHandTypeName );
  //
  //// Before: void SetMyDefinitionCardsThatDefineTheHandTypeName( Card * (& myDefinitionCardsThatDefineTheHandTypeName )[ _MAX_CARD_PER_HAND_COUNT ] );
  //
  // Another implementation (Method OVERLOAD):
  //
  void SetMyDefinitionCardsThatDefineTheHandTypeName( Card * (& myDefinitionCardsThatDefineTheHandTypeName )[ _MAX_CARD_PER_HAND_COUNT ] );


  /**
   * Gets an Array of NOT-DEFINITION Cards in the Player's Hand.
   * Getter for this attribute:
   * 		std::vector< Card* > 	_myNotDefinitionCards
   */
  std::vector< Card* > &GetMyNotDefinitionCards();
  //
  ///// Before: 	Card * (* GetArrayOfNotDefinitionCards()) [ _MAX_CARD_PER_HAND_COUNT ];

  /**
   * Sets an Array of NOT-DEFINITION-CARDS in the Player's Hand.
   * Setter for this attribute:
   * 		std::vector< Card* >	_myNotDefinitionCards
   */
  void SetMyNotDefinitionCards( std::vector< Card* > &myNotDefinitionCards );
  //
  ///// Before it was: 	void SetArrayOfNotDefinitionCards( Card *  (& myNotDefinitionCards )[ _MAX_CARD_PER_HAND_COUNT ] );
  //
  // Another implementation (Method OVERLOAD):
  //
  void SetMyNotDefinitionCards( Card * (&myNotDefinitionCards)[ _MAX_CARD_PER_HAND_COUNT ] );



};
#endif
