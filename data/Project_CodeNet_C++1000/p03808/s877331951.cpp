#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 50;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N;
    vec a(N);
    S = "YES";
    ll sum = 0;
    rep(i,N){
        cin>>a[i];
        sum += a[i];
    }
    if(sum%(N*(N+1)/2) != 0) S = "NO";
    ll num = sum / (N*(N+1)/2), freq = num;
    rep(i,N){
        ll temp = a[i] + num - a[(i+1)%N];
        if(temp < 0 || temp%N != 0) S = "NO";
        freq -= temp/N;
    }
    if(freq != 0) S = "NO";
    cout<<S<<endl;
}