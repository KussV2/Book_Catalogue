#include "Presenter.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>


void Presenter::start()
{
	char choice;
	bool isFinished = false;
	
	while (!isFinished) 
	{
		myModel.clearVector();
		myModel.loadFromFile();

        choice = myView.showMainChoices();

        if (choice == '1') 
		{
			int size = myModel.size();
			for (int number = 0; number < size; number++)
			{
				Book book;
				book = myModel.getBook(number);
                myView.showCatalogue(number, book);
			}
        }
        else if (choice == '2')
		{
			Book book;
			book.name = myView.getName();
			book.author = myView.getAuthor();
			book.releaseYear = myView.getYearOfRelease();
			book.ISBN = ISBNCheck();
			
			myModel.add(book);
        }

        else if (choice == '3') 
		{
			int bookNumber = editBook(), size = myModel.size();
			char choice;
			Book book;
			string editReplaceWord;

			choice = myView.showEditFieldNumber();
			book = myModel.getBook(bookNumber);
			editReplaceWord = myView.showEditBookReplacement(choice, book);
			editReplaceWord = showCheckRepeatWord(editReplaceWord, book, choice);
			myModel.edit(bookNumber, choice, editReplaceWord);
			myModel.clearFile();
			myModel.rewriteFile();
        }
	        
		else if (choice == '4')
		{	
			Book book;
			string key;
			key = myView.showSearchBook();
			book = myModel.searchByKey(key);
			myView.showSearchByKey(book);

			myModel.clearFile();
			myModel.rewriteFile();
		}
		
		else if (choice == '5')
		{
			int bookNumber = 0;
			myModel.clearVector();
			myModel.loadFromFile();
			int size = myModel.size();

			myView.showMessage("What book do you want to delete?");
			bookNumber = myView.getEditableData(bookNumber);
			bookNumber = searchDeletedData(size, bookNumber);

			myModel.deleteData(bookNumber);
			myModel.clearFile();
			myModel.rewriteFile();
		}
	
        else if (choice == '6') 
		{
            isFinished = true;
        }
    }
};

string Presenter::ISBNCheck() 
{
	string tempISBN;
	bool checkRepeatNumber = false, start = false;

	tempISBN = myView.getISBN();
	checkRepeatNumber = myModel.checkDublicated(tempISBN);
	while (true)
	{
		if (checkRepeatNumber == true)
		{
			myView.showMessage("This ISBN already exists, plz enter another one ");
			tempISBN = myView.getISBN();
			checkRepeatNumber = myModel.checkDublicated(tempISBN);
		}
		else if (checkRepeatNumber == false)
		{
			return tempISBN;
		}
	}
	
};

int Presenter::searchDeletedData(int size, int bookNumber)
{
	while (bookNumber > size)
	{
		myView.showMessage("There are too little books in this catalogue");
		myView.getEditableData(bookNumber);
		bookNumber -= 1;
		if (bookNumber <= size)
		{
			break;
		}
	}
	myView.showMessage("Data deleted succesfully!");
	return bookNumber;
};

int Presenter::editBook()
{
	int size = myModel.size();
	int bookNumber = myView.getBookNumberToEdit();
	while (true) 
	{
		if (bookNumber == 0) 
		{
			cin.clear();
			cin.ignore(32767, '\n');
			bookNumber = myView.getBookNumberToEdit();
		}
		else
		{
			break;
		}
	}
	while (bookNumber > size) 
	{
		myView.showWrongBookCapacity(size);
		bookNumber = myView.getBookNumberToEdit();
		if (bookNumber <= size) 
		{
			break;
		}
	}
	bookNumber -= 1;
	return bookNumber;
};

string Presenter::showCheckRepeatWord(string editReplaceWord, Book book, char choice)
{
	bool check;
	check = false;
	while (check != 1)
	{
		if (choice == '1')
		{
			if (editReplaceWord == book.name)
			{
				myView.showCheckDub();
			}
			else
			{
				check = true;
			}
		}
		else if (choice == '2')
		{
			if (editReplaceWord == book.author)
			{
				myView.showCheckDub();
			}
			else
			{
				check = true;
			}
		}
		else if (choice == '3')
		{
			if (editReplaceWord == book.releaseYear)
			{
				myView.showCheckDub();
			}
			else
			{
				check = true;
			}
		}
		else if (choice == '4')
		{
			if (editReplaceWord == book.ISBN)
			{
				myView.showCheckDub();
			}
			else
			{
				check = true;
			}
		}
	}
	return editReplaceWord;
};
