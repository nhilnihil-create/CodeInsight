#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

const string t[] = {"dream","dreamer","erase","eraser"};
string s;
bool dfs(int i = 0){
  if(i==s.size()) return true;
  bool res = false;
  for(const string& ti:t){
    if(i+ti.size()>s.size()) continue;
    string si = s.substr(i,ti.size());
    if(si!=ti) continue;
    if(dfs(i+si.size())) return true;
  }
  return false;
}
int main() {
  cin >> s;
  cout << (dfs()?"YES":"NO") << endl;
}
