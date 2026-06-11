#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    int arr[2*n];
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+2*n);
    int ans=0;
    for(int i=0;i<2*n;i+=2){
        if(arr[i]<arr[i+1]){
            ans+=arr[i];
        }
        else if(arr[i+1]<arr[i]){
            ans+=arr[i+1];
        }
        else if(arr[i]==arr[i+1]){
            ans+=arr[i];
        }
    }
    cout<<ans<<endl;

    return 0;
}
