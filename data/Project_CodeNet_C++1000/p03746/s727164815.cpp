// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<list>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void anser(list<ll>& p){
  cout << p.size()<<endl;
  for(auto i:p){
    cout << i+1<<" ";
  }
  cout << endl;
}
signed main(){
  ll n,m;
  cin >> n >> m;
  ll a[m],b[m];
  bool used[n];
  fill(used,used+n,false);
  list<ll> path;
  vector<ll> G[n];
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  path.push_back(a[0]);
  path.push_back(b[0]);
  bool end=true;
  used[a[0]]=used[b[0]]=true;
  while(end){
    end = false;
    ll v = path.back();
    for(auto np:G[v]){
      if(!used[np]){
        end = true;
        used[np]=true;
        path.push_back(np);
        break;
      }
    }

    v = path.front();
    for(auto np:G[v]){
      if(!used[np]){
        end = true;
        used[np]=true;
        path.push_front(np);
        break;
      }
    }
  }
  anser(path);
}
