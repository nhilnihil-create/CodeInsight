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

    int ans = 2*N;
    for(int i=1; i<=N; i++)
    {
        if(s.substr(N-i, i) == t.substr(0, i)) ans = 2*N-i;
    }
    cout << ans << endl;

    return 0;
}
