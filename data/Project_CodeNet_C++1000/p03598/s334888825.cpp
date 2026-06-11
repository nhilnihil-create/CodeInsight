#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n,k,c=0;
    cin >> n >> k;
    int a [n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]<=k/2) c+=a[i]*2;
        else c+=(k-a[i])*2;
    }
    cout << c << endl;
}