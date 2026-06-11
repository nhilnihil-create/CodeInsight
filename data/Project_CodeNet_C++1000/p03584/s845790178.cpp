#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int N, K;
    long ans = 0;
    int A[100000];
    int B[100000];
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    for(int i = 0; i < N; i++){
        if((K|A[i]) <= K) ans += B[i];
    }
    int n = 1;
    for(int i = 0; i <= 30; i++){
        if(K & n){
            int m = n-1;
            int K_ = K^n;
            K_ = K_ | m;
            //std::cout << std::bitset<8>(n) << endl;
            //std::cout << std::bitset<8>(K_) << endl;
            long tmp = 0;
            for(int i = 0; i < N; i++){
                if((K_|A[i]) <= K_) tmp += B[i];
            }
            ans = max(ans, tmp);
        }
        n = n << 1;
    }
    cout << ans << endl;
}