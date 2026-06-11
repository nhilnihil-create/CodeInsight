#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    sort(a.begin(), a.end());
    int r = 0;
    for(int l = 0; l < n; l++){
        int cnt = 0;
        while(r < n && a[l] == a[r]){
            r++;
            cnt++;
        }
        if(cnt%2 == 1) ans++;
    }
    cout << ans << endl;
}