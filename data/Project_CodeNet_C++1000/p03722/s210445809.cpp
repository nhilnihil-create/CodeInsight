#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint dp[1000][2001];

int main() {
    lint n, m;
    cin >> n >> m;

    vector<tuple<lint, lint, lint>> edge; // (from, to, cost)
    for(lint i=0; i<m; i++) {
        lint a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edge.emplace_back(a, b, -c);
    }

    fill(dp[0], dp[1000], 1e18);
    dp[0][0] = 0;
    for(lint len=1; len<=2000; len++)
    for(auto& e : edge) {
        lint from, to, cost;
        tie(from, to, cost) = e;
        dp[to][len] = min(dp[to][len], dp[from][len-1] + cost);
    }

    auto it = min_element(begin(dp[n-1]), end(dp[n-1]));
    if(it - dp[n-1] > n-1)  cout << "inf" << endl;
    else  cout << -(*it) << endl;
}