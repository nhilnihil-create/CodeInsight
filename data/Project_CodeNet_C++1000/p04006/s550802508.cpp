#include <iostream>
#include <vector>
using namespace std;
long long MAX = 1e18;
int main(){
    long long N, x;
    cin >> N >> x;
    vector<long long> a(N), b(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    long long ans = MAX;
    for(long long i = 0; i < N; i++){
        long long temp = 0;
        temp += i * x;
        for(int j = 0; j < N; j++){
            b[j] = min(b[j], a[(N + j - i) % N]);
            temp += b[j];
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
}