#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL << 60; 

int main()
{
  string s; cin >> s;
  int count = s.size()-2;
  cout << s[0] << count << s[s.size()-1] << endl;
}