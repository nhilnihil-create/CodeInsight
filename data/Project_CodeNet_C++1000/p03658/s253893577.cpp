#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int l[60];
    for(int i = 0; i < N; i++) {
        cin >> l[i];
    }
    sort(l,l+N);
    reverse(l, l+N);
    int sum = 0;
    for(int i = 0; i < K; i++) {
        sum += l[i];
    }
    cout << sum << endl;
}