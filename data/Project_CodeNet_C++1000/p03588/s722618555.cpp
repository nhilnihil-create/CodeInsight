#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end());
    cout << a[0]+b[0] << endl;
    return 0;
}