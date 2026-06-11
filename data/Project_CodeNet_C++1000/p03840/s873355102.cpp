#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tpl = tuple<int,int,int>;

ll A[7];
ll back[7];

int main(){
    
    for(int i = 0; i < 7; i++){
        cin >> A[i];
        back[i] = A[i];
    }

    ll ans = 0;
    {
        ll cand = 0;
        cand += A[0] / 2 * 2;
        cand += A[1];
        cand += A[3] / 2 * 2;
        cand += A[4] / 2 * 2;
        ans = max(ans, cand);
    }
    {
        ll cand = 0;
        if(A[0] > 0 && A[3] > 0 && A[4] > 0){
            A[0]--;
            A[3]--;
            A[4]--;
            cand+=3;
        }
        cand += A[0] / 2 * 2;
        cand += A[1];
        cand += A[3] / 2 * 2;
        cand += A[4] / 2 * 2;
        ans = max(ans, cand);
    }
    cout << ans << endl;

    return 0;
}
