#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> v(7);
    
    for(int i=0; i<7; i++)
        cin >> v[i];
    
    long long ans1 = 0, ans2 = 0;
    ans1 += v[3] / 2 * 2 + v[4] / 2 * 2;

    if(v[3] % 2 + v[4] % 2 == 2 && v[0])
        ans1 += 3LL + (v[0] - 1) / 2 * 2;
    else
        ans1 += v[0] / 2 * 2;

    if(v[0] && v[3] && v[4])
        ans2 += 3LL + (v[0] - 1) / 2 * 2 + (v[3] - 1) / 2 * 2 + (v[4] - 1) / 2 * 2;
    else
        ans2 += v[0] / 2 * 2LL + v[3] / 2 * 2 + v[4] / 2 * 2;

    cout << max(ans1, ans2) + v[1] << "\n";
    return 0;
}
