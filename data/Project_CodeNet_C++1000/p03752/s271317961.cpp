#include <bits/stdc++.h>

using namespace std;

int num_flag(int x) {
    int count = 0;
    for(int i = 0; i < sizeof(int)*8; i++) {
        if(x & (1 << i)) count++;
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    int heights[n];
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    long long min_cost = 1000000000000;
    for(int i = 0; i < (1 << (n-1)); i++) {
        int bit_count = num_flag(i);
        if(bit_count != (k-1)) continue;
        long long cost = 0;
        int cur_height = heights[0];
        for(int b = 1; b < n; b++) {
            if(i & (1 << (b-1))) {
                if(cur_height >= heights[b]) {
                    cost += cur_height + 1 - heights[b];
                    cur_height++;
                }else {
                    cur_height = heights[b];
                }
            }else {
                cur_height = max(cur_height, heights[b]);
            }
        }
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;
}