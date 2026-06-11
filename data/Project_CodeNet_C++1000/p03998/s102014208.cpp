#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string sa, sb, sc;
  cin >> sa >> sb >> sc;
  int a = sa.length();
  int b = sb.length();
  int c = sc.length();

  int i = 0, j= 0, k = 0;
  char x = 'a';
  while (i != a+1 && j != b+1 && k != c+1) {  
    if (x == 'a') {
      x = sa[i];
      i++;
    } else if (x == 'b') {
      x = sb[j];
      j++;
    } else if (x == 'c') {
      x = sc[k];
      k++;
    }
  }
  char ans;
  if (i == a+1) ans = 'A';
  else if (j == b+1) ans = 'B';
  else if (k == c+1) ans = 'C';
  cout << ans << endl;
  return 0;
}
