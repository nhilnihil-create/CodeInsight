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
    string s,t;cin>>s>>t;
    vector<ll>sa(s.size()+1),sb(s.size()+1),ta(t.size()+1),tb(t.size()+1);
    REP(i,1,s.size()+1){
        sa[i]=sa[i-1];
        sb[i]=sb[i-1];
        if(s[i-1]=='A')sa[i]++;
        else sb[i]++;
    }
    REP(i,1,t.size()+1){
        ta[i]=ta[i-1];
        tb[i]=tb[i-1];
        if(t[i-1]=='A')ta[i]++;
        else tb[i]++;
    }
    ll q;cin>>q;
    rep(i,q){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        ll x=sa[b]-sa[a-1]-(sb[b]-sb[a-1]);
        ll y=ta[d]-ta[c-1]-(tb[d]-tb[c-1]);
        x%=3,y%=3;
        if(x<0)x+=3;
        if(y<0)y+=3;
        cout<<(x==y?"YES":"NO")<<endl;
    }
}