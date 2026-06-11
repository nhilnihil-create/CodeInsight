#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main(){
    bool f1 = false, f2 = false;
    string s; cin >> s;
    map<char,int> mp;

    for(auto c:s){
        mp[c]++;
    }

    if(mp['S'] > 0 && mp['N'] > 0 ||
        mp['S'] == 0 && mp['N'] == 0){
            f1 = true;
    }else{
        f1 = false;
    }
    if(mp['E'] > 0 && mp['W'] > 0 ||
        mp['E'] == 0 && mp['W'] == 0){
            f2 = true;
    }else{
        f2 = false;
    }

    cout << (f1 && f2 ? "Yes" : "No") << endl;
}