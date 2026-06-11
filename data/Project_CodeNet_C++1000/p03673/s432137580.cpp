#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  deque<int> dq;
  if(N%2 == 1){
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      if(i%2 == 0){
        dq.push_front(x);
      }
      else{
        dq.push_back(x);
      }
    }
  }
  else{
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      if(i%2 == 0){
        dq.push_back(x);
      }
      else{
        dq.push_front(x);
      }
    }
  }
  for(int i=0; i<N; i++){
    if(i == N-1){
      cout << dq[i] << endl;
      return 0;
    }
    else{
      cout << dq[i] << " ";
    }
  }
}