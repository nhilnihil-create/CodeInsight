#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
//---------------
 
void qry(ll x) {
	printf("? %lld\n",x);
	fflush(stdout);
}
void print(ll x) {
	printf("! %lld\n",x);
	fflush(stdout);
}
bool check(ll mid) {
	qry(mid);
	char c;scanf("\n%c",&c);
//	cout<<c<<endl;
	return c=='Y';
}
bool che() {
    ll x=1e16;
    while(x) {
        qry(x);
		char c;scanf("\n%c",&c);
		if(c=='N') return 0;
		x=x/10ll;
    }
    ll y=999999999;
    while(y) {
        qry(y);
		char c;scanf("\n%c",&c);
		if(c=='N') {
		    print(y+1);
            return 1;    
        }
		y=y/10ll;
    }
    print(1);
    return 1;   
}
 
int main() {
    if(che()) return 0;
	ll x=1e16;
	for(;;) {
		qry(x);
		char c;scanf("\n%c",&c);
		if(c=='Y') break;
		x=x/10ll;
	}
	ll l=x*10,r=l*10-1,ans=-1;
	while(l<=r) {
		ll mid=(l+r)/2ll;
		if(check(mid)) {
			ans=mid;
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	print(ans/10);
	return 0;
}