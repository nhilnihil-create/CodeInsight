#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int d=a[n-1]-a[0];
    if (d>=2) {
        cout << "No";
    } else if (d==1) {
        int chi=upper_bound(a.begin(), a.end(), a[0])-a.begin();
        if (2*(a[0]-chi+1)<=n-chi&&a[0]>chi-1) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    } else {
        if (2*a[0]<=n||a[0]==n-1) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    return 0;
}