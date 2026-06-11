#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<long long int>height(N);
    long long int max_height=0, answer=INT64_MAX, cost=0;
    int num = 1;
    for (int i = 0; i < N; i++)cin >> height.at(i);
    for (int bit = 0; bit < (1 << N); bit++) {
        max_height = height.at(0), cost = 0,num=1;
        for (int i = 1; i < N; i++) {
            if (bit & (1 << i)) {
                num++;
                if (max_height >= height.at(i)) {
                    cost += max_height - height.at(i) + 1;
                    max_height++;
                }
            }

            if (max_height < height.at(i))max_height = height.at(i);
        }
        if (num >= K && cost <= answer)answer = cost;
    }
    cout << answer << endl;
     return 0;
}