#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	char a,b;
	cin >> a >> b;
	if (a == 'H') cout << b << endl;
	else
	{
		if (b == 'H') cout << 'D' << endl;
		else cout << 'H' << endl;
	}
	return 0;
}