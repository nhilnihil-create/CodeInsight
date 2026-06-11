#include <bits/stdc++.h>
using namespace std;

int main(){// 上2つと下1つをセットにするのが最善
  int N;
  cin >> N;

  vector<int64_t> data(3*N);
  for(int i=0; i<data.size(); i++){
    cin >> data.at(i);
  }
  sort(data.begin(), data.end(), greater<int64_t>());

  int64_t ans= 0;
  for(int i=0; i<N; i++){
    ans+= data.at(2*i+ 1);
  }

  cout << ans << endl;
}