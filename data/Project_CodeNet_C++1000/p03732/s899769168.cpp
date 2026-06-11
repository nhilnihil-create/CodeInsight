#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first > b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N,W;
    cin >>N>>W;
    //vector<ll>w(N),v(N);
    vector<ll>v1,v2,v3,v4;
    ll w1,v11;
    cin>>w1>>v11;
    v1.pb(v11);

    rep(i,N-1){
        ll w,v;
        cin>>w>>v;
        if(w==w1){
            v1.pb(v);
        }else if(w==w1+1){
            v2.pb(v);
        }else if(w==w1+2){
            v3.pb(v);
        }else{
            v4.pb(v);
        }
    }
    sort(all(v1));
    reverse(all(v1));
    sort(all(v2));
    reverse(all(v2));
    sort(all(v3));
    reverse(all(v3));
    sort(all(v4));
    reverse(all(v4));
    ll s1,s2,s3,s4;
    s1=v1.size();
    s2=v2.size();
    s3=v3.size();
    s4=v4.size();
    vector<ll>sum1(s1+1),sum2(s2+1),sum3(s3+1),sum4(s4+1);
    rep(i,s1){
        sum1[i+1]=sum1[i]+v1[i];
        //cout<<sum1[i+1]<<endl;
    }
    rep(i,s2){
        sum2[i+1]=sum2[i]+v2[i];
    }
    rep(i,s3){
        sum3[i+1]=sum3[i]+v3[i];
    }
    rep(i,s4){
        sum4[i+1]=sum4[i]+v4[i];
    }
    ll ans=0;
    rep(i,N+1){
        rep(j,min(i+1,s1+1)){
            rep(k,min(i-j+1,s2+1)){
                rep(m,min(i-j-k+1,s3+1)){
                    rep(n,min(i-j-k-m+1,s4+1)){
                        ll we=w1*j+(w1+1)*k+(w1+2)*m+(w1+3)*n;
                        if(we<=W){
                            //cout<<i<<" "<<j<<endl;
                            chmax(ans,sum1[j]+sum2[k]+sum3[m]+sum4[n]);
                        }
                    }
                }
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;
    

}