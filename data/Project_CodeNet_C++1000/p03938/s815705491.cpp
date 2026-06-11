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
ll p[200010];
int main(){
    cin>>N;
    ll inf=40000;
    for(ll i=0;i<N;i++){
        ll a;cin>>a;
        p[a-1]=i;
    }

    for(ll i=0;i<N;i++)cout<<inf*(i+1)+p[i]<<" ";
    cout<<endl;
    for(ll i=0;i<N;i++)cout<<inf*(N-i)<<" ";
    cout<<endl;
    return 0;
}