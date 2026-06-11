#include<bits/stdc++.h>
using namespace std;

// A*B = Nを満たしながら動くとき、A、Bの内、桁数が大きい物の最小値を求めよ。

long long int_len(long long N){
    // int型の桁数を返す関数
    string S = to_string(N);
    return S.size();
}

int main(){
    long long N;
    cin >> N;
    long long i = 1;
    long long ans = 10000;
    while (pow(i,2) <= N){
        // A,B対称なのでO(sqrt(N))の計算
        long long j = N / i;
        long long tmp;
        if (i*j == N){
            tmp = max(int_len(i), int_len(j));
        }
        ans = min(ans, tmp);
        i += 1;
    }
    cout << ans << endl;
}