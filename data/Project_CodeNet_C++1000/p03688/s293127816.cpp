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
    ll N;
    cin >> N;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    sort(A, A+N);
    if(A[N-1] - A[0] >= 2){
        print("No");
    }else{
        if(A[N-1] == A[0]){
            if(A[0] <= N/2 || A[0] == N-1){
                print("Yes");
            }else{
                print("No");
            }
        }else{
            ll cnt = 0;
            rep(i,0,N){
                if(A[i] == A[0]) cnt++;
            }
            ll v = A[0] + 1 - cnt;
            if(v <= 0){
                print("No");
                return 0;
            }
            if((N-cnt) / 2 >= v){
                print("Yes");
            }else{
                print("No");
            }

        }

    }
}