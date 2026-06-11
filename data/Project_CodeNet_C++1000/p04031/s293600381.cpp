#include <bits/stdc++.h>

using namespace std;

long get_cost(int n, vector<int>& v) {
    long ret = 0;
    for (auto i : v) {
        ret += (n - i) * (n - i);
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int min = *min_element(v.begin(), v.end());
    int max = *max_element(v.begin(), v.end());

    long min_cost = INT_MAX;

    for (int j = min; j <= max; ++j) {
        long new_cost = get_cost(j, v);
        if (new_cost < min_cost) {
            min_cost = new_cost;
        }
    }

    cout << min_cost << endl;

    return 0;
}