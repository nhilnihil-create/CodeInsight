// Special thanks to RCC.
#include <iostream>
#include <climits>
#include <queue>

template<typename T>
using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;

template<typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using lli = long long int;

int main() {
//    freopen("input.txt", "r", stdin);

    int N;
    lli res = LLONG_MIN;
    scanf("%d", &N);

    int a[3 * N];
    for (int I = 0; I < 3 * N; I++)
        scanf("%d", &a[I]);

    min_heap<int> min_pq;
    max_heap<int> max_pq;
    lli sum_left[N + 1], sum_right[N + 1];

    lli sum = 0;
    for (int I = 0; I < N; I++) {
        min_pq.push(a[I]);
        sum += a[I];
    }
    sum_left[0] = sum;
    // Calculate max sums for the reds cutting at the position K
    for (int I = 0 ; I < N; I++) {
        if (a[I + N] > min_pq.top()){
            sum -= min_pq.top();
            min_pq.pop();
            min_pq.push(a[I+N]);
            sum += a[I+N];
        }
        sum_left[I+1] = sum;
    }

    sum = 0;
    for (int I = (3 * N) - 1; I >= 2 * N; I--){
        max_pq.push(a[I]);
        sum += a[I];
    }
    sum_right[N] = sum;
    for (int I = N-1 ; I >= 0; I--) {
        if(a[I + N] < max_pq.top()){
            sum -= max_pq.top();
            max_pq.pop();
            sum += a[I+N];
            max_pq.push(a[I+N]);
        }
        sum_right[I] =  sum;
    }

    for (int I = 0; I <= N; I++) {
        res = std::max(res, sum_left[I] - sum_right[I]);
    }
    std::cout << res << "\n";

    return 0;
}