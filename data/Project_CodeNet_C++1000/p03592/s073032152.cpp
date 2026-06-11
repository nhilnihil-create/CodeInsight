#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;



int main(){
    int N, M, K; cin >> N >> M >> K;
    if(K % N == 0 || K % M == 0){
        cout << "Yes" << endl;
        return 0;
    }

    for(int i = 0; i <= N; i++){
        for(int j = 0; j < M; j++){
            ll tmp = N*M - N*j - M * i + 2*i*j;
            if(tmp == K){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

}