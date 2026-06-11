#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  deque<int64_t> dq;
  for(int i=0;i<N;i++){
    int64_t A;
    cin >> A;
    dq.push_back(A);
  }
  sort(dq.begin(),dq.end());
  int ans=N;
  int64_t x=dq.front();
  dq.pop_front();
  while(true){
    if(dq.empty()){
      break;
    }
    if(x*2<dq.front()){
      ans=dq.size();
    }
    x+=dq.front();
    dq.pop_front();
  }
  cout << ans << endl;
  return 0;
}
