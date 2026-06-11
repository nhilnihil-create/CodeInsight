#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n;
    cin >> n;
    vec<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(i == a[a[i]])
        {
            ans++;
        }
    }
    ans /= 2;
    cout << ans << endl;
}
