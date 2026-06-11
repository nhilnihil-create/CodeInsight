#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> s(N);
  int sum = 0;
  bool ten = true;
  for(int i = 0; i < N; i++) {
    cin >> s[i];
    sum += s[i];
    if(ten && s[i] % 10 != 0) {
      ten = false;
    }
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < N; i++) {
    if(ten) {
      cout << 0 << endl;
      break;
    }
    if(sum % 10 != 0) {
      cout << sum << endl;
      break;
    }
    else if((sum - s[i]) % 10 != 0) {
      cout << sum - s[i] << endl;
      break;
    }
    if(i == N - 1) {
      cout << 0 << endl;
      break;
    }
  }



  return 0;
}
