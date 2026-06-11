#include<iostream>
#include<string>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string O, E;
  cin >> O >> E;

  rep(i,0,E.size()-1) cout << O[i] << E[i];
  if (O.size() != E.size()) cout << O.back();
  cout << endl;
  return 0;
}
