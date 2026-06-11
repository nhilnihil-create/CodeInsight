#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    string s; cin >> s;
    ll ans = 0,ans2 = 0;
    char mem = s[0];

    for(int i = 1; i < s.length(); i ++){
        if(mem != s[i]){
            ans ++;
            mem = s[i];
        }
    }
    mem = s[s.length()-1];

    for(int i = s.length()-2; i >= 0; i --){
        if(mem != s[i]){
            ans2 ++;
            mem = s[i];
        }
    }

    cout << min(ans,ans2);
    return 0;
}
