#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    vector<ll>x(n);
    rep(i,n)cin>>x[i];
    ll i=0;
    ll ans=1;
    ll cnt=1;
    REP(i,1,n){
        if(x[i-1]>=2*cnt-1){
            cnt++;
        }else{
            ans*=cnt;
            cnt--;
            ans%=inf;
            i--;
        }
    }
    while(cnt){
        ans*=cnt;
        cnt--;
        ans%=inf;
    }
    cout<<ans<<endl;
}