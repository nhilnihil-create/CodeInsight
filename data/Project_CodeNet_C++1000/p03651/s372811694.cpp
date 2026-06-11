#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;

//最大公約数
int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main(){
    int N, K; cin >> N >> K;
    ll Max = 0;
    vector<ll> V(N); 
    for(int i = 0; i < N; i++) { 
        cin >> V[i]; 
        Max = max(Max, V[i]);
        if(V[i] == K){cout << "POSSIBLE" << endl; return 0;}
    }
    if(N == 1) {
        if(V[0] == K) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if(Max < K){ cout << "IMPOSSIBLE" << endl; return 0;}

    ll GCD = gcd(V[0], V[1]);
    for(int i = 2; i < N; i++) GCD = gcd(GCD, V[i]);

    if(K % GCD == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    


}