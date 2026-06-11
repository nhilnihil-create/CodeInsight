#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  string s; cin >> s;
  int l = s.find_first_of('A');
  int r = s.find_last_of('Z');
  cout << r-l+1 << "\n";
  return 0;
}