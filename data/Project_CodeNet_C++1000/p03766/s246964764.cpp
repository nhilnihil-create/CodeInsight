#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <memory>
#include <valarray>

using namespace std;

using ll = long long int;
#define loop(i, N) for (int i = 0; i < N; ++i)
#define scanInt(x) int x; scanf("%d", &x); getchar();
#define scanLLInt(x) ll x; scanf("%lld", &x); getchar();
#define scanVecInt(A, N) vector<int> A(N); loop(i, N){scanf("%d", &(A[i])); getchar();}
#define scanVecLLInt(A, N) vector<ll> A(N); loop(i, N){scanf("%lld", &(A[i])); getchar();}

constexpr int mod = 1000000007;

// modをとった和を返す
inline
int modPlus(int a, int b){return (a + b) % mod;}

// modをとった差を返す
inline
int modMinus(int a, int b){return (mod + a - b) % mod;}

// modをとった積を返す
inline
int modMultiple(int a, int b){return (static_cast<long long>(a) * b) % mod;}

int main()
{
    scanInt(N);
    vector<int> dpsum(N + 1);
    dpsum[0] = 0;
    dpsum[1] = N;
    // printf("%d ", N);
    for (int i = 2; i <= N; ++i){
        dpsum[i] = dpsum[i - 1];
        dpsum[i] = modPlus(dpsum[i], modMinus(dpsum[i - 1], dpsum[i - 2]));
        dpsum[i] = modPlus(dpsum[i], modMultiple(N - 1, N - 1));
        dpsum[i] = modPlus(dpsum[i], min(N - 1, N - 1 - (i - 3)));
        dpsum[i] = modPlus(dpsum[i], dpsum[max(0, i - 3)]);
        // printf("%d ", modMinus(dpsum[i], dpsum[i - 1]));
    } // puts("");
    printf("%d\n", modMinus(dpsum[N], dpsum[N - 1]));
}
