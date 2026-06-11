#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int sum_0 = 0;
  for (int i=0; i<N;i++) {
    cin >> vec.at(i);
    sum_0 += vec.at(i)*vec.at(i);  //0で置き換える場合
  }
  sort(vec.begin(), vec.end());

  for (int i=vec.at(0); i<=vec.at(N-1); i++){
    int sum = 0;
    for (int j=0; j<N; j++){
      sum += (vec.at(j)-i)*(vec.at(j)-i);
    }
    sum_0 = min(sum_0, sum);
  }
  cout << sum_0 << endl;
}