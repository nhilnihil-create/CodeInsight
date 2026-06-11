#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s, t; cin >> s >> t;
    string ans = "";
    for(int i = 0; i < s.size() + t.size(); ++i){
        if(i % 2 == 0)ans += s[i/2];
        else ans += t[i/2];
    }
    cout << ans << endl;
}