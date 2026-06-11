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
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    ll n2 = 0, n4 = 0;
    rep(i,n){
        if(v[i]%4==0) n4++;
        else if(v[i]%2==0) n2++;
    }
    if(n4*2+1 >=n) cout << "Yes" << endl;
    else if(n2>=n-n4*2) cout<<"Yes" << endl;
    else if(n2>=n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}