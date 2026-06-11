#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main()
{
	int a,b;
	cin  >> a >>b;
	if(a+b>9)
	{
		cout<<"error"<<endl;
	}
	else
	{
		cout<<a+b<<endl;
	}
	
	return 0;
}