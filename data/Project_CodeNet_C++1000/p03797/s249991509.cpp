#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,m;
	cin >> n >> m;
	ll ans = min(n,m/2);
	ll ANS = ans;
	n -= ans;
	m -= ans*2;
	ANS += m/4;
	cout<<ANS<<endl;
}
