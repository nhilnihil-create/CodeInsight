#include <iostream>
using namespace std;

int main()
{
    long long x;
    long long sol,p=1;
    cin>>x;
    for(;p<=x;p*=2);
    for(sol=0;p;p/=2)
    {
     //   cout<<sol<<' '<<p<<' '<<(sol+p)*(sol+p+1)<<' '<<2*x<<'\n';
        if(sol+p<=x)
            if( 1LL*(sol+p)*(sol+p+1) <= 2*x )
                sol+=p;
    }
    if(sol*(sol+1)<2*x) sol++;
    cout<<sol<<'\n';
    return 0;
}
