#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    string yes = "YES", no = "NO";    
    ll N;
    cin >> N;
    ll A[N], cnt[N], sum = 0, K, n = N*(N+1)/2;
    rep(i, N){
        cin >> A[i];
        sum += A[i];
    }
    if(sum%n != 0){
        cout << no << endl;
        exit(0);
    }
    K = sum/n;
    rep(i, N){
        ll j = (i+1)%N;
        ll s = A[i]-A[j]+K;
        if(s < 0){
            cout << no << endl;
            exit(0);
        }
        elif(s%N != 0){
            cout << no << endl;
            exit(0);
        }
        else cnt[i] = s/N;
    }
    ll S = 0;
    rep(i, N) S += cnt[i];
    if(S == K) cout << yes << endl;
    else cout << no << endl;
}