#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    int group[] = {1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
    int x, y;
    cin >> x >> y;
    cout << (group[x-1] == group[y-1] ? "Yes" : "No") << endl;
}