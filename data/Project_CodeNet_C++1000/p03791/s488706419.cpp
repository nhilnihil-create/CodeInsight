#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-7;
const int inf=1e9+99;
const ll linf=1e18+88;
const int P=1e9+7;




int32_t main() {
	ll Z=1;
	int n; scanf("%d",&n);
	int ct=0;
	for(;n--;) {
		int x; scanf("%d",&x);
		++ct;
		if(x<=ct*2-2) Z=Z*ct%P, --ct;
		// cerr<<"got "<<x<<" curans "<<Z<<" and ct "<<ct<<endl;
	}
	for(;ct;) Z=Z*ct--%P;
	cout<<Z<<endl;
}


