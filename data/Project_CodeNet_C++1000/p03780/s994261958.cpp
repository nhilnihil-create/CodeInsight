#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
long a[5000];

int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    for(int i=0; i < N; ++i) cin >> a[i];
    sort(a, a + N);

    long s = 0;
    int ans = N;
    for(int i=N-1; i >= 0; --i) {
        if(s + a[i] < K) s += a[i];
        else ans = min(ans, i);
    }

    cout << ans << endl;
    return 0;
}