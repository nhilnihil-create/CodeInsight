#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0;
  cin >> N;
  
  int as[N];
  
  for( int i = 0; i < N; ++i ){
    cin >> as[i];
  }
  
  int number = 0;
  int count = 0;
  while( count < N ){
    if( as[number] == 2 ){
      ++count;
      break;
    }else{
      number = as[number] - 1;
      ++count;
    }
  }

  if( count == N ){
    cout << "-1" << endl;
  }else{
    cout << count << endl;
  }
}