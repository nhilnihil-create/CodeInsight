#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  int A=1;
  vector<int> ni;
  while(A<=N){
    ni.push_back(A);
    A*=2;
  }
  int S=ni.size();
  vector<int64_t> seg(A*2-1);
  vector<pair<int64_t,int>> p(N);
  int64_t B=0,Z=0;
  for(int i=0;i<N;i++){
    int64_t a;
    cin>>a;
    B+=a;
    B-=K;
    p[i]=make_pair(B,i);
    if(B>=0){
      Z++;
    }
  }
  sort(p.begin(), p.end());
  for(int i=0;i<N;i++){
    int x=p[i].second;
    x++;
    int Q=A+x-2;
    while(Q>0){
      if(Q%2==1){
        Z+=seg[Q];
        Q--;
      }
      Q--;
      Q/=2;
    }
    Q=A+x-2;
    while(true){
      seg[Q]++;
      if(Q==0){
        break;
      }
      Q=(Q-1)/2;
    }
  }
  cout<<Z<<endl;
}