#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1e18+5;

int main()
{
	int n;
	cin >> n;
	ll tempt,tempa,t,a;
	cin >> t >> a;
	tempt = t; tempa = a;
	rep(i,n-1)
	{
		cin >> t >> a;
		ll nt = (tempt + t - 1) / t, na = (tempa + a - 1) / a;
		tempt = max(nt,na) * t;
		tempa = max(nt,na) * a;
		
		//cout << "now:" << tempt << " " << tempa << endl;
	}
	cout << tempt + tempa << endl;
	return 0;
}