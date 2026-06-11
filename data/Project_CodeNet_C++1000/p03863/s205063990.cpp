
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif

	string s;
	cin >> s;
	int k;
	if (s[0] == s[s.length() - 1])
	{
		k = s.length() - 3;

	}
	else
	{
		k = s.length() - 2;
	}

	if (k % 2)
		cout << "First" << endl;
	else
		cout << "Second" << endl;


}
