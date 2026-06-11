#include<bits/stdc++.h>
using namespace std;
int main()
{
       ios::sync_with_stdio(false);
       cin.tie(0);
    int n,m;
    cin>>n>>m;
    string arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}
