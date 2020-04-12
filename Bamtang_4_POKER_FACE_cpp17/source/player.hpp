#ifndef PLAYER_H		// Guard for not including twice the same API / LIB.
#define PLAYER_H

// Default C++ Includes:
//
//#include <string>
//
// My Custom Includes:
//
#include "hand.hpp"


using namespace std;


class Player
{
  
  private:
  
  // attr

  /**
   * Player Number: i.e.: P1 => 1, P2 => 2.
  */
  int _id;
  
  //Pointer
  //
  ////Nope: CardManager * _myCardManager = nullptr;	 //	NULL

  /**
   * tThis Player's Hand of Cards, to Play the Game.
   */
  Hand * _myHand;                 // = nullptr;
  
  
  // methods
  public:
  //
  // Constructors
  // Empty Default Constructor:
  //
  Player();
  //
  Player(const int &id);
  
  //Destructors
  //
  ~Player();

  //*************************** Methods ***************************//

  private:
  /**
   * Constructor friend:
   * It creates this Object's asscociated objects and Pointers.
   */
  void CreatePointersAndAssociatedObjects( const bool &initializeToNewOrNULL );


  public:
  //
  // _myID
  //
  int GetId();
  void SetId(int const &id);

  Hand*  GetMyHand();
  void SetMyHand( Hand* myHand );

  

  
};
#endif
