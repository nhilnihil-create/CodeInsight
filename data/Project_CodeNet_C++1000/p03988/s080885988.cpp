#include <bits/stdc++.h>

using namespace std;

int a[110];
int main()
{
    int n, md = 0; cin >> n;
    for (int i = 0; i < n; i ++){
        int d; cin >> d; a[d] ++;
        md =  max(d, md);
    }
    int r = (md + 1) / 2;
    for (int i = 0; i < r; i ++){
        if (a[i] >= 1) return cout << "Impossible", 0;
    }
    if (md % 2 == 0) if (a[r] != 1) return cout << "Impossible", 0;
    if (md % 2 != 0) if (a[r] != 2) return cout << "Impossible", 0;
    for (int i = r + 1; i <= md; i ++){
        if (a[i] <= 1) return cout << "Impossible", 0;
    }
    cout << "Possible";
    return 0;
}
