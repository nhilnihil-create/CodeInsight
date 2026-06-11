#include <bits/stdc++.h>
using namespace std;

int main() {
    long long  n, ans=0, x, y;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    queue<long long> q;
    for(int i=0; i<n-1; i++) {
        if(a[i]==a[i+1]) {
            q.push(a[i]);
            i++;
        }
    }
    if(q.size()>=2) {
        x=q.front();
        q.pop();
        y=q.front();
        ans=x*y;
    }
    cout << ans;
}