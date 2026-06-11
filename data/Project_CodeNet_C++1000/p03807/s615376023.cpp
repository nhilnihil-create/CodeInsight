#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum%2) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}