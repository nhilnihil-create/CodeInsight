#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  int sum = 0;

  cin >> N;
  vector<int> T(N);
  for(int i=0;i<N;++i){
    cin >> T.at(i);
    sum += T.at(i);
  }

  cin >> M;
  for(int i=0;i<M;++i){
    int P,X;
    cin >> P >> X;
    cout << sum - (T.at(P-1) - X) << endl;
  }
  return 0;
}
