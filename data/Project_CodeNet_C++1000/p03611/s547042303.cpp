#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    unordered_map<int, int> C;
    rep(i, n) C[a[i]] = 0;
    rep(i, n) C[a[i]]++;

    int res = 0;
    for (auto kv: C) {
        int ai = kv.first;
        int cnt = kv.second;
        int sum = cnt;
        sum += C.find(ai - 1) == C.end() ? 0 : C[ai - 1];
        sum += C.find(ai + 1) == C.end() ? 0 : C[ai + 1];
        res = max(res, sum);
    }

    put(res);


    return 0;
}