#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> button(N);
  rep(i, N){
  	cin >> button.at(i);
  }
    int X = 0;
  rep(j, 10 * 10 * 10 * 10 * 10){
    X = button.at(X) - 1;
  	if(X == 1){
    	cout << j + 1 << endl;
    	return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}