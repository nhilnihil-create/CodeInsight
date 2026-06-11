#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

signed main(){
    string s;
    cin >> s;
    int n = s.size();
    int cn = 0;
    int ans = n;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'S'){
            ++cn;
        }
        else{
            if(cn){
                --cn;
                ans -= 2;
            }
        }
    }
    cout << ans << endl;
}

