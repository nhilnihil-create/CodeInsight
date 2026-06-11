#include <bits/stdc++.h>
using namespace std;

int main(){

int a,b,c,d,s,e,f;
cin >>a>>b>>c>>d;

s=max(a, c);
e=min(b, d);

 f=e-s;
    if(f>=0)
    {
        cout<<f<<endl;
    }
    else
    {
        cout<<0<<endl;
    }

}
