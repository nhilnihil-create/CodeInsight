#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    ll N,W;
    cin>>N>>W;
    vector<ll> q1,q2,q3,q4;
    ll w0,v0;
    cin>>w0>>v0;
    q1.push_back(v0);
    for(int i=1;i<N;i++){
        ll w,v;
        cin>>w>>v;
        if(w==w0)   q1.push_back(v);
        if(w==w0+1) q2.push_back(v);
        if(w==w0+2) q3.push_back(v);
        if(w==w0+3) q4.push_back(v);
    }
    sort(ALL(q1),greater<ll>());
    sort(ALL(q2),greater<ll>());
    sort(ALL(q3),greater<ll>());
    sort(ALL(q4),greater<ll>());
    vector<ll> s1,s2,s3,s4;
    s1.push_back(0);s2.push_back(0);
    s3.push_back(0);s4.push_back(0);
    for(int i=0;i<q1.size();i++) s1.push_back(s1[i]+q1[i]);
    for(int i=0;i<q2.size();i++) s2.push_back(s2[i]+q2[i]);
    for(int i=0;i<q3.size();i++) s3.push_back(s3[i]+q3[i]);
    for(int i=0;i<q4.size();i++) s4.push_back(s4[i]+q4[i]);
    ll ans=0;
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            for(int k=0;k<s3.size();k++){
                for(int l=0;l<s4.size();l++){
                    if(i*w0+j*(w0+1)+k*(w0+2)+l*(w0+3)<=W) ans=max(ans,s1[i]+s2[j]+s3[k]+s4[l]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}