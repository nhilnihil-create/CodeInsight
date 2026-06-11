#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,C,K;
  cin >> N >> C >> K;
  vector<int> t(N);
  for(int i = 0; i < N; i++) cin >> t.at(i);
  //到着順に並び替える
  sort(t.begin(),t.end());
  int c_bus = 0;
  int passenger = 0;
  int depart_time = 0;
  for(int i = 0; i < N; i++){
    if(t.at(i) <= depart_time && passenger < C){
      passenger++;
      continue;
    }
    if(t.at(i) > depart_time || passenger == C){
      c_bus++;
      depart_time = t.at(i) + K;
      passenger = 1;
    }
  }
  cout << c_bus << endl;
  
}