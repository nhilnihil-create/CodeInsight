#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int arr[105];

ll ways(int N, int P, int even, int odd) {
    if(even == N) {
        if(P == 0) return pow(2, N);
        else if(P == 1) return 0;
    }
    return pow(2, N-1);     // at least 1 odd
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, P, odd, even;
    cin >> N >> P;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        if(arr[i]%2 == 0) even++;
    }
    odd = N-even;
    
    cout << ways(N, P, even, odd) << endl;
}