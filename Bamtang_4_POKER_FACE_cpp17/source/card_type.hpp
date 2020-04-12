#ifndef CARD_TYPE_H		// Guard for not including twice the same API / LIB.
#define CARD_TYPE_H

// Default C++ Includes:
//
#include <string>
//
// My Custom Includes:
//
///// Nope: #include "card_manager.hpp"
///// Nope: #include "hand.hpp"


using namespace std;


class CardType
{
  
  private:
  
  // attr

  /**
   * It is the INDEX of the CARD TYPE
   */
  int _id;

  /**
   * The (Short, one-letter) NAME un UPPERCASE of the TYPE OF CARD: S, C, H, D.
   */
  string _shortName;	// S, C, H, D.

  /**
   * The (Full) NAME un UPPERCASE of the TYPE OF CARD: SPADES, CLUB, HEART, DIAMOND.
   */
  string _longName;


  // methods
  public:

  // Redefine = operator (default assignment operator) for the Constructor to work:
  //
  CardType & operator=(const CardType &c);
  //
  // Constructors
  //
  CardType();
  //
  //CardType(const int &id, const string &shortName, const string &longName);
  //
  // Constructor 1
  //
  CardType(const int &id, const string &shortName, const string &longName)
  				:
  					_id 		(id),
  					_shortName 	(shortName),
  					_longName 	(longName)
  { }//End Constructor


  // Destructors
  //
  ~CardType();

  //*************************** Methods ***************************//


//  //
//  // _myID
//  //
//  int GetId();
//  void Set_myID(int const &id);
//
//  // _myNext
//  //
//  // Cosa Get_myNext_Objeto();
//  // Ejemplo:   Cosa * Get_myNext();
//  // Ejemplo:   void Set_myNext(Cosa myNextAux);
  
  
  const int &GetId();
  void SetId(int const &id);
  const string &GetShortName();
  const string &GetLongName();

  
};
#endif
