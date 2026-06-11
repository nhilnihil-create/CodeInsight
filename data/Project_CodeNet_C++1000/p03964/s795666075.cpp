#include <iostream>
#include <cmath>
using namespace std;

void solve()
{
    int n; cin >> n;
    long long t[n], a[n];
    for(int i = 0; i < n; ++i){
        cin >> t[i] >> a[i];
    }

    for(int i = 1; i < n; i++){
        long long n = max((t[i-1]-1)/t[i]+1, (a[i-1]-1)/a[i]+1);
        t[i] *= n;
        a[i] *= n;  
    }
    cout << t[n-1]+a[n-1] << endl;
}

int main()
{
    solve();
    return 0;
}