#include<cstdio> 
#include<algorithm>  
#include<iostream>  
using namespace std;   
int gcd(int x,int y)
{        return x ? gcd(y%x,x) : y;    }  
  int main()   
   {        int n,a,Max,k;   
        int i;       
         cin>>n>>a>>k;   
              int tmp=k;     
                 Max=k;      
                   int ans=0;  
                         for(i=1;i<n;i++)   
                              {            int t;     
                                     cin>>t;      
                                           tmp=gcd(tmp,t);
                        Max=max(Max,t);        }  
                              //cout<<a<<endl;    
                                  if(n == 1)       
                 {            if(a == tmp)         
                        ans = 1;        }         
                                   else        {            if(a%tmp == 0 && a <= Max)
                                        ans = 1;        }               
                                             if(ans == 1)           
                                              puts("POSSIBLE");     
                                                         else        
                                                             puts("IMPOSSIBLE");   
                                                                              }



                                                                              
