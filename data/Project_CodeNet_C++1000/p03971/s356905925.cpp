#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,a,b;
    string s;
    cin>>n>>a>>b>>s;
    ll ta=0,tb=0;
    rep(i,n){
        if(s[i]=='a' && ta+tb<a+b){
            cout<<"Yes"<<endl;
            ta++;
        }else if(s[i]=='b' && ta+tb<a+b && tb<b){
            cout<<"Yes"<<endl;
            tb++;
        }else cout<<"No"<<endl; 
    }
    return 0;
}