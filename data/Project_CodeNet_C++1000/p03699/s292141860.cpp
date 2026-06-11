#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
const double PI=acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n; cin>>n;
    vector<int> s(n);
    int sum=0;
    rep(i,0,n){
        cin>>s[i];
        sum+=s[i];
    }
    if(sum%10!=0){
        cout<<sum<<endl;
        return 0;
    }
    sort(all(s));
    rep(i,0,n){
        if(s[i]%10!=0){
            cout<<sum-s[i]<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}