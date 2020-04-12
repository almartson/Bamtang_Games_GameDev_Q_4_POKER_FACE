#include "util_functions.hpp"

//// Default C++ Includes:
////
///// Does not work in Visual C++:  bits/stdc++.h
////
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>	 // Sort an array according to other (array) using pair in STL. + // Also: For a 'Tokenizer' Method:
////
//#include <sstream> 	// Number to String
////
//// Formating the cout Output:
////
//#include <iomanip>       // std::setfill, std::setw

//// Custom includes
////
//#include "card.hpp"
//
//constexpr auto _MAX_CARDS_PER_HAND = 5;

//using namespace std;


// Destructors
//
UtilFunctions::~UtilFunctions()
{
	//std::cout << "CardManager::_myID = " << CardManager::_myID << "\n";
	//std::cout << "this = (Original Object Memory Address & =) " << this << "\n";
	//std::cout << "CardManager::_myNext = " << CardManager::_myNext << "\n\n";
}


/**
 * Generic of Generic: Function to copy the contents of any array (of ANY TYPE T1) (i.e: arrayA) into another (i.e: arrayBTarget) (of ANY TYPE T2).
 */
template<typename T1, typename T2, std::size_t N>
void UtilFunctions::CopyArrayAToOtherArrayBGenericTypes( T1 (&arrayA)[N], T2 (&arrayBTarget)[N] )
{

	for (unsigned int i = 0; i < N; i++)
	{

		arrayBTarget[ i ] = arrayA[ i ];

	}//End for

}//End Function


/**
 * Generic Function to copy the contents of any array (i.e: arrayA) into another (i.e: arrayBTarget).
 */
template<typename T, std::size_t N>
void UtilFunctions::CopyArrayAToOtherArrayB( const T (&arrayA)[N], T (&arrayBTarget)[N] )
{

	for (unsigned int i = 0; i < N; i++)
	{

		arrayBTarget[ i ] = arrayA[ i ];

	}//End for

}//End Function


/**
 * Generic Function to initialize any array to a VALUE.
 */
template<typename T, std::size_t N>
void UtilFunctions::InitializeArrayWithAValue(T (&arr)[N], const T& value = T())
{
    for(auto& e : arr)
        e = value;

}//End Function


/**
 * Generic Function to initialize any array to a VALUE.
 */
template<typename T, std::size_t N>
void UtilFunctions::InitializeArrayOfPointersWithNullptr( T* (&arr)[N] )
{
    for(auto& e : arr)
        e = nullptr;

}//End Function



/**
 * Generic Function to TOKENIZE a string, splitting it into an c-style: ARRAY of STRING.
 */
template<std::size_t N /*= 10*/>
void UtilFunctions::TokenizeStringSplitIntoCArray( const string &line, const char  &delimiter, std::string  (&myArrayOfStrings) [N] )
{

	// Necessary variables:
	//
    const int lengthLine = line.length();
    int indexArrayFinal = 0;
    //
    // String-Token to assign in every case:
    //
    string myString = "";

    // Tokenizing
    // Loop through the string
    //
    for (int i = 0; i < lengthLine; i++)
    {

		// Add to the String
		//
		myString += line[ i ];

		// Condition to TOKENIZE / SPLIT the Word/String:
		//
    	if ( ( line[ i ] == delimiter ) || ( (i + 1) == lengthLine ) )
    	{

    		// It found the 'delimiter', => Tokenize:
    		// Add to the array:
    		//
    		myArrayOfStrings[ indexArrayFinal ] = myString;
    		//
    		// Clean the auxiliary variable:
    		//
    		myString = "";
    		//
    		// Increment Final Array index:
    		//
    		indexArrayFinal++;

    	}//End if ( line[ i ] != delimiter )

    }//End For

}//End Method



/**
 * It splits a Big array (bigArray)...: into two arrays: arr1  and arr2.
 * Condition:	_SIZE_BIG_ARRAY >= ( _SIZE_SMALL_ARRAY_1 + _SIZE_SMALL_ARRAY_2 )
 *
 * Type of the Array: C-Style Classic array: e.g.:   int[], double[], string[], char[].
 */
