#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;

template<typename T>
T modPow(T x, T n, const T &mod){
    T res = 1;
    while(n > 0){
        if(n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1; // nを1bit左にずらす
    }
    return res;
}

int main() {
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    ll sum = 0;
    bool x = false, y = false;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(s1[i] == s1[i + 1]){
                sum += 6;
                y = true;
                i++;
            }
            if(s1[i] == s2[i]){
                sum += 3;
                x = true;
            }
        }else{
            if(s1[i] == s1[i + 1]){
                if(x) (sum *= 2) %= MOD;
                else if(y) (sum *= 3) %= MOD;
                y = true;
                x = false;
                i++;
            }else if(s1[i] == s2[i]){
                if(x) (sum *= 2) %= MOD;
                x = true;
                y = false;
            }
        }
    }

    cout << sum % MOD << endl;
}
