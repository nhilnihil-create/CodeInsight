#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  char a[64],b[64];
  while(~scanf("%s%s",a,b)){
    int i;
    for(i=0;b[i];i++){
      printf("%c%c",a[i],b[i]);
    }
    if(a[i]) printf("%c",a[i]);
    printf("\n");
  }
  return 0;
}