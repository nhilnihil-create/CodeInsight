#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
	int a, b; cin >> a >> b;
	vector<vector<long long>>che(b, vector<long long>(2));
	vector<vector<long long>>stu(a, vector<long long>(2));
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> stu[i][j];
		}
	}
	for (int i = 0; i < b; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> che[i][j];
		}
	}
	int c = 0;
	for (int i = 0; i < a; ++i)
	{
		int mn = 100000000000;
		for (int j = 0; j< b; ++j)
		{
			int sum = 0;
			for (int k = 0; k < 2; ++k)
			{
				sum += abs(stu[i][k] - che[j][k]);
			}
			if (mn > sum){
				mn = sum;
				c = j + 1;
	         	}
		}
		cout << c << endl;
	}
	
}