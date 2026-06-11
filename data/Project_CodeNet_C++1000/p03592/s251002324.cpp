#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 0; i <= M; ++i){
        int sum = i*N;
        for(int j = 0; j <= N; ++j){
            sum = i*N - i*j + j*(M-i);
            if(sum == K){
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}