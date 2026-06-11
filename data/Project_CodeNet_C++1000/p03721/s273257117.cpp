#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n + 1); i++)
// vector<vector<int>> A(3, vector<int>(4));
int main() {
  	ll N,K;
    cin>>N>>K;
    vector<pair<ll,ll>>A(N);
    rep(i,N){
        cin>>A[i].first;
        cin>>A[i].second;
    }
    sort(A.begin(),A.end());
    rep(i,N){
        K-=A[i].second;
        if(K<=0){
            cout<<A[i].first<<endl;
          	i+=K;
          	break;
        }
    }
}
