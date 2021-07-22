#ifndef ViewH
#define ViewH

#include "Book.h"
#include <stdlib.h>

class View
{
	private:

	public:
		View()	{};
		
		void showCatalogue(int i, Book x);
		void showEnteredData(Book book); 
		void showMessage(const char msg[]);
		
		string showCheckRepeatWordNumber();
		string showCheckRepeatWord(string editReplaceWord, Book x, int n, char b);
		string showSearchBook();
		string getSearchedString(string key);
		string getName();
		string getAuthor();
		string getYearOfRelease();
		string getISBN();
		string showEditBookReplacement(char b, Book x, int d);
		
		int showEditBookNumber(int vecSize);
		int showDeletedData(int vecSize);
		
		char showEditTempNumber();
		char showMainChoices();
		
		Book showSearchByKey(Book x);
};

#endif
