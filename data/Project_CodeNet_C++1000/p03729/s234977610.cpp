#include<bits/stdc++.h>
using namespace std;
 
 
#define mod(cans) cans%10**9+7
#define debug(x) cout << "Debug" << x << "\n"
#define rep(i,n) for(unsigned i=0;i<n;i++)
#define repr(i,n) for(unsigned i=n-1;i>=0;i--)
#define rep1(i,n) for(unsigned i=1;i<=n;i++)
#define cin_pl(n,x) rep(i,n){cin>>x[i];}
#define cins(s,n) rep(i,n)cin>>s.at[i];
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define prians(Answer) cout<<Answer<<"\n"
#define TF(X) X==1?cout<<"YES\n":cout<<"NO\n"
#define elcon else{continue;}
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int> > matrix;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef greater<int> gi;
typedef vector<unsigned> vu;


ll gcd(ll x, ll y) { return (y == 0) ? x : gcd(y, x % y); }
bool is_prime(const unsigned n){
    switch(n){
        case 0:
        case 1: return false;
        case 2: return true;
    }
 
 
    for(unsigned i=2;i<n;++i){
        if(n%i == 0) return false;
    }
 
    return true;
}


bool F(string s,string t,string u)
{
    if(s[s.length()-1]==t[0]&&t[t.length()-1]==u[0])return true;
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t,u;cin>>s>>t>>u;
    TF(F(s,t,u));
}