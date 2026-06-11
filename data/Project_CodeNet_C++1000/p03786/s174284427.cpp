#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int64_t> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }
  sort(data.begin(), data.end());

  vector<int64_t> cumsum(N);
  int min_eater= 0;
  for(int i=0; i<N-1; i++){
    cumsum.at(i)= (i > 0) ? data.at(i)+ cumsum.at(i-1)
                          : data.at(i);

    if(2*cumsum.at(i) < data.at(i+1)){
      min_eater= i+1;
    }
  }

  int ans= N- min_eater;

  cout << ans << endl;
}