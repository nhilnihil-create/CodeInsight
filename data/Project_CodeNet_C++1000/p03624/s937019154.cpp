#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  vector<char> a;
  vector<int> b(26);
  for(char moji='a'; moji<='z'; ++moji) {
    a.push_back(moji);
  }
  for (int i = 0; i < 26; i++) {
    b[i] = 0;
  }
  vector<char>::iterator itr;
  for (int i = 0; i < S.length(); i++) {
    itr = find(a.begin(), a.end(), S[i]);
    size_t index = distance(a.begin(), itr);
    
    b[index]++;
  }
  
  for (int i = 0; i < 26; i++) {
    if (b[i] == 0) {
      cout << a[i] << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}