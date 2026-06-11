#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define INF 1e16
#define N (1000000007)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> Q;


ll a[7];
int main(void){
    for(int i=0;i<7;i++)cin>>a[i];
    ll ans=0;
    ll k = min(a[0],min(a[3],a[4]));
    ll cnt=0;
    if(a[0]%2==1)cnt++;
    if(a[3]%2==1)cnt++;
    if(a[4]%2==1)cnt++;
    ans+=a[1];
    if(k%2==0){
      if(cnt==0)ans+=a[0]+a[3]+a[4];
      if(cnt==1)ans+=a[0]+a[3]+a[4]-1;
      if(cnt==2){
        if(k!=0)ans+=a[0]+a[3]+a[4]-1;
        else ans+=a[0]+a[3]+a[4]-2;
      }
      cout<<ans<<endl;
    }
    else{
      if(cnt==3)ans+=a[0]+a[3]+a[4];
      if(cnt==2)ans+=a[0]+a[3]+a[4]-1;
      if(cnt==1)ans+=a[0]+a[3]+a[4]-1;
      cout<<ans<<endl;
    }
    return 0;
}
