/*
 *	@Author:	Jeff Berube
 *	@Title:		dictionary.cpp
 *
 *	@Description:	Contains all functions related to dictionary program
 *
 */

#ifndef __dictionary_h__

	#define __dictionary_h__

#include <string>
#include <iostream>

using namespace std;

const int MAX = 100;

typedef string STRING;
typedef bool BOOL;
typedef string WORD;

/* 	Dictionary entry structure	*/
typedef struct entry {
	int count;
	WORD w;
	struct entry *nextWord;
} ENTRY;

/*	Dictionary structure	*/
typedef struct dict {
	int maxEntries;
	int numWords;
	ENTRY *Words;
} DICT;

/*	Function Prototypes 	*/
ENTRY* LocateWord(DICT&, WORD);
WORD lowercase(WORD);
BOOL FullDictionary(DICT&);
BOOL InsertWord(DICT&, WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT&);

#endif
