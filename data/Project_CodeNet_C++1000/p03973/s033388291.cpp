#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
        int N;
        int A[100005];
        ll sum = 0, d = 2;
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> A[i];
                if (i == 0) sum += A[i] - 1;
                else if (d == A[i]) d++;
                else sum += (A[i] - 1) / d;
        }
        cout << sum << endl;
        return (0);
}
