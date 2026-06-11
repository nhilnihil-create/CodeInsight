#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int five = 0;
  int seven = 0;
  int x;
  for(int i = 0; i < 3; i++){
    scanf("%d",&x);
    if(x == 5) five++;
    else if(x == 7) seven++;
  }
  if(five == 2 && seven == 1) printf("YES\n");
  else printf("NO\n");
  return 0;
 
}  