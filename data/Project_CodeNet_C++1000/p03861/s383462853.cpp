#include<bits/stdc++.h>
using namespace std;

int main()

{
    long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,t,flag=0;

    cin>>a>>b>>t;

    if(a%t==0)
    {
        cout<<(b/t)-(a/t)+1<<endl;
    }

     else if(a%t!=0)
     {
         cout<< (b/t)-(a/t)<<endl;
     }
}