template<typename T, std::size_t _SIZE_BIG_ARRAY, std::size_t _SIZE_SMALL_ARRAY_1, std::size_t _SIZE_SMALL_ARRAY_2>
void UtilFunctions::SplitBigArrayIntoTwoArrays( const T (&bigArray)[_SIZE_BIG_ARRAY], T (&arr1)[_SIZE_SMALL_ARRAY_1], T (&arr2)[_SIZE_SMALL_ARRAY_2] )
{

	// Validation:
	//
	if ( _SIZE_BIG_ARRAY >= ( _SIZE_SMALL_ARRAY_1 + _SIZE_SMALL_ARRAY_2 ) )
	{

		// Split into: FIRST ARRAY
		//
		for (unsigned int i = 0; i < _SIZE_SMALL_ARRAY_1; i++)
		{

			arr1[ i ] = bigArray[ i ];

		}//End for
		//
		// Split into: SECOND ARRAY
		//
		for (unsigned int i = 0; i < _SIZE_SMALL_ARRAY_2; i++)
		{

			arr2[ i ] = bigArray[ _SIZE_SMALL_ARRAY_1 + i ];

		}//End for

	}//End if ( _SIZE_BIG_ARRAY >= ( _SIZE_SMALL_ARRAY_1 + _SIZE_SMALL_ARRAY_2 ) )

}//End Function


/************SORTING METHOD**************/


/**
 * Method Overload:
 * Function to sort Card Object array b[]
 * according to the order defined by a[]
*/
template<const std::size_t arrayLength>
void UtilFunctions::PairSortObjects(int (&a)[ arrayLength ], Card* (&myArrayOfCard) [ arrayLength ], const bool &ascending)
{

    pair<int, Card*> pairt[ arrayLength ];

    // Storing the respective array
    // elements in pairs.
    //
    for (unsigned int i = 0; i < arrayLength; i++)
    {
        pairt[i].first = a[ i ];
        pairt[i].second = myArrayOfCard[ i ];
    }


    // Sorting the pair array.
    //
    sort(pairt, pairt + arrayLength);


    // Ascendent: 	1, 100, ...1000000
    // Desce: 		1000, 100, 1.
    //
    if (ascending)
    {

    	// ASCENDING:
    	//
        // Modifying original arrays
        //
        for (unsigned int i = 0; i < arrayLength; i++)
        {
            a[ i ]              = pairt[ i ].first;
            myArrayOfCard[ i ]  = pairt[ i ].second;
        }

    }//End if (ascending)
    else
    {

    	// DESCENDING:
    	//
        // Modifying original arrays
        //
        for (unsigned int i = 0; i < arrayLength; i++)
        {
            a[ i ]              = pairt[ arrayLength - 1 - i ].first;
            myArrayOfCard[ i ]  = pairt[ arrayLength - 1 - i ].second;
        }

    }//End else

} //End Method


///*
// * Versión v-3.0 usando: OBJETOS: Pair <Card, int>.
// *
// * Driver function
//*/
//template<std::size_t arrayLength>
//void mainVersionObjetosEInt( Card* (&myArrayOfCard) [ arrayLength ], int (&a)[ arrayLength ] )
//{
//
//    // Function calling
//    PairSortObjects(a, myArrayOfCard, false);
//
//
//
//    for (int i = 0; i < arrayLength; i++)
//        cout << a[i] << " ";
//    cout << endl;
//
//    for (int i = 0; i < arrayLength; i++)
//        cout << myArrayOfCard[i] << " ";
//
//    cout << endl;
//
//    // Names of the Cards:
//    //
//    for (int i = 0; i < arrayLength; i++)
//        cout << myArrayOfCard[i]->GetName() << " ";
//
//    cout << endl;
//
//}//End Method


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
void UtilFunctions::SortCards( Card* (&myArrayOfCard) [ arrayLength ], const bool &ascending )
{

  // Create a (the NUMBERS ARRAY - from the array 'b' = 'myArrayOfCard')
  //
  int a[ arrayLength ];    // = { 1, 2, 3, 4, 5 };    //     a: Values to Sort - array
  //
  for (unsigned int i = 0; i < arrayLength; i++)
  {

    // Populate array
    //
    a[ i ] = myArrayOfCard[ i ]->GetValue();

  }//End for


  // Function calling, to Sort:
  //
  PairSortObjects(a, myArrayOfCard, ascending);

}//End Method



/************SORTING VECTORS of Card* ***************/

