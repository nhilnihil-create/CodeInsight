#include <bits/stdc++.h>
using namespace std;
int main(){
    long long i, j, k;
    long long N, K;
    cin >> N >> K;
    vector<long long> as(N), bs(N);
    for(i=0; i<N; i++) cin >> as[i] >> bs[i];
    long long ans = 0;
    for(i=-1; i<=30; i++){
        if(i>=0 && ((K>>i) & 1) == 0) continue;
        long long sum = 0;
        for(j=0; j<N; j++){
            if(i>=0 && ((as[j]>>i) & 1) == 1) continue;
            bool result = true;
            for(k=i+1; k<=30; k++){
                if(((as[j]>>k) & 1) > ((K>>k) & 1)){
                    result = false;
                    break;
                }
            }
            if(result) sum += bs[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}