#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    int ans = 0,light = 1;
    for (int i = 0; i < N; ++i)
    {
        ++ans;
        light = a[light - 1];
        if (light == 2)
        {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}