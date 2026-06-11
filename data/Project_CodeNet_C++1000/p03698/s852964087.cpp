#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
string s;
cin >> s;
set<char> a;
rep(i,s.size()){
  a.insert(s.at(i));
}
if(a.size() == s.size()) cout << "yes" << endl;
else cout << "no" << endl;
  }
