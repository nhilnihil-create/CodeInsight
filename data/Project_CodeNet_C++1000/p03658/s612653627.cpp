#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n,k,s=0;
   cin>>n>>k;
   int x[n];
   for(int i=0;i<n;i++)
    cin>>x[i];
    sort(x,x+n,greater<int>());
    for(int i=0;i<k;i++)
    s+=x[i];
    cout<<s;
   return 0;
   }