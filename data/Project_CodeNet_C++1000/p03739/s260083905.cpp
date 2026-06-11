#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//input
ll n;
vector<ll>a;
ll s;

ll solve(bool rem){
    s = 0;
    ll res = 0;
    for(int i=1;i<=n;i++){
        s += a[i];
        if(i%2==rem){
            if(s<=0){
                res += 1-s;
                s = 1;
            }
        }
        else{
            if(s>=0){
                res += s+1;
                s = -1;
            }
        }
    }
    return res;
}

int main(){
    cin >> n;
    a.resize(n+1,0);
    rep(i,n)cin>>a[i+1];
    cout << min(solve(1),solve(0)) << endl;

    return 0;
}

