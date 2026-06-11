#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
const unsigned int M = 1000000007;
using namespace std;
 
int main()
{
long long n,m=1; cin>>n;
for(long long i=1;i<=n;i++)
{
   m=(m*i)%M;
}
cout<<m;
return 0;
}