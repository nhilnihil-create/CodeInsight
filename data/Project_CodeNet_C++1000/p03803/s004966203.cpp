#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int a,b;
	cin >> a >> b;
	if (a == b) cout << "Draw" << endl;
	else if (a == 1) cout << "Alice" << endl;
	else if (b == 1) cout << "Bob" << endl;
	else if (a > b) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}