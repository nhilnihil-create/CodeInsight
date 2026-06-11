//Simple Calculator

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "

using p = pair<ll,string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int a,b;cin>>a>>b;
    if(a*b>0){
        if(a<b){
            cout<<b-a<<nnn;
        }else{
            cout<<a-b+2<<nnn;
        }
    }else if((a==0&&b<0)||(b==0&&a>0)){
        cout<<abs(b-a)+1<<nnn;
    }else{
        cout<<min(abs(a-b),abs(-a-b)+1)<<nnn;
    }
    return 0;
}