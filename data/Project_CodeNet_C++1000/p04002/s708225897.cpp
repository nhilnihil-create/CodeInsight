#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc061.contest.atcoder.jp/tasks/arc061_b>
問題文============================================================
 縦 H 行、横 W 列のマス目からなる盤があります。最初、どのマス目も白く塗られています。
 
 すぬけ君が、このうち N マスを黒く塗りつぶしました。
 i 回目 ( 1≤i≤N ) に塗りつぶしたのは、 上から ai 行目で左から bi 列目のマスでした。
 
 すぬけ君がマス目を塗りつぶした後の盤の状態について、以下のものの個数を計算してください。
 
 各整数 j ( 0≤j≤9 ) について、盤の中に完全に含まれるすべての 3 行 3 列の連続するマス目のうち、
 黒いマスがちょうど j 個あるもの。

=================================================================

解説=============================================================

================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll H,W,N; cin >> H >> W >> N;
    vector<ll> a(N),b(N);
    for(int i = 0; i < N;i++) cin >> a[i] >> b[i];
    
    map<pll,ll> mp;
    for(int i = 0; i < N;i++){
        for(int j = -2; j <= 0; j++){
            for(int k = -2; k <= 0; k++){
                ll nx = a[i] + j,ny = b[i] + k;
                if(nx <= 0 || nx >= H - 1 || ny <= 0 || ny >= W - 1) continue;
                mp[pll(nx,ny)]++;
            }
        }
    }
    ll ans[10] = {0};
    for(auto it = mp.begin(); it != mp.end(); it++) ans[it->second]++;
    
    ll sum = (H - 2) * (W - 2);
    for(auto v:ans){
        sum -= v;
    }
    ans[0] += sum;
    for(auto v:ans){
        cout << v << endl;
    }
    
	return 0;
}
