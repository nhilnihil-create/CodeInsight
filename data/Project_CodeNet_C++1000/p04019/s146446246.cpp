#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    string s;
    cin >> s;
    // NがあるなあらSが必要
    // EがあるなあらWが必要
    bool isN=false;
    bool isE=false;
    bool isW=false;
    bool isS=false;
    rep(i,s.size()){
        if(s.at(i)=='N') isN=true;
        if(s.at(i)=='E') isE=true;
        if(s.at(i)=='W') isW=true;
        if(s.at(i)=='S') isS=true;
    }
    if((isN!=isS)||(isE!=isW)){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}