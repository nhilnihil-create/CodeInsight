#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];

    int min_cost = 100000000;
    sort(a.begin(), a.end());
    int min_a = a[0];
    int max_a = a[N-1];

    for(int i = min_a; i <= max_a; i++) {
        int cost = 0;
        for(int j=0; j<N; j++) {
            cost += pow(a[j]-i, 2);
        }
        min_cost = min(min_cost, cost);
    }
    cout << min_cost << endl;
}