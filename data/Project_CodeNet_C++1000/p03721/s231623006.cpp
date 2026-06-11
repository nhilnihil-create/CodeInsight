#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    ll N, K, b, v[100001]{};
    cin >> N >> K;
    while (cin >> N >> b) {
        v[N] += b;
    }
    N = 0;
    while (K > 0){
        K -= v[++N];
    }
    cout << N << endl;
}
