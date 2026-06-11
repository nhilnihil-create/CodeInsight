#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
map<char,int> a;
string s;
cin >> s;
rep(i,s.size()){
  a[s.at(i)]++;
}
bool ans  = true;
rep(i,s.size()){
  if(a.at(s.at(i))%2 != 0) ans = false;
}
cout << (ans?"Yes":"No") << endl;
}
