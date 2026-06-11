#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    ll q,h,s,d;
    ll n;
    cin >> q >> h >> s >> d;
    cin >> n;
    ll l1 = min({q*4, h*2, s});
    ll l2 = min({q*8, h*4, 2*s, d});
    if(l1*2 <= l2){
        cout << l1*n << endl;
    }else{
        cout << l2*(n/2) + l1*(n%2) << endl;
    }
    return 0;
}