#include <bits/stdc++.h>
using namespace std;


int main(){
  int64_t N,M,x=0;
  cin >> N >> M;
  vector<pair<int64_t,int64_t>> A(M);
  vector<vector<int64_t>> B(N, vector<int64_t>(0));
  deque<int64_t> C;
  vector<int64_t> D(N,0);
    
  for(int64_t i=0;i<M;i++){
    cin >> A.at(i).first >> A.at(i).second;
    A.at(i).first--;
    A.at(i).second--;
    B.at(A.at(i).first).push_back(A.at(i).second);
    B.at(A.at(i).second).push_back(A.at(i).first);
  }
  C.push_back(0);
  D.at(0)=1;
  while(x==0){
    for(int64_t i=0;i<B.at(C.front()).size();i++){
      if(D.at(B.at(C.front()).at(i))==0){
        D.at(B.at(C.front()).at(i))=1;
        C.push_front(B.at(C.front()).at(i));
        break;
      }
      if(i==B.at(C.front()).size()-1){
        x=1;
      }
    }
  }
  x=0;
  while(x==0){
    for(int64_t i=0;i<B.at(C.back()).size();i++){
      if(D.at(B.at(C.back()).at(i))==0){
        D.at(B.at(C.back()).at(i))=1;
        C.push_back(B.at(C.back()).at(i));
        break;
      }
      if(i==B.at(C.back()).size()-1){
        x=1;
      }
    }
  }
  cout << C.size() << endl;
  for(int64_t i=0;i<C.size();i++){
    cout << C.at(i)+1 << " ";
  }
  cout << endl;
}