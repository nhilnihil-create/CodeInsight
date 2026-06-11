#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    set<string> boje;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 400) boje.insert("gray");
        else if (a[i] < 800) boje.insert("brown");
        else if (a[i] < 1200) boje.insert("green");
        else if (a[i] < 1600) boje.insert("cyan");
        else if (a[i] < 2000) boje.insert("blue");
        else if (a[i] < 2400) boje.insert("yellow");
        else if (a[i] < 2800) boje.insert("orange");
        else if (a[i] < 3200) boje.insert("red");
        else cnt++;
    }
    int mx, mn;
    mx = boje.size() + cnt;
    if (boje.size() == 0) mn = 1;
    else mn = boje.size();
    cout << mn << " " << mx << "\n";
    return 0;
}
