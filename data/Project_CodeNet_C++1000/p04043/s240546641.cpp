#include <bits/stdc++.h>
using namespace std;
const int N=101;

int arr[11];
int solve()
{
    int p;
    cin>>p;
    arr[p]++;
    cin>>p;
    arr[p]++;
    cin>>p;
    arr[p]++;
    if(arr[5]==2 && arr[7]==1)
        return cout<<"YES", 0;
    return cout<<"NO", 0;
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