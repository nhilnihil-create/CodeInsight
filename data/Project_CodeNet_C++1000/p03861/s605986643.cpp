#include <iostream>

using namespace std;

int main()
{
   long long int a,b,x;
    cin>>a>>b>>x;
    long long res;
    if(a>0)
        res = (b/x) - (a-1)/x;
    else
        res = (b/x) + 1;
    cout<<res<<endl;
        return 0;
}