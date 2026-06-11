#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

const int mod = 1000000000 + 7;
ll N, M;
ll X[100010];
ll Y[100010];

int main(){

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> X[i];
    for(int i = 0; i < M; i++) cin >> Y[i];
    ll base = 0;
    for(int i = 1; i < N; i++){
        (base += (((X[i] - X[i-1]) * i) % mod) * (N - i)) %= mod;
    }
    ll ans = 0;
    for(int i = 1; i < M; i++){
        (ans += ((((base * i) % mod) * (M - i)) % mod) * (Y[i] - Y[i-1])) %= mod;
    }

    cout << ans << endl;


    return 0;
}
