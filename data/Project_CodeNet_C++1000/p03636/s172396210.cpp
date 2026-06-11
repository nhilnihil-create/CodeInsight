#include <bits/stdc++.h>

using namespace std;


int main() {
  string s;
  cin>>s;
  int n = s.length();
	string res = s.substr(0,1)+to_string(n-2)+s.substr(n-1);
  cout<<res<<endl;
}