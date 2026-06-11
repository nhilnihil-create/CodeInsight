#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    for(int i=0; i<M; i++) cin >> a[i] >> b[i];

    vector<int> cnt(N+1, 0);
    for(int i=0; i<M; i++)
    {
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    string ans = "YES";
    for(auto num : cnt)
    {
        if(num%2==1) ans = "NO";
    }
    cout << ans << endl;

    return 0;
}
