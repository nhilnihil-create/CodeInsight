#include <iostream>
using namespace std;
const long long mod = 1e9+7;
int main(void){
    long long N;
    cin >> N;
    long long ans = 1;
    for(long long i=1;i<=N;i++){
        ans = (ans * i) % mod;
    }
    cout << ans << endl;
}
