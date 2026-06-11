#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
string a,b;
cin >> a >> b;
if(a.size() > b.size()) cout << "GREATER" << endl;
else if(a.size() < b.size()) cout << "LESS" << endl;
else{
  rep(i,a.size()){
    if('0'+a.at(i) > '0'+b.at(i)){
      cout << "GREATER" << endl;
      return 0;
    }
    else if('0'+a.at(i) < '0'+b.at(i)){
      cout << "LESS" << endl;
      return 0;      
    }
    
  }
  cout << "EQUAL" << endl;
}
  }
