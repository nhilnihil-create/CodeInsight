#include <iostream> 
  
using namespace std; 
int a[100001],i,n,k,x,y,t; 
int main(int argc, char** argv) { 
      
    cin>>n; 
    if(n==1) 
    {   cin>>x; 
        cout<<1; 
        return 0; 
    } 
    if(n==2) 
    {   cin>>x>>y;  
        if(x!=y) 
           cout<<2; 
        else
            cout<<0; 
        return 0; 
    } 
    for(i=0;i<n;i++) 
    { 
        cin>>x; 
        a[x]++; 
    } 
      
      
    for(i=1;i<=100000;i++) 
        if(a[i]) 
        { 
            if(a[i]%2!=0) 
                k++; 
            else
                t++; 
        } 
    if(t%2==0) 
        k=k+t; 
    else
        k=k+t-1; 
    cout<<k; 
    return 0; 
} 