#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    ll N,M;
    cin >> N >>M;
    ll ans = 0;
    if((N*2)<M){
        ll sumMC = M-N*2;
        sumMC /= 4;
        ans = sumMC + N;
    } else {
        ans = M/2;
    }
    
    cout << ans << endl;
    return 0;
}
