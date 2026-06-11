#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),Sum(N+1);
    rep(i,N) cin >> A[i];
    sort(A.begin(),A.end());
    rep(i,N){
        Sum[i+1] = Sum[i]+A[i];
    }
    int l=0;
    for(int i=1;i<N;i++){
        if(Sum[i]*2<A[i]){
            l=i;
        }
    }
    cout << N-l << endl;
    return 0;
}