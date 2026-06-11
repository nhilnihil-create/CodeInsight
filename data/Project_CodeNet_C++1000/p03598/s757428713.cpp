#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int xs[N];
    for (int i=0; i<N; i++) cin >> xs[i];
    int sum_of_distance = 0;
    for (int x : xs){
        sum_of_distance += 2 * min(x, abs(x-K));
    }
    cout << sum_of_distance << endl;
}
