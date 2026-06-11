#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int t[n];
    for (int i=0; i<n; i++) cin >> t[i];
    cin >> m;
    int p[m];
    int x[m];
    for (int i=0; i<m; i++) cin >> p[i] >> x[i];
    for (int i=0; i<m; i++) {
        int res = 0;
        for (int j=0; j<n; j++) {
            if (j == p[i]-1) {
                res += x[i];
            }
            else res += t[j];
        }
        cout << res << '\n';
    }
    
    return 0;
}