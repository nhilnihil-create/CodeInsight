#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> v(n,0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a]++;
        v[b]++;
    }

    for(int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    return 0;
}