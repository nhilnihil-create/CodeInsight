#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#include <random>
#define ll long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const int INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const int MOD = 1000000007;
const int MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;


bool ok(ll a,ll b, ll c,ll d){
    a%=3;b%=3;c%=3;d%=3;
    ll stype,ttype;
    if(a==b) stype=0;
    else if((a==0&&b==2)||(a==1&&b==0)||(a==2&&b==1)) stype=1;
    else stype=2;
    if(c==d) ttype=0;
    else if((c==0&&d==2)||(c==1&&d==0)||(c==2&&d==1)) ttype=1;
    else ttype=2;
    if(stype==ttype) return true;
    else return false;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    string s,t;
    cin>>s>>t;
    ll q,n=s.size(),m=t.size();
    cin>>q;
    ll An[100010]={},Bn[100010]={},Am[100010]={},Bm[100010]={};
    rep(i,n){
        if(s[i]=='A'){
            An[i+1]=An[i]+1;
            Bn[i+1]=Bn[i];
        } else{
            Bn[i+1]=Bn[i]+1;
            An[i+1]=An[i];
        }
    }
    rep(i,m){
        if(t[i]=='A'){
            Am[i+1]=Am[i]+1;
            Bm[i+1]=Bm[i];
        } else{
            Bm[i+1]=Bm[i]+1;
            Am[i+1]=Am[i];
        }
    }
    rep(Q,q){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        ll As,At,Bs,Bt;
        As=An[b+1]-An[a];
        Bs=Bn[b+1]-Bn[a];
        At=Am[d+1]-Am[c];
        Bt=Bm[d+1]-Bm[c];
        if(ok(As,Bs,At,Bt)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
