#ifndef ModelH
#define ModelH
#include "Book.h"
#include <vector>


class Model
{
private:
	vector<Book> books;
public:
	Model()	{};

	void rewriteFile();
	void deleteData(int bookNumber);
	void edit(int tempBookNumber, char tempNumber, string replacement);
	void clearFile();
	void clearVector();
	void loadFromFile();
	void add(Book book);
	
	bool checkDublicated(string tempNumber);

	Book searchByKey(string key);
	Book getBook(int number);
	
	int size();
};

#endif
