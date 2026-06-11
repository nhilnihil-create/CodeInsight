#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    bool plus = true;
    bool minus = true;
    ll ans = 1;
    rep(i,N - 1){
        if (A[i + 1] > A[i]){
            if (!plus){
                plus = true;
                minus = true;
                ans++;
            }
            else{
                minus = false;
            }
        }
        else if (A[i + 1] < A[i]){
            if (!minus){
                plus = true;
                minus = true;
                ans++;
            }
            else{
                plus = false;
            }
        }
    }
    cout << ans << endl;
}
