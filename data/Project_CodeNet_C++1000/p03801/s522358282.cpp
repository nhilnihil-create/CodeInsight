/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.21 00:30:05
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n;cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    a.push_back(make_pair(0,n));
    sort(a.begin(), a.end(), [](pair<int,int> a, pair<int,int> b){
        if (a.first == b.first) {
            return a.second < b.second;
        }
        else {
            return a.first > b.first;
        }
    });
    ll now = a[0].first,idx = a[0].second;
    vector<ll> ans(n,0);
    for (int i = 0; i < a.size(); i++) {
        ans[idx] += (now - a[i].first) * i;
        now = a[i].first;
        if (idx > a[i].second) {
            idx = a[i].second;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}