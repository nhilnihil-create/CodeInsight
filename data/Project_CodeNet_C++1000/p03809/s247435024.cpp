#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 100000007
typedef long long ll;
using namespace std;
ll n,t[100010];
vector<int> v[100010];
ll DFS(int x,int from){
  if(v[x].size()==1)return t[x];
  ll sum=0,maxi=0;
  lol(i,v[x].size()){
    if(v[x][i]==from)continue;
    ll res=DFS(v[x][i],x);
    if(res<0)return -1;
    sum+=res;
    maxi=max(maxi,res);
  }
  if(sum-t[x]<0)return -1;
  if(sum-t[x]<=min(sum/2,sum-maxi))return t[x]*2-sum;
  return -1;
}
int main(){
  cin>>n;
  lol(i,n)cin>>t[i];
  lol(i,n-1){
    int a,b;cin>>a>>b;
    a--,b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  if(n==2){
    if(t[0]==t[1])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  else{
    lol(i,n)if(v[i].size()>1){
      if(DFS(i,-1)==0)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
      break;
    }
  }
  return 0;
}
