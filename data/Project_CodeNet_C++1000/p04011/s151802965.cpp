#include <iostream>
using namespace std;
int main()
{
  long long int n,k,x,y,rem,coast;
    cin>>n>>k>>x>>y;
    if(n>k)
    {
        rem = n-k;
        coast = (k*x) + (rem*y);
    }
    else if(n==k)
        coast = k * x;
    else
        coast = n * x;
    cout<<coast<<endl;
    return 0;
}