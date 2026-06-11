#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<iomanip>
#include<map>
#include<cstring>
using namespace std;
long long n,m;
int main()
{
    cin>>n>>m;
    if(n*2>m) cout<<m/2;
    else if(n*2==m) cout<<n;
         else
		 {
             m-=n*2;
             m/=4;
             cout<<n+m;
         }
    return 0;
}