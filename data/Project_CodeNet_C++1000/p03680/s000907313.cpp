#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> buttons(N);
  
  for (int n = 0; n < N; n++) cin >> buttons.at(n);
  int answer = 0;
  int pushedButton = 0;
  for (int n = 0; n < N; n++) {
    answer++;
    if (buttons.at(pushedButton) == 2) {    
      cout << answer << endl;
      return 0;
    } else {
      pushedButton = buttons.at(pushedButton) - 1;
    }
  }
  cout << -1 << endl;
}
