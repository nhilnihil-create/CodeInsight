#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  
    return true;
  }
  return false;
}
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll N,K;
    ll mincost = INF;
    cin >>N>>K;
    vector<ll> a(N);
    vector<ll> b(N);
    rep(i,N){
        cin >> a[i];
    }
    b = a;
    rep(bit,1<<N){
        vector<ll> S;
        vector<ll> T;
        rep(i,N){
            if(bit&(1<<i)){
                S.pb(1);
                T.pb(i);
            }else{
                S.pb(0);
            }
        }
        ll mx = 0;
        ll cost = 0;
        
        if(T.size() >= K){
            rep(i,N){
                if(S[i] == 1){
                    if(a[i] > mx){
                        mx = a[i];
                    }else{
                        cost +=  mx +1-a[i];
                        mx ++;
                    }
                }else{
                    chmax(mx,a[i]);
                }
                
            }
            chmin(mincost,cost);
        }

    }
    cout << mincost << endl;
    
    
    return 0;
    

}