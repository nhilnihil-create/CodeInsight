#include<iostream>
using namespace std;
int add(int n)
{
    int i,sum=0;
    for(i=1; i<=n; i++)
    {
        sum+=i;
    }
    return sum;
}
int main()
{
    int n,i,sum=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        sum=add(n);
    }
    cout<<sum<<endl;

    return 0;
}

