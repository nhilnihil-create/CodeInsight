#include<bits/stdc++.h>
using namespace std;

vector< int > z_algorithm(const string &s) {
  vector< int > prefix(s.size());
  for(int i = 1, j = 0; i < s.size(); i++) {
    if(i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while(i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int) s.size();
  return prefix;
}

string s;

int main(void){
    cin >> s;
    int n = s.size()/2;
    int res;
    for(int i = 0; i < n; i++){
        string a, b;
        a = s.substr(0, i);
        b = s.substr(i, i);
        if(a == b) res = 2*a.size();
    }
    cout << res << endl;
    return 0;
}
