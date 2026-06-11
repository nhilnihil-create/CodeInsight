#include<iostream>
#include<string>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

string comp(string a, string b) {
  if (a.size() < b.size()) return "LESS";
  if (a.size() > b.size()) return "GREATER";
  rep(i,0,a.size()-1) {
    if (a[i] < b[i]) return "LESS";
    if (a[i] > b[i]) return "GREATER";
  }
  return "EQUAL";
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << comp(a, b) << endl;
  return 0;
}
