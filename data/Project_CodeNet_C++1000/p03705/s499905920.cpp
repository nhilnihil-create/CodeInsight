#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    ll N , A , B;
    cin >> N >> A >> B;
    ll C = A * (N - 1) + B;
    ll D = B * (N - 1) + A;
    if(D - C + 1 <= 0){
        cout << 0 << endl;
    }
    else{
        cout << D - C + 1 << endl;
    }
}