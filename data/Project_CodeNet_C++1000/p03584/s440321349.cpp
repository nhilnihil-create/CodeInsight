#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    while(cin >> N >> K){
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++) cin >> A[i] >> B[i];
        long long res = 0;
        for(int i=0;i<N;i++){
            if((K&A[i]) == A[i]) res += B[i];
        }
        while(K){
            int curK = K;
            --K;
            long long sum = 0;
            for(int i=0;i<N;i++){
                if((K&A[i]) == A[i]) sum += B[i];
            }
            res = max(res, sum);
            K &= curK;
        }
        cout << res << endl;
    }
}