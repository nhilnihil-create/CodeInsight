#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18;
ll MOD = 1e9+7;



int main() {
    ll H, W; cin >> H >> W;
    map<char, ll> M;
    for(int i = 0; i < H; i++){
        string S; cin >> S;
        for(auto ch : S) M[ch]++;
    }
    ll o=0, t=0;
    for(auto m : M) {
        if(m.second %2 != 0) o++;
        else if(m.second % 4 != 0 && m.second % 2 == 0) t++;
    }
    bool flag = false;
    if(H % 2 == 0 && W % 2 == 0){
        if(o == 0 && t == 0) flag = true;
    }
    else if(H % 2 == 0 || W % 2 == 0){
        ll temp;
        if(H %2 == 0) temp = H;
        else temp = W;
        if(o== 0 && t <= temp/2) flag = true;
    }
    else{
        if(o == 1 && t <= H/2 + W/2)flag = true;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}