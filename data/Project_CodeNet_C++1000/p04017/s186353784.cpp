#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int R[23][100100];
int main(){
    int N;
    cin >> N;
    vector<ll> X(N);
    REP(i,N){
        ll x;
        cin >> x;
        X[i] = x;
    }

    ll L;
    cin >> L;

    int Q;
    cin >> Q;

    REP(k,N){
        R[0][k] = upper_bound(X.begin(), X.end(), X[k]+L) - X.begin() - 1;
    }

    REP(i,20){
        REP(k,N){
            R[i+1][k] = R[i][R[i][k]];
        }
    }

    REP(i,Q){
        int a, b;
        int ans = 0;
        cin >> a >> b;
        a--, b--;
        if(a > b) swap(a,b);

        for(int i = 20; i >= 0; i--){
            int r = R[i][a];
            if(r < b){
                a = r;
                ans += 1 << i;
            }
        }

        cout << ans+1 << endl;
    }
    return 0;
}
