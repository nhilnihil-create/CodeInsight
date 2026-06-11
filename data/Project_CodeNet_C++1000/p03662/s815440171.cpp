#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PP;
const ll MOD = 1000000007;
ll T[200005]={0};
ll oya[200005]={0};
ll used[200005]={0};
vector<ll> V[200005];
ll T2[200005]={0};
ll oya2[200005]={0};
ll used2[200005]={0};
void ki(int x){
  for(int j=0;j<V[x].size();j++){
    int now=V[x][j];
    if(used[now]==0){
      oya[now]=x;
      T[now]=T[x]+1;
      used[now]++;
      ki(now);
    }
  }
}
void ki2(int x){
  for(int j=0;j<V[x].size();j++){
    int now=V[x][j];
    if(used2[now]==0){
      oya2[now]=x;
      T2[now]=T2[x]+1;
      used2[now]++;
      ki2(now);
    }
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  used[1]=1;
  ki(1);
  used2[n]=1;
  ki2(n);
  ll B=0;ll W=0;
  for(int i=1;i<=n;i++){
    if(T[i]<=T2[i])B++;
    else W++;
  }
  if(B>W)cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
}
