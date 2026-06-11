#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    string a,b,c; cin>>a>>b>>c;
    if(a[a.size()-1]==b[0]&&b[b.size()-1]==c[0]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}