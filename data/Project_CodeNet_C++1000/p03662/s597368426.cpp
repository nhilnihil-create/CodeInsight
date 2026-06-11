#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>a(N-1),b(N-1);
  for(int i=0;i<N-1;i++)cin>>a[i]>>b[i];
  for(int i=0;i<N-1;i++)a[i]--,b[i]--;
  vector<vector<int>>e(N);
  for(int i=0;i<N-1;i++){
    e[a[i]].push_back(b[i]);
    e[b[i]].push_back(a[i]);
  }
  vector<int>B(N,-1),W(N,-1);

  queue<pii>bq;
  bq.push({0,0});
  while(bq.size()){
    int now=bq.front().first;
    int num=bq.front().second;
    bq.pop();
    B[now]=num;
    for(auto it:e[now]){
      if(B[it]==-1)bq.push({it,num+1});
    }
  }

  queue<pii>wq;
  wq.push({N-1,0});
  while(wq.size()){
    int now=wq.front().first;
    int num=wq.front().second;
    wq.pop();
    W[now]=num;
    for(auto it:e[now]){
      if(W[it]==-1)wq.push({it,num+1});
    }
  }

  int sw=0;
  int sb=0;
  for(int i=1;i<N-1;i++){
    if(W[i]<B[i])sw++;
    else sb++;
  }

  if(sb>sw)cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
  return 0;
}
