#include "bits/stdc++.h"
using namespace std;

int main() {
  int N,C,K;
  cin >> N >> C >> K ;
  vector<int> T(N);
  for(int i=0;i<N;i++){
    cin >> T.at(i) ;
  }
  sort(T.begin(), T.end());
  int time=T.at(N-1);
  int person = 0;
  int bus = 0;
  for(int i=N-1;i>=0;i--){
    int t = T.at(i);
    if(time - t > K || person == C){
      bus++;
      person=0;
      time = t;
    }
    person++;
  }
  bus++;
  cout << bus << endl;
  return 0;
}