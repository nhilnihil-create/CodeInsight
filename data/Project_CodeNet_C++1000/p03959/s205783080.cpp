#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
ll T[100010];
ll A[100010];

ll u[100010];
ll d[100010];
ll uA[100010];
ll dA[100010];

int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>T[i];
    }
    for(ll i=0;i<N;i++){
        cin>>A[i];
    }
    u[0]=T[0];
    d[0]=T[0];
    for(ll i=1;i<N;i++){
        if(T[i]>u[i-1]){
            u[i]=T[i];
            d[i]=T[i];
        }else if(T[i]==u[i-1]){
            u[i]=u[i-1];
            d[i]=1;
        }else{
            cout<<"0"<<endl;
            return 0;
        }
    }
    uA[N-1]=A[N-1];
    dA[N-1]=A[N-1];
    for(ll i=N-2;i>=0;i--){
        if(A[i]>uA[i+1]){
            uA[i]=A[i];
            dA[i]=A[i];
        }else if(A[i]==uA[i+1]){
            uA[i]=uA[i+1];
            dA[i]=1;
        }else{
            cout<<"0"<<endl;
            return 0;
        }
    }
    ll ans=1;
    for(ll i=0;i<N;i++){
        ll tmp=min(u[i],uA[i])-max(d[i],dA[i])+1;
        ans=ans*tmp%MOD;
        if(ans<=0)ans=0;
    }
    cout<<ans<<endl;
    return 0;
}