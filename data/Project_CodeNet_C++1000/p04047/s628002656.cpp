#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[2*n];
    for(int i=0; i<2*n; i++)
        cin>>ar[i];

    int s=sizeof(ar)/sizeof(ar[0]);

    sort(ar, ar+s);

    int add=0;
    for(int i=0; i<n; i++)
        add+=ar[2*i];

     cout<<add;
    cout<<endl;

    return 0;
}
