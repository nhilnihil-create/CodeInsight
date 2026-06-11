#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
  
      int n;
      scanf("%d",&n);
       
      int flag=0;
      while(n!=0)
      {
        if(n%10==9)
        {
          flag=1;
          break;
        }
        
        n/=10;
      }
  
  if(flag==1)
     printf("Yes");
  
  else
     printf("No");
   
  
  return 0;
  
  
} 