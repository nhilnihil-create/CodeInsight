#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

int main() {
    scanf("%lld", &n), n++;
    deque<ll> V;
    function<void(ll)> solve = [&](ll n) {
        if (n == 1) return;
        if (n & 1) solve(n - 1), V.push_front(V.size() + 1);
        else solve(n >> 1), V.push_back(V.size() + 1);
    };
    solve(n);
    for (int i = 1, j = V.size(); i <= j; i++) V.push_back(i);
    printf("%d\n", V.size());
    for (ll x : V) printf("%lld ", x);
    return 0;
}