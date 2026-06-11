#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> length(N);
    int total_length = 0;

    for(int i=0; i<N; i++) cin >> length[i];
    sort(length.begin(), length.end());
    reverse(length.begin(), length.end());
    for(int i=0; i<K; i++) total_length += length[i];
    cout << total_length << endl;
}