#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x, y;
    long long int sum = 0;
    cin >> n >> k >> x >> y;

    if(n>k)
        sum = x*k + y*(n-k);
    else
        sum = x*n;

    cout << sum;

    return 0;
}
