#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    
    vector<ll> ans;
    for (int i=0; i<n-1; i++) {
        if (a[i] == a[i+1]) {
            ans.push_back(a[i]);
            i++;
        }
        if (ans.size() == 2) break;
    }
    cout << (ans.size() == 2 ? ans[0] * ans[1] : 0) << endl;
    return 0;
}