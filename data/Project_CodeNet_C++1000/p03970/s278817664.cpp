#include <bits/stdc++.h>
using namespace std;
int main() {
  string s,t="CODEFESTIVAL2016";
  cin>>s;
  auto i=t.begin();
  cout << accumulate(s.begin(),s.end(),0,[&](int a,char c){return a+(*(i++)!=c);}) << endl;
}