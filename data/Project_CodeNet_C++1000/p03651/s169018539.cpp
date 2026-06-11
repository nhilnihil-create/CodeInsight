//Getting Difference

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
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,k;cin>>n>>k;
    vecrep(n,a,int);
    if(*max_element(range(a))<k){
        cout<<"IMPOSSIBLE"<<nnn;
        return 0;
    }
    int c = inf;
    sort(range(a),greater<int>());
    rep(i,0,n-1){
        if(a[i]==a[i+1])continue;
        c=min(c,a[i]-a[i+1]);
    }
    rep(i,0,n){
        if(abs(k-a[i])%c==0||k==a[i]){
            cout<<"POSSIBLE"<<nnn;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<nnn;
    return 0;
}