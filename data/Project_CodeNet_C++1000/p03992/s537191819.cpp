#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  for(int i = 0; i < a.size(); i++){
    cout << a.at(i);
    if(i == 3)
      cout << ' ';
    else if(i == a.size() - 1)
      cout << endl;
  }
}
