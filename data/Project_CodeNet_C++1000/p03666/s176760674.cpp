#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    ll dis=d*(n-1)-abs(b-a);
    bool f=1;
    if(dis<0)f=0;
    else if(dis%(d+c)>(d-c)*(n-1))f=0;
    cout<<(f?"YES":"NO")<<endl;
}