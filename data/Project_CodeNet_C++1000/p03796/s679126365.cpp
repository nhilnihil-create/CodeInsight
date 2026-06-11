#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif

	int n;
	cin >> n;

	long long res = 1;

	for (int i = 1; i <= n; i++)
	{
		res = ((res % 1000000007) * (i % 1000000007)) % 1000000007;
	}
	cout << res << endl;


	return 0;
}