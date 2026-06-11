#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using ll = long long;
using lli = long long int;

std::string s;
ll k, n;
std::vector<ll> vec, vec3;
std::vector<std::pair<ll, ll>> vec2;

int main() {
    std::cin >> s;
    n = s.size();
    ll min_change = 100;
    std::cin >> k;
    vec.assign(n, 0);
    vec3.assign(n, 0);
    for (int i = 0; i < n; i++) {
        ll p;
        if (s[i] == 'a') {
            p = 0;
        }
        else {
            p = ('z'-s[i]) + 1;
        }
        vec[i] = p;
        vec2.push_back(std::make_pair(p, i));
        if (p < min_change) {
            min_change = p;
        }
    }
    if (k < min_change) {
        s[s.size()-1] += k;
        std::cout << s << std::endl;
        return 0;
    }
    for (ll i = 0; i < n; i++) {
        if (k >= vec2[i].first) {
            k -= vec2[i].first;
            s[i] = 'a';
        }
    }
    k %= 26;
    s[s.size()-1] += k;
    std::cout << s << std::endl;
}
