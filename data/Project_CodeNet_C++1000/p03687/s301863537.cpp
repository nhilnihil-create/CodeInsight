//Shrinking 

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
using p = pair<ll, string>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    string s,ss;cin>>ss;
    int n = ss.size(),ans = inf;
    set<char>t{};
    rep(i,0,n)t.insert(ss[i]);
    for(auto i:t){
        s = ss;int c = 0;
        while(true){
            bool flag = true;
            rep(k,0,s.size())if(s[k]!=i)flag = false;
            if(flag||s.size()==1)break;
            c++;
            rep(k,0,s.size()-1)if(s[k+1]==i)s[k]=i;
            s.erase(s.begin()+s.size()-1);
        }
        ans=min(ans,c);
    }
    cout<<ans<<nnn;
    return 0;
}