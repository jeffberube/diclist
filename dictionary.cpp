/*
 *	@Author:	Jeff Berube
 *	@Title:		dictionary.cpp
 *
 *	@Description:	Contains all functions related to dictionary program
 *
 */

#include "dictionary.h" 
#include <assert.h>

/*
 *	InsertWord
 *	
 *	Adds word to dictionary. Sorts dictionary in ascending alphabetical order on insertion.
 *
 *	INPUT
 *		DICT& dict	Reference to dictionary to operate on.
 *		WORD word	Word to add to the dictionary
 *
 *	RETURN
 *		FALSE if word cannot be added, otherwise TRUE
 */

BOOL InsertWord(DICT& dict, WORD word) {

	/* If dictionary isn't full, insert word */
	if (!FullDictionary(dict)) {
		
		/* Initialize pointers to traverse list */		
		ENTRY* next = dict.Words, * prev = NULL;

		/* Instatiate new word entry */
		ENTRY* newWord = new ENTRY;
		newWord->w = word;
		newWord->count = 1;
		newWord->nextWord = NULL;		

		/* If dictionary is empty, insert and fix head pointer */
		if (next == NULL) {

			dict.Words = newWord;

		/* If word comes before first word, insert and fix head pointer */
		} else if (word < next->w) {

			newWord->nextWord = next;
			dict.Words = newWord;

		/* Else traverse list and insert in proper order */
		} else {

			assert(next != 0);

			while (next && word > next->w) {

				prev = next;
				next = next->nextWord;

			}
			
			if (prev) prev->nextWord = newWord;	
			newWord->nextWord = next;

		}
	
		/* Increment word count */
		dict.numWords++;

		return 1;

	} else
		return 0;


}

/*
 *	DumpDictionary
 *
 *	Displays the contents of the dictionary
 *
 *	INPUT
 *		DICT& dict	Reference to dictionary to sort and dump.	
 *	
 *	RETURN
 *		No return value
 */

void DumpDictionary(DICT& dict) {

	ENTRY* entry = dict.Words;

	cout << "Dictionary\n\nFreq\tWord\n---------------------------------------\n";
		
	while (entry) {

		cout << entry->count << "\t" << entry->w << endl;

		entry = entry->nextWord;
	}

}

/*
 *	GetNextWord
 *	
 *	Retrieves next word from input stream.
 *
 *	INPUT
 *		No arguments
 *
 *	RETURN
 *		Returns a word or an empty string on EOF
 */

WORD GetNextWord(void) {

	/* Variables */
	WORD nextWord = "", buffer = "";

	/* In case end of file, return empty string */
	if (cin.eof()) 
		return "";

	/* In case of multiple non alpha characters, just throw output away until you get next word */
	
	char c;

	while (nextWord == "" && cin.good()) 
		cin >> nextWord;

	for (char c: nextWord)
	       if (isalpha(c)) buffer.push_back(c);

	nextWord = buffer;	
	
	return nextWord;

}

/*
 *	FullDictionary
 *	
 *	Determines if dictionary is full
 *
 *	INPUT
 *		DICT& dict	Reference to dictionary to assess
 *
 *	RETURN
 *		TRUE if dictionary is full, otherwise FALSE
 */

BOOL FullDictionary(DICT& dict) {

	return dict.numWords == dict.maxEntries;

}

/*
 *	LocateWord
 *	
 *	Search dictionary for input word.
 *
 *	INPUT
 *		DICT& dict	Reference to dictionary to search
 *		WORD word	Word to search
 *
 *	RETURN
 *		Pointer to entry if found, otherwise returns NULL
 */

ENTRY* LocateWord(DICT& dict, WORD word) {

	ENTRY* entry = dict.Words;

	while (entry && lowercase(entry->w) != lowercase(word)) entry = entry->nextWord;
	
	return entry;

}	

/*
 *	lowercase
 *
 *	Returns a lowercase copy of input word
 *
 *	INPUT
 *		WORD word	Word to transform to lowercase
 *
 *	RETURN
 *		Return lowercase copy of input word
 *
 */

WORD lowercase(WORD word) {

	WORD modified, s;

	for (char c : word) {

		s = tolower(c);
		modified.append(s);	

	}

	return modified;

}
