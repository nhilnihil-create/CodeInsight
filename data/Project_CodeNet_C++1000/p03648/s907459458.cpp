#include <iostream>
using namespace std;
long long  K, rec[60], ans[60];
const long long  N = 50;
int main() {
    cin >> K;
    long long  div = K / N, mo = K % N;
    for (long long  i=0;i<N;i++)
        rec[i] = div + (i < mo);
    for (long long  i=0;i<N;i++) {
        long long  sum = 0;
        for (long long  j=0;j<N;j++)
            if(i != j)
                sum += rec[j];
        ans[i] = N * (rec[i] + 1) - sum - 1;
    }
    cout << N << endl;
    for (long long  i=0;i<N;i++) cout << (i ? " " : "") << ans[i];
    cout << endl;
    return 0;
}
