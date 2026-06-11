#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> A(N);
    ll gnum=1;
    rep(i,N){
        cin >> A[i];
        if(A[i]==K){
            cout << "POSSIBLE" << endl;
            return 0;
        }
        gnum*=A[i];
    }
    sort(A.rbegin(),A.rend());
    if(K>A[0]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    rep(i,N){
        gnum = __gcd(gnum,A[i]);
    }
    if(K%gnum==0){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}