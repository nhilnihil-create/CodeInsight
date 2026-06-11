#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;

int main(){
    string s; cin>>s;
    map<char, int>mp;
    rep(i, s.size()){
        mp[s[i]]++;
    }
    bool jud = true;
    for (auto p : mp){
        if (p.second%2 != 0) jud = false;
    }
    if (jud) cout << "Yes" << endl;
    else cout << "No" << endl;
}