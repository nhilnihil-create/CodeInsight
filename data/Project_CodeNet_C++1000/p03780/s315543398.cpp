#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

long long a[5000];
bool dp[5000][10001];
bool is_needed(int ind, int K, int N){
    //cout << ind << endl;
    if(K <= a[ind]){
        return true;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++){
            dp[i][j] = false;
        }
    }
    if(ind != 0){
        dp[0][0] = true;
        dp[0][a[0]] = true;
    } else {
        dp[1][0] = true;
        dp[1][a[1]] = true;
    }
    for(int i = 1; i < N; i++){
        if(i == ind){
            for(int j = 0; j <= K; j++){
                dp[i][j] = dp[i - 1][j];
            }
            continue;
        }
        for(int j = 0; j <= K; j++){
            dp[i][j] |= dp[i - 1][j];
            if(j + a[i] < K){
                dp[i][j + a[i]] |= dp[i - 1][j];
            } else {
                dp[i][K] |= dp[i - 1][j];
            }
        }
    }
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    for(int i = K - a[ind]; i < K; i++){
        if(dp[N - 1][i]){
            return true;
        }
    }
    return false;
}

int main(){ 
    int N;
    int K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    sort(a, a + N);
    if(!is_needed(N - 1, K, N)){
        cout << N << endl;
        return 0;
    }
    if(is_needed(0, K, N)){
        cout << 0 << endl;
        return 0;
    }
    
    int left = 0;
    int right = N - 1;
    while(left + 1 < right){
        int mid = (left + right) / 2;
        //cout << mid << " " << is_needed(mid, K, N) << endl;
        if(is_needed(mid, K, N)){
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
    return 0;
}
