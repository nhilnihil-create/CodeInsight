#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main(){
    int a, b, c, d;

    cin >> a >> b >> c >> d;

   int minv = min(b, d);
   int maxv = max(a, c);
   if(minv >= maxv){
       printf("%d\n", minv - maxv);
   }
   else{
       printf("0\n");
   }

   return 0;
}