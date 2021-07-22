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
			int vecSize = myModel.vecSize();
			for (int i = 0; i < vecSize; i++) 
			{
				Book x;
				x = myModel.returnBook(i);
                myView.showCatalogue(i, x);
			}
        }
        else if (choice == '2')
		{
			Book x;
			x.name = myView.getName();
			x.author = myView.getAuthor();
			x.releaseYear = myView.getYearOfRelease();
		    x.ISBN = ISBNCheck();

            myModel.add(x);
			
        }

        else if (choice == '3') 
		{
			int bookNumber, vectorSize = myModel.vecSize();
			char choice;
			Book x;
			string editReplaceWord;

			bookNumber = myView.showEditBookNumber(vectorSize);
			choice = myView.showEditTempNumber();
			x = myModel.getBook(bookNumber);
			editReplaceWord = myView.showEditBookReplacement(choice, x, bookNumber);
			editReplaceWord = myView.showCheckRepeatWord(editReplaceWord, x, bookNumber, choice);
            myModel.edit(bookNumber, choice, editReplaceWord);
            myModel.clearFile();
            myModel.rewriteFile();
        }
	        
		else if (choice == '4')
		{	
			Book x;
			string key = myView.showSearchBook();
			x = myModel.searchByKey(x, key);
			myView.showSearchByKey(x);
		}
		
		else if (choice == '5')
		{
			myModel.clearVector();
			myModel.loadFromFile();
			int bookNumber;
			int vectorSize = myModel.vecSize();
			bookNumber = myView.showDeletedData(vectorSize);
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
	checkRepeatNumber = myModel.checkRepeatWordNumber(tempISBN);
	while (true)
	{
		if (checkRepeatNumber == true)
		{
			myView.showMessage("This ISBN already exists, plz enter another one ");
			tempISBN = myView.getISBN();
			checkRepeatNumber = myModel.checkRepeatWordNumber(tempISBN);
		}
		else if (checkRepeatNumber == false)
		{
			return tempISBN;
		}
	}
	
};

