#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());

    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[i].second % 2 != i % 2) ans += 1;
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}