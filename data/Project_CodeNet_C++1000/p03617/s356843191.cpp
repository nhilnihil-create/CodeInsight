//Ice Tea Store

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
template<class T>inline bool chmin(T& a,T b,bool f){
if(f==1){if(a>b){a=b;return true;}return false;}
else if(f==0){if(a<b){a=b;return true;}return false;}return false;}
typedef pair<int,string> p;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int main (){
    ll q,h,s,d,n;cin>>q>>h>>s>>d>>n;
    q=4*q;h=2*h;
    ll ans;
    s=min(min(s,h),q);
    if(n%2==0){
        ans = min(n/2*d,s*n);
    }else{
        ans=min(n/2*d+s,s*n);
    }
    cout<<ans<<nnn;
    return 0;
}