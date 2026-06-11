#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,a,b;
	cin >> n >> a >> b;
	ll mn = a*(n-1)+b;
	ll mx = b*(n-1)+a;
	cout << max(0LL,mx-mn+1)<<endl;
}
