#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long N,M;
    cin >> N >> M;
    long long S = 0;
    if(N*2 <= M){
        long long L = M - N*2;
        S += N + L / 4;
    }
    else{
        S += M / 2;
    }
    cout << S << endl;
}
