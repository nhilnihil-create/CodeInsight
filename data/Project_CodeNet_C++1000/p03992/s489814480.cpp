#include<bits/stdc++.h>
using namespace std;

int main(void)
{
  char a[12],s[4],d[8];
  scanf("%s",a);
  for(int i=0;i<4;i++){
    s[i]=a[i];
  }
  for(int j=0;j<8;j++){
    d[j]=a[j+4];
  }
  printf("%s %s\n",s,d);
  
}