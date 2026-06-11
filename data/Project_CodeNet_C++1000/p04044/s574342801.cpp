#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,L;
  priority_queue<string, vector<string>,greater<string>> pq;
  cin >> N >> L;
  for(int i=0;i<N;++i){
    string S; cin >> S;
    pq.push(S);
  }

  while(!pq.empty()){
    cout << pq.top();
    pq.pop();
  }
  cout << endl;
  return 0;
}
