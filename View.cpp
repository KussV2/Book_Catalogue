#include "View.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

string View::readName() 
{
    string name;
    cout << "Name" 					<< "= ";
    cin.ignore();
    getline(cin, name);
    return name;
}
string View::readAuthor() 
{
    string author;
    cout << "Author" 				<< "= ";
    getline(cin, author);
    return author;

}
string View::readYearOfRelease() 
{
    string releaseYear;
    cout << "Year of Release" 		<< "= ";
    getline(cin, releaseYear);
    return releaseYear;

}
string View::readISBN() 
{
    string ISBN;
    cout << "ISBN" 					<< "= ";
    getline(cin, ISBN);
    return ISBN;
}

void View::showCatalogue(int identificationNumber, Book book)
{
    cout << "\n";
    cout << "/***Book #" << identificationNumber + 1 << "***/"  << endl;
    cout << book.name                                           << endl;
    cout << book.author                                         << endl;
    cout << book.releaseYear                                    << endl;
    cout << book.ISBN                                           << endl;
    cout << "<----------------------->"                         << endl;
};

void View::showMessage( const char msg[] ) 
{
	cout << msg << endl;
};

string View::showSearchBook() 
{
    string key;
    cout << "What ISBN do you want to find ";
    cin.ignore();
    getline(cin, key);
    return key;
};

string View::getSearchedString(string key)
{
	getline(cin, key);
    return key;
};

Book View::showSearchByKey(Book book)
{
    cout << "\n";
    cout << "/***Book***/"                     << endl;
    cout << book.name                          << endl;
    cout << book.author                        << endl;
    cout << book.releaseYear                   << endl;
    cout << book.ISBN                          << endl;
    cout << "<----------------------->"        << endl;
    return book;
};

void View::showEnteredData(Book book)
{
	
	cout << "Name" 					<< "= " << endl;
	getline(cin, book.name);	
	
	cout << "Author" 				<< "= " << endl;
	getline(cin, book.author);
	
	cout << "Year of Release" 		<< "= " << endl;
	getline(cin, book.releaseYear);
	
	cout << "ISBN" 					<< "= " << endl;
	getline(cin, book.ISBN);	
};

char View::showMainChoices()
{
    char choice;
	cout << "Enter (1) to get the catalogue" 					<< endl;
    cout << "Enter (2) to add a book to the catalogue" 			<< endl;
    cout << "Enter (3) to edit a book in the catlogue" 			<< endl;
    cout << "Enter (4) to search for a book in the catlogue" 	<< endl;
    cout << "Enter (5) to delete a book from the catlogue " 	<< endl;
	cout << "Enter (6) to exit the conversation" 				<< endl;
    cin >> choice;
    return choice;
};


int View::getEditableData(int bookNumber) 
{
    cin >> bookNumber;
    return bookNumber;
};


string View::showCheckRepeatWordNumber()
{
    string tempNumber;
    cout << "this ISBN already exists, you need to type another one" << endl;
    cin >> tempNumber;
    return tempNumber;
};


char View::showEditFieldNumber() 
{    
    char bookNumber;
    cout << "Change Name(1), Author(2), Year of release(3), ISBN(4)" << endl;
    cin >> bookNumber;
    return bookNumber;
}


string View::showEditBookReplacement(char choice, Book book)
{
    string replacement;

    if (choice == '1')
	{
        cout << "The name that is currently written in the catalogue = " 				<< book.name <<            ",  Enter another name ";
        cin >> replacement;
    }
    else if (choice == '2')
	{
        cout << "The author that is currently written in the catalogue = " 				<< book.author <<          ", Enter another author ";
        cin >> replacement;
    }
    else if (choice == '3')
	{
        cout << "The year of release that is currently written in the catalogue = " 	<< book.releaseYear <<     ", Enter another year of release ";
        cin >> replacement;
    }
    else if (choice == '4')
	{
        cout << "The ISBN that is currently written in the catalogue = " 	            << book.ISBN <<            ", Enter another ISBN ";
        cin >> replacement;
    }
    return replacement;
};

string View::showCheckDub()
{
    string editReplaceWord;
    cout << "This word is the same that the one you want to change, please enter another word" << endl;
    cin >> editReplaceWord;
    return editReplaceWord;
};

int View::getBookNumberToEdit()
{
    int bookNumber = 0;
    cout << "What book do you want to change?" << endl;
    cin >> bookNumber;
    return bookNumber;
};

void View::showWrongBookCapacity(int size) 
{
    cout << "We don't have that many profiles, please enter from 1 to " << size << endl;
}




