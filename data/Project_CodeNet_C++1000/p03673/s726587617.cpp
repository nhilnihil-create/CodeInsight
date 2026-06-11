#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> b,c;
    for(int i = 0; i < n; i += 2) {
        b.push_back(a[i]);
    }
    for(int i = 1; i < n; i += 2) {
        c.push_back(a[i]);
    }
    vector<int> ans;
    if(n%2==0){
        reverse(c.begin(),c.end());
        for(int i = 0; i < c.size(); i++) {
            ans.push_back(c[i]);
        }
        for(int i = c.size(); i < n; i++) {
            ans.push_back(b[i-c.size()]);
        }
    }
    else{
        reverse(b.begin(),b.end());
        for(int i = 0; i < b.size(); i++) {
            ans.push_back(b[i]);
        }
        for(int i = b.size(); i < n; i++) {
            ans.push_back(c[i-b.size()]);
        }
    }
    for(int i = 0; i < n-1; i++) {
        cout << ans[i] << ' ' ;
    }
    cout << ans[n-1] << endl;


    return 0;
}