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

ll N,x;
ll ans[200010]={};
ll Abs(ll n){
    if(n<0)return -n;
    else return n;
}
int main(){
    cin>>N>>x;
    if(N==2){
        if(x==2){
            cout<<"Yes"<<endl;
            cout<<1<<endl<<2<<endl<<3<<endl;
        }else{
            cout<<"No"<<endl;
        }
        return 0;
    }
    if(x==1 || x==2*N-1){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    vector<ll> v;
    if(x==2){
        ans[N-1]=2;
        ans[N-2]=1;
        ans[N-3]=4;
        ans[N]=3;
        for(ll i=5;i<=2*N-1;i++){
            v.push_back(i);
        }
    }
    else{
        ans[N-1]=x;
        ans[N]=x+1;
        ans[N-2]=x-1;
        ans[N+1]=x-2;
        for(ll i=1;i<=2*N-1;i++){
            if(Abs(x-i)<=1)continue;
            if(i==x-2)continue;
            v.push_back(i);
        }
    }
    ll now=0;
    for(ll i=0;i<2*N-1;i++){
        if(ans[i]==0){
            ans[i]=v[now];
            now++;
        }
        cout<<ans[i]<<endl;
    }
    return 0;
}