#include <iostream>
#include <string>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  rep(i, 0, 19) {
    if(i == 5 || i == 13) cout << " ";
    else cout << s[i];
  }
  cout << "\n";
}
