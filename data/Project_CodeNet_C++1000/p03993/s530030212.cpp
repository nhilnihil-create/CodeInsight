#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
    data.at(i)--; // 1-indexed -> 0-indexed
  }

  int ans= 0;
  for(int i=0; i<N; i++){
    if(i < data.at(i) && data.at(data.at(i))==i){
      ans++;
    }
  }

  cout << ans << endl;
}