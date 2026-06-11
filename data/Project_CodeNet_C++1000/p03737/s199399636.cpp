#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   vector<string> s(3);
   rep(i, 3) {
       cin >> s[i];
   }

   cout << (char)(s[0][0]-32) << (char)(s[1][0]-32) << (char)(s[2][0]-32) << endl;

}