#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;
 
int main()
{
int n,k,m=0; cin>>n>>k; int a[n];
for(int i=0;i<n;i++) cin>>a[i];
for(int i=0;i<k;i++)
{
    m+=*max_element(a,a+n);
    a[std::max_element(a,a+n) - a]=0;
}
cout<<m;
return 0;
}