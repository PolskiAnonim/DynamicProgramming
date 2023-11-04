#include "Test.h"

ofstream out;

vector<pair<int, int>> vec_gen(int& n,int& b) // n - number of items, b - knapsack weight limit
{
	vector<pair<int, int>> items(n);
	srand(time(NULL));
	;	for (int i = 0; i < n; i++)
	{
		items[i].first = rand() % (b - 1) + 1; //weight
		items[i].second = rand() % (b - 1) + 1; //value
	}

	return items;
}

void test()
{
	out.open("results.txt");
	out << "Knapsack;Items;Brute force Algorithm;Greedy Algorithm;Dynamic Programming Algorithm" << endl;
	for (int b = 10; b < 100; b += 10)	// n - number of items, b - knapsack weight limit
	{
		for (int n = 4; n < 15; n += 1)
		{
			for (int i = 0; i < 10; i++)
			{
				vector <pair<int, int>> items = vec_gen(n, b);
				algorithms(items, n, b, 1);
			}
		}
	}
	out.close();
	system("pause");
	return;
}