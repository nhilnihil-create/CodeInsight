#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    uint N, M;
    cin >> N >> M;
    vector<int> towns(N+1);

    for (size_t i=0; i<M; ++i) {
        uint a, b;
        cin >> a >> b;
        towns[a]++;
        towns[b]++;
    }

    for (size_t i=1; i<towns.size(); ++i) {
        cout << towns[i] << endl;
    }
}
