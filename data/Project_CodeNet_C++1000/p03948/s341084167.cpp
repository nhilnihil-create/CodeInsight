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

ll N,T;
ll A[100010];
ll minA[100010];
unordered_map<ll,ll> cnt;
int main(){
    cin>>N>>T;
    for(ll i=0;i<N;i++){
        cin>>A[i];
    }
    minA[0]=A[0];
    ll maxDiff=0;
    for(ll i=1;i<N;i++){
        maxDiff=max(maxDiff,A[i]-minA[i-1]);
        cnt[A[i]-minA[i-1]]++;
        minA[i]=min(minA[i-1],A[i]);
    }
    cout<<cnt[maxDiff]<<endl;
    return 0;
}