/**
 * Method Overload:
 * Function to sort Card* Object Vector < Card* >: 	std::vector<Card*> b
 * according to the order defined by the 'array of int':  a[]
*/
template<typename T>
/*inline*/ void UtilFunctions::PairSortObjectsVector( std::vector <int> &a, std::vector< T* > &myArrayOfPtrToObjects, const bool &ascending, const int &arrayLength )
{

	// Declaring vector of pairs, to Sort it:
	//
	std::vector< pair <int, T*> > pairt;


    // Storing the respective array
    // elements in pairs.
    //
    for (int i = 0; i < arrayLength; i++)
    {

		pairt.push_back( make_pair( a.at( i ), myArrayOfPtrToObjects.at(i) ) );

        //pairt.at( i ).first = a[ i ];
        //pairt[i].second = myArrayOfCard.at( i );	 // myArrayOfCard[ i ]; is an: Insecure way, because it does not throw OUT-OF-BOUNDS-EXCEPTION if it goes beyond .SIZE()...
    }

    // Sorting the pair array.
    //
	sort( pairt.begin(), pairt.end() );
	//
    /// Before:	 sort(pairt, pairt + arrayLength);


    // Ascendent:   1, 100, ...1000000
    // Desce:       1000, 100, 1.
    //
    if (ascending)
    {

        // ASCENDING:
        //
        // Modifying original arrays
        //
        for (int i = 0; i < arrayLength; i++)
        {
			a.at(i)					= pairt.at(i).first;
			myArrayOfPtrToObjects.at( i )	= pairt.at(i).second; 	// ArrayOfCard[ i ]  = pairt[ i ].second;
        }

    }//End if (ascending)
    else
    {

        // DESCENDING:
        //
        // Modifying original arrays
        //
        for (int i = 0; i < arrayLength; i++)
        {
            a.at( i )					  	= pairt.at( arrayLength - 1 - i ).first;
			myArrayOfPtrToObjects.at( i )  	= pairt.at( arrayLength - 1 - i ).second;
        }

    }//End else

} //End Method


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
/*inline*/ void UtilFunctions::SortVectorOfPointerToCards( std::vector< Card* > &myVectorOfCard, const bool &ascending )
{

    // 1- Size: Vector is DYNAMIC, but at this stage it will not change its size, because we will just reorder it.
    //
    const int vectorLength = myVectorOfCard.size();


    // 2- Create a (the NUMBERS ARRAY - from the Vector 'b' = 'myVectorOfCard')
    //
    std::vector <int> a;    // = { 1, 2, 3, 4, 5 };    //     a: Values to Sort - array
    //
    for (int i = 0; i < vectorLength; i++)
    {

        // Populate array
        //
        a.push_back( myVectorOfCard.at( i )->GetValue() );

    }//End for


	// Function calling
	//
    PairSortObjectsVector(a, myVectorOfCard, ascending, vectorLength);

}//End Method


/**
 * Concatenates 'myVector1' + 'myVector2', and populates the result in: 'myVector3'
 */
template<typename T>
void UtilFunctions::ConcatenateTwoVectorsAandBAndAddToC( std::vector< T* > &myVector1, std::vector< T* > &myVector2 , std::vector< T* > &myVector3Result )
{

	myVector3Result.reserve( myVector1.size() + myVector2.size() );						 // preallocate memory
	myVector3Result.insert( myVector3Result.end(), myVector1.begin(), myVector1.end() );
	myVector3Result.insert( myVector3Result.end(), myVector2.begin(), myVector2.end() );

}//End Method

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
const bool UtilFunctions::SearchInArrayAndReturnObjectFound(const std::vector< T* >  & vecOfElements, T* (&element))
{

    // Find given element in vector
    //
    auto it = std::find( vecOfElements.begin(), vecOfElements.end(), element );

    // Check: Was it Found??
    //
    if ( it != vecOfElements.end() )     // Yes
    {

        // Return true
        //
        return true;

    }
    else    // No
    {

        // Not Found, return NOTHING:
        //
        return false;

    }// End else of if ( it != myarraySize.end() )     // Yes

}//End Method


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
void UtilFunctions::SetAVectorComparison( T* (&arrayOfElements) [ myarraySize ], std::vector < T* > &myVectorList, std::vector < T* > &myResultingVectorList, const bool &getGetSimilarOcurrencesTrueOrDifferentElementsFalse )
{

    // Set clean  the RESULTING VECTOR LIST:
    //
    myResultingVectorList.clear();

    // Search:  SIMILAR or DIFFERENT:
    //
    if ( getGetSimilarOcurrencesTrueOrDifferentElementsFalse )    // Get the Exact SAME ELEMENTS: Coincidences!
    {

        // Get the Exact SAME ELEMENTS: Coincidences!
        //
        // Iterate over all elements in Vector
        //
        for (unsigned int i = 0; i < myarraySize; i++)
        {

            if ( SearchInArrayAndReturnObjectFound( myVectorList, arrayOfElements[ i ] ) )   // FOUND IT!
            {

                // Add to the Vector-List:
                //
                myResultingVectorList.push_back( arrayOfElements[ i ] );

            }//End if
            // else    // NOT found
            // {
            // }//End else

        }//End for

    }//End if
    else   // Get the DIFFERENT ELEMENTS: Differences!
    {

        // Get ELEMENTS in A (array) but not in B (Vector)
        //
        // Iterate over all elements in Vector
        //
        for (unsigned int i = 0; i < myarraySize; i++)
        {

            if ( ! SearchInArrayAndReturnObjectFound( myVectorList, arrayOfElements[ i ] ) )   // NOT found in VECTOR.
            {

                // Add to the Vector-List:
                //
                myResultingVectorList.push_back( arrayOfElements[ i ] );

            }//End if
            // else    // FOUND IT!
            // {
            // }//End else

        }//End for

    }//End else of if ( getDifferentElementsTrueOrGetSimilarOcurrences )    // Get the Exact SAME ELEMENTS: Coincidences!

}//End Method


