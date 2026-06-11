#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ,K;
  cin >> N >> K;
  vector <int> a(N);
  for (int i=0 ; i<N ; i++){
    cin >> a.at(i);
  }
  sort ( a.begin() , a.end());
  reverse (a.begin() , a.end());
  int sum=0 ;
  for ( int i=0 ; i<K ;i++){
    sum += a.at(i);
  }
  cout << sum << endl;
}