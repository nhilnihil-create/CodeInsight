#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll C[51][51];

void comb_table(int n){
	rep(i,n+1)rep(j,i+1){
		if(j == 0 || j == i){
			C[i][j] = 1LL;
		}
		else{
			C[i][j] = (C[i-1][j-1] + C[i-1][j]);
		}
	}
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    ll even = 0;
    rep(i,n){
        cin >> a[i];
        a[i] %= 2;
        if(a[i] == 0) ++even;
    }
    comb_table(n);
    ll ans = pow(2, even);
    ll odd = n - even;
    ll mul = 0;
    if(p){
        for(ll i = 1; i <= odd; i+=2){
            mul += C[odd][i];
        }
    }
    else{
        for(ll i = 0; i <= odd; i+=2){
            mul += C[odd][i];
        }
    }
    ans *= mul;
    cout << ans << endl;
	return 0;
}