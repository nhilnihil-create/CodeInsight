#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  vector<string> s(a);
  for(int i = 0;i < a;i++){
    cin >> s[i];
  }
  
  for(int i = 0;i < b+2;i++){
    cout << '#';
  }
    cout << endl;
  for(int i = 0;i < a;i++){
    cout << '#' << s[i] << '#' << endl;
  }
  for(int i = 0;i < b+2;i++){
    cout << '#';
  }
  cout << endl;
}