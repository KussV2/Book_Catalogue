#ifndef BookH
#define BookH

#include <string>

using namespace std;

struct Book 
{
	string name;
	string author;
	string releaseYear;
	string ISBN;
	
	string toString() {
		return
			"name:" + name +"\n" +
			"author:" + author +"\n" +
			"year:" + releaseYear +"\n" +
			"isbn:" + ISBN +"\n";
	}
};

#endif
