#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

int main() {
    int N, K;
    vector<int> x;
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        x.push_back(temp);
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int sub = K - x[i];
        if (sub > x[i]) {
            sum += 2 * x[i];
        } else {
            sum += 2 * sub;
        }
    }
    cout << sum << endl;
    return 0;
}
