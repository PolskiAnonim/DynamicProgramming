#include "ReadData.h"

void data(bool a)
{
	system("cls");
	string filename;
	//number of items, knapsack weight limit, item weight, item value
	int n = 0, b = 0, weight, val;
	vector <pair<int, int>> items; //first==weight second==value

	if (a)			//Data from file
	{
		do {
			system("cls");
			cout << "----------------------Dynamic programming---------------------" << endl;
			cout << "------------------------Data from File------------------------" << endl;
			cout << "Write full filename (with extension) or 0 to cancel: ";
			cin >> filename;
			cin.sync();
			cin.clear();
			if (filename == "0")	//exit to previous menu
				return;
			if (filesystem::exists(filename))	//Look for file, exit loop when it exists
				break;
			else
				cout << "File doesn't exists!" << endl;
		} while (true);
		//read file
		ifstream in;
		in.open(filename.c_str());
		in >> n >> b;
		for (int i = 0; i < n; i++)
		{
			in >> weight >> val;
			if (weight > 0 && val > 0)
				items.push_back(make_pair(weight, val));
		}
		in.close();
	}
	else			//Data from keyboard
	{
		while (b <= 0)
		{
			system("cls");
			cout << "----------------------Dynamic programming---------------------" << endl;
			cout << "-----------------------Data from Keyboard---------------------" << endl;
			cout << "Knapsack weight limit: ";
			cin >> b;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Write items (weight and value separated by space) to use\n";
		cout << "or -1 -1 to end adding items: " << endl;
		while (true)
		{
			cin >> weight >> val;
			cin.sync();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (weight == -1 && val == -1)
				break;
			if (weight < 1 || val < 1)
			{
				cout << "Incorrect data!" << endl;
				continue;
			}
			items.push_back(make_pair(weight, val));
			n++;
		}
		if (items.size() == 0)
		{
			cout << "List is empty\nReturning" << endl;
			system("pause");
			return;
		}

	}
	algorithms(items, n, b, 0);
	system("pause");
}

