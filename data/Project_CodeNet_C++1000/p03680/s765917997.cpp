#include <bits/stdc++.h>
using namespace std;
 
int main() {
long long n;cin >> n ;
vector<long long> a(n);
for (long long i = 0; i < n; i++)
{
    cin >> a[i];
}
long long now=1;
for (long long i = 1; i < n+1; i++)
{

    now = a[now-1];
    if (now == 2)
    {
        cout << i << endl;
    return 0;    
    }
    
}
    cout << -1 << endl;
}