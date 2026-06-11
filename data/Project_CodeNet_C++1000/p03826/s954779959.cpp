#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,f,s;
    cin>>a>>b>>c>>d;
    f=a*b;
    s=c*d;
    if(f>s){
        cout<<f<<endl;
    }
    else if(s>f){
        cout<<s<<endl;
    }
    else{
        cout<<s<<endl;
    }

    return 0;
}

