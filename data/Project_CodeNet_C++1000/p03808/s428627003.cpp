#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll sum = 0;
    rep(i,N){
        sum += A[i];
    }
    if(sum % (N*(N+1)/2) != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll k = sum / (N*(N+1)/2);
    vector<ll> d(N);
    rep(i,N){
        if(i == N-1) d[i] = A[0]-A[N-1];
        else d[i] = A[i+1]-A[i];
    }
    rep(i,N) d[i] -= k;
    bool ok = true;
    rep(i,N){
        if(d[i] > 0 || d[i] % N != 0) ok = false;
    }
    cout << (ok?"YES" : "NO") << endl;
}
    

