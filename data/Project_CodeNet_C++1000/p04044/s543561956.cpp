#include <bits/stdc++.h>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/irange.hpp>
#include <boost/algorithm/string/join.hpp>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    int n, l; cin >> n >> l;
    vector<string> s(n);

    for (auto i : boost::irange(0, n)) cin >> s[i];

    sort(s.begin(), s.end());

    string ans = boost::join(s, "");

    cout << ans << endl; 
}