//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

vector<ll> sum;

ll merge_count(vector<ll> &a){
    int n=a.size();
    if(n<=1) return 0;

    ll cnt=0;
    vector<ll> b(a.begin(),a.begin()+n/2);
    vector<ll> c(a.begin()+n/2,a.end());

    cnt+=merge_count(b);
    cnt+=merge_count(c);

    ll ai=0,bi=0,ci=0;
    while(ai<n){
        if(bi<b.size() && (ci==c.size() || b[bi]<=c[ci])){
            a[ai++]=b[bi++];
        }
        else{
            cnt+=n/2-bi;
            a[ai++]=c[ci++];
        }
    }
    return cnt;
}

int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n,0);
    sum.assign(n+1,0);
    rep(i,n){
        cin>>a[i]; a[i]-=k;
        sum[i+1]=sum[i]+a[i];
    }
    cout<<n*(n+1)/2-merge_count(sum)<<endl;
}