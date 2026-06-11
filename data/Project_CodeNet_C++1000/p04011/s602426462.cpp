#include <bits/stdc++.h>
using namespace std;

main()
{
    long long int n,a,b,c;
    cin>>n>>a>>b>>c;
    if(n<=a)
    {
        cout<<n*b<<endl;
    }
    else{
        cout<<a*b+(n-a)*c<<endl;
    }
}
