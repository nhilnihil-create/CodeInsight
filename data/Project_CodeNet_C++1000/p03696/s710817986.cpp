#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int main(){
    int n; cin>>n;
    string s; cin>>s;

    int close=0;
    int res=0;
    rep(i,0,n){
        if(s[i]=='(') res++;
        else if(res!=0){
            res--;
            close++;
        }
    }
    int rcnt=0;
    int lcnt=0;
    rep(i,0,n){
        if(s[i]=='(') lcnt++;
        else rcnt++;
    }
    string ans="";
    rep(i,0,rcnt-close) ans+='(';
    ans+=s;
    rep(i,0,lcnt-close) ans+=')';
    cout<<ans<<endl;
}