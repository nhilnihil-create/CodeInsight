#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0,1,-1,1,-1},dy={0,1,0,-1,1,-1,-1,1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll H,W,ans;
    cin>>H>>W;
    if(H%3==0||W%3==0){
        cout<<"0"<<endl;
        return 0;
    }
    ans=min(H,W);
    for(ll i=1;i<H;i++){
        ll a,b,c,M,m;
        a=W/2*i;
        b=(W-W/2)*i;
        c=W*(H-i);
        M=max(a,max(b,c));
        m=min(a,min(b,c));
        ans=min(ans,M-m);
    }
    for(ll i=1;i<W;i++){
        ll a,b,c,M,m;
        a=H/2*i;
        b=(H-H/2)*i;
        c=H*(W-i);
        M=max(a,max(b,c));
        m=min(a,min(b,c));
        ans=min(ans,M-m);
    }
    cout<<ans<<endl;
}