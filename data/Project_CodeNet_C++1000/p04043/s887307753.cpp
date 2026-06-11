#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int N = 2e5 + 5;

int32_t main()
{
    IOS;
    int t=1;
    // cin>>t;
    while(t--)
    {
        int a[3];
        for (int i = 0; i < 3; ++i)
        {
            cin>>a[i];
        }
        sort(a,a+3);
        if(a[0]==5&&a[1]==5&&a[2]==7) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}