#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
// #include <cmath>
// #include <string>
// #include <map>
// #include <iomanip>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}

template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << "{";
    for (const auto& i : s) {
        os << i << " ";
    }
    os << "}";
    return os;
}


int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<int> a(N*3);
    for (int i = 0; i < N*3; ++i) {
        cin >> a[i];
    }

    vector<ll> sum1(N+1), sum2(N+1);
    multiset<int> items1, items2;
    for (int i = 0; i < N; ++i) {
        items1.insert(a[i]);
        items2.insert(a[N*3-1-i]);
    }
    sum1[0] = accumulate(items1.begin(), items1.end(), 0LL);
    sum2[0] = accumulate(items2.begin(), items2.end(), 0LL);
    // p(sum1[0], sum2[0]);

    // cout << items1 << endl;
    // cout << items2 << endl;

    for (int i = 0; i < N; ++i) {
        int added1 = a[N+i];
        items1.insert(added1);
        auto iter1 = items1.begin();
        int deleted1 = *iter1;
        items1.erase(iter1);
        sum1[i+1] = sum1[i] + added1 - deleted1;

        int added2 = a[N*2-1-i];
        items2.insert(added2);
        auto iter2 = prev(items2.end());
        int deleted2 = *iter2;
        items2.erase(iter2);
        sum2[i+1] = sum2[i] + added2 - deleted2;

        // p(i);
        // p(items1);
        // p(items2);
    }

    ll ans = sum1[0] - sum2[N];
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, sum1[i] - sum2[N-i]);
    }

    cout << ans << endl;

    return 0;
}
