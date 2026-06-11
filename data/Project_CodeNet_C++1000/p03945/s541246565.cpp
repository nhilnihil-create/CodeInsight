#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    string s; cin>>s;
    int cnt=0;
    rep(i,1,s.size()){
        if(s[i]!=s[i-1]) cnt++;
    }
    cout<<cnt<<endl;
}