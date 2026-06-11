#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    bool ans = false;
    rep(i,n)cin>>a[i];
    int f = 0;
    int d = 0;
    int c = 0;
    rep(i,n){
        if(a[i]%4==0){
            f++;
        }
        else if(a[i]%2==0){
            d++;
        }
        else{
            c++;
        }
    }
    if(f>=c){
        ans = true;
    }
    if(f+1==c&&d==0)ans = true;
    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
