#ifndef PresenterH
#define PresenterH

#include <vector>
#include"Model.h"
#include"View.h"
#include"Book.h"


class Presenter
{
	private:
		Model myModel;
		View myView;
	public:
		Presenter() {};
		void start();
        string ISBNCheck();
};

#endif
