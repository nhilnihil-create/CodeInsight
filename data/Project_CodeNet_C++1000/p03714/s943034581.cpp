#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;cin>>n;
    vll a(3*n),front(3*n),rear(3*n);//front:前から数えてそこまでの中ででかいやつn個の和 rear:後から数えてでかいやつn個の和
    priority_queue<ll,vector<ll>,greater<ll>> pqf;
    ll sum=(ll)0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
        pqf.push(a[i]);
    }
    front[n-1]=sum;
    rep2(i,n,2*n){
        cin>>a[i];
        pqf.push(a[i]);
        sum+=a[i];
        sum-=pqf.top();pqf.pop();
        front[i]=sum;
    }
    sum=(ll)0;
    priority_queue<ll> pqr;
    rep2(i,2*n,3*n){
        cin>>a[i];
        sum+=a[i];
        pqr.push(a[i]);
    }
    rear[2*n]=sum;
    for(int i=2*n-1;i>n-1;i--){
        pqr.push(a[i]);
        sum+=a[i];
        sum-=pqr.top();pqr.pop();
        rear[i]=sum;
    }
    ll ans=-INF;
    rep2(i,n-1,2*n)ans=max(ans,front[i]-rear[i+1]);
    cout<<ans<<endl;
}