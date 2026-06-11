#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    int n;
    cin >> n;
    n *= 2;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int sum = 0;
    for(int i=0;i<n;i+=2) {
        sum += a[i];
    }
    cout << sum;
}
