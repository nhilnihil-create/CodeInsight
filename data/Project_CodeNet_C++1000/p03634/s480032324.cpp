#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin>>N;
  vector<pair<int,ll>>A[N];
  int f,t;
  long long c;
  for(int i=0;i<N-1;i++){
    cin>>f>>t>>c;
    f--;
    t--;
    A[f].push_back({t,c});
    A[t].push_back({f,c});
  }
  
  int Q,K;
  cin>>Q>>K;
  K--;
  long long D[N]={};
  queue<int>que;
  que.push(K);
  D[K]=0;
  while(que.size() != 0){
    int temp=que.front();
    que.pop();
    for(auto itr=A[temp].begin();itr !=A[temp].end();itr++){
      if(D[(itr->first)]==0){
        D[(itr->first)]=D[temp]+(itr->second);
        //cout<<temp<<" "<<itr->first<<" "<<itr->second<<endl;
        que.push(itr->first);
      }
    }
  }
  int x,y;
  for(int i=0;i<Q;i++){
    cin>>x>>y;
    x--;
    y--;
    cout<<D[x]+D[y]<<endl;
  }
  return 0;
}

           