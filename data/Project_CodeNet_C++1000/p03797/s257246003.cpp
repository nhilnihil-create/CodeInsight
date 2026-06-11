#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N,M, ans = 0;
    cin >> N >> M;
    if(M >= 2*N){
        ans += N;
        M -= 2*N;
        ans += M/4;
    }
    else{
        ans = M/2;
    }
    cout << ans << endl;
    return 0;
}