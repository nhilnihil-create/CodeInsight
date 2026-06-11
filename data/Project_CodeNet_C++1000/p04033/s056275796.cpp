#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;


int main(){
    string ans;
    ll a,b; cin>>a>>b;
    if(b<0){
        if((b-a)%2==1){
            ans="Positive";
        }else{
            ans="Negative";
        }
    }else if(b==0){
        ans="Zero";
    }else{
        if(a>0){
            ans="Positive";
        }else{
            ans="Zero";
        }
    }
    cout<<ans<<endl;
}