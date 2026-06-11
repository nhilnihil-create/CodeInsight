#include <stdio.h>
#include <string.h>
int main(){
 char a[100],  b[100],  c[100];
 scanf("%s %s %s", &a, &b, &c);
 
 int akhirA= strlen(a)-1;
 int akhirB= strlen(b)-1;
 if(a[akhirA] == b[0] && b[akhirB] == c[0]){
  puts("YES");
 }
 else{
  puts("NO");
 }
 return 0;
}