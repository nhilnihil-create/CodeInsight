#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   string s;
   cin >> s;
   char a,b;
   ll c,d = 0;
   a = s.at(0);
   c = s.length() - 2;
   d = s.length() - 1;
   b = s.at(d);
   cout << a << c << b <<endl;
}