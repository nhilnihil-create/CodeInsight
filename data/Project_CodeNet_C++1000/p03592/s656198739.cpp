#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;



int main(){
    ll N, M; cin >> N >> M;
    ll K; cin >> K;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            ll tag =  i*M + j*N - 2*(i*j);
            if(tag == K){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    
    cout << "No" << endl;
}