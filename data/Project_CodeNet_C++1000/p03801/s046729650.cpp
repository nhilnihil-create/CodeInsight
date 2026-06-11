#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    //amax[i] : i-1番目以前の石の山の内，最大個数を格納．
    vector<ll> amax(n, 0);
    for(int i = 1; i < n; ++i) amax[i] = max(amax[i-1], a[i-1]);
    vector<P> ap(n);
    //同じ石の個数の場合は前の山が前にくるように設定．
    rep(i,n){
        ap[i].first = a[i];
        ap[i].second = -i;
    }
    //石の個数が大きい順にソート．
    sort(ap.rbegin(), ap.rend());
    int cnt = 0;
    vector<ll> ans(n, 0);
    for(int i = 0, j = 0; i < n; ){
        //idx : 今見ている山が元の位置で何番目か．
        int idx = -ap[i].second;
        ++cnt;
        ans[idx] += (a[idx] - amax[idx]) * cnt;
        j = i + 1;
        while(j < n){
            if(amax[idx] < ap[j].first){
                ans[idx] += (ap[j].first - amax[idx]);
                ++cnt;
                ++j;
            }
            else break;
        }
        i = j;
    }
    rep(i,n) cout << ans[i] << endl;
	return 0;
}