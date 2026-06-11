#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    LL a,b,x;
    LL term=0;
    cin>>a>>b>>x;
    term+=(b/x);
    term-=(a/x);
    if(a%x==0)
    {
        term++;
    }
    cout<<term<<endl;
    return 0;
}
