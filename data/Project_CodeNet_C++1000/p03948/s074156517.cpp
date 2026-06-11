#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    int N;
    ll T, A;
    cin >> N >> T;
    vector<ll> sell(N);
    sell[0] = 0;

    cin >> A;

    ll A_min, max_sell;
    max_sell = 0ll;
    A_min = A;
    for(int i=1;i<N;i++){
        cin >> A;
        A_min = min(A_min, A);
        max_sell = max(max_sell, A-A_min);
        sell[i] = A - A_min;
    }

    int ans = 0;
    for(int i=0;i<N;i++){
        if(sell[i] == max_sell) ans++;
    }

    cout << ans << endl;

    return 0;
}