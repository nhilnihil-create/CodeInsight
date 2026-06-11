#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0; i < n; ++i){
        cin >> a[i];
    }
    long long ans = max(0, a[0]-x);
    a[0] -= max(0, a[0]-x);
    for(int i = 1; i < n; ++i){
        ans += max(0, a[i]+a[i-1]-x);
        a[i] -= max(0,a[i]+a[i-1]-x);
    }
    cout << ans << endl;
    return 0;
}