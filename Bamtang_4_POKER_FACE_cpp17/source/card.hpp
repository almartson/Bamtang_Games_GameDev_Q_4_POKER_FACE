#ifndef CARD_H		// Guard for not including twice the same API / LIB.
#define CARD_H

// Default C++ Includes:
//
#include <string>
//
// My Custom Includes:
//
#include "card_type.hpp"

using namespace std;

/***************** Forward declarations & Function prototypes **********************/

//class CardType;

/***************** This Class Definition **********************/


class Card
{

  private:
  
  // Attr
  int _id;

  /**
   * In Spanish there are several problems with the name of Cards: Singular and Plural Form.
   * So, we will include both options here, and let the 'selecting' routine to the: method caller.
   * e.g.:  T (is 10), 2, 3, 4, 5 J, K, A
   */
  string _shortName;

  /**
   * In Spanish there are several problems with the name of Cards: Singular and Plural Form.
   * So, we will include both options here, and let the 'selecting' routine to the: method caller.
   * e.g.:  diez, dos, tres, reina, etc.
   */
  string _longNameEspanishSingular;

  /**
   * In Spanish there are several problems with the name of Cards: Singular and Plural Form.
   * So, we will include both options here, and let the 'selecting' routine to the: method caller.
   * e.g.:  dieces, doses, treses, reina, etc.
   */
  string _longNameEspanishPlural;

  int _value;

  
  //Pointers to other Objects (from Classes)
  //
  /** Type of Card: T, S, H, D.
  */
  CardType* _myCardType; // = nullptr;
  
  
  // Methods
  public:

  // Redefine = operator (default assignment operator) for the COnstructor to work:
  //
  Card &operator =( Card &c );


  // Constructors
  //
  // Default:
  //
  Card();
  //
  //Card(const int &id, const string &name, const int &value, CardType  &myCardType);
  //
  Card(const int &id, const string &shortName, const string &longNameSpanishSingular, const string &longNameSpanishPlural, const int &value, CardType* myCardType)
  			:
  			_id 		(id),

  			_shortName 		(shortName),
  			_longNameEspanishSingular 		(longNameSpanishSingular),
  			_longNameEspanishPlural 		(longNameSpanishPlural),

  			_value		(value),
  			_myCardType	(myCardType)
  { }//End Constructor
  

  //Destructors
  //
  ~Card();

  //*************************** Methods ***************************//

  // _id
  //
  int GetId();
  void SetId(const int &id);

  const std::string GetShortName();
  void SetShortName( const std::string &name );

  const std::string GetLongNameEspanishSingular();
  void SetLongNameEspanishSingular( const std::string &name );


  const std::string GetLongNameEspanishPlural();
  void SetLongNameEspanishPlural( const std::string &name );


  const int GetValue();
  void SetValue( const int  &value );

  const CardType &GetMyCardType();
  CardType & GetMyCardTypeNonConst();	// To be used as a variable
  //
  void SetMyCardType( CardType* myCardType );

  /**
   * Performs Deep Copy of this Card ('c'), inside this Object.
   */
  void CopyDeepCardInHere( Card &c );

};
#endif
