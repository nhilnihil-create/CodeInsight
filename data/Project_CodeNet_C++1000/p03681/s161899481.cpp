#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define nyan "(=^･ω･^=)"
using namespace std;

const int mod = 1e9 + 7;
const long long INF = 1LL<<60;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

long long factorial(long long n){
    long long temp = 1;
    for (int i = 1; i <= n; i++) temp *= i, temp %= mod;
    return temp;
}

int main(){
    long long n, m;
    cin >> n >> m;
    
    if (abs(n-m) >= 2){
        cout << 0 << endl;
        return 0;
    }
    
    if (n - m == 1){
        cout << (factorial(n) * factorial(m)) % mod << endl;
    }
    else if (m - n == 1) {
        cout  << (factorial(n) * factorial(m)) % mod << endl;
    }
    
    if (n == m){
        cout << (2 * factorial(n) * factorial(m)) % mod << endl;
    }
}
