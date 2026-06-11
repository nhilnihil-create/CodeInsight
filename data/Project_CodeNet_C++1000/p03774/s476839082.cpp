#include<bits/stdc++.h>
#include <vector>
#define endl '\n';
using namespace std;

int main()
{   
    int n, m; cin >> n >> m;
    int s[51][2];
    int p[51][2];
    for (int i = 0; i < n; ++i)
        cin >> s[i][0] >> s[i][1];
    for (int i = 0; i < m; ++i)
        cin >> p[i][0] >> p[i][1];
    for (int i = 0; i < n; ++i) {
        int mn = INT_MAX;
        int chosen = i;
        int xindx = -1;
        for (int j = 0; j < m; ++j) {
            int val = abs(s[i][0] - p[j][0]) + abs(s[i][1] - p[j][1]);
            if (val < mn) 
                mn = val, chosen = j + 1, xindx = p[j][0]; 
            else if(val == mn && p[j][0] < xindx) 
                mn = val, chosen = j + 1, xindx = p[j][0];
        }
        cout << chosen << "\n";
    }
    return 0;
}