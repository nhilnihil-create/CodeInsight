#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int a,b,c,d;
cin >> a >> b >> c >> d;
int x = a*b;
int y = c*d;
int ans = max(x,y);
cout << ans << endl;
 }