#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    vector<int> v(n, 0);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int m = 0;
    cin >> m;
    while(m --) {
        int a = 0, b = 0;
        cin >> a >> b;

        cout << sum - v[a - 1] + b << endl;;
    }



    
    return 0;
}