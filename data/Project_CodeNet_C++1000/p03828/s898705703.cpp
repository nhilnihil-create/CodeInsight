//-fexec-charset=CP932
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100
#define THOU 1000
#define FIVEMAX 100000
#define NINEMAX 1000000000
#define TWEMAX 1000000000000
#define rep(i,n) for (int i=0;i<n;i++)
#define drep(i,n) for(int i=n-1;i>=0;i--)
#define arep(i,a,n) for(int i=a;i<n;i++)
#define darep(i,a,n) for(int i=n,i>=a;i--)

vector<pair<ll,ll>>prime_factorize(ll n){
    vector<pair<ll,ll>>res;
    for(ll a=2;a*a<=n;a++){
        if(n%a!=0)continue;
        ll ex=0;
        while(n%a==0){
            ex++;
            n/=a;
        }res.push_back({a,ex});
    }
    if(n!=1)res.push_back({n,1});
    return res;
}


int main(){
    ll n;
    cin>>n;
   
 cin.tie(0);
 ios::sync_with_stdio(false);
 string str;
 vector<int>v(n);
 map<string,int>m;
 pair<int,int>p;
 vector<ll>ex(n+1,0);

 for(ll i=2;i<=n;i++){
     const auto &res=prime_factorize(i);
     for(auto p:res)ex[p.first]+=p.second;
 }

 ll res=1;
 const int MOD = 1000000007;
 arep(i,2,n+1){
     res*=ex[i]+1;
     res%=MOD;
 }
 
 
 cout<<res<<endl;
 return 0;
}


