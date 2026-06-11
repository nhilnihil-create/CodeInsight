#include<bits/stdc++.h>
#define FastRead                      \
                                    ios_base::sync_with_stdio(false); \
                                    cin.tie(0);
#define ll long long
#define endl "\n"
#define f for
using namespace std;
int main()

{
    FastRead
    ll int n,m,i;
    cin>>n>>m;
    string a[n];
    f(i=0; i<n; i++)
    {
       cin>>a[i];
    }
    sort(a,a+n);
    f(i=0; i<n; i++)
    {
       cout<<a[i];
    }
    return 0;

}