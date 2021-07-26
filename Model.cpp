#include <iostream>
#include <fstream>
#include "Model.h"

const string Path = "C:\\Users\\Vlad\\Desktop\\Books.txt";

void Model::clearFile()
{
	ofstream outf(Path, ofstream::out | ofstream::trunc);
	outf.close();
};

void Model::clearVector() 
{
    books.clear();
};

void Model::loadFromFile() 
{
    ifstream inf(Path);
	
    while (inf)
    {
    	Book book;
	    string strInput1;
        getline(inf, strInput1);
        if (strInput1 == "") 
		{
            continue;
        }
        else 
		{
            book.name = strInput1;
            getline(inf, book.author);
            getline(inf, book.releaseYear);
            getline(inf, book.ISBN);
			books.push_back(book);
        }
    }
    inf.close();
};

void Model::add(Book book)
{
	ofstream outf(Path, ios::app);
	
	if (!outf.eof()) 
	{
        outf << "\n";
    }
    outf << book.name           << endl;
    outf << book.author         << endl;
    outf << book.releaseYear    << endl;
    outf << book.ISBN           << endl;

	outf.close();
    books.push_back(book);
};

Book Model::searchByKey(string key)
{
    Book book;
    int size = books.size();
	for (int number = 0; number < size; number++)
	{
        if (books[number].ISBN == key)
		{
            book.name =             books[number].name;
            book.author =           books[number].author;
            book.releaseYear =      books[number].releaseYear;
            book.ISBN =             books[number].ISBN;
            return book;
        }
    }
     book.name = "Not Found";
     return book;
};



void Model::rewriteFile()
{
    ofstream outf(Path, ios::app);
    int size = books.size();
    for (int number = 0; number < size; number++)
    {
        outf << books[number].name           << endl;
        outf << books[number].author         << endl;
        outf << books[number].releaseYear    << endl;
        outf << books[number].ISBN           << endl;
        outf << "\n";
    }
    outf.close();
};


void Model::deleteData(int bookNumber)
{
    int vectorSize = size();
    bookNumber -= 1;
    books.erase(books.begin() + bookNumber);
};



bool Model::checkDublicated(string tempNumber) 
{
    int size = books.size();
    int repeatCounter = 0;
    for (int number = 0; number < size; number++)
	{
        if (books[number].ISBN == tempNumber)
		{
            return true;
        }
        else 
		{
            repeatCounter++;
        }
    }
    if (repeatCounter == size)
    {
        return false;
    }
};


void Model::edit(int tempBookNumber, char tempNumber, string replacement)
{
    int bookNumber, vectorSize = size();
    
    bookNumber = tempBookNumber;

    if (tempNumber == '1') 
	{
        books[bookNumber].name = replacement;
    }
    else if (tempNumber == '2') 
	{
        books[bookNumber].author = replacement;
    }
    else if (tempNumber == '3') 
	{
        books[bookNumber].releaseYear = replacement;
    }
    else if (tempNumber == '4') 
	{
        books[bookNumber].ISBN = replacement;
    }
};

int Model::size()
{
    int size = books.size();
    return size;
};

Book Model::getBook(int number)
{
    Book book;
    book.name =           books[number].name;
    book.author =         books[number].author;
    book.releaseYear =    books[number].releaseYear;
    book.ISBN =           books[number].ISBN;
    return book;
}


