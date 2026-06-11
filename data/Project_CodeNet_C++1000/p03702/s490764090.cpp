#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e9
typedef long long ll;
typedef pair<ll,ll> P;

ll n,A,B;
ll h[100010];

bool check(ll x){
    ll res=0;
    for(ll i=0;i<n;i++){
        ll t=h[i]-B*x;
        if(t<=0)continue;
        else{
            res+=t/(A-B);
            if(t%(A-B)!=0)res++;
        }
    }
    return (res>x);
}

int main(void){
    cin>>n>>A>>B;
    for(ll i=0;i<n;i++)cin>>h[i];
    ll ng=0,ok=(ll)INF;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        if(check(mid))ng=mid;
        else ok=mid;
  }
    cout<<ok<<endl;
    return 0;
}