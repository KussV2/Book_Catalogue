#ifndef ViewH
#define ViewH

#include "Book.h"
#include <stdlib.h>

class View
{
	private:

	public:
		View()	{};
		
		void showCatalogue(int identificationNumber, Book book);
		void showEnteredData(Book book); 
		void showMessage(const char msg[]);
		void showWrongBookCapacity(int size);
		
		string showCheckRepeatWordNumber();
		string showCheckDub();
		string showSearchBook();
		string getSearchedString(string key);
		string readName();
		string readAuthor();
		string readYearOfRelease();
		string readISBN();
		string showEditBookReplacement(char choice, Book book);
		
		int getEditableData(int bookNumber);
		int getBookNumberToEdit();
		
		char showEditFieldNumber();
		char showMainChoices();
		
		Book showSearchByKey(Book book);
};

#endif
