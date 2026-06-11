#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> a(3);
    for(int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if(a[0] + a[1] == a[2])
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
