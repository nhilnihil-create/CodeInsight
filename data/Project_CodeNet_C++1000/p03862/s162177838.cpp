#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll count=0;
    if(a[0]>x){
        count+=a[0]-x;
        a[0]=x;
    }
    for(int i = 1; i < n; i++) {
        if(a[i]+a[i-1] > x){
            int tmp=a[i]+a[i-1]-x;
            count+=tmp;
            a[i]-=tmp;
        }
    }
    cout << count << "\n";
    return 0;
}