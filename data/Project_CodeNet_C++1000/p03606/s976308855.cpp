#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int l,r;
    while (cin >> l >> r)
    {
        ans += r-l+1;
    }
    cout << ans << endl;
}