#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>

using namespace std;

int main(){

    int N, T;
    cin >> N >> T;

    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int maxValue = A[N - 1];
    int maxDiff = 0;
    for(int i = N - 2; i >= 0; i--){
        int diff = maxValue - A[i];
        maxDiff = max(maxDiff, diff);
        maxValue = max(maxValue, A[i]);
    }

    int ans = 0;
    maxValue = A[N - 1];
    for(int i = N - 2; i >= 0; i--){
        int diff = maxValue - A[i];
        if(diff == maxDiff){
            ans++;
        }
        maxValue = max(maxValue, A[i]);
    }

    cout << ans << endl;

    return 0;
}