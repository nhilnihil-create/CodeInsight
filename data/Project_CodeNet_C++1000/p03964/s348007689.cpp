#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    unsigned long long arr[n][2];
    unsigned long long x,y;
    cin>>arr[0][0]>>arr[0][1];
    for (int i=1;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
        if (arr[i-1][0]%arr[i][0]==0){
            x=arr[i-1][0]/arr[i][0];
        }else x=arr[i-1][0]/arr[i][0]+1;
        if (arr[i-1][1]%arr[i][1]==0){
            y=arr[i-1][1]/arr[i][1];
        }else y=arr[i-1][1]/arr[i][1]+1;
        x=max(x,y);
        arr[i][0]*=x;arr[i][1]*=x;
    }cout<<arr[n-1][0]+arr[n-1][1]<<endl;
    return 0;

}