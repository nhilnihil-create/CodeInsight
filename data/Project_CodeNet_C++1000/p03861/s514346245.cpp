#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long int
#define test_case long long int t,i;cin>>t;for(i=0;i<t;i++)

using namespace std;
int main()
{
    ll a, b, x, p, q, cnt=0;
    cin >> a >> b >> x;

    if(a%x==0)
        p = (a/x) - 1 ;
    else
        p=(a/x);

    q = b/x;

    cout << q-p << endl;;


    return 0;
}
