#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((b-a)==(c-b))
        printf("YES");
  
    else
       printf("NO");
 
    
	return 0;
}