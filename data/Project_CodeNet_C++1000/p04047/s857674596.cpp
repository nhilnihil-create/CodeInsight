#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    return a<=b? a:b;
}
int main()
{
    int n,i,sum=0;
    cin>>n;
    int arr[2*n];
    for(i=0 ; i<2*n ; i++)
     cin>>arr[i];
    sort(arr,arr+2*n);
    for(i=0 ; i<2*n ;)
    {
        sum=sum+min(arr[i],arr[i+1]);
        i=i+2;
    }
    cout<<sum;
    
}