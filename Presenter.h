#ifndef PresenterH
#define PresenterH

#include"Model.h"
#include"View.h"
#include"Book.h"


class Presenter
{
	private:
		Model myModel;
		View myView;
		string ISBNCheck();
	public:
		Presenter() {};
		void start();
		int searchDeletedData(int size, int bookNumber);
		int editBook();
		string showCheckRepeatWord(string editReplaceWord, Book book, char choice);
};

#endif
