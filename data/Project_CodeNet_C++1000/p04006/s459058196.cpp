#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)


int main()
{
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    REP(i, N) cin >> a[i];

    long long ans = accumulate(a.begin(), a.end(), (long long) 0);
    // 何回魔法を唱えるかを全探索
    for(int i = 1; i < N; ++i){
        long long time = (long long) x * i;
        int tmp = a[N-1];
        for(int j = N-1; j >= 0; --j){
            a[j] = min(a[j], j == 0? tmp: a[j-1]);
            time += a[j];
        }
        ans = min(ans, time);
    }
    cout << ans << endl;

    return 0;
}