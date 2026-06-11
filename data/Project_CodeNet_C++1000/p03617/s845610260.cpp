#include <iostream>
#include <algorithm>
using namespace std;

long long int Q,H,S,D,N;
long long int raito[4];

int main(){
    cin >> Q >> H >> S >> D >> N;
    long long ans = 0;

    if(Q * 2 < H){
        H = Q * 2;
    } 
    if(H * 2 < S){
        S = H * 2;
    }
    if(S * 2 < D){
        D = S * 2;
    }

    ans += (N / 2) * D;
    N -= 2 * (N / 2);
    ans += (N / 1) * S;

    cout << ans << endl;
}