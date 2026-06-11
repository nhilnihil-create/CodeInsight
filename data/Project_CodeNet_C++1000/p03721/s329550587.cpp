#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int64_t K;
  cin >> N >> K;
  vector<int>A(N);
  vector<int>B(N);
  for(int i=0; i<N; i++)cin >> A.at(i) >> B.at(i);
  vector<pair<int, int>>P(N);
  for(int i=0; i<N; i++)P.at(i)=make_pair(A.at(i), B.at(i));
  sort(P.begin(), P.end());
  int64_t count=0;
  
  for(int i=0; i<N; i++){
    count += P.at(i).second;
    if(count >= K){
      cout << P.at(i).first << endl;
      break;
    }
  }
  
    
}