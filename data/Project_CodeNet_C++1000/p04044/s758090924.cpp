#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;
    cin >> n >> m;
    string a[n],b="";
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        b+= a[i];
    }
    cout << b;
}
