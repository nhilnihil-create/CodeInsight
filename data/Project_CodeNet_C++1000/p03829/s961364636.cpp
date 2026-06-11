#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}



int main() {
    ll N,A,B; cin >> N >> A >> B;
    vector<ll> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    ll res = 0;
    for (int i = 0; i < N-1; i++) {
        res += min(A*(X[i+1]-X[i]),B);
    }
    cout << res << endl;
    
}