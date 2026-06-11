#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int K = S.size();
    ll mod = 1e9+7;
    
    vector<ll> from1(K+5, 0), from2(5, 0);
    from1[K] = 1;
    from2[0] = 1;
    
    for (int z = 0; z < N; z++) {
        vector<ll> to1(z+K+5, 0), to2(min(z+5, N/2+5), 0);
        from1[0] %= mod;
        to1[1] += from1[0] * 3;
        for (int i = 1; i <= z+K; i++) {
            from1[i] %= mod;
            if (i != K) {
                to1[i-1] += from1[i];
                to1[i+1] += from1[i]*2;
            }else {
                to1[i-1] += from1[i];
                to1[i+1] += from2[0] + (from1[i]+mod-from2[0])%mod*2;
                to1[i] += from2[0];
            }
        }
        
        to2[0] = (from2[0]+from2[1])%mod;
        for (int i = 1; i <= min(z+2, N/2+3); i++) {
            to2[i] += (from2[i+1] + from2[i-1]*2)%mod;
        }
        
        swap(from1, to1);
        swap(from2, to2);
    }
    
    cout << from1[0]%mod << endl;
    
    return 0;
}