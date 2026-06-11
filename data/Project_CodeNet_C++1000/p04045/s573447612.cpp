#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    int n,k;
    cin >> n >> k;
    vector<int>d(k);
    rep(i,k)cin>>d[i];
    vector<bool>v(10,false);
    rep(i,k)v[d[i]]=true;
    for(int i=n;i<=100000;i++){
        bool flag =false;
        int tmp = i;
        while(tmp>0){
            int now = tmp % 10;
            if(v[now])flag = true;
            tmp /= 10;
        }
        if(flag)continue;
        cout << i << endl;
        return 0;
    }

    return 0;
}
