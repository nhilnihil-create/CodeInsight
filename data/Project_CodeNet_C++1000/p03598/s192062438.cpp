#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    int ans = 0;
    for(int i=0; i<n; ++i){
        ans += (2*a[i] <= 2*(k-a[i]))? 2*a[i] : 2*(k-a[i]);
    }
    cout << ans;
    return 0;
}
