#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    
    ll N;
    cin >> N;
    vector<ll> V(N);
    ll sum = 0, k;
    rep(i,0,N){
        cin >> V[i];
        sum += V[i];
    }
    if(sum % (N * (N+1) / 2)){
        cout << "NO" << endl;
        return 0;
    }
    k = sum / (N * (N+1) / 2);
    ll cnt = 0;
    rep(i,0,N){
        ll dif = V[(i+1)%N] - V[i];
        //cout << dif << " ";
        if((k - dif) % N || k < dif){
            cout << "NO" << endl;
            return 0;
        }
        cnt += (k - dif) / N;
    }
    //cout << endl;
    //cout << k << " " << cnt << endl;
    if(k != cnt)cout << "NO" << endl;
    else cout << "YES" << endl;
    
    /*
    int N,K;
    cin >> N >> K;
    vector<int> V(N);
    rep(i,0,K){
        int t;
        cin >> t;
        rep(j,0,N){
            V[(j+t) % N] += j + 1;
        }
    }
    rep(i,0,N)cout << V[i] << " \n"[i==N-1];
    */
}