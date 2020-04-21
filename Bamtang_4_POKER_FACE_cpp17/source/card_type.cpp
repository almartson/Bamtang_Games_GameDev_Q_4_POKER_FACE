#include "card_type.hpp"
#include <iostream>


// Constructor 0: Empty default
//
CardType::CardType() { }


// Constructor 1: See .hpp
////
//CardType::CardType(const int &id, const string &shortName, const string &longName)
//				:
//					_id 		(id),
//					_shortName 	(shortName),
//					_longName 	(longName)
//{ }//End Constructor


// Constructor 2
//

// Destructors
//
CardType::~CardType()
{
  //std::cout << "this->_myID = " << this->_myID << "\n";
  //std::cout << "this = (Original Object Memory Address & =) " << this << "\n";
  //std::cout << "this->_myNext = " << this->_myNext << "\n\n";
}


//**************************** Methods*********************************//


/**
 * Redefine = operator (default assignment operator) for the Constructor to work:
 */
CardType & CardType::operator= (const CardType &c)
{
	/* SELF ASSIGNMENT CHECK */
	if(this != &c)
	{

		this->_id 			= c._id;
		this->_shortName	= c._shortName;
		this->_longName 	= c._longName;

	}//End if

	return *this;

}//End


/************GETTERs & SETTERs***************/


const int &CardType::GetId()
{

	return this->_id;

}//End Method

void CardType::SetId(int const &id)
{

	this->_id = id;

}//End Method

const string &CardType::GetShortName()
{

	return this->_shortName;

}//End Method

const string &CardType::GetLongName()
{

	return this->_longName;

}//End Method
