#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define rfore(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);--i)
#define rrep(i,n) rfore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

void solve(long long N, std::vector<long long> a){
    vp b(N);
    vl ma;
    rep(i,N){
        if(ma.empty()||a[ma.back()]<a[i]){
            ma.push_back(i);
        }
    }
    ll M=ma.size();
    vl sum1(M+1),sumr(M+1);
    rep(i,N){
        ll hi=M,lo=-1;
        while(hi-lo>1){
            ll mid=(hi+lo)/2;
            if(a[ma[mid]]<=a[i])lo=mid;
            else hi=mid;
        }
        if(hi==0){
            sumr[0]+=a[i];
        }else{
            sum1[0]++;
            sum1[hi]--;
            sumr[hi]+=a[i]-a[ma[lo]];
        }
    }
    rep(i,M)sum1[i+1]+=sum1[i];
    rep(i,M){
        if(i==0)sum1[i]*=a[ma[i]];
        else sum1[i]*=a[ma[i]]-a[ma[i-1]];
    }
    vl ans(N);
    rep(i,M)ans[ma[i]]=sum1[i]+sumr[i];
    rep(i,N)cout<<ans[i]<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
}
