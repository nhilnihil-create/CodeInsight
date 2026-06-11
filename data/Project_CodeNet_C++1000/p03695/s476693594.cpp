#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), cnt(9, 0);
    rep(i,n){
        cin >> a[i];
        if(a[i] >= 3200) cnt[8]++;
        else cnt[a[i]/400]++;
    }
    int mx = 0;
    rep(i,8){
        if(cnt[i] > 0) ++mx;
    }
    int mi = mx;
    mx += cnt[8];
    chmax(mi, 1);
    cout << mi << " " << mx << endl;
	return 0;
}