#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
    cin >> N ;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    ll ans = 0;
    ll x = 2;
    ans += A[0] - 1;
    for(int i=1;i<N;i++){
        if(A[i]<x)continue;
        if(A[i]==x){
            x++;
            continue;
        }
        ans += (A[i]-1)/x;
    }
    cout << ans << endl;
}