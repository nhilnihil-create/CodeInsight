#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> a(M), b(M), c(N+1, 0);
    rep(i,M){
        cin >> a[i] >> b[i];
        c[a[i]]++;
        c[b[i]]++;
    }
    rep(i,N+1){
        if(c[i] % 2 == 1){
            cout << "NO" <<endl;
            return 0;
        }
    }
    cout << "YES" << endl;

}
