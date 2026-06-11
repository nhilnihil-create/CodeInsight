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
    int k;
    cin >> s >> k;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        int id = s[i] - 'a';
        int id_pr = (id == 0 ? 0 : 26 - id);
        if(id_pr <= k){
            s[i] = 'a';
            k -= id_pr;
        }
    }
    s.back() = (s.back() - 'a' + k) % 26 + 'a';
    cout << s << endl;
}
