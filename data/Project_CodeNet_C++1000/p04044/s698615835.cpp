#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n,l;cin >> n >> l;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(),a.end());    

    for(int i = 0; i < n-1; i++) {
        cout << a[i];
    }
    cout << a[n-1] << endl;

    return 0;
}