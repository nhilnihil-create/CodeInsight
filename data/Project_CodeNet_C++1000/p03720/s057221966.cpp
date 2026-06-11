#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;
 
int main() {
    long long n,m; cin >> n >> m;
    vector<int> ans(n);
    long long a;
    for (int i = 0; i < 2*m; i++)
    {
        cin >> a;
        ans[a-1] = ans[a-1]+1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}