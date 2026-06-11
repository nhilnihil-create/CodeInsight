#include <iostream>
using namespace std;
const long long mod = 1e9+7;
int main(void){
    long long N,M;
    cin >> N >> M;
    long long ans = 0;
    long long x;
    if(N*2 <= M){
        ans = N + (M - N * 2) / 4;
    }
    else{
        ans = M / 2;
    }
    cout << ans << endl;
}
