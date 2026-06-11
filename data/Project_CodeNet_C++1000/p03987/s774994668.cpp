#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(),a.end());

    set<int> pos = {0,n+1};
    long long int ans = 0;
    for(int i=0; i<n; i++){
        long long int p = a[i].second;
        long long int left = *pos.lower_bound(a[i].second);
        long long int right = *prev(pos.lower_bound(a[i].second));
        //cout << i+1 << " : " << left << " " << right << endl;
        
        ans += (i+1) * (p - left) * (right - p);
        pos.insert(a[i].second);
    }
    cout << ans << endl;
    return 0;
}