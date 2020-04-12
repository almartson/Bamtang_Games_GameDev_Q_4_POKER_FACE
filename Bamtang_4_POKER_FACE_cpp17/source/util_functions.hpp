#ifndef UTIL_FUNCTIONS_H		// Guard for not including twice the same API / LIB.
#define UTIL_FUNCTIONS_H

// Default C++ Includes:
//
/// Does not work in Visual C++:  bits/stdc++.h
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	 // Sort an array according to other (array) using pair in STL. + // Also: For a 'Tokenizer' Method:
//
#include <sstream> 	// Number to String
//
// Formating the cout Output:
//
#include <iomanip>       // std::setfill, std::setw

// Custom includes
//
#include "card.hpp"

using namespace std;

// Headers
class Card;

constexpr auto _MAX_CARDS_PER_HAND = 5;

/***************** This Class Definition **********************/

class UtilFunctions
{

public:

	// Destructors
	//
	~UtilFunctions();

	/**
	 * Generic of Generic: Function to copy the contents of any array (of ANY TYPE T1) (i.e: arrayA) into another (i.e: arrayBTarget) (of ANY TYPE T2).
	 */
	template<typename T1, typename T2, std::size_t N>
	static void CopyArrayAToOtherArrayBGenericTypes(T1(&arrayA)[N], T2(&arrayBTarget)[N]);

	/**
	 * Generic Function to copy the contents of any array (i.e: arrayA) into another (i.e: arrayBTarget).
	 */
	template<typename T, std::size_t N>
	static void CopyArrayAToOtherArrayB(const T(&arrayA)[N], T(&arrayBTarget)[N]);


	/**
	 * Generic Function to initialize any array to a VALUE.
	 */
	template<typename T, std::size_t N>
	static void InitializeArrayWithAValue(T(&arr)[N], const T& value = T());

	/**
	 * Generic Function to initialize any array to a VALUE.
	 */
	template<typename T, std::size_t N>
	static void InitializeArrayOfPointersWithNullptr(T* (&arr)[N]);


	/**
	 * Generic Function to TOKENIZE a string, splitting it into an c-style: ARRAY of STRING.
	 */
	template<std::size_t N /*= 10*/>
	static void TokenizeStringSplitIntoCArray(const string &line, const char  &delimiter, std::string(&myArrayOfStrings)[N]);


	/**
	 * It splits a Big array (bigArray)...: into two arrays: arr1  and arr2.
	 * Condition:	_SIZE_BIG_ARRAY >= ( _SIZE_SMALL_ARRAY_1 + _SIZE_SMALL_ARRAY_2 )
	 *
	 * Type of the Array: C-Style Classic array: e.g.:   int[], double[], string[], char[].
	 */
	template<typename T, std::size_t _SIZE_BIG_ARRAY, std::size_t _SIZE_SMALL_ARRAY_1, std::size_t _SIZE_SMALL_ARRAY_2>
	static void SplitBigArrayIntoTwoArrays(const T(&bigArray)[_SIZE_BIG_ARRAY], T(&arr1)[_SIZE_SMALL_ARRAY_1], T(&arr2)[_SIZE_SMALL_ARRAY_2]);


	/************SORTING METHOD**************/


	/**
	 * Method Overload:
	 * Function to sort Card Object array b[]
	 * according to the order defined by a[]
	*/
	template<const std::size_t arrayLength>
	static void PairSortObjects(int(&a)[arrayLength], Card* (&myArrayOfCard)[arrayLength], const bool &ascending);


	/*
	 * It Sorts an ARRAY OF CARDS, ACCORDING TO THEIR 'VALUES'.
	 *
	 * Parameters:
	 *
	 * @myArrayOfCard       Array of Cards
	 * @ascending:          TRUE - ASC || FALSE:  Descending.
	 *
	 * Driver function
	*/
	template<const std::size_t arrayLength>
	static void SortCards(Card* (&myArrayOfCard)[arrayLength], const bool &ascending);


	/************SORTING VECTORS of Card* ***************/

	/**
	 * Method Overload:
	 * Function to sort Card* Object Vector < Card* >: 	std::vector<Card*> b
	 * according to the order defined by the 'array of int':  a[]
	*/
	template<typename T>
	static /*inline*/ void PairSortObjectsVector(std::vector <int> &a, std::vector< T* > &myArrayOfPtrToObjects, const bool &ascending, const int &arrayLength);


	/*
	 * It Sorts a VECTOR of POINTERS TO: CARDS, ACCORDING TO THEIR 'VALUES'.
	 *
	 * Parameters:
	 *
	 * @myArrayOfCard       Vector of Cards
	 * @ascending:          TRUE - ASC || FALSE:  Descending.
	 *
	 * Driver function
	*/
	static /*inline*/ void SortVectorOfPointerToCards(std::vector< Card* > &myVectorOfCard, const bool &ascending);


	/**
	 * Concatenates 'myVector1' + 'myVector2', and populates the result in: 'myVector3'
	 */
	template<typename T>
	static void ConcatenateTwoVectorsAandBAndAddToC(std::vector< T* > &myVector1, std::vector< T* > &myVector2, std::vector< T* > &myVector3Result);

