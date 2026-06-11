#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int tmp_len = 0;
  int max_len = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'I') {
      tmp_len++;
    } else {
      tmp_len--;
    }
    max_len = max(max_len, tmp_len);
  }
  cout << max_len << endl;
  return 0;
}
