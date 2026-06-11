#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> answer;
    int sum = 0;
    for (int p = 1; p <= N; p++) {
        if (sum + p > N) break;
        sum += p;
        answer.push_back(p);
    }
    int diff = N - sum,
        m = answer.size();
    int idx = m - 1;
    while (diff > 0) {
        answer[idx]++;
        diff--;
        idx = (idx - 1 + m) % m;
    }
    for (int a : answer) {
        cout << a << endl;
    }

    return 0;
}
