#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  char a[106];
  char b[106];
  int na,nb;

  scanf("%s %s", a, b);

  na = strlen(a);
  nb = strlen(b);

  if(na > nb) printf("GREATER\n");

  else if(nb > na) printf("LESS\n");

  else {
    int i;
    int f = 0;
    for(i = 0;i < na;i++){
      if(a[i] > b[i]){
        f = 1;
        printf("GREATER\n");
        break;
      }

      else if(a[i] < b[i]){
        f = 1;
        printf("LESS\n");
        break;
      }
    }

    if(f == 0) printf("EQUAL\n");
  }

  return 0;
}