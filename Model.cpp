#include <iostream>
#include <fstream>
#include "Model.h"


void Model::clearFile()
{
	ofstream outf("C:\\Users\\Vlad\\Desktop\\Books.txt", ofstream::out | ofstream::trunc);
	outf.close();
};

void Model::clearVector() 
{
    books.clear();
};

void Model::loadFromFile() 
{
    ifstream inf("C:\\Users\\Vlad\\Desktop\\Books.txt");
	
    while (inf)
    {
    	Book x;
	    string strInput1;
        inf >> strInput1;
        if (strInput1 == "") 
		{
            continue;
        }
        else 
		{
            x.name = strInput1;            
            inf >> x.author;
            inf >> x.releaseYear;
            inf >> x.ISBN;
			books.push_back(x);
        }
    }
    inf.close();
};

Book Model::returnBook(int i) 
{
    int vecSize = books.size();
    Book x;
    for (; i < vecSize; i++) 
	{
        x.name 			=	books[i].name;
        x.author 		= 	books[i].author;
        x.releaseYear 	= 	books[i].releaseYear;
        x.ISBN 			= 	books[i].ISBN;
        return x;
    }
};

void Model::add(Book x) 
{
	ofstream outf("C:\\Users\\Vlad\\Desktop\\Books.txt", ios::app);
	
	if (!outf.eof()) 
	{
        outf << "\n";
    }
    outf << x.name << endl;
    outf << x.author << endl;
    outf << x.releaseYear << endl;
    outf << x.ISBN << endl;

	outf.close();
    books.push_back(x);	
    
};

Book Model::searchByKey(Book x, string key)
{
	int i;
    int vecSize = books.size();
    bool searchBK, check = true;
	for (i = 0; i < vecSize; i++) 
	{
        if (books[i].name == key || books[i].author == key || books[i].releaseYear == key || books[i].ISBN == key) 
		{
            searchBK = true;
            x.name = books[i].name;
            x.author = books[i].author;
			x.releaseYear = books[i].releaseYear; 
			x.ISBN = books[i].ISBN; 
            check = false;
            return x;
        }
    }
	if (check == true) 
	{
        x.name = "Not Found";
        return x;
    }	
};



void Model::rewriteFile()
{
    ofstream outf("C:\\Users\\Vlad\\Desktop\\Books.txt", ios::app);
    int vecSize = books.size();
    for (int i = 0; i < vecSize; i++) 
    {
        outf << books[i].name           << endl;
        outf << books[i].author         << endl;
        outf << books[i].releaseYear    << endl;
        outf << books[i].ISBN           << endl;
        outf << "\n";
    }
    outf.close();
};


void Model::deleteData(int bookNumber)
{
    int vectorSize = vecSize();
    bookNumber -= 1;
    books.erase(books.begin() + bookNumber);
};



bool Model::checkRepeatWordNumber(string tempNumber) 
{
    int vecSize = books.size();
    int repeatCounter = 0;
    for (int i = 0; i < vecSize; i++)
	{
        if (books[i].ISBN == tempNumber) 
		{
            return true;
        }
        else 
		{
            repeatCounter++;
        }
    }
    if (repeatCounter == vecSize)
    {
        return false;
    }
};


void Model::edit(int tempBookNumber, char tempNumber, string replacement)
{
    int bookNumber, vectorSize = vecSize();
    
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

int Model::vecSize()
{
    int a = books.size();
    return a;
};

Book Model::getBook(int i) 
{
    Book x;
    x.name =           books[i].name;
    x.author =         books[i].author;
    x.releaseYear =    books[i].releaseYear;
    x.ISBN =           books[i].ISBN;
    return x;
}


