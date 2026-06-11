#include<stdio.h>
int n, s, tmp;
int main(){
  scanf("%d", &n);
  s=0;
  for (int i=0;i<n;i++){
    scanf("%d", &tmp);
    s += (tmp%2);
  }
  if (s%2){
    printf("NO\n");
  }
  else{
    printf("YES\n");
  }
  return 0;
}