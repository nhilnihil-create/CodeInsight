#include<iostream>
#include<iomanip>
using namespace std; 
 
int main ()
{
    int n;
    cin>>n;
    int rem=0;
    int q=n;
    while (q!=0)
    {
        
        rem =rem*10+q%10;
        q=q/10;
    }
    if (rem==n)
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}