#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll get_sum(ll n,vector<ll> que){
  ll sum=0;
  for(int i=0;i<n;i++){
    if(i==que.size()){
      break;
    }
    sum+=que[i];
  }
  return sum;
}
int main(){
  ll N,W,sum,we,ans=-1;
  cin >> N >> W;
  ll w[N],v[N];
  vector<ll> que[4];
  for(ll i=0;i<N;i++){
    cin >> w[i]>>v[i];
    que[w[i]-w[0]].push_back(v[i]);
  }
  for(int i=0;i<4;i++){
    sort(que[i].begin(),que[i].end(),greater<ll>());
  }
  for(int i=0;i<=N;i++){
    for(int j=0;i+j<=N;j++){
      for(int k=0;i+j+k<=N;k++){
        for(int l=0;i+j+k+l<=N;l++){
          we = i*(w[0])+j*(w[0]+1)+k*(w[0]+2)+l*(w[0]+3);
          if(we>W)break;
          sum = get_sum(i,que[0])+get_sum(j,que[1])+
            get_sum(k,que[2])+get_sum(l,que[3]);
          ans = max(ans,sum);
        }
      }
    }
  }
  cout << ans<<endl;
}
