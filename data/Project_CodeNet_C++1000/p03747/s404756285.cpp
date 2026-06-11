#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    ll N, L, T;
    cin >> N >> L >> T;
    ll X[N];
    int W[N];
    rep(i, N){
        cin >> X[i] >> W[i];
    }
    ll sum = 0;
    rep2(i, 1, N-1){
        if(W[i] == W[0]) continue;
        ll d;
        if(W[i] == 2 && W[0] == 1){
            d = X[i]-X[0];
        }
        else{
            d = L+X[0]-X[i];
        }
        if(2*T < d) continue;
        if(W[0] == 1){
            sum++;
            sum += (2*T-d)/L;
            sum %= N;
        }
        else{
            sum += N-1;
            sum += 2*N*T-(2*T-d)/L;
            sum %= N;
        }
    }
    rep(i, N){
        if(W[i] == 1){
            X[i] = (X[i]+T)%L;
        }
        else{
            X[i] = (X[i]+L*T-T)%L;
        }
    }
    ll st = X[0], be;
    sort(X, X+N);
    rep(i, N){
        if(X[i] < st) continue;
        elif(X[i] == st){
            if(W[0] == 2){
                if(X[(i+N-1)%N != st]){
                    be = i;
                    break;
                }
            }
            else{
                if(X[(i+1)%N] != st){
                    be = i;
                    break;
                }
            }
        }
    }
    rep(i, N){
        cout << X[(i+N+be-sum)%N] << endl;
    }
}