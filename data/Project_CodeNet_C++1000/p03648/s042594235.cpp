#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))

#define MOD 1000000007
#define INF 1000000000

ll K;

int main()
{
    cin >> K;
    vector<ll> ans;
    if(K == 0) {
        printf("4\n");
        printf("3 3 3 3\n");
        return 0;
    }
    else if(K == 1) {
        printf("3\n");
        printf("1 0 3\n");
        return 0;
    }
    else if(2 <= K && K <= 50) {
        printf("%lld\n", K);
        for(int i = 1; i <= K; ++i) {
            ans.push_back(i);
        }
    } else {
        ll N = 50;
        ll x = K % N;
        printf("50\n");
        for(int i = 0; i < x; ++i) {
            ans.push_back((K / N) + N - i);
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < N - x; ++i) {
            ans.push_back((K / N) + i);
        }
    }
    REP(i, ans.size()) {
        printf("%lld", ans[i]);
        if(i != ans.size() - 1) { printf(" "); }
        else { printf("\n"); }
    }

    return 0;
}
