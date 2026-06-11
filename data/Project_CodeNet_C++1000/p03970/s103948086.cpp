#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> data(16);
  for (int i = 0; i < 16; i++) {
    cin >> data.at(i);
  }

  string str = "CODEFESTIVAL2016";
    
  int answer = 0 ;

  for (int i = 0; i < 16; i++) {

    if (data.at(i) != str.at(i) ) {
      answer++;
    }

  }

  cout << answer << endl;
}
