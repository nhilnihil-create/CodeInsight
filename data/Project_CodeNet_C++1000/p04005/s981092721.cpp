#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
#define ll long long
int main()
{
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]%2 == 0 || a[1]%2 == 0 || a[2]%2 == 0)
    {
        cout<<0;
    }
    else cout<<(ll)(a[0] * a[1] * (a[2]%2));
    return 0;
}
