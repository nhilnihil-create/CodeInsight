#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    int n;
    cin >> n;
    vector<int> a(1e5);
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        a[x]++;
    }

    int ans = 0;
    ans = max(ans, a[0]+a[1]);
    ans = max(ans, a[1e5]+a[1e5-1]+a[1e5+1]);
    for(int i=1; i<1e5; ++i){
        ans = max(ans, a[i]+a[i-1]+a[i+1]);
    }
    cout << ans;
}