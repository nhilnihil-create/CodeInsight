#include<iostream>
using namespace std;
int main()
{
   long long int n;
    cin>>n;
   long long int a,b;
    cin>>a>>b;
   long long int arr[100000];
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
  long long   int cost=0;
    for(long long int i=1;i<n;i++)
    {
        cost+=min((arr[i]-arr[i-1])*a,b);
    }
    cout<<cost;
}