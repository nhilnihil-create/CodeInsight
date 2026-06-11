#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
vector<ll> node[100005];
bool used[100005]={false};
ll grundy(ll pos){
  ll cnt=0;
  for(int i=0;i<node[pos].size();i++){
    ll to=node[pos][i];
    if(!used[to]) cnt++;
  }
  if(cnt==0) return 0;
  else if(cnt==1){
    for(int i=0;i<node[pos].size();i++){
      ll to=node[pos][i];
      if(!used[to]){
        used[to]=true;
        return grundy(to)+1;
      }
    }
  }
  else{
    ll res=0;
    for(int i=0;i<node[pos].size();i++){
      ll to=node[pos][i];
      if(!used[to]){
        used[to]=true;
        res^=grundy(to)+1;
      }
    }
    return res;
  }
}
int main(){
  ll n;
  cin>>n;
  for(int i=1;i<n;i++){
    ll s,t;
    cin>>s>>t;
    node[s].push_back(t);
    node[t].push_back(s);
  }
  for(int i=1;i<=n;i++) used[i]=false;
  used[1]=true;
  cout<<(grundy(1)==0?"Bob":"Alice")<<endl;
}
