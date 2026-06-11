#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007
 
int main(){
  int h,w;
  char s[106][106];
 
  scanf("%d %d", &h, &w);
 
  int i;
  for(i = 0;i < h;i++) scanf("%s", s[i]);
 
  for(i = 0;i < h;i++){
    printf("%s\n", s[i]);
    printf("%s\n", s[i]);
  }
 
  return 0;
}
