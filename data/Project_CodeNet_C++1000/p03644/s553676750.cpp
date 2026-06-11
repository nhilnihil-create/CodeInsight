#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,g,t=0,k=0,h;cin>>m;
    if(m==1)cout<<1;
    else {
    for(int i=2;i<=m;i++){
            h=i;
        while(h>0&&h%2==0){
                h/=2;
                t++;
        }
        if(t>k){
            k=t;
            g=i;
        }
        t=0;
    }
    cout<<g<<endl;
    }
   return 0;
   }