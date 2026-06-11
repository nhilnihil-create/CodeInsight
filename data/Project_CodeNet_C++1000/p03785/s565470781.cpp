#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll N, C, K;
    cin >> N >> C >> K;
    vector<ll> T(N);
    rep(i, N) cin >> T[i];
    sort(T.begin(), T.end());
    vector<ll> T_lim(N);
    rep(i, N) T_lim[i] = T[i] + K;

    ll bus_cnt = 0;
    for(int i = 0; i < N; ){
        int p = i;
        i++;
        while(T_lim[p] >= T[i] && i < N && i < p + C){
            i++;
        }
        bus_cnt++;
    }
    cout << bus_cnt << endl;
    return 0;
}