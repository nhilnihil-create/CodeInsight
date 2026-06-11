#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  set<int> s1, s2;
  for(int i=0; i<m; i++){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    if(tmp1==1) s1.insert(tmp2);
    if(tmp2==n) s2.insert(tmp1);
  }
  for(auto itr=s1.begin(); itr!=s1.end(); itr++){
    if(s2.count(*itr)){
      cout << "POSSIBLE";
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}