#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif

	long long n, m;
	cin >> n >> m;


	long long  zx = min(n, m / 2);
	long long  left = n - zx;
	long long  right = m - (zx * 2);
	if (right == 0)
	{
		cout << zx << endl;
	}
	else {
		cout << zx + (right / 4) << endl;
	}


	return 0;
}