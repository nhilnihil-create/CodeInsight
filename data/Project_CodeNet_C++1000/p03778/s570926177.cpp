#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif

	long long w, a, b;
	cin >> w >> a >> b;


	if (b > a + w)
	{
		cout << b - a - w << endl;
	}
	else if (a > b + w)
	{
		cout << a - b - w << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}