#include <bits/stdc++.h>

using namespace std;

bool is_unique(string str){
  int n = str.size();
  sort(str.begin(),str.end());
  str.erase(unique(str.begin(),str.end()),str.end());
  return n == str.size();
}

int main(){
  string str;
  cin >> str;
  cout << (is_unique(str)?"yes":"no") << endl;
}
