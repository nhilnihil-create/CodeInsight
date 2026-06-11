#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    uint N;
    cin >> N;
    vector<int> freq(1000000+1, 0);

    for (size_t i=0; i<N; ++i) {
        uint bin;
        cin >> bin;
        ++bin;  // add offset. -1->0, 0->1, 1->2...
        ++freq[bin-1];
        ++freq[bin];
        ++freq[bin+1];
    }
    auto maxIter = max_element(freq.begin(), freq.end());
    cout << *maxIter << endl;
    // size_t d = distance(freq.begin(), maxIter);
    // cout << ans << endl;
}
