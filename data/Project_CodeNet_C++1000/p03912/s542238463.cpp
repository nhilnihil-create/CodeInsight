#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N, M; cin >> N >> M;
    int A[N]; rep(i, N) cin >> A[i];
    // Mが偶数の時,mod MがM/2なら,好きに組ませていい mod Mが0の時も同様(Mは奇数でもいい) cnt[M]/2 + cnt[0]/2
    // それ以外はmod Kとmod M-Kの個数を考える 同じ数字はなるべく残すようにするのが最適
    sort(A, A+N);
    int mod_cnt[M] = {};
    int same_card[M] = {};

    rep(i, N){
        if(i == N-1) mod_cnt[A[i] % M]++;
        else if(A[i] == A[i+1]){
            mod_cnt[A[i] % M] += 2;
            same_card[A[i] % M]++;
            i++;
        }
        else{
            mod_cnt[A[i] % M]++;
        }
    }
    int ans = 0;
    if(M % 2 == 0) ans += mod_cnt[M/2]/2;
    ans += mod_cnt[0]/2;
    int loop = M/2;

    //cout << "before loop: " << ans << endl;

    for(int i = 1; i <= loop; i++){
        int a = i, b = M-i;
        if(a == b) break;
        //cout << i << ": " << mod_cnt[a] << ", " << mod_cnt[b] << endl;

        int add = min(mod_cnt[a], mod_cnt[b]);
        ans += add;

        int is_larger;
        if(add == mod_cnt[a]) is_larger = b;
        else is_larger = a;
        int rem = mod_cnt[is_larger] - add;
        ans += min(rem/2, same_card[is_larger]);
    }
    cout << ans << endl;

    return 0;
}