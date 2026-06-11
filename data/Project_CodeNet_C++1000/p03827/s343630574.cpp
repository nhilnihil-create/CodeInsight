#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N  >>S;
  vector <int> vec(N + 1);
  
  vec.at(0) = 0;
  for (int i = 0 ; i < N ; i++ ){
    if (S.at(i) == 'I' ){
      vec.at(i + 1) = vec.at(i) + 1;
    }
    else {
      vec.at(i + 1 ) = vec.at(i) - 1;
    }
  }
  
//  for ( int i = 0 ; i < N ; i++ ) {
//    cout << vec.at(i) << " " ;
//  }
  
  int answer = 0;
  for ( int i = 0 ; i < N + 1 ; i++ ){
    answer = max(answer, vec.at(i) );
  }
  
  cout << answer;
}