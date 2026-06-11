#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)


int main()
{
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    REP(i, N) cin >> a[i];

    long long ans = 1e+18;
    // 何回魔法を唱えるかを全探索
    REP(i, N){
        long long time = x * i;
        if(i != 0){
            int tmp = a[N-1];
            for(int j = N-1; j >= 0; --j){
                a[j] = min(a[j], j == 0? tmp: a[j-1]);
            }
        }
        REP(j, N) time += a[j];
        ans = min(ans, time);
    }
    cout << ans << endl;

    return 0;
}