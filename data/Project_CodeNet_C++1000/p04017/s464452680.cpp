#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll dpos[100005][20]={0};
int main(){
  ll n;
  cin>>n;
  vector<ll> vec;
  vec.push_back(0);
  for(int i=1;i<=n;i++){
    ll x;
    cin>>x;
    vec.push_back(x);
  }
  ll L;
  cin>>L;
  for(int i=1;i<=n;i++){
    ll npos=upper_bound(vec.begin(),vec.end(),vec[i]+L)-vec.begin();
    npos--;
    if(npos<=i||npos>n) dpos[i][0]=-1;
    else dpos[i][0]=npos;
  }
  for(int k=1;k<20;k++){
    for(int i=1;i<=n;i++){
      if(dpos[i][k-1]==-1) dpos[i][k]=-1;
      else dpos[i][k]=dpos[dpos[i][k-1]][k-1];
    }
  }

  ll q;
  cin>>q;
  for(int i=0;i<q;i++){
    ll a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    ll lb=0,rb=n+5;
    while(rb-lb>1){
      ll mid=(lb+rb)/2;
      ll max_goal=a;
      for(int k=0;k<20;k++){
        if(((mid>>k)&1)==1){
          max_goal=dpos[max_goal][k];
          if(max_goal==-1) max_goal=n;
        }
      }
      if(max_goal>=b) rb=mid;
      else lb=mid;
    }
    cout<<rb<<endl;
  }
}
