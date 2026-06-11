#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a[3*n];
    for(long long i=0;i<3*n;i++) cin >> a[i];
    sort(a,a+3*n);
    long long ans=0;
    for(long long i=n;i<3*n;i+=2){
        ans+=a[i];
    }
    cout << ans << endl;
}