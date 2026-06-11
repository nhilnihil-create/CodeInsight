#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>

#include<iomanip>
using namespace std;
// استغفر الله العظيم
// عليه افضل الصلاه والسلام

int main()
{
	int n, m; cin >> n >> m;
	vector<vector<long long>>s(n, vector<long long>(2));
	vector<vector<long long>>ch(m, vector<long long>(2));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> ch[i][j];
		}
	}
	long long mn, sum = 0,t=0;
	for (int i = 0; i < n; ++i)
	{
		 mn = 10e11;
		for (int j = 0; j < m; ++j)
		{
			sum = 0;
			for (int k = 0; k < 2; ++k)
			{
				sum += abs(s[i][k] - ch[j][k]);
			}
			if (mn > sum)
			{
				mn = sum;
				t = j + 1;
			}
		}
		cout << t << endl;
	}

}