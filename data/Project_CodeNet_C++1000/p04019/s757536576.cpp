#include <bits/stdc++.h>
using namespace std;

int n, s, w, e;

int main() {
  string a;
  cin >> a;
  int l = a.size();
  for (int i = 0; i < l; i++)
    if (a[i]=='N') n++;
    else if (a[i]=='S') s++;
    else if (a[i]=='W') w++;
    else e++;

  if (n==0 && s>0 ||
      s==0 && n>0 ||
      w==0 && e>0 ||
      e==0 && w>0 ) cout << "No" << endl;
  else cout << "Yes" << endl;
}