#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    int a,b; cin>>a>>b;
    if(a==1) a=14;
    if(b==1) b=14;
    if(a>b) cout<<"Alice"<<endl;
    else if(a==b) cout<<"Draw"<<endl;
    else cout<<"Bob"<<endl;
}