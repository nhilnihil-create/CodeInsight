#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; long long K;
    cin >> N >> K;
    vector<pair<long long, long long> > v(N);
    for (int i = 0; i < N; ++i) cin >> v[i].first >> v[i].second;

    // ソート
    sort(v.begin(), v.end());
    
    // a_i が小さい順に b_i を合計して K 以上になる瞬間をとらえる
    long long res = 0;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += v[i].second;
        if (sum >= K) {
            res = v[i].first; // sum >= K になった瞬間の a_i
            break;
        }
    }
    cout << res << endl;
}