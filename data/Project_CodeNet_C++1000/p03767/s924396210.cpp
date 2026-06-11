#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    long long int n,sum=0;
    cin>>n;
    long long int arr[3*n+1];
    for(long long int i=0;i<3*n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+3*n,greater<long long>());
    for(long long int i=1;i<=2*n;i=i+2)
    {
        sum=sum+arr[i];

    }
    cout<<sum<<endl;

}
