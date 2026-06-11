#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string t = to_string(s.size() - 2);
  cout << s.at(0) + t + s.at(s.size() - 1) << endl;
}