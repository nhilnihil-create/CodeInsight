#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
string s;
cin >> s;
for(int i = s.size()-1; i >= 2; i--){
  string t = s.substr(0,i);
  if(t.size()%2 == 0){
    string x = t.substr(0,t.size()/2);
    string y = t.substr(t.size()/2,t.size()/2);
    if(x == y){
      cout << t.size() << endl;
      return 0;
    }
  }
}
}
