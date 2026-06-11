#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
string s;
cin >> s;
string a,b,c;
a = s.substr(0,5);
b = s.substr(6,7);
c = s.substr(14,5);
cout << a << " " << b << " " << c << endl;
 }