#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b; 
  string c;
  cin >> a >> b;
  vector<string> vec(0);
  for (int i = 0; i < a; i++) {
     cin >> c;
     vec.push_back(c);
  }
  for(int i = 0 ; i < b+1 ; i++){
    cout << "#";
  }
  cout << "#" << endl;
  for(int i = 0 ; i < a ; i++){
    cout << "#";
    cout << vec.at(i);
    cout << "#" << endl;
  }
  for(int i = 0 ; i < b+1 ; i++){
    cout << "#";
  }
  cout << "#" << endl;
}
