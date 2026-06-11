#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c;
     d=a+b;
     e=b+c;
     f=c+a;
     if(d>e && d>f)
     {
       if(e>f)
        {
           cout<<f;
        }
        else
        {
            cout<<e;
        }
     }
     else if(e>f && e>d )
     {
         if(f>d)
     {
         cout<<d;
     }
     else
     {
         cout<<f;
     }
     }
     else if(f>d && f>e)
     {
            if(d>e)
     {
         cout<<e;
     }
     else
     {
         cout<<d;
     }
     }
     else if(d==e && e==f)
     {
         cout<<d;
     }

    return 0;
}
