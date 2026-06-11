#include<iostream>
#include <string.h>
#include <algorithm>
#include<cstdlib>
typedef long long ll;
using namespace std;

int main()
{
    ll n,a[200000],x = 0,y  = 0,lim= 9223372036854775807,ans=0;
    memset(a,0,sizeof(a));
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }

    for(int i = 0; i < n-1; i++)
    {
       x += a[i];
       if(abs(ans-2*x) <= lim)
       {
           lim = abs(ans-2*x);
       }
    }

    cout << lim << endl;
}