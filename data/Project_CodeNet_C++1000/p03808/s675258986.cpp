#include<bits/stdc++.h>
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
    ll n;cin>>n;
    vector<ll>a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    bool f=1;
    if((sum*2)%(n*(n+1))!=0)f=0;
    else{
        ll k=(sum*2)/(n*(n+1));
        vector<ll>b(0);
        rep(i,n-1){
            if(a[i+1]-a[i]-k<=0&&abs(a[i+1]-a[i]-k)%n==0)continue;
            f=0;
        }
        if(a[0]-a[n-1]-k>0||abs(a[0]-a[n-1]-k)%n!=0)f=0;
    }
    cout<<(f?"YES":"NO")<<endl;
}