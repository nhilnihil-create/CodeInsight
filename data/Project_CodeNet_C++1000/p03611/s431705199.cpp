#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    int ma=a[0]+a[1];
    for(int i=2;i<N;i++)
    {
        int t=a[i-2]+a[i-1]+a[i];
        if(t>ma)ma=t;
    }
    cout<<ma<<endl;
    return 0;
}