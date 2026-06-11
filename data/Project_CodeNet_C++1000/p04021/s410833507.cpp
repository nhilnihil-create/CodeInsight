#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define xx first
#define yy second
pii a[100009];
int main()
{
    int n,i,j;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i].xx;
        a[i].yy=i;
    }
    sort(a,a+n);
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(abs(a[i].yy-i)%2)
            ans++;
    }
    cout << ans/2 << endl;
}
