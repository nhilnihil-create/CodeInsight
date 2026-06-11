#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);


typedef long long ll;
typedef long double ld;
const ll SIZE = 1e6;
ll q;
vector<ll> vec;
vector<pair<ll, ll>> st;
ll pos[SIZE], ans[SIZE], lft[SIZE];

int main() {
    fastInp;

    ll n;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        vec[i]--;
        pos[vec[i]] = (i + 1);
        lft[i] = n;
        st.push_back({ vec[i], i });
    }

    sort(st.begin(), st.end());

    queue<ll> emp;
    for (int i = 0; i < n * n; i++) {
        if (!pos[i]) {
            emp.push(i);
        }
        else {
            if (emp.size() < pos[i] - 1) {
                cout << "No";
                return 0;
            }
            ans[i] = pos[i];
            lft[pos[i] - 1]--;
            for (int j = 0; j < pos[i] - 1; j++) {
                ll q = emp.front();
                emp.pop();
                ans[q] = pos[i];
                lft[pos[i] - 1]--;
            }
        }
    }

    for (int i = 0; i < n * n; i++) {
        if (ans[i] == 0) {
            for (int k = 0; k < n; k++) {
                if (lft[st[k].second] > 0) {
                    ans[i] = st[k].second + 1;
                    lft[st[k].second]--;
                    k = n;
                }
            }
            continue;
        }
    }

    for (int i = 0; i < n; i++) {
        ll s = 0;
        for (int j = 0; j < vec[i]; j++) {
            s += (ans[j] == (i + 1));
        }
        if (s != i) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n * n; i++) cout << ans[i] << " ";
    return 0;
}