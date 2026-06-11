/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[310][310];
    rep(i,0,N){
        rep(j,0,M){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    bool play[310];
    rep(i,0,M) play[i] = true;
    ll ans = INF;
    while(1){
        bool end = true;
        rep(i,0,M){
            if(play[i] == true) end = false;
        }
        if(end) break;
        ll num[310] = {};
        rep(i,0,N){
            rep(j,0,M){
                if(A[i][j] != -1){
                    num[A[i][j]]++;
                    break;
                }
            }
        }
        ll max_val = 0;
        rep(i,0,M){
            max_val = max(max_val, num[i]);
        }
        ans = min(ans, max_val);
        rep(i,0,N){
            rep(j,0,M){
                if(A[i][j] != -1){
                    if(num[A[i][j]] == max_val){
                        play[A[i][j]] = false;
                        A[i][j] = -1;
                    }
                }
            }
        }
    }
    print(ans);
    // rep(i,0,N){
    //     num[A[i][0]]++;
    // }
    // ll ans = INF
    // ll mv = 0;
    // rep(i,1,M+1) mv = max(mv, num[i]);



}