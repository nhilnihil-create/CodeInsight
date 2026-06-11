#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> citys(N+1);
  for(; M > 0; M--) {
    int a, b;
    cin >> a >> b;
    citys.at(a)++;
    citys.at(b)++;
  }
  
  for(int i = 1; i <= N; i++) {
    cout << citys.at(i) << endl;
  }
}
