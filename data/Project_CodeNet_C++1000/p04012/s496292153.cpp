#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string w;
    cin >> w;

    map<char, int> mp;
    for(int i = 0; i < (int)w.size(); i++){
        mp[w[i]]++;
    }
    bool ok = true;
    for(auto v: mp){
        if(v.second % 2 == 1) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}