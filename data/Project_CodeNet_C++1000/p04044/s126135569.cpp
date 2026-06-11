#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main() {
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  for (int i=0; i<N; i++) {
    cin >> S.at(i);
  }
  sort(S.begin(),S.end());
  if (N==1) {
    cout << S.at(0) << endl;
  }
  else {
    for (int j=0; j<N-1; j++) {
      cout << S.at(j);
    }
    cout << S.at(N-1) << endl;
  }
}