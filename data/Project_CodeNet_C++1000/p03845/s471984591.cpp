#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ;
  cin >> N ;
  vector <int> a(N);
  int sum = 0 ;
  for ( int i=0 ; i<N ; i++){
    cin >> a.at(i) ;
    sum += a.at(i) ;
  }
  int M ;
  cin >> M ;
  vector <int> d(M) ;
  vector<pair<int, int>> p(M);
  for (int i = 0; i < M; i++) {
    int b, c;
    cin >> b >> c;
    p.at(i) = make_pair(b, c);  // b, a の順でペアにする
  }
  for ( int i=0 ; i<M ; i++){
    int b, c;
    tie(b, c) = p.at(i);
    d.at(i) = sum -a.at(b-1) +c;
    cout << d.at(i) << endl;
  }
}