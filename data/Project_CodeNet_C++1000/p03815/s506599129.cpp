#include<bits/stdc++.h>
using namespace std;

int findmax(map<int, int>mp, long long x, long long maxi)
{
	long long totalscore = 0;
	long long ct = 0;

	while (totalscore < maxi)
	{
		int y = mp[x];
		totalscore += y;
		ct++;
	}
	return ct;
}

int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif


	long long x;
	cin >> x;
	long long zx = x / 11;
	long long y = x % 11;
	long long zc = 2 * zx + ceil(y / 6.0) ;
	cout << zc << endl;







	return 0;
}