#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    int a,b,c; cin>>a>>b>>c;
    vector<int> x(3);
    x[0]=a; x[1]=b; x[2]=c;
    sort(all(x));
    cout<<x[0]+x[1]<<endl;
}