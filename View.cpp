#include "View.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

string View::getName() 
{
    string name;
    cout << "Name" 					<< "= ";
    cin.ignore();
    getline(cin, name);
    return name;
}
string View::getAuthor() 
{
    string author;
    cout << "Author" 				<< "= ";
    getline(cin, author);
    return author;

}
string View::getYearOfRelease() 
{
    string releaseYear;
    cout << "Year of Release" 		<< "= ";
    getline(cin, releaseYear);
    return releaseYear;

}
string View::getISBN() 
{
    string ISBN;
    cout << "ISBN" 					<< "= ";
    getline(cin, ISBN);
    return ISBN;
}

void View::showCatalogue(int i, Book x) 
{
    cout << "\n";
    cout << "/***Book #" << i + 1 << "***/" << endl;
    cout << x.name << endl;
    cout << x.author << endl;
    cout << x.releaseYear << endl;
    cout << x.ISBN << endl;
    cout << "<----------------------->" << endl;
};

void View::showMessage( const char msg[] ) 
{
	cout << msg << endl;
};

string View::showSearchBook() 
{
    string key;
    cout << "The word that you wanna search by= ";
    cin >> key;
    return key;
};

string View::getSearchedString(string key)
{
	getline(cin, key);
    return key;
};

Book View::showSearchByKey(Book x) 
{
    cout << "\n";
    cout << "/***Book***/"                  << endl;
    cout << x.name                          << endl;
    cout << x.author                        << endl;
    cout << x.releaseYear                   << endl;
    cout << x.ISBN                          << endl;
    cout << "<----------------------->"     << endl;
    return x;
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


int View::showDeletedData(int vecSize) 
{
    int bookNumber;
    cout << "What book do you want to delete?" << endl;
    cin >> bookNumber;
    
    while (bookNumber > vecSize) 
    {
        cout << "There are too little books in this catalogue, enter from 1 to " << vecSize << endl;
        cin >> bookNumber;
        bookNumber -= 1;
        if (bookNumber <= vecSize) 
        {
            break;
        }
    }
    return bookNumber;
};


string View::showCheckRepeatWordNumber()
{
    string tempNumber;
    cout << "this ISBN already exists, you need to type another one" << endl;
    cin >> tempNumber;
    return tempNumber;
};



int View::showEditBookNumber(int vecSize)
{
    int bookNumber = 0;
    string replacement;

    while(true) 
	{
        cout << "What book do you want to change" << endl;
        cin >> bookNumber;
        if(cin.fail())
        {
            cin.clear(); 
            cin.ignore(32767, '\n'); 
        }
        else 
        {
            bookNumber -= 1;
            return bookNumber;
        }
    }
    while (bookNumber > vecSize) 
	{
        cout << "There are too little books in this catalogue, enter from 1 to " << vecSize << endl;
        cin >> bookNumber;
        if (bookNumber <= vecSize)
        {
            break;
        }
    }
    bookNumber -= 1;
    return bookNumber;
};


char View::showEditTempNumber() 
{    
    char b;
    cout << "Change Name(1), Author(2), Year of release(3), ISBN(4)" << endl;
    cin >> b;
    return b;
}


string View::showEditBookReplacement(char b, Book x, int d) 
{
    string replacement;
    d -= 1;

    if (b == '1')
	{
        cout << "The name that is currently written in the catalogue = " 				<< x.name <<            ",  Enter another name ";
        cin >> replacement;
    }
    else if (b == '2') 
	{
        cout << "The author that is currently written in the catalogue = " 				<< x.author <<          ", Enter another author ";
        cin >> replacement;
    }
    else if (b == '3') 
	{
        cout << "The year of release that is currently written in the catalogue = " 	<< x.releaseYear <<     ", Enter another year of release ";
        cin >> replacement;
    }
    else if (b == '4') 
	{
        cout << "The ISBN that is currently written in the catalogue = " 	            << x.ISBN <<            ", Enter another ISBN ";
        cin >> replacement;
    }
    return replacement;
};

string View::showCheckRepeatWord(string editReplaceWord, Book x, int n, char b)
{
    int i = 0;
    n -= 1;
    while (i != 1)
    {
        if (b == '1')
        {
            if (editReplaceWord == x.name)
            {
                cout << "This word is the same that the one you want to change, please enter another word" << endl;
                cin >> editReplaceWord;
            }
            else 
            {
                i = 1;
            }
        }
        else if (b == '2')
        {
            if (editReplaceWord == x.author)
            {
                cout << "This word is the same that the one you want to change, please enter another word" << endl;
                cin >> editReplaceWord;
            }
            else
            {
                i = 1;
            }
        }
        else if (b == '3')
        {
            if (editReplaceWord == x.releaseYear)
            {
                cout << "This word is the same that the one you want to change, please enter another word" << endl;
                cin >> editReplaceWord;
            }
            else
            {
                i = 1;
            }
        }
        else if (b == '4')
        {
            if (editReplaceWord == x.ISBN)
            {
                cout << "This word is the same that the one you want to change, please enter another word" << endl;
                cin >> editReplaceWord;
            }
            else
            {
                i = 1;
            }
        }
    }
    return editReplaceWord;
};





