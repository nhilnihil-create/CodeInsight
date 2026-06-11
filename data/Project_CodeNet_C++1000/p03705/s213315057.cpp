#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a,b;
    cin>>a>>b;
    long long int dif=b-a;

    long long int sum=1;
    long long int ase=n-2;
    sum+=ase*dif;
    if(sum<0)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<sum<<endl;
    }

}
