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
	
	bool checkRepeatWordNumber(string tempNumber);

	Book returnBook(int i);
	Book searchByKey(Book x, string key);
//	Book searchBy(Book x, string key);
	Book getBook(int i);
	
	int vecSize();
};

#endif
