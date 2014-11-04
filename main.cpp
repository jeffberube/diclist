/*
 *	@Author:	Jeff Berube
 *	@Title:		main.cpp
 *
 *	@Description:	Contains main routine for dictionary program
 *
 */

#include "dictionary.h"

/* 	Globals 	*/
DICT dictionary = {MAX, 0, 0};
WORD word;

int main(void) {

	ENTRY* pos;

	while (1) {

		word = GetNextWord();

		if (word.empty()) {

			DumpDictionary(dictionary);
			break;

		}

		if ((pos = LocateWord(dictionary, word)) > 0)
			pos->count++;
		else if (!InsertWord(dictionary, word)) {

			cout << "Dictionary is full. Sorting, dumping and terminating.";
			break;

		}

	}


	return 0;

}
