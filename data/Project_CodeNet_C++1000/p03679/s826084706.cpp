#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
  
    int x,a,b;
    scanf("%d%d%d",&x,&a,&b);
    
    if((b-a)<=x)
      {
          if((b-a)<=0)
              printf("delicious");
              
          else
              printf("safe");
      }
      
    else
      printf("dangerous");
  
    	return 0;
} 