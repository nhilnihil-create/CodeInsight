#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,c,k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());   
    ll ans=1;
    int f=0;
    for(int i = 1; i < n; i++) {
        if(a[i]>a[f]+k){
            f=i;

            ans++;
        }
        else{
            if(i-f==c){
                f=i;

                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}