#include<bits/stdc++.h>
using namespace std;
 long long int  div(long long int a,long long int b,long long int x)
{
    if (a%x==0) 
        return (b / x) - (a / x) + 1; 
    return (b / x) - (a / x); 
}

int main(){
    long long a,b,x,y;
    cin>>a>>b>>x;
    div(a,b,x);
    cout<<div(a,b,x)<<endl;
    return 0;
}
