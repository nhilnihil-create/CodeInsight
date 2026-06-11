#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,I=1;
  int64_t Z=100000000000000;
  cin>>N>>K;
  vector<int> p(N);
  vector<int> m(N);
  for(int i=0;i<N;i++){
    cin>>p.at(i);
    if(i==0){
      m.at(i)=p.at(i);
    }
    else{
      m.at(i)=max(m.at(i-1),p.at(i));
    }
  }
  vector<int> v(N-1);
  for(int i=0;i<N-1;i++){
    if(i<N-K){
      v.at(i)=0;
      I*=N-1-i;
      I/=i+1;
    }
    else{
      v.at(i)=1;
    }
  }
  for(int i=0;i<I;i++){
    vector<int> q;
    vector<int> atai;
    for(int j=0;j<N-1;j++){
      if(v.at(j)==1){
        q.push_back(p.at(j+1));
        atai.push_back(j);
      }
    }
    int64_t A=0;
    int C=p.at(0);
    for(int j=0;j<K-1;j++){
      C=max(C+1,m.at(atai.at(j))+1);
      A+=max(0,C-q.at(j));
    }
    Z=min(A,Z);
    next_permutation(begin(v),end(v));
  }
  cout<<Z<<endl;
    
}

