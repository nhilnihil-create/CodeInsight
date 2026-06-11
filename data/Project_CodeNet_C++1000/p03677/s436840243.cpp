#include <bits/stdc++.h>
using namespace std;typedef long long ll;typedef vector<ll> vl;typedef vector<vl> vvl;typedef pair<ll,ll> pl;typedef vector<pl> vp;const ll INF=1001001001;const ll LINF=1001001001001001001;const ll D4[]={0,1,0,-1,0};const ll D8[]={0,1,1,0,-1,-1,1,-1,0};template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()

void solve(long long n, long long m, std::vector<long long> a){
    rep(i,n)a[i]--;
    vl sum1(m+5),sumM(m+5);
    rep(i,n-1){
        if(a[i]<a[i+1]){
            sum1[a[i]+2]++;
            sum1[a[i+1]+1]--;
            sumM[a[i+1]+1]-=a[i+1]-a[i]-1;
        }else{
            sum1[a[i]+2]++;
            if(a[i]==m-1){
                sum1[1]++;
            }else{
                sum1[0]++;
                sumM[0]+=m-2-a[i];
            }
            sum1[a[i+1]+1]--;
            sumM[a[i+1]+1]-=m+a[i+1]-a[i]-1;
        }
    }

    rep(i,m)sum1[i+1]+=sum1[i];
    rep(i,m)sum1[i]+=sumM[i];
    rep(i,m)sum1[i+1]+=sum1[i];

    ll ma=0;
    rep(i,m){
        chmax(ma,sum1[i]);
    }

    ll ans=0;
    rep(i,n-1){
        ll tmp=a[i+1]-a[i];
        if(tmp<0)tmp+=m;
        ans+=tmp;
    }
    ans-=ma;
    cout<<ans<<endl;
}

int main(){
    long long n;
    scanf("%lld",&n);
    long long m;
    scanf("%lld",&m);
    std::vector<long long> a(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&a[i]);
    }
    solve(n, m, std::move(a));
}
