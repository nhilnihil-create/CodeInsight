#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    if(2*n>=m){
        ans = m/2;
    }else{
        ans = (2*n+m)/4;
    }
    cout << ans << endl;
}