#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
string s;
cin >> s;
string t = "CODEFESTIVAL2016";
int cnt  = 0;
rep(i,s.size())if(s.at(i)!=t.at(i)) cnt++;
  cout << cnt << endl;
}
