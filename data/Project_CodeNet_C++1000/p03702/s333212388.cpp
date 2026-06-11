#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;


int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> hs(N, 0);
    rep(i, N){
        cin >> hs[i];
    }
    int l = 0;
    int r = 1e9;
    int ans = 1;
    while(l <= r){
        ll t = 0;
        int mid = (l + r) / 2;
        double de = A - B;
        rep(i, N){
            // midの必要性を検証.
            double tmp = hs[i] - 1.0 * B * mid;
            if(tmp > 0){
                t += ceil((double)(tmp) / (de));
            }
        }
        if(t > mid){
            // mdではng
            l = mid + 1;
        }else{
            // mdでもok.
            r = mid - 1;
            ans = mid;
        }
    }

    cout  << ans << endl;

    return 0;
}
