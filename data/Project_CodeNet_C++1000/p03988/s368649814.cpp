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
typedef pair<int, int> P;
const ll INF=2e18;
const ll MOD=1e9+7;
ll N;
ll a[105];
map<ll,ll> mp;
int main(){
    cin>>N;
    ll m=0;
    for(ll i=0;i<N;i++){
        cin>>a[i];
        mp[a[i]]++;
        m=max(m,a[i]);
    }
    for(ll i=m;i>(m+1)/2;i--){
        if(mp[i]<2){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    if(m%2==0 && mp[m/2]!=1){
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(m%2==1 && mp[(m+1)/2]!=2){
        cout<<"Impossible"<<endl;
        return 0;
    }

    for(ll i=(m+1)/2-1;i>=0;i--){
        if(mp[i]!=0){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}