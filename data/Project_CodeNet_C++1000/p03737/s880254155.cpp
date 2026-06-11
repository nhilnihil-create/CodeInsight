#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  string a,b,c;
  cin >> a >> b >> c;
  int dif = 'A' - 'a';
    cout << (char)(a.at(0)+dif) << (char)(b.at(0)+dif)<<(char)(c.at(0)+dif)<<endl;
}