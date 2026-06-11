#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> vec(3*N);
  int64_t former = 0;
  int64_t latter = 0;
  priority_queue<int64_t> F;
  priority_queue<int64_t> L;
  for(int i=0; i<3*N; i++){
    cin >> vec.at(i);
    if(i < N){
      former += vec.at(i);
      F.push(vec.at(i)*-1);
    }
    if(i >= 2*N){
      latter += vec.at(i);
      L.push(vec.at(i));
    }
  }
  
  vector<int64_t> f_sum(N+1);
  vector<int64_t> l_sum(N+1);
  
  f_sum.at(0) = former;
  for(int i=0; i<N; i++){
    F.push(vec.at(i+N)*-1);
    int64_t x = F.top();
    F.pop();
    f_sum.at(i+1) = f_sum.at(i) + vec.at(i+N) + x;
  }
  
  l_sum.at(N) = latter;
  for(int i=N-1; i>=0; i--){
    L.push(vec.at(N+i));
    int64_t x = L.top();
    L.pop();
    l_sum.at(i) = l_sum.at(i+1) + vec.at(i+N) - x;
  }
  
  int64_t ans = -100000000000000000;
  
  for(int i=0; i<N+1; i++){
    ans = max(ans,f_sum.at(i) - l_sum.at(i));
  }
  cout << ans << endl;
  
}

