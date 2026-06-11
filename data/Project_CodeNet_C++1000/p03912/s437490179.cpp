#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll cnt[100005]={0};
ll cn2[100005]={0};
queue<ll> same_cn[100005];
int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    cnt[a%m]++;
    cn2[a]++;
  }
  for(int i=0;i<100005;i++) same_cn[i%m].push(cn2[i]);
  ll ans=0;
  for(int i=1;2*i<m;i++){
    ll mv=min(cnt[i],cnt[m-i]);
    cnt[i]-=mv;
    cnt[m-i]-=mv;
    ans+=mv;

    while(cnt[i]>=2&&!same_cn[i].empty()){
      ll tp=same_cn[i].front();
      same_cn[i].pop();
      while(cnt[i]>=2&&tp>=2){
        ans++;
        tp-=2;
        cnt[i]-=2;
      }
    }
    while(cnt[m-i]>=2&&!same_cn[m-i].empty()){
      ll tp=same_cn[m-i].front();
      same_cn[m-i].pop();
      while(cnt[m-i]>=2&&tp>=2){
        ans++;
        tp-=2;
        cnt[m-i]-=2;
      }
    }
  }
  ans+=cnt[0]/2;
  if(m%2==0) ans+=cnt[m/2]/2;
  cout<<ans<<endl;
}
