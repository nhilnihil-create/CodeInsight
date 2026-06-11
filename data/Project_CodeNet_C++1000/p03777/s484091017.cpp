#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  char a[2];
  char b[2];

  scanf("%s %s", a, b);

  if(a[0] == b[0]) printf("H\n");
  else printf("D\n");

  return 0;
}