#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int64_t>>> G;
vector<int64_t> r;

void DFS(int a){
  for(pair<int,int64_t> x:G.at(a)){
    int b;
    int64_t l;
    tie(b,l)=x;
    if(r.at(b)==-1){
      r.at(b)=r.at(a)+l;
      DFS(b);
    }
  }
}

int main() {
  int N;
  cin>>N;
  r.resize(N);
  G.resize(N);
  r.at(0)=-1;
  for(int i=1;i<N;i++){
    r.at(i)=-1;
    int a,b;
    int64_t c;
    cin>>a>>b>>c;
    a--,b--;
    G.at(a).push_back(make_pair(b,c));
    G.at(b).push_back(make_pair(a,c));
  }
  int Q,K;
  cin>>Q>>K;
  K--;
  r.at(K)=0;
  DFS(K);
  for(int i=0;i<Q;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    cout<<r.at(a)+r.at(b)<<endl;
  }
}