#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    string s; cin >> s;
    ll n = s.size();
    map<char, bool> mp;
    rep(i,n)mp[s[i]] = 1;;
    if(mp['N']^mp['S'] == 0 && mp['W']^mp['E'] == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}