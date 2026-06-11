#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N + 1);
    for (int i = 0; i < N; ++i) cin >> p[i];
    
    vector<int> a(N + 1), b(N + 1);
    for (int i = 0; i < N; ++i) a[i + 1] = (i + 1) * N;
    for (int i = 0; i < N; ++i) b[i + 1] = N * N + 1 - a[i + 1];
    for (int i = 0; i < N; ++i) a[p[i]] += i;
    
    for (int i = 1; i < N; ++i) cout << a[i] + 1 << " ";
    cout << a[N] + 1 << endl;
    for (int i = 1; i < N; ++i) cout << b[i] + 1 << " ";
    cout << b[N] + 1 << endl;
    return 0;
}
