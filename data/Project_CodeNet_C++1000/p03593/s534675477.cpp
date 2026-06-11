#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  int h,w; cin>>h>>w;
  vector<string> a(h);
  vector<int> c(26, 0);
  rep(i, h) cin>>a[i];
  rep(i, h) rep(j, w) c[a[i][j]-'a']++;

  int g1 = (h%2 && w%2);
  int g2 = 0;
  if (h%2) g2 += w/2;
  if (w%2) g2 += h/2;
  int g4 = (h/2) * (w/2);

  int cnt1 = 0;
  int cnt2 = 0;
  int cnt4 = 0;
  rep(i, 26) {
    int x = c[i]%4;
    if (x == 1) {
      cnt1++;
    } else if (x == 2) {
      cnt2++;
    } else if (x == 3) {
      cnt1++;
      cnt2++;
    }
    cnt4 += c[i]/4;
  }
  if (cnt4-g4 > 0) {
    cnt2 += (cnt4-g4)*2;
    cnt4 = g4;
  }
  if (cnt1==g1 && cnt2==g2 && cnt4==g4) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
