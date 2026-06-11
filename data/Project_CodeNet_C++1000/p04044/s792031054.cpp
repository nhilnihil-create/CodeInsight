#include <bits/stdc++.h>
using namespace std;
const int N=101;

string arr[N];
int solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        cout<<arr[i];
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt" ,"r" ,stdin);
    //freopen("output.txt" ,"w" ,stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // int t;
   // cin>>t;
   // while(t--)
        solve();

    return 0;
}