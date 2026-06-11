#include <bits/stdc++.h>

using namespace std;

 
 
int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
     

      
   
    int i,j,h,w,x,y;
    cin>>h>>w;
    string s;
    
    for(i=0;i<h;++i)
     {
         for(j=0;j<w;++j)
           {
               cin>>s;
               if(s=="snuke")
                  {
                      x=i;
                      y=j;
                  }
           }
     }
     
     cout<<(char)(y+65)<<x+1;
    
      
         
	return 0;
	
} 