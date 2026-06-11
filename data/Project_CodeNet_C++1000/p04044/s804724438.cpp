#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >>l;
    vector<string>a(n);
    for(int i =0 ; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    string ans;
    for(int i =0 ; i < n; ++i){
        ans += a[i];
    }
    cout << ans;
    return 0;
}
