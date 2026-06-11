#include<bits/stdc++.h>

int main(){
  int a, i;
  scanf("%d", &a);
  for(i = 1; (i-1)*i < 2*a; i++);
  printf("%d\n", --i);
}