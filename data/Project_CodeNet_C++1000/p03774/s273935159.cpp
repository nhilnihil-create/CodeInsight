#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif


	long n, m;
	cin >> n >> m;

	vector<pair<int, int>>vp1;
	vector<pair<int, int>>vp2;

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		vp1.push_back(make_pair(a, b));
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		vp2.push_back(make_pair(a, b));
	}

	for (int i = 0; i < n; ++i)
	{
		int a = vp1[i].first;
		int b = vp1[i].second;
		int maxi = INT_MAX;
		int index;
		for (int j = 0; j < m; ++j)
		{
			if (abs(vp2[j].first - a) + abs(vp2[j].second - b) < maxi)
			{
				index = j;
				maxi = abs(vp2[j].first - a) + abs(vp2[j].second - b);
			}
		}

		cout << index + 1 << endl;





	}







	return 0;
}