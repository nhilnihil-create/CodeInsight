#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void){
    ll N,M;cin>>N>>M;
    ll S_TOTAL = min(M / 2, N);
    M = M - 2 * S_TOTAL;
    ll M_TOTAL = M / 4;
    cout << S_TOTAL + M_TOTAL << endl;
    return 0;
}