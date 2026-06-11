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
    int n,m;
    cin >> n;
    vi t(n);
    rep(i,n) cin >> t[i];
    cin >> m;
    vi p(m),x(m);
    rep(i,m) cin >> p[i] >> x[i];

    int sum = 0;
    rep(i,m){
        sum = 0;
        rep(j,n){
            if(p[i]-1==j) sum += x[i];
            else sum += t[j];
        }
        cout(sum);
    }
    return 0;
}