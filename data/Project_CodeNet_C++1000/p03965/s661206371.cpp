#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  char s[100006];
  int gcnt = 0;
  int pcnt = 0;
  int i,n;

  scanf("%s", s);
  n = strlen(s);

  for(i = 0;i < n;i++){
    if(s[i] == 'g') gcnt++;

    else pcnt++;
  }

  int r;
  if(gcnt >= pcnt){
    r = gcnt - pcnt;
    printf("%d\n", r/2);
  }

  else {
    r = pcnt - gcnt;

    printf("%d\n", -r/2 - 1);
  }

  return 0;
}