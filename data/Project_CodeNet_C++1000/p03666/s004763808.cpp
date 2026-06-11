#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll M = 998244353;
const int N = 5*1e5+5;
const int K = 3000;
const ll INF = 1e18;
const double EPS = 1e-6;

ll n,a,b,c,d,l1,l2,r1,r2;

int main () {
	faster
	cin>>n>>a>>b>>c>>d;
	ll st = n-1;
	for (int i = 0; i<=st; i++) {
		l1 = a + i*c;
		r1 = a + i*d;
		l2 = b + (st - i)*c;
		r2 = b + (st - i) *d;
		if (l2<l1) {
			swap(l2,l1);
			swap(r2,r1);
		}
		if (l2 <= r1) {
			cout<<"YES";
			//cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
			return 0;
		}
	}
	cout<<"NO";

    return 0;
}
