#include <iostream>
#include <vector>

using namespace std;

const long long INFTY = 1e20;

int main(){
    int N; cin >> N;
    vector<long long> A(N);
    long long sum = 0ll;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
    }

    long long x, y, ans;
    x = A[0];
    y = sum - x;
    ans = abs(x-y);
    for(int i=1;i<N-1;i++){
        x += A[i];
        y = sum - x;
        ans = min(ans, abs(x-y));
    }
    cout << ans << endl;

    return 0;
}