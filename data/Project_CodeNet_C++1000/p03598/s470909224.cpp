#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0, K = 0;
  cin >> N >> K;
  int sum = 0;

  for( int i = 0; i < N; ++i ){
    int x = 0;
    cin >> x;
    int ansA = x * 2;
    int ansB = ( K - x ) * 2;
    if( ansA > ansB ){
      sum += ansB;
    }else{
      sum += ansA;
    }
  }
  cout << sum << endl;
}
