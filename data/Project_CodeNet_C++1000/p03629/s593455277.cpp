#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std; using ll=long long; const int INF=1e2; using P=pair<int,int>;
bool cmp(string s1, string s2) {
  if (s1 == "") return true;
  if (s1.size() != s2.size()) return s1.size() > s2.size();
  return s1 > s2;
}
bool cmp(P p1, P p2) {
  
}
int main() {
  string s; cin>>s; int n=s.size();
  int nx[n+1][26]; fill(nx[0], nx[n+1], n+1);
  for(int i=0;i<n;i++) {
    nx[i][s[i]-'a'] = i+1;
  }
  for(int j=0;j<26;j++) {
    for(int i=n-2;i>=0;i--) {
      nx[i][j] = min(nx[i][j],nx[i+1][j]);
    }
  }
  //for(int i=0;i<n;i++) cout<<nx[i]['b'-'a']<<" "; cout<<endl;

  string t[n+2];
  for(int i=0;i<=n;i++) {
    for(int j=0;j<26;j++) {
      int id = nx[i][j];
      if (cmp(t[id], t[i]+(char)('a'+j))) t[id] = t[i]+(char)('a'+j);
    }
    t[i].clear(); t[i].shrink_to_fit();
  }
  /*
  for(int i=0;i<=n+1;i++) {
    cout<<t[i]<<" ";
  } cout<<endl;*/
  cout<<t[n+1]<<endl;
}
