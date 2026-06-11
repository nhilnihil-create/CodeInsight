#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{ 
      string c,d,e;
       
      cin>>c>>d>>e;
 
      
      
        int n = c.length(); 
    char g[n + 1]; 
    strcpy(g, c.c_str()); 
    
     int m = d.length(); 
    char h[m + 1]; 
    strcpy(h, d.c_str()); 
    
    
     int o = e.length(); 
    char k[o + 1]; 
    strcpy(k, e.c_str()); 

     if((g[n-1]==h[0])&&(h[m-1]==k[0]))
        cout<<"YES";

     else  cout<<"NO";
     
   return 0;

}