	/***END*********SORTING VECTORS of Card* ***************/


	/***END******SORTING METHOD***************/

	/************** VECTOR & ARRAYS COPY & interchangeability *****************/

	/**
	 *  MY CUSTOM:  Generic function to find an ELEMENT in vector Of PONTERS to another TYPENAME
	 *  ...(i.e.: std::vector < T* >)
	 *
	 *  It returns the ELEMENT found.
	*/
	template <typename T>
	static const bool SearchInArrayAndReturnObjectFound(const std::vector< T* >  & vecOfElements, T* (&element));


	/**
	 *  MY CUSTOM:  Generic function to find all 'SIMILAR' or 'All DIFFERENT' ELEMENTs
	 * ...in the COMPARISON between:
	 *
	 *      arrayOfElements     a c-style array of:  " T* "
	 *          AND
	 *      myVectorList        vector Of PONTERS to another TYPENAME   ...(i.e.: std::vector < T* >)
	 *
	 *  It returns a VECTOR-LIST of all the ELEMENTs [ Found / NOT Found]:  According to the Booolean Parameter:
	 *
	 *      -> const bool &getDifferentElementsTrueOrGetSimilarOcurrences
	*/
	template <typename T, std::size_t myarraySize>
	static void SetAVectorComparison(T* (&arrayOfElements)[myarraySize], std::vector < T* > &myVectorList, std::vector < T* > &myResultingVectorList, const bool &getGetSimilarOcurrencesTrueOrDifferentElementsFalse);


	/***END*********** VECTOR & ARRAYS COPY & interchangeability *****************/


	/*******************Printing with Format**********************/


	/**
	 *  Prints out (to a Variable): a TEXT with a Format, and fillin empty spaces with a desired char
	 *  OUTPUT: std::cout (ALSO AN INPUT)
	 *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
	 */
	static void PrintSectionToVariable(std::stringstream &myStringstreamVariable, const std::string &textToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd);


	/**
	 *  Prints out (to a Variable): a NUMBER with a Format, and fillin empty spaces with a desired char
	 *  OUTPUT: std::cout (ALSO AN INPUT)
	 *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
	 */
	static void PrintSectionToVariable(std::stringstream &myStringstreamVariable, const int &numbersToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd);


	/***********************/

	/**
	 *  Prints out a TEXT with a Format, and fillin empty spaces with a desired char
	 *  OUTPUT: std::cout (ALSO AN INPUT)
	 *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
	 */
	static std::ostream& PrintSection(std::ostream& o, const std::string &textToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd);


	/**
	 *  Prints out a NUMBER with a Format, and fillin empty spaces with a desired char
	 *  OUTPUT: std::cout (ALSO AN INPUT)
	 *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
	 */
	static std::ostream& PrintSection(std::ostream& o, const int &numbersToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd);

	/**
	 *  Prints out a certain number (INTEGER),
	 *  ..then fills the rest of the Section with BLANK SPACES.
	 *
	 *  OUTPUT:
	 *  @printOutToConsole      ->   Prints out to Console
	 *  @printOutToATextFile    ->   Prints out to a given TEXT FILE.
	 */
	static /*inline*/ void PrintVariableAndThenFillWithSpaces(std::string &myOutputString,
		const int &numberItemToPrint, const int &totalNumberOfChars,
		const bool &printOutToConsole, const bool &printOutToATextFile,
		const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd);


	/**
	 *  Prints out a certain portion of TEXT (Type: 'char []', 'char *', or 'Char Array').
	 *  ..then fills the rest of the Section with BLANK SPACES.
	 *
	 *  OUTPUT:
	 *  @printOutToConsole      ->   Prints out to Console
	 *  @printOutToATextFile    ->   Prints out to a given TEXT FILE.
	 */
	static /*inline*/ void PrintVariableAndThenFillWithSpaces(std::string &myOutputString,
		const std::string &stringItemToPrint, const int &totalNumberOfChars,
		const bool &printOutToConsole, const bool &printOutToATextFile,
		const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd);

	//EJEMPLO DE INVOCACION Y USO:
	//
	////  1-  Create the Input String:
	////
	//string str = "1g 2h 3y 4u 5i 6i 7i";
	////
	////  2-  Create the Output Char * (or char []):
	////
	//char varCharArrayStoreTheOutputHereFinal33333333 [ maxLongSectionCharArraySize + 1 ];
	////
	//PrintVariableAndThenFillWithSpaces( varCharArrayStoreTheOutputHereFinal33333333, str /*stringItemToPrint*/, 27 /*totalNumberOfChars*/, true, true );


	//// Uses this: #include <sstream>
	//
	/**
	 * Convert a NUMBER to String
	 */
	template <typename T>
	static std::string NumberToString(T Number);

	/***END****************Printing with Format**********************/


	/********************Miscelaneous**********************/

	/*
	 * It returns a Terminator Picture, made with (ANSI) ASCII characters.
	*/
	static /*inline*/ const std::string GetTerminatorASCII();


	/***END**************Miscelaneous**********************/

};
#endif
