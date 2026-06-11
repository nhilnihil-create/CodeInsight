#include<iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int a[N];

int main()
{
    int n,i,sum=0,l=1,t;
    cin >> n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    t=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]==t) sum++;
        else
        {
            t=a[i];
            l++;
        }
    }
    if(sum%2==1)
    cout << l-1 << endl;
    else
    cout << l << endl;
    return 0;
}