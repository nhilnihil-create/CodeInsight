#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(ll i = 0;i < (n); ++i)
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    string s,t={'N', 'W', 'S', 'E'};
    cin >> s;
    map<char, int> m;
    rep(i,t.size()){
        m[t[i]] = 0;
    }
    rep(i,s.size()){
        m[s[i]]++;
    }
    if(m['N'] == 0 && m['S'] > 0){
        cout << "No" << endl;
        return 0;
    }
    if(m['N'] > 0 && m['S'] == 0){
        cout << "No" << endl;
        return 0;
    }
    if(m['W'] == 0 && m['E'] > 0){
        cout << "No" << endl;
        return 0;
    }
    if(m['W'] > 0 && m['E'] == 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}