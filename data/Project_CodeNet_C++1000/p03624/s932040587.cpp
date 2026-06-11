#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int> num(26);
  for(int i = 0; i < 26; i++) {
    num.at(i) = i;
  }
  vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                           'n','o','p','q','r','s','t','u','v','w','x','y','z'};
  for(int i = 0; i < N; i++) {
    int x = S.at(i) - 'a';
    num.at(x) = 26;
  }
  sort(num.begin(), num.end()); 
  if(num.at(0) == 26) {
    cout << "None" << endl;
  }
  else {
    int y = num.at(0);
    cout << alphabet.at(y) << endl;
  }
}