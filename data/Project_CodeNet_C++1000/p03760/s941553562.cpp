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
#define TF(X) X==1?cout<<"Yes\n":cout<<"No\n"
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
int Digits(unsigned x)
{
    int ans=0;
    while(x!=0)
    {
        x/=10;
        ans++;
    }
    return ans;
}
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}


int main()
{
    cin.tie(0);
ios_base::sync_with_stdio(false);
string s,t,z="";cin>>s>>t;
rep(i,s.length())
{
    z+=s[i];
    if(i!=s.length()-1||s.length()==t.length())
    z+=t[i];
    
}
cout<<z;

}    