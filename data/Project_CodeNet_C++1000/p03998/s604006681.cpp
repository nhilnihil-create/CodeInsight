//3人でカードゲームイージー

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
    vector<string>s(3);
    cin>>s[0]>>s[1]>>s[2];
    int o = s[0][0]-97;
    s[0].erase(0,1);
    while(true){
        if(o==0&&s[0].empty()){cout<<"A"<<nnn;return 0;}
        else if(o==1&&s[1].empty()){cout<<"B"<<nnn;return 0;}
        else if(o==2&&s[2].empty()){cout<<"C"<<nnn;return 0;}
        int c = s[o][0];
        s[o].erase(0,1);
        o=c-97;
    }
    return 0;
}