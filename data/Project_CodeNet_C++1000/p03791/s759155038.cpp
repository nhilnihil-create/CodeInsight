#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int mod = 1000000007;

inline int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());


    int next_coor = 1;
    int res = 1;
    int num_elements = 0;
    int departed = 0;
    for (int i = 0, j; i < N; i = j) {
        // Find the interval.
        for (j = i+1; j < N; ++j) {
           if (a[j] != next_coor + j-i) {
               break;
           }
        }
    
        for (int k = 0; k < (j - i)/2; ++k) {
            num_elements += 2;
            res = mul(res, num_elements - departed);
            ++departed;
        }
        num_elements += (j - i) % 2;

        int candidate = next_coor + j - i + 1;
        if ((j - i) % 2 == 0) {
            --candidate;
        }
        next_coor = candidate;
    }
    while (departed < num_elements) {
        res = mul(res, num_elements - departed);
        ++departed;
    }
    cout << res << endl;

    return 0;
}
