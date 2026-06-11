#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;
    int ans = N;
    for(int i=0; i<N; i++)
    {
        if(s.substr(i, N-i) == t.substr(0, N-i)) break;
        ans++;
    }
    cout << ans << endl;

    return 0;
}
