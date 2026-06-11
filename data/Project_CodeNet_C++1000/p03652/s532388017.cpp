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
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll INF=2e18;
const ll MOD=1e9+7;
ll N,M;


vector<ll> v[500];
ll a[500][500];
bool isActive[500];
ll idx[500];
int main(){
    cin>>N>>M;
    for(ll i=0;i<N;i++){
        idx[i]=0;
        for(ll j=0;j<M;j++){
            cin>>a[i][j];
        }
    }
    for(ll j=1;j<=M;j++){
        isActive[j]=true;
    }
    ll ans=INF;
    while(1){
        ll cnt[500]={};
        ll maxCnt=0,maxNum=0;
        for(ll i=0;i<N;i++){
            cnt[a[i][idx[i]]]++;
        }
        for(ll i=0;i<N;i++){
            ll n=a[i][idx[i]];
            if(maxCnt < cnt[n]){
                maxCnt=cnt[n];
                maxNum=n;
            }
        }
        isActive[maxNum]=false;
        ans=min(ans,maxCnt);
        for(ll i=0;i<N;i++){
            while(idx[i]<M && !isActive[a[i][idx[i]]]){
                idx[i]++;
            }
            if(idx[i]>=M){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
}