#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
ll a[300010];
priority_queue<ll,vector<ll>,greater<ll>> leftQ;
priority_queue<ll> rightQ;
ll leftSum[300010];
ll rightSum[300010];
int main(){
    cin>>N;
    for(ll i=0;i<3*N;i++){
        cin>>a[i];
    }
    leftSum[N-1]=0;
    for(ll i=0;i<N;i++){
        leftSum[N-1]+=a[i];
        leftQ.push(a[i]);
    }
    for(ll i=N;i<2*N;i++){
        leftSum[i]=a[i]+leftSum[i-1];
        leftQ.push(a[i]);
        leftSum[i]-=leftQ.top();
        leftQ.pop();
    }

    rightSum[2*N]=0;
    for(ll i=3*N-1;i>=2*N;i--){
        rightSum[2*N]+=a[i];
        rightQ.push(a[i]);
    }
    for(ll i=2*N-1;i>=N;i--){
        rightSum[i]=a[i]+rightSum[i+1];
        rightQ.push(a[i]);
        rightSum[i]-=rightQ.top();
        rightQ.pop();
    }


    ll ans=-INF;
    for(ll i=N-1;i<2*N;i++){
        ans=max(ans,leftSum[i]-rightSum[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}