#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int L;
  int R;
  int Total = 0;
  
  cin >> N;

  for(int i = 0; i < N; i++){
	cin >> L >> R;
    
    Total = Total + ( R - L + 1 );
  }
    
  cout << Total << endl;
    
}
