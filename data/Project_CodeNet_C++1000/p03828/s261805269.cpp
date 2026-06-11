#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long mod = 1e9+7;
int main(void){
    int N;
    cin >> N;
    int P[1001] = {0};
    long long ans = 1;
    for(int i=2;i<=N;i++){
        int M = i;
        for(int j=2;j*j<=N;j++){
            if(M % j == 0){
                while(M % j == 0){
                    M /= j;
                    P[j]++;
                }
            }
        }
        if(M != 1){
            P[M]++;
        }
    }
    for(int i=2;i <= N;i++){
        if(P[i]){
            ans = (ans * (P[i] + 1)) % mod;
        }
    }
    cout << ans << endl;
}
