#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    sort(l.begin(), l.end(), greater<int>());
    for(int i = 0; i < k; i++){
        ans += l[i];
    }
    cout << ans << endl;
}