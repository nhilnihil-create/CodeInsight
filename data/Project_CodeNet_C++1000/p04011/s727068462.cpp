#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    if(n<=k)cout << n*x;
    else{
        int sum = k*x;
        n-=k;
        sum+=n*y;
        cout << sum;
    }
}

