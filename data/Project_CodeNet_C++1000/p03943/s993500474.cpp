#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    vector<int> s(3);
    rep(i,0,3) cin>>s[i];
    sort(all(s));
    if(s[0]+s[1]==s[2]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}