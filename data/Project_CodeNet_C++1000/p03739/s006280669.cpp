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
ll a[100010];
ll Calc(){
    ll ret=0;
    ll sum=a[0];
    ll preSum;
    for(ll i=1;i<N;i++){
        preSum=sum;
        sum+=a[i];
        if(sum==0 || ((preSum<0)^(sum>0))){
            if(preSum>0){
                ret+=abs(-1-sum);
                sum=-1;
            }else{
                ret+=abs(1-sum);
                sum=1;
            }
        }
    }
    return ret;
}
int main(){
    cin>>N;
    for(ll i=0;i<N;i++) cin>>a[i];
    ll a0=a[0];
    ll ans0=Calc();
    a[0]=1;
    ll ans1=Calc()+abs(1-a0);
    a[0]=-1;
    ll ans2=Calc()+abs(-1-a0);
    cout<<min({ans0,ans1,ans2})<<endl;
    return 0;
}