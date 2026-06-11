//Palindromic Matrix

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int h,w;cin>>h>>w;
    vecrep(h,a,string);
    map<int,int>m;
    rep(i,0,h)rep(j,0,w)m[a[i][j]-'a']++;
    bool ans=true;
    int o=0,t=0,s=0,f=0;
    for(auto i:m){
        if(i.second%4==1)o++;
        else if(i.second%4==2)t+=2;
        else if(i.second%4==3)s+=3;
    }
    bool flag=true;
    if(o>1||s!=0)flag=false;
    if((w&1)&&(h&1)){
        if(o!=1)flag=false;
        if(h+w-2<t)flag=false;
    }else if(w&1){
        if(h<t)flag=false;
    }else if(h&1){
        if(w<t)flag=false;
    }else{
        if(t!=0)flag=false;
    }
    if(flag)cout<<"Yes"<<nnn;
    else cout<<"No"<<nnn;
    return 0;
}