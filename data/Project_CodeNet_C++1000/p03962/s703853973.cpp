#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    int a,b,c; cin>>a>>b>>c;
    map<int,int> m;
    m[a]++; m[b]++; m[c]++;
    cout<<m.size()<<endl;
}