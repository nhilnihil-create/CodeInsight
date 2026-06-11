#include <iostream>
#include <sstream>  // istringstream
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

// qiita
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{   
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; ++i) cin >> A[i];

    // 余りをとる問題
    // 計算途中で余りをとっても変わらない

    // 記録
    int memo[100000+10] = {0};
    for(int i=0; i<N; ++i){
        memo[A[i]]++;
    }

    bool flag = true;
    if(N%2 != 0){ // 奇数人の場合
        if(memo[0] != 1){ // 0が必ず一人いる
            flag = false;
        }
        for(int i=2; i<N; i+=2){
            if(memo[i] != 2){ // 各偶数が2人ずつ
                flag = false;
            }
        }
    }
    else{ // 偶数人の場合
        for(int i=1; i<N/2; i+=2){
            if(memo[i] != 2){ // 各奇数が2人ずつ
                flag = false;
            }
        }
    }

    long long ans = modpow(2, N/2, 1000000000+7);
    if(!flag) ans = 0;

    cout << ans << endl;

    return 0;
}