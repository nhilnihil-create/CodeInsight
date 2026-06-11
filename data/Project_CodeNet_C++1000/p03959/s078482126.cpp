#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll N;
    cin >> N;
    ll T[N];
    ll A[N];
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    bool isDecided[N];
    ll maxHeight[N];
    for (int i = 0; i < N; ++i) {
        isDecided[i] = false;
        maxHeight[i] = -1;
    }
    isDecided[0] = true;
    maxHeight[0] = T[0];
    for (int i = 1; i < N; ++i) {
        if(T[i-1] != T[i]){
            isDecided[i] = true;
        }
        maxHeight[i] = T[i];
    }

    if(isDecided[N - 1]){
        if(maxHeight[N - 1] != A[N - 1]){
            cout << 0 << endl;
            return 0;
        }
    }
    isDecided[N - 1] = true;
    if(maxHeight[N - 1] < A[N - 1]){
        cout << 0 << endl;
        return 0;
    }
    maxHeight[N - 1] = A[N - 1];
    for (int i = 1; i < N; ++i) {
        if(A[N - i] != A[N - i - 1]){
            isDecided[N - i - 1] = true;
            if(maxHeight[N - i -1] < A[N - i - 1]){
                cout << 0 << endl;
                return 0;
            }
            maxHeight[N - i - 1] = A[N - i - 1];
        }else{
            maxHeight[N - i - 1] = min(maxHeight[N - i - 1],A[N - i - 1]);
        }

    }
    ll count = 1;
    ll MOD = 1000000007;
    for (int i = 0; i < N; ++i) {
        if(isDecided[i]){
            continue;
        }
        count = (count * maxHeight[i]) % MOD;
    }
    cout << count << endl;
}
