#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int gcd(int a, int b){ return b?gcd(b, a%b):a; }

bool canWin(vector<int> ov, vector<int> ev, ll s){
	int n=ov.size() + ev.size();
	if(n == 1){
		ov.pb(0); ev.pb(0);
		if(ov[0]+ev[0] == 1) return 0;
		else return 1;
	} else if(n == 2){
		if(ev.empty()) return 0;
		else return 1;
	} else {
		if((n&1) != (s&1)) return 1;
		if(ov.size() != 1) return 0;
		if(ov[0] == 1) return 0;
		--ov[0];
		vector<int> no, ne;
		ll ns=0;
		int ng=0;
		for(int& x:ov) ng=gcd(ng, x);
		for(int& x:ev) ng=gcd(ng, x);
		for(int& x:ov) x/=ng, ns+=x, ((x&1)?no:ne).pb(x);
		for(int& x:ev) x/=ng, ns+=x, ((x&1)?no:ne).pb(x);
		return !canWin(no, ne, ns);
	}
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> ov, ev;
    for(int i=1; i<=n; ++i){
		int x; scanf("%d",&x);
		if(x&1) ov.pb(x);
		else ev.pb(x);
    }
    ll s = accumulate(all(ov), 0LL) + accumulate(all(ev), 0LL);
    puts(canWin(ov, ev, s)?"First":"Second");
    return 0;
}
