#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main()
{
	int n,m,k;
	cin >> n >>m >> k;

	rep(i,n+1)
	{
		rep(j,m+1)
		{
			if(i*j+(n-i)*(m-j)==k)
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
					cout<<"No"<<endl;

	return 0;
}