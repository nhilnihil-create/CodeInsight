#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N ;
  vector<int> l(N);
  vector<int> r(N);
  for ( int i=0 ; i < N ; i++ ) {
    cin >> l.at(i) >> r.at(i) ;
  }
  int l_sum = accumulate(l.begin(), l.end(), 0);
  int r_sum = accumulate(r.begin(), r.end(), 0);
  cout << r_sum-l_sum+N << endl;
}
