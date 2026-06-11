#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int main(){
    int N, X[100000];
    cin >> N;
    for(int i=0; i<N; i++) cin >> X[i];

    vector<int> num(100000, 0);
    int lim = 0;
    for(int i=0; i<N; i++){
        num[lim]++;
        lim = max(lim, i+1 - (X[i]+1)/2);
    }

    int sum = 0;
    int64_t ans = 1;
    for(int i=0; i<N; i++){
        sum += num[i];
        mul(ans, sum);
        sum--;
    }
    cout << ans << endl;
    return 0;
}