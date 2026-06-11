#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  char s[29];
  int i;

  scanf("%s", s);

  for(i = 0;i <= 18;i++){
    if(i == 5 || i == 13) printf(" ");

    else printf("%c", s[i]);
  }
  return 0;
}