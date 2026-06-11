#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int count = 0;
  for (int i=0; i<N; i++) {
    vector<int> l(N),r(N);
    cin >> l.at(i) >> r.at(i);
    count += (r.at(i)-l.at(i)+1) ;
  }
  
  cout << count << endl;
  
}