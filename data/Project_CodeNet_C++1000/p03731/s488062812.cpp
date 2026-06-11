#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,t;
    cin>>n>>t;
    int arr[n];
    for (int i=0;i<n;i++)cin>>arr[i];
    int p=0;
    int ans=0;
    for (int i=1;i<n;i++){
        if (arr[i]<=arr[i-1]+t){
            continue;
        }else{
            ans+=arr[i-1]-arr[p]+t;
            p=i;
        }
    }ans+=arr[n-1]-arr[p]+t;
    cout<<ans<<endl;
    return 0;
}