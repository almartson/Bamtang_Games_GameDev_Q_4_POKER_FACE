#ifndef FILE_MANAGER_H		// Guard for not including twice the same API / LIB.
#define FILE_MANAGER_H

#include <TCHAR.H> // Implicit or explicit include
#include <windows.h>
#include <tchar.h>

// Problem: COnversion between TCHAR and string:  Another soluton is:
//
//#ifndef UNICODE
//	typedef std::string String
//#else
//	typedef std::wstring String
//#endif

// With:

//#ifdef UNICODE
//	#define TCHAR wchar_t
//#else
//	#define TCHAR char
//#endif

////.h
// Headers

//std::string get_working_path();
///// Deprecated, can be done with operator=	std::string TCHARToStringOptimum( TCHAR* myTCHAR );
TCHAR* StringToTCHAROptimum( const std::string &myString );

bool ValidateAlreadyOpenFileNotClosing( std::fstream &myfile );
bool OpenFileForWritingNotClosing( std::ofstream &myfile );
bool CloseFileForWriting( std::ofstream &myfile );

bool OpenFileForWritingOrCreateIt( const std::string &fileName );
const std::string GetFullCurrentFullPathName( const std::string &fileName );

#endif
