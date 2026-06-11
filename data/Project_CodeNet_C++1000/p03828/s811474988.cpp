#include <bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1000000007;
int main(void) {
    int N;
    cin >> N;
    int target;
    int64_t ans = 1;
    
    vector<int64_t> prime(N,0);

    for(int i=2;i<=N;i++) {
        bool found = false;
        target = i;
        for(int j=2;j<=target;j++) {
            if((target%j)== 0) {
                found = true;
                prime[j-1]++;
                target = target / j;
                j = 1;
            }
        }
    }

    for(auto p:prime) {
        if(p>0){
            ans = (ans * (p+1)) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}
