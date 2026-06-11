//Insertion

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
    int n;string s;cin>>n>>s;
    int c{},ans{};
    rep(i,0,s.size()){
        if(s[i]==')'){
            if(c>=1)c--;
            else{
                s.insert(s.begin(),'(');
                i++;
            }
        }else{
            c++;
        }
    }
    rep(i,0,c)s.pb(')');
    cout<<s<<nnn;
    return 0;
}