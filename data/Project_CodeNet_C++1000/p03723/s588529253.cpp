#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d,e,f,i;scanf("%d%d%d",&a,&b,&c);
  if(a==b && b==c && a%2==0){
    printf("-1\n");return 0;
  }
  for(i=0;a%2==0 && b%2==0 && c%2==0;i++){
    d = a;e = b;f = c;
    a = (e+f)/2;
    b = (d+f)/2;
    c = (d+e)/2;
  }
  printf("%d\n",i);
}