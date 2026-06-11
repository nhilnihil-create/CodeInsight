#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug_print.hpp"
#else
#define debug(...) 0
#endif

template<class T> inline bool chmax(T &a, T b)
{
    if(a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b)
{
    if(a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    ll ans = 1LL<<60;
    for(int bit=0; bit < (1<<N); bit++)
    {
        vector<bool> can_see(N, false);
        for(int i=0; i<N; i++)
        {
            if(bit & (1<<i))
            {
                can_see[i] = true;
            }
        }
        int num_see = 0;
        ll cost = 0;
        for(int i=0, height=-1; i<N; i++)
        {
            if(chmax(height, A[i])) num_see++;
            else if(can_see[i])
            {
                cost += height+1 - A[i];
                height++;
                num_see++;
            }
        }
        if(num_see >= K) chmin(ans, cost);
    }
    cout << ans << endl;

    return 0;
}
