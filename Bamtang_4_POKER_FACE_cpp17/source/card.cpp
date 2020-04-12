#include "card.hpp"
#include <iostream>

// Constructor 0: Empty default
//
Card::Card()
{
	this->_myCardType = nullptr;	 //	NULL
}

// Constructor 1
//
//Card::Card(const int &id, const string &name, const int &value, CardType &myCardType)
//			:
//			_id 		(id),
//			_name 		(name),
//			_value		(value),
//			_myCardType	(myCardType)
//{
//}//End Constructor

//Card::Card(const int &id, const string &name, const int &value, CardType &myCardType)
//{
//  // NOTE: (*this.) is the SAME as: this->
//  //
//  /////this->_myID = myID;
//  //
//  (*this)._id = id;
//  (*this)._name = name;
//  (*this)._value = value;
//  //
//  // Pointers to other Classes:
//  //
//  this->_myCardType = myCardType;  // nullptr;	 //	NULL
//
//}//End Constructor


// Destructors
//
Card::~Card()
{
  //std::cout << "this->_myID = " << this->_myID << "\n";
  //std::cout << "this = (Original Object Memory Address & =) " << this << "\n";
  //std::cout << "this->_myNext = " << this->_myNext << "\n\n";
}


//**************************** Methods*********************************//


// Redefine = operator (default assignment operator) for the Constructor to work:
//
Card &Card::operator =( Card &c )
{
	/* SELF ASSIGNMENT CHECK */
	if( (this != &c) && ( &c != nullptr /*NULL*/ ) )
	{

		this->_id 						= c.GetId();	//	_id;

		this->_shortName 				= c.GetShortName();	//	_name;
		this->_longNameEspanishSingular = c.GetLongNameEspanishSingular();
		this->_longNameEspanishPlural 	= c.GetLongNameEspanishPlural();

		this->_value 					= c.GetValue();	//	_value;

		this->_myCardType 				= &(c.GetMyCardTypeNonConst());		//	_myCardType;

	}//End if

	return *this;

}//End


/**
 * Performs Deep Copy of this Card ('copyThisCard'), inside this Object.
 */
void Card::CopyDeepCardInHere( Card &c )
{
	/* SELF ASSIGNMENT CHECK */
	if( (this != &c) && ( &c != nullptr  /*NULL*/ ) )
	{

		this->_id 			= c.GetId();	//	_id;

		this->_shortName 				= c.GetShortName();	//	_name;
		this->_longNameEspanishSingular = c.GetLongNameEspanishSingular();
		this->_longNameEspanishPlural 	= c.GetLongNameEspanishPlural();

		this->_value 		= c.GetValue();	//	_value;

		this->_myCardType 	= &(c.GetMyCardTypeNonConst());		//	_myCardType;

	}//End if

}//End



/*****************GETTERs & SETTERs******************/


int Card::GetId()
{

	return this->_id;

}//End Method

void Card::SetId(const int &id)
{

	this->_id = id;

}//End Method


const std::string Card::GetShortName()
{

	return this->_shortName;

}//End Method

void Card::SetShortName( const std::string &name )
{

	this->_shortName = name;

}//End Method


const std::string Card::GetLongNameEspanishSingular()
{

	return this->_longNameEspanishSingular;

}//End Method

void Card::SetLongNameEspanishSingular( const std::string &name )
{

	this->_longNameEspanishSingular = name;

}//End Method


const std::string Card::GetLongNameEspanishPlural()
{

	return this->_longNameEspanishPlural;

}//End Method

void Card::SetLongNameEspanishPlural( const std::string &name )
{

	this->_longNameEspanishPlural = name;

}//End Method


const int Card::GetValue()
{

	return this->_value;

}//End Method

void Card::SetValue( const int  &value )
{

	this->_value = value;

}//End Method


const CardType & Card::GetMyCardType()
{

	return *(this->_myCardType);

}//End Method


CardType & Card::GetMyCardTypeNonConst()
{

	return *(this->_myCardType);

}//End Method

void Card::SetMyCardType( CardType* myCardType )
{

	/////& std::cout << "\n\nINSIDE (before assignment): void Card::SetMyCardType( CardType* myCardType ), WORKING\n";

	this->_myCardType = myCardType;

	/////& std::cout << "\n\nINSIDE (AFTER assignment): void Card::SetMyCardType( CardType* myCardType ), WORKING\n";

}//End Method

