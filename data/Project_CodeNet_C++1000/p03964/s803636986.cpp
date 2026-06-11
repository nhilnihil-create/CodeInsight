#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long t[n],a[n];
    long long tt=1,aa=1;
    long long m;
    for(long long i=0;i<n;i++){
        cin >> t[i] >> a[i];
        m=max((tt+t[i]-1)/t[i],(aa+a[i]-1)/a[i]);
        tt=m*t[i];
        aa=m*a[i];
    }
    cout << tt+aa << endl;
}