#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,h,rt,ra,t=1,a=1;
    cin>>N;
    ll A[N],B[N];
    for(ll i=0;i<N;i++) cin>>A[i]>>B[i];
    for(ll i=0;i<N;i++){
        if(t%A[i]==0) rt=t/A[i];
        else rt=t/A[i]+1;
        if(a%B[i]==0) ra=a/B[i];
        else ra=a/B[i]+1;
        h=max(rt,ra);
        t=h*A[i];
        a=h*B[i];
        //cout<<t<<" "<<a<<endl;
    }
    cout<<t+a<<endl;
}