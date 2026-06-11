#include <bits/stdc++.h>
using namespace std;

int main(){
  const int N= 3;
  vector<int64_t> data(N);
  bool is_even= false;
  for(int i=0; i<N; i++){
    cin >> data.at(i);
    if(data.at(i)%2==0){ is_even= true; }
  }
  sort(data.begin(), data.end());

  int64_t ans= (is_even) ? 0
                         : data.at(0)* data.at(1);
  
  cout << ans << endl;
}