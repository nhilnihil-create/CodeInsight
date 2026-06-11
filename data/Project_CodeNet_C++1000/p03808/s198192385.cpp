#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;
    vector<ll> A(N),D(N);
    ll sum = 0;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    ll b = (N+1)*N/2;
    if(sum % b != 0 ){
        cout << "NO" << endl;
        return 0;
    }
    ll k = sum / b;
    rep(i,N){
        D[i] = A[(i+1)%N] - A[i] - k;
    }
    ll cnt = 0;
    rep(i,N){
        if(D[i]% N !=0 || D[i]>0){
            cout << "NO" << endl;
            return 0;
        }else cnt += -D[i]/N;
    }
    if(cnt==k)cout << "YES" << endl;
    else cout << "NO" << endl;
}
