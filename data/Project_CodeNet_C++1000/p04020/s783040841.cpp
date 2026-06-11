#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    long long ans = 0;
    for(int i = 0; i< N; i++){
        ans += A[i] / 2;
        if(i < N - 1) {
            if(A[i + 1] > 0){
                ans += A[i] % 2;
                A[i + 1] -= A[i] % 2;
            }
        }
    }
    cout << ans << endl;
}