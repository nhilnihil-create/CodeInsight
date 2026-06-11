#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,fl=0 ; cin>>a>>b>>c ;
    for(int x=1 ; x<=100000 ; x++)
    {
        if((b*x+c)%a==0) {fl=1 ; break ;}
    }
    if(fl) cout<<"YES"<<endl ;
    else cout<<"NO"<<endl ;
}
