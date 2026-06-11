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
	string S;
	cin >> S;
	int x = 0;
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		if (S[i] == 'I')
		{
			x++;
		}
		else {
			x--;
		}
		maxi = max(maxi, x);
		/* code */
	}
	cout << maxi << endl;






	return 0;
}