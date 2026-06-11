#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define lol(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
int NOEL(){
  cout<<"Impossible"<<endl;
  return 0;
}
#define N 100010
ll n,m,a[N];
vector<ll> ans;
void Outs(){
  cout<<ans.size()<<endl;
  for(auto x:ans)cout<<x<<endl;
}
void Lend(ll x){
  if(x%2==1){
    lol(i,x/2+1)ans.push_back(2);
  }
  else{
    lol(i,x/4)ans.push_back(2);
    ans.push_back(1);
    lol(i,x/2-x/4)ans.push_back(2);
  }
  
}
void Rend(ll x){
  vector<ll> mem;
  if(x%2==1){
    lol(i,x/2)mem.push_back(2);
  }
  else{
    lol(i,x/4)mem.push_back(2);
    mem.push_back(1);
    lol(i,x/2-1-x/4)mem.push_back(2);
  }
  reverse(mem.begin(),mem.end());
  for(auto t:mem)ans.push_back(t);
}
void Centor(ll x){
  if(x==2){
    ans.push_back(2);
    return;
  }
  ans.push_back(x-4);
  ans.push_back(4);
}
int main(){
    cin>>n>>m;
    lol(i,m){
      cin>>a[i];
      if(a[i]&1)a[i]=-a[i];
    }
    sort(a,a+m);
    if(m==1){
      if(a[0]<0)a[0]=-a[0];
      Lend(a[0]);
      ans.pop_back();
      ans.push_back(1);
      cout<<a[0]<<endl;
      Outs();
      return 0;
    }
    ll cnt=0;
    lol(i,m)if(a[i]<0)cnt++,a[i]=-a[i];
    if(cnt>2)return NOEL();
    Lend(a[0]); cout<<a[0]<<endl;
    for(int i=2;i<m;i++){
      Centor(a[i]);
      cout<<a[i]<<endl;
    }
    Rend(a[1]); cout<<a[1]<<endl;
    cout<<endl;
    Outs();
    return 0;
}
