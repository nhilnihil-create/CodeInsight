#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    vector<int> x(3);
    cin>>x[0]>>x[1]>>x[2];
    sort(all(x));
    if(x[2]-x[1]==x[1]-x[0]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}