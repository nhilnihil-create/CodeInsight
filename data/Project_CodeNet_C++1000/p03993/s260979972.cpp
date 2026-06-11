#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] -= 1;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[a[i]] == i) ans += 1;
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}