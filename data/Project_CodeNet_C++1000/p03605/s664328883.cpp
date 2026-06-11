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
    if(n%10==9){
        cout << "Yes" << endl;
        return 0;
    }
    n/=10;
    if(n==9){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}