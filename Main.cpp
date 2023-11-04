#include "Libraries.h"
#include "ReadData.h"
#include "Test.h"
//----------------------------------------------------------------------------------------------------------------
//											  Count sum

int sum(string& x,vector<pair<int, int>> &items,bool r)
{
	int s = 0;
	for (int i = 0; i < x.size(); i++)
		s += (x[i] - '0') * (r == 0 ? items[i].first : items[i].second);
	return s;
}

//----------------------------------------------------------------------------------------------------------------
//												Main - Menu
int main()
{
	do
	{
		cin.clear();
		cin.sync();
		system("cls");
		cout << "--------------------Dynamic programming-------------------" << endl;
		cout << "0 - Exit\n1 - Load data from keyboard\n";
		cout<<"2 - Load data from file\n3 - Tests\nChoose option: ";
		char o = _getch();
		cout << o << endl;
		switch (o)
		{
		case '0':
			return 0;
			break;
		case '1':
			data(0);
			break;
		case '2':
			data(1);
			break;
		case '3':
			test();
			break;
		default:
			cout << "Wrong value!" << endl;
			system("pause");
		}
	} while (true);
}