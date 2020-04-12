#ifndef HAND_TYPE_H		// Guard for not including twice the same API / LIB.
#define HAND_TYPE_H

// Default C++ Includes:
//
#include <string>
//
// My Custom Includes:
//
///// Nope: #include "card_manager.hpp"
///// Nope: #include "hand.hpp"
///// Nope: #include "card.hpp"	 // I could Discard this Include if I Get to use well "card_manager.hpp".


using namespace std;


class HandType
{

  private:
  
  // attr

  int _id;

  /**
   * Value of this Type of Hand, in contrast to any other Type of Hand.
   * ..STARTING FROM ZERO (e.g.: 'HIGH CARD' = 0; 'ONE PAIR' = 1;... the highest would be
   * ..=> 'ROYAL FLUSH' = 9).
   */
  int _hierarchyValue;

  string _name;

  /** Name of this Type of Hand	, but in a "Printer-friendly" fashion.
  */
  string _printerFriendlyName;

  
  
  // methods
  public:
  //
  //constructors
  //
  HandType(const int &id, const int &hierarchyValue, const string &name, const string &printerFriendlyName);
  //
  /////Nope: ,Card *  myCard, Hand *  myHand, CardManager *  myCardManager);

  
  //Destructors
  //
  ~HandType();

  //*************************** Methods ***************************//

  /*****************GETTERs & SETTERs******************/


  const int &GetId();
  void SetId(const int &id);

  const std::string &GetName();
  void SetName( const std::string &name );

  const int &GetHierarchyValue();
  void SetHierarchyValue( const int &hierarchyValue );
  
  /** Name of this Type of Hand	, but in a "Printer-friendly" fashion.
    */
  const std::string &GetPrinterFriendlyName();

  /** Name of this Type of Hand	, but in a "Printer-friendly" fashion.
  */
  void SetPrinterFriendlyName( const std::string &printerFriendlyName );


};
#endif
