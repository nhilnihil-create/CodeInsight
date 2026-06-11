#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<pair<int,long long>> ab(N);
  for(int i=0;i<N;i++){
    cin >> ab.at(i).first >> ab.at(i).second;
  }
  
  sort(ab.begin(),ab.end());
  
  long long cnt = 0;
  for(int i=0;i<N;i++){
    cnt += ab.at(i).second;
    if( cnt >= K ){
      cout << ab.at(i).first << endl;
      return 0;
    }
  }
}