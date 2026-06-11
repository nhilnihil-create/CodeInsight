#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
const int MN = 105;
map<ll,vl> ew;
ll dp[MN][MN];
ll ch(ll n, ll k) {
	if(k > n || k < 0) {return 0;}
	if(k == 0 || n == 0) {return 1;}
	if(dp[n][k] != -1) {return dp[n][k];}
	return dp[n][k] = ch(n-1,k-1)+ch(n-1,k);
}
ll rmul(ll a, ll b) {
	if(a > 1e13/b) {
		return 1e13;
	}
	return a*b;
}
int main() {
	ll n;
	cin >> n;
	memset(dp,-1,sizeof(dp));
	for(int i=2;i<50;i++) {
		ll ok = (1LL<<(i-1))-1;
		ew[ok] = {i};
	}
	for(int i=1;i<=40;i++) {
		for(int j=1;j<=40;j++) {
			for(int k=1;k<=i;k++) {
				if(k+i > 40) {continue;}
				for(int l=1;l<=j;l++) {
					if(l+j > 40) {continue;}
					ll ct = 0;
					ct += ((1LL<<(i+k-1))-1);
					ct += ((1LL<<(j+l-1))-1);
					ll wa = 0,wb = 0;
					for(int a=1;a<=k;a++) {
						wa += ch(k,a)*ch(i,a);
					}
					for(int a=1;a<=l;a++) {
						wb += ch(l,a)*ch(j,a);
					}
					ct += rmul(wa,wb);
					ew[ct] = {i,j,k,l};
				}
			}
		}
	}
	for(int i=10;i<=20;i++) {
		for(int j=10;j<=20;j++) {
			for(int k=10;k<=20;k++) {
				for(int x=1;x<=10;x++) {
					for(int y=1;y<=10;y++) {
						for(int z=1;z<=10;z++) {
							ll ct = 0;
							ct += ((1LL<<(i+x-1))-1);
							ct += ((1LL<<(j+y-1))-1);
							ct += ((1LL<<(k+z-1))-1);
							ll rs = 1;
							ll wa = ch(x+i,x)-1;
							rs = rmul(rs,wa);wa = 0;
							wa = ch(y+j,y)-1;
							rs = rmul(rs,wa);wa = 0;
							wa = ch(z+k,z)-1;
							rs = rmul(rs,wa);
							ct += rs;
							ct += rmul(ch(x+i,x)-1,ch(y+j,y)-1);
							ct += rmul(ch(z+k,z)-1,ch(y+j,y)-1);
							ct += rmul(ch(x+i,x)-1,ch(z+k,z)-1);
							if(ct <= 1e12) {
							ew[ct] = {i,j,k,x,y,z};
							}
						}
					}
				}
			}
		}
	}
	ll C = 0;
	ll E = 1;
	vl res;
	while(n > 0) {
		auto it = ew.upper_bound(n);
		it--;
		vl val = (it->second);
		if(val.size() > 1) {
			int num = val.size()/2;
			for(int i=0;i<val.size();i++) {
				for(int j=0;j<val[i];j++) {
					res.push_back(E+(i%num));
				}
			}
			E += num;
		} else {
			for(int i=0;i<val.back();i++) {
				res.push_back(E);
			}
			E += 1;
		}
		n -= it->first;
	}
	cout << res.size() << '\n';
	for(int i=0;i<res.size();i++) {
		if(i > 0) {cout << " ";}
		cout << res[i];
	}
	cout << '\n';
}
