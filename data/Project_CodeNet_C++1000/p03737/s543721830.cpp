#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int a[13],b[13],c[13];

  scanf("%s %s %s", a, b, c);

  printf("%c%c%c\n", a[0] - 'a' + 'A', b[0] - 'a' + 'A', c[0] - 'a' + 'A');
  
  return 0;
}
