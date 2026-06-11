#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  char o[56];
  char e[56];
  int no,ne;
  int i,j,k;

  scanf("%s %s", o, e);

  no = strlen(o);
  ne = strlen(e);

  j = 0;
  k = 0;
  for(i = 1;i <= no + ne;i++){
    if(i % 2 == 0) printf("%c", e[j++]);

    else printf("%c", o[k++]);
  }

  printf("\n");

  return 0;
}
