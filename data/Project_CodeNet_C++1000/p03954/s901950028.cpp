#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int a[N];
int n;

bool solve(int x) {
    for (int i=n, j=n; i>1; i--, j++) {
        if ((a[i]>x) == (a[i-1]>x)) return a[i] > x;
        if ((a[j]>x) == (a[j+1]>x)) return a[j] > x;
    }
    return a[1] > x;
}

int main() {
    cin>>n;
    for (int i=1; i<2*n; i++)   cin>>a[i];

    int lo = 1, hi = 2*n-1;
    while (lo < hi) {
        int m = (lo+hi)/2;
//        cout<<lo<<" "<<hi<<" "<<m<<" "<<solve(m)<<endl;
        if (solve(m))   lo = m+1;
        else            hi = m;
    }
    cout<<lo<<endl;
}