/***END*********** VECTOR & ARRAYS COPY & interchangeability *****************/


/*******************Printing with Format**********************/


/**
 *  Prints out (to a Variable): a TEXT with a Format, and fillin empty spaces with a desired char
 *  OUTPUT: std::cout (ALSO AN INPUT)
 *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
 */
void UtilFunctions::PrintSectionToVariable(std::stringstream &myStringstreamVariable, const std::string &textToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd)
{

	// Set the preferences for the cout AND Print
	//
	myStringstreamVariable << ((printJumpOfLineAtTheStart) ? "\n" : "") << std::setfill(fillSpacesWithChar) << std::setw(totalChars) << ((padTextToTheRightOrFalseISLeft) ? std::right : std::left) << textToPrint << ((printJumpOfLineAtTheEnd) ? "\n" : "");

}//End Method


/**
 *  Prints out (to a Variable): a NUMBER with a Format, and fillin empty spaces with a desired char
 *  OUTPUT: std::cout (ALSO AN INPUT)
 *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
 */
void UtilFunctions::PrintSectionToVariable(std::stringstream &myStringstreamVariable, const int &numbersToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd)
{

	// Set the preferences for the cout AND Print
	//
	myStringstreamVariable << ((printJumpOfLineAtTheStart) ? "\n" : "") << std::setfill(fillSpacesWithChar) << std::setw(totalChars) << ((padTextToTheRightOrFalseISLeft) ? std::right : std::left) << numbersToPrint << ((printJumpOfLineAtTheEnd) ? "\n" : "");

}//End Method


/***********************/

/**
 *  Prints out a TEXT with a Format, and fillin empty spaces with a desired char
 *  OUTPUT: std::cout (ALSO AN INPUT)
 *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
 */
std::ostream& UtilFunctions::PrintSection(std::ostream& o, const std::string &textToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd)
{

	// Set the preferences for the cout AND Print
	//
	return o << ((printJumpOfLineAtTheStart) ? "\n" : "") << std::setfill(fillSpacesWithChar) << std::setw(totalChars) << ((padTextToTheRightOrFalseISLeft) ? std::right : std::left) << textToPrint << ((printJumpOfLineAtTheEnd) ? "\n" : "");

}//End Method


/**
 *  Prints out a NUMBER with a Format, and fillin empty spaces with a desired char
 *  OUTPUT: std::cout (ALSO AN INPUT)
 *  Example of HowTo use:   PrintSection(std::cout, "I wrote this...", '*', 15, true);
 */
std::ostream& UtilFunctions::PrintSection(std::ostream& o, const int &numbersToPrint, const char &fillSpacesWithChar, const int &totalChars, const bool &padTextToTheRightOrFalseISLeft, const bool &printJumpOfLineAtTheStart, const bool &printJumpOfLineAtTheEnd)
{

	// Set the preferences for the cout AND Print
	//
	return o << ((printJumpOfLineAtTheStart) ? "\n" : "") << std::setfill(fillSpacesWithChar) << std::setw(totalChars) << ((padTextToTheRightOrFalseISLeft) ? std::right : std::left) << numbersToPrint << ((printJumpOfLineAtTheEnd) ? "\n" : "");

}//End Method


/**
 *  Prints out a certain number (INTEGER),
 *  ..then fills the rest of the Section with BLANK SPACES.
 *
 *  OUTPUT:
 *  @printOutToConsole      ->   Prints out to Console
 *  @printOutToATextFile    ->   Prints out to a given TEXT FILE.
 */
/*inline*/ void UtilFunctions::PrintVariableAndThenFillWithSpaces( std::string &myOutputString,
                const int &numberItemToPrint, const int &totalNumberOfChars,
                const bool &printOutToConsole, const bool &printOutToATextFile,
                const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd )
{

    // 0- Clean the Buffer stdout:
    //
    fflush(stdout); // Will now print everything in the stdout buffer
    //
	std::flush(std::cout);


	// 1- Declare the variable to store the data (Print to String:)
	//
	std::stringstream buffer;
	//
	// 2- Print to Variable and to cout, if the parameter = true
	//
	PrintSectionToVariable(buffer /*myStringstreamVariable*/, numberItemToPrint /*textToPrint*/, ' ' /*fillSpacesWithChar*/, totalNumberOfChars /*totalChars*/, true /*padTextToTheRightOrFalseISLeft*/, printNewLineAtTheBeginning /*printJumpOfLineAtTheStart*/, printNewLineAtTheEnd /*printJumpOfLineAtTheEnd*/);
	//
	// 3- Copy the result to: 'myOutputString'
	//
	myOutputString = buffer.str();


    // zz- Print to std::cout CONSOLE OUTPUT:
    //
    if ( printOutToConsole )
    {

        // Print to Console:
        //
        std::cout << myOutputString << std::flush;

    }//End if ( printOutToConsole )
    //
    // Print to a TEXT FILE .txt
    //
    // if ( printOutToATextFile )
    // {
    // }//End if ( printOutToConsole )

}//End Function


/**
 *  Prints out a certain portion of TEXT (Type: 'char []', 'char *', or 'Char Array').
 *  ..then fills the rest of the Section with BLANK SPACES.
 *
 *  OUTPUT:
 *  @printOutToConsole      ->   Prints out to Console
 *  @printOutToATextFile    ->   Prints out to a given TEXT FILE.
 */
/*inline*/ void UtilFunctions::PrintVariableAndThenFillWithSpaces( std::string &myOutputString,
                const std::string &stringItemToPrint, const int &totalNumberOfChars,
                const bool &printOutToConsole, const bool &printOutToATextFile,
                const bool &printNewLineAtTheBeginning, const bool &printNewLineAtTheEnd )
{

	// 0- Clean the Buffer stdout:
	//
	fflush(stdout); // Will now print everything in the stdout buffer
	//
	std::flush(std::cout);


	// 1- Declare the variable to store the data (Print to String:)
	//
	std::stringstream buffer;
	//
	// 2- Print to Variable and to cout, if the parameter = true
	//
	PrintSectionToVariable(buffer /*myStringstreamVariable*/, stringItemToPrint /*textToPrint*/, ' ' /*fillSpacesWithChar*/, totalNumberOfChars /*totalChars*/, true /*padTextToTheRightOrFalseISLeft*/, printNewLineAtTheBeginning /*printJumpOfLineAtTheStart*/, printNewLineAtTheEnd /*printJumpOfLineAtTheEnd*/);
	//
	// 3- Copy the result to: 'myOutputString'
	//
	myOutputString = buffer.str();


	// zz- Print to std::cout CONSOLE OUTPUT:
	//
    if ( printOutToConsole )
    {

        // Print to Console:
        //
        std::cout << myOutputString << std::flush;

    }//End if ( printOutToConsole )
    //
    // Print to a TEXT FILE .txt
    //
    // if ( printOutToATextFile )
    // {
    // }//End if ( printOutToConsole )

}//End Function


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
std::string UtilFunctions::NumberToString ( T Number )
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}//End Function

/***END****************Printing with Format**********************/


/********************Miscelaneous**********************/

/*
 * It returns a Terminator Picture, made with (ANSI) ASCII characters.
*/
/*inline*/ const std::string UtilFunctions::GetTerminatorASCII()
{
	// Set the String:
	//
	string str = "                       ______\n";
	str += "                     <((((((\\\\\\\n";
	str += "                     /      . }\\\n";
	str += "                     ;--..--._|}\n";
	str += "  (\\                 '--/\\--'  )\n";
	str += "   \\\\                | '-'  :'|\n";
	str += "    \\\\               . -==- .-|\n";
	str += "     \\\\               \\.__.'   \\--._\n";
	str += "     [\\\\          __.--|       //  _/'--.\n";
	str += "     \\ \\\\       .'-._ ('-----'/ __/      \\\n";
	str += "      \\ \\\\     /   __>|      | '--.       |\n";
	str += "       \\ \\\\   |   \\   |     /    /       /\n";
	str += "        \\ '\\ /     \\  |     |  _/       /\n";
	str += "         \\  \\       \\ |     | /        /\n";
	str += "Terminate \\  \\      \\        /\n";

	return str;
}//End Procedure


/***END**************Miscelaneous**********************/

