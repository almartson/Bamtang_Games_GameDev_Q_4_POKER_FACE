#include "hand_type.hpp"


// Constructor 1
//
HandType::HandType(const int &id, const int &hierarchyValue, const string &name, const string &printerFriendlyName)
{
	// NOTE: (*this.) is the SAME as: this->
	//
	(*this)._id = id;
	(*this)._hierarchyValue = hierarchyValue;
	(*this)._name = name;
	(*this)._printerFriendlyName = printerFriendlyName;

}//End Constructor


// Destructors
//
HandType::~HandType()
{
  //std::cout << "this->_myID = " << this->_myID << "\n";
  //std::cout << "this = (Original Object Memory Address & =) " << this << "\n";
  //std::cout << "this->_myNext = " << this->_myNext << "\n\n";
}


//**************************** Methods*********************************//

/*****************GETTERs & SETTERs******************/


const int &HandType::GetId()
{

	return this->_id;

}//End Method

void HandType::SetId(const int &id)
{

	this->_id = id;

}//End Method


const std::string &HandType::GetName()
{

	return this->_name;

}//End Method


void HandType::SetName( const std::string &name )
{

	this->_name = name;

}//End Method


/**
 * Value of this Type of Hand, in contrast to any other Type of Hand.
 * ..STARTING FROM ZERO (e.g.: 'HIGH CARD' = 0; 'ONE PAIR' = 1;... the highest would be
 * ..=> 'ROYAL FLUSH' = 9).
 */
const int &HandType::GetHierarchyValue()
{

	return this->_hierarchyValue;

}//End Method


/**
 * Value of this Type of Hand, in contrast to any other Type of Hand.
 * ..STARTING FROM ZERO (e.g.: 'HIGH CARD' = 0; 'ONE PAIR' = 1;... the highest would be
 * ..=> 'ROYAL FLUSH' = 9).
 */
void HandType::SetHierarchyValue( const int &hierarchyValue )
{

	this->_hierarchyValue = hierarchyValue;

}//End Method


/** Name of this Type of Hand	, but in a "Printer-friendly" fashion.
*/
const std::string &HandType::GetPrinterFriendlyName()
{

	return this->_printerFriendlyName;

}//End Method

/** Name of this Type of Hand	, but in a "Printer-friendly" fashion.
*/
void HandType::SetPrinterFriendlyName( const std::string &printerFriendlyName )
{

	this->_printerFriendlyName = printerFriendlyName;

}//End Method



