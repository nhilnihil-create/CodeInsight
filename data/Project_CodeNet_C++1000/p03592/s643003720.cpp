#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n,m,K;
    cin >> n >> m >> K;
    bool ok = false;
    for(int l=0;l<=m;l++){
        int e = m - 2*l;
        int r = K-n*l;
        if(e<=0) break;
        if(r%e==0 && r/e>=0 && r/e<=n){
            ok = true;
            break;
        }
    }
    cout << (ok? "Yes" : "No") << endl;
}