#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int N, K;
vector<ll> A;

void solve(){
    ll m = 1e16;
    ll height = A[0];
  
    for (int b = 0; b < (1 << N); b++)
    {
        height = A[0];
        ll cost = 0;
        bitset<20> bs(b);
        int cnt = 0;
        vector<int> v;

        if(__builtin_popcount(b) < K) continue;

      
        for (int i = 1; i < N; i++){
            if(bs.test(i)){
                cost += max(height - A[i] + 1, (ll)0);
                height = max(height + 1, A[i]);
                
            }
            else{
                height = max(height, A[i]);
            }

            
        }
        m = min(m, cost);
    }
    
    cout << m << endl;
}


int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    
    solve();

    return 0;

}