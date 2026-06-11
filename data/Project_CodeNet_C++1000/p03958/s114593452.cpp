#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

struct node {
    int cake;
    int count;
};

bool v_cmp(const struct node &p, const struct node &q) {
    return p.count > q.count;
}
// sort(v.begin(), v.end(), v_cmp); //large to samll

int main() {
    int K, T;
    cin >> K >> T;
    vector<node> a(T);
    for (int i = 0; i < T; i++) {
        struct node tmp;
        cin >> tmp.count;
        tmp.cake = i + 1;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end(), v_cmp);

    cout << max(a[0].count - (K - a[0].count) - 1, 0) << endl;

    return 0;
}
