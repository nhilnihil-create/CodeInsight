#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, C, K;
    cin >> N >> C >> K;
    long long ppl[N];
    for (int i=0; i<N; i++) cin >>ppl[i];
    sort(ppl, ppl+N);
    int cap=0, limit=-1, ans=0;
    for (int i=0; i<N; i++){
        if (cap==C || ppl[i]> limit){
            ans++;
            limit=ppl[i]+K;
            cap=0;
        }
        cap++;
    }
    cout << ans << endl;
}
