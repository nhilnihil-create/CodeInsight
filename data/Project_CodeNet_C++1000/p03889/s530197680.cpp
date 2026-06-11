#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
int main() {
  string s;
  cin >> s;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='p'&&s[s.size()-i-1]=='q') {
      continue;
    }
    else if(s[i]=='q'&&s[s.size()-i-1]=='p') {
      continue;
    }
    else if(s[i]=='b'&&s[s.size()-i-1]=='d') {
      continue;
    }
    else if(s[i]=='d'&&s[s.size()-i-1]=='b') {
      continue;
    }
    else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
