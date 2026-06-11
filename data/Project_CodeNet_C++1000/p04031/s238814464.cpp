#include "bits/stdc++.h"
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  vector<int> sum(201);
  for(int i=-100;i<101;i++){
    int tmp = 0;
    for(int j=0;j<N;j++){
      tmp += (i-a[j])*(i-a[j]);
    }
    sum.at(i+100) = tmp;
  }
  sort(sum.begin(),sum.end());
  cout << sum[0] << endl;
  return 0;
}