#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int x,a,b;
	cin >> x >> a >> b;
	if (abs(x-a) < abs(x-b))
	{
		cout << "A" << endl;
	}
	else cout << "B" << endl;
	return 0;
}