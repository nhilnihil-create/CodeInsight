#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int n;
  char s[100006];
  int f = 0;
  int fi = -1;
  int en = -1;

  scanf("%s", s);
  n = strlen(s);

  int i;
  for(i = 0;i < n - 1;i++){
    if(s[i] == s[i + 1]){
      f = 1;
      fi = i + 1;
      en = i + 2;
    }
  }

  if(f == 0){
    for(i = 0;i < n - 2;i++){
      if(s[i] == s[i + 2]){
        f = 1;
        fi = i + 1;
        en = i + 3;
      }
    }
  }

  printf("%d %d\n", fi, en);

  return 0;
}