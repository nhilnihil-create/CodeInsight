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
    ll a,b,x;
    cin >> a >> b >> x;

    ll ans = 0;
    if(a==0) ans = b/x + 1;
    else ans = b/x - (a-1)/x;
    cout(ans);
    return 0;
}