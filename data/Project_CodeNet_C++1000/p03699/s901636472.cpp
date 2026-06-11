#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> s(N);
  int sum = 0;
  bool flag = false;
  for ( int i = 0; i < N; i++ ) {
    cin >> s[i];
    if ( s[i] % 10 ) flag = true;
    sum += s[i];
  }

  sort(s.begin(), s.end());

  if ( !flag ) {
    cout << 0 << endl;
  } else if ( sum % 10 ) {
    cout << sum << endl;
  } else {
    for ( int i = 0; i < N; i++ ) {
      if ( s[i] % 10 ) {	
	sum -= s[i];
	break;
      }      
    }
    cout << sum << endl;
  }

  return 0;
}
