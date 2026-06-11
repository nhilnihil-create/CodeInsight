#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    vector<ll> X(N);
    rep(i,N){
        cin >> X[i];
    }
    ll cost = 0;
    rep(i,N-1){
        ll dist = X[i+1]-X[i];
        cost += min(dist*A,B);
    }
    cout << cost << endl;
}
