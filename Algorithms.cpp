#include "Algorithms.h"

//----------------------------------------------------------------------------------------------------------------
//										Dynamic Programming Algorithm

string Dynamic(vector <pair<int, int>>& items, int& n, int& b)
{
	vector <vector<int>> matrix(n, vector<int>(b + 1, 0));
	//create matrix
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= b; j++)
		{
			if (items[i].first > j)
				matrix[i][j] = (i - 1 >= 0 ? matrix[i - 1][j] : 0);
			else
				matrix[i][j] = max((i - 1 >= 0 ? matrix[i - 1][j] : 0),
					(i - 1 >= 0 && j - items[i].first >= 0 ? matrix[i - 1][j - items[i].first] : 0) + items[i].second);
		}
	//read solution
	string solution = "";
	for (int i = 0; i < n; i++)
	{
		solution += '0';
	}
	int i = matrix.size() - 1, j = matrix[0].size() - 1;
	if (matrix[i][j] == 0)
		return solution;

	while (i >= 0 && j > 0)
	{
		if (i - 1 < 0)
		{
			solution[i] = '1';
			break;
		}
		if (matrix[i][j] != matrix[i - 1][j] && j - items[i].first <= 0)
		{
			solution[i] = '1';
			break;
		}
		if (matrix[i][j] == matrix[i - 1][j])
			--i;
		else
		{
			solution[i] = '1';
			j -= items[i].first;
			--i;
		}

	}
	return solution;
}

//----------------------------------------------------------------------------------------------------------------
//											  Greedy Algorithm

bool compare(pair<int, double> i, pair<int, double> j) { return i.second > j.second; }

string Greedy(vector <pair<int, int>>& items, int& n, int& b)
{
	int z = 0, w = 0;
	string solution = "";
	for (int i = 0; i < n; i++)
	{
		solution += '0';
	}
	vector <pair<int, double>> op;	//first==index second==value/weight
	for (int i = 0; i < n; i++)
		op.push_back(make_pair(i, items[i].second / double(items[i].first)));
	sort(op.begin(), op.end(), compare);

	for (int i = 0; i < n; i++)
	{
		if (z + items[op[i].first].first <= b)
		{
			z += items[op[i].first].first;
			w += items[op[i].first].second;
			solution[op[i].first] = '1';
		}
	}
	return solution;
}

//----------------------------------------------------------------------------------------------------------------
//											  Brute Force Algorithm

string BF(vector <pair<int, int>>& items, int& n, int& b)
{
	vector <string> solution;

	string sol = "";
	for (int i = 1; i < pow(2, n); i++)
	{
		string s;
		int len = n;
		do
			s.push_back(((i >> len) & 1) + '0');
		while (--len > -1);
		solution.push_back(s.substr(1));
	}
	int maxs = 0, su;
	for (int i = 0; i < solution.size(); i++)
		if (sum(solution[i], items, 0) <= b)
		{
			su = sum(solution[i], items, 1);
			if (su > maxs)
			{
				maxs = su;
				sol = solution[i];
			}
		}
	return sol;
}

//----------------------------------------------------------------------------------------------------------------
//											Calling algorithms

void algorithms(vector <pair<int, int>>& prz, int& n, int& b, bool t)
{
	string solution;
	//Brute force algorithm
	auto start = chrono::steady_clock::now();
	solution = BF(prz, n, b);
	auto stop = chrono::steady_clock::now();
	if (!t)
	{
		if (solution.size() > 0)
		{
			cout << "Brute Force Algorithm:\nSolution:\n";
			cout << solution << endl;
			cout << "Size: " << sum(solution, prz, 0) << endl;
			cout << "Goal function value: " << sum(solution, prz, 1) << endl;
			cout << "Elements:\n";
			for (int i = 0; i < solution.size(); i++)
				if (solution[i] == '1')
					cout << prz[i].first << " " << prz[i].second << endl;
			cout << endl;
		}
		else
		{
			cout << "You can't place anything in knapsack";
			return;
		}
	}
	else
		out << b << ";" << n << ";" << chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
	//Greedy algorithm
	start = chrono::steady_clock::now();
	solution = Greedy(prz, n, b);
	stop = chrono::steady_clock::now();
	if (!t)
	{
		cout << "Greedy Algorithm:\nSolution:\n";
		cout << solution << endl;
		cout << "Size: " << sum(solution, prz, 0) << endl;
		cout << "Goal function value: " << sum(solution, prz, 1) << endl;
		cout << "Elements:\n";
		for (int i = 0; i < solution.size(); i++)
			if (solution[i] == '1')
				cout << prz[i].first << " " << prz[i].second << endl;
		cout << endl;
	}
	else
		out << ";" << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << ";";
	//Dynamic programming algorithm
	start = chrono::steady_clock::now();
	solution = Dynamic(prz, n, b);
	stop = chrono::steady_clock::now();
	if (!t)
	{
		cout << "Dynamic Programming Algorithm:\nSolution:\n";
		cout << solution << endl;
		cout << "Size: " << sum(solution, prz, 0) << endl;
		cout << "Goal function value: " << sum(solution, prz, 1) << endl;
		cout << "Elements:\n";
		for (int i = 0; i < solution.size(); i++)
			if (solution[i] == '1')
				cout << prz[i].first << " " << prz[i].second << endl;
		cout << endl;
	}
	else
		out << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << endl;
	return;
}