#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    int n;
    long long int k;
    cin >> n >> k;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    long long int x = a[0];
    for(int i=0; i<n; i++){
        x = gcd(x, a[i]);
    }

    if(k > a[n-1] || (a[n-1] - k) % x != 0) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;
    return 0;
}