#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 105;
int a[N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= 2*n; ++i)
        cin >> a[i];
    sort(a+1,a+1+2*n);
    int ans = 0;
    for(int i = 1; i <= 2*n; i += 2) {
        ans += min(a[i],a[i+1]);
    }
    cout << ans << '\n';
return 0;
}