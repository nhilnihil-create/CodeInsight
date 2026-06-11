
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int mid[N];
int arr[N*2];
int n, t;
priority_queue<int, vector<int>, greater<int>> a;
multiset<int> m1;
multiset<int> m2;
ll suma, sumc, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        suma += t;
        a.push(t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        mid[i] = arr[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[n + i];
    }
    sort(arr, arr + n * 2);
    for (int i = 0; i < n; ++i) {
        sumc += arr[i];
        m1.insert(arr[i]);
    }
    for (int i = n; i < n * 2; ++i)
        m2.insert(arr[i]);

    ans = suma - sumc;

    for (int i = 0; i < n; ++i) {
        int num = mid[i];
        int t = a.top();
        if (num > t) {
            suma += num - t;
            a.pop();
            a.push(num);
        }
        auto p1 = m1.find(num);
        if (p1 != m1.end()) {
            m1.erase(p1);
            auto p2 = m2.begin();
            sumc -= num;
            sumc += *p2;
            m1.insert(*p2);
            m2.erase(p2);
        } else {
            m2.erase(m2.find(num));
        }
        ans = max(ans, suma - sumc);
    }

    cout << ans << endl;
    return 0;
}

