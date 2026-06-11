#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
    int N;cin>>N;
    ll A[N],B[N];
    for (int i = 0; i < N; i++) {
        cin>>A[i]>>B[i];
    }
    ll result = 0;
    ll sum = 0;
    for (int i = N-1; i>=0 ; i--) {
        ll tmp = A[i] + sum;
        if (tmp % B[i] > 0) {
            result += (tmp / B[i] + 1) * B[i] - tmp;
            sum += (tmp / B[i] + 1) * B[i] - tmp;
        }
    }
    cout << result << endl;
    return 0;
}