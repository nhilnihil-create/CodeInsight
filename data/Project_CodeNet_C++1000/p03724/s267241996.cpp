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

ll N,M;
ll cnt[100010];
int main(){
    cin>>N>>M;
    for(ll i=0;i<M;i++){
        ll a,b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    for(ll i=0;i<N;i++){
        if(cnt[i]%2!=0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}