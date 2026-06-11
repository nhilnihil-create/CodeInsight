#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

int main(void){
    int N;
    ll A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    if(A > B) swap(A, B);
    for(int K = 0; K <= N-1; K++){
        ll ulim = D*K - C*((N-1) - K);
        ll dlim = C*K - D*((N-1) - K);
        if(dlim <= B-A && B-A <= ulim){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}