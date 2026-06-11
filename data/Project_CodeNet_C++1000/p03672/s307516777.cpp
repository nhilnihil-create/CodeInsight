#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  char str[205];
  scanf("%s", str);
  int n = strlen(str);
  for(int i = n-2; i; i-=2){
    if(strncmp(str, str+i/2, i/2)==0){
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}