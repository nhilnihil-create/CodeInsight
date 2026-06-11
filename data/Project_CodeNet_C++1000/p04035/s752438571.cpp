#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; long long L; cin >> N >> L;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    int pl = -1;
    for (int i = 0; i+1 < N; ++i) if (A[i] + A[i+1] >= L) pl = i;

    if (pl == -1) { cout << "Impossible" << endl; return 0; }

    cout << "Possible" << endl;
    for (int i = 0; i < pl; ++i) cout << i+1 << endl;
    for (int i = N-2; i > pl; --i) cout << i+1 << endl;
    cout << pl+1 << endl;
}