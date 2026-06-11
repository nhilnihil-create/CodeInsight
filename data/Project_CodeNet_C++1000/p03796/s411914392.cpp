#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;


int main(){
    ll n;
    cin >> n;

    ll ans=1;
    ll x = 1e9 + 7;
    for(int i=1; i<=n; ++i){
        ans =  (i*ans)%x;
    }
    cout(ans);
    return 0;
}