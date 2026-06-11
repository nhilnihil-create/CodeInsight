#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

int main()
{
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  a *= 100;
  b *= 100;

  int ans1 = 0;
  int ans2 = 0;
  for (int i=0; i<=30 && i*a<=f; i++) {
    for (int j=0; j<=30 && i*a+j*b<=f; j++) {
      if (i+j > 0) {
        int water = a*i + b*j;
        int maxsugar = min(water*e/100, f-water);
        int sugar = 0;

        for (int k=0; k<=100 && c*k<=maxsugar; k++) {
          for (int l=0; l<=100 && c*k+d*l<=maxsugar; l++) {
            sugar = max(sugar, c*k + d*l);
          }
        }
        if (ans1==0 || sugar*(ans1+ans2) > ans2*(water+sugar)) {
          ans1 = water;
          ans2 = sugar;
        }
      }
    }
  }
  printf("%d %d\n", ans1+ans2, ans2);

  return 0;
}
