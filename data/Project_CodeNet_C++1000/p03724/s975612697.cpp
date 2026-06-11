#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) begin(a),end(a)

int main()
{
    int N, M; cin >> N >> M;
    vi c(N+1, 0);
    rep(i, M) {
        int a, b; cin >> a >> b;
        c[a]++;
        c[b]++;
    }
    cout << (all_of(all(c),[](int x){return x%2==0;}) ? "YES" : "NO") << endl;
}
