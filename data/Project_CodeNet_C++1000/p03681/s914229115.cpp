#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int64_t kaijo(int64_t n){
    if(n==1) return n;
    return (kaijo(n-1))%INF * n;
}

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n,m;
    cin >> n >> m;
    int64_t res = 0;
    if(n==m){
        res = 2 * ((kaijo(n)%INF) * (kaijo(m)%INF))%INF;
    }
    if(abs(n-m)==1){
        res = ((kaijo(n)%INF) * (kaijo(m)%INF))%INF;
    }
    cout << res << endl;
}