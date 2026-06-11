#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
    }

    ll M = 1;
    ll ans = 0;
    REP(i,N){
        ll a = A[i];
        if(i == 0){
            ans += a - 1;
            a = 1;
            M = 2;
        }
        else{
            if(a <= M) {
                chmax(M, a+1);
                continue;
            }

            ll k = 0;
            if(a % M != 0){
                k = a/M;
                a -= M*k;
            }
            else{
                while(a % M == 0){
                    k++;
                    a -= (M+1);
                }
                k += a/M;
                a -= M*a/M;
            }
            chmax(M, a+1);
            ans += k;
        }
    }

    cout << ans << endl;
    return 0;
